$sample_count = 0
$test_count = 0
$targets = {}

file "Rakefile"
directory "aux"
directory "samples"
directory "tests"

def find(symbol)
  Dir["#{symbol}.{cc,cpp,java,py,rb}"].first.split(".")
end

def command(symbol)
  b, e = find(symbol)
  case e
  when "cc"
    "./#{b}.exe"
  when "cpp"
    "./#{b}.exe"
  when "java"
    "java #{b}"
  when "py"
    "python3 #{b}.py"
  when "rb"
    "ruby #{b}.rb"
  end
end

def make_target(symbol)
  b, e = find(symbol)
  case e
  when "cc"
    target = "#{b}.exe"
    file target => "#{b}.cc" do
      sh "clang-format -i #{b}.cc"
      sh "c++ -I../.. ${CXXFLAGS} #{b}.cc -o#{b}.exe"
    end
  when "cpp"
    target = "#{b}.exe"
    file target => "#{b}.cpp" do
      sh "clang-format -i #{b}.cpp"
      sh "c++ -I../.. ${CXXFLAGS} #{b}.cpp -o#{b}.exe"
    end
  when "java"
    target = "#{b}.class"
    file target => "#{b}.java" do
      sh "javac #{b}.java"
    end
  when "py"
    target = "#{b}.py"
    file target
  when "rb"
    target = "#{b}.rb"
    file target
  end
  target
end

def target(symbol)
  $targets[symbol] ||= make_target(symbol)
end

def add_target(symbol)
  task :default => target(symbol)
end

def generate(generator, test_input, test_output, *params, **options)
  common_deps = %w(Rakefile aux samples tests)
  if generator.is_a? String
    file test_input => [*common_deps, generator] do
      cp generator, test_input
    end
  else
    file test_input => [*common_deps, target(generator)] do
      sh "#{command generator} #{params.join(" ")} #{options[:seed] || test_input} > #{test_input}"
    end
  end

  file test_output => [*common_deps, test_input, target(:check), target(:solution), target(:validator)] do
    sh "#{command :validator} < #{test_input}"
    sh "#{command :solution} < #{test_input} > #{test_output}"
    sh "#{command :check} #{test_input} #{test_output} #{test_output}"
  end
end

def sample(generator, *params, **options)
  $sample_count += 1

  test_input = "samples/%03d" % [$sample_count]
  test_output = "samples/%03d.a" % [$sample_count]

  generate generator, test_input, test_output, *params, **options
  task :default => test_output
end

def test(generator, *params, **options)
  $test_count += 1

  test_input = "tests/%03d" % [$test_count]
  test_output = "tests/%03d.a" % [$test_count]

  generate generator, test_input, test_output, *params, **options
  task :default => test_output
end

def multitest(*tests)
  $test_count += 1

  aux_inputs, aux_outputs = [], []
  tests.each_with_index do |test, test_id|
    generator, *params = test
    options = {}
    options = params.pop if not params.empty? and params[-1].is_a?(Hash)
    aux_input = "aux/%03d.%03d" % [$test_count, test_id]
    aux_output = "aux/%03d.%03d.a" % [$test_count, test_id]
    generate generator, aux_input, aux_output, *params, **options
    aux_inputs << aux_input
    aux_outputs << aux_output
  end

  test_input = "tests/%03d" % [$test_count]
  test_output = "tests/%03d.a" % [$test_count]

  file test_input => aux_inputs do
    sh "cat #{aux_inputs.join(" ")} > #{test_input}"
  end
  file test_output => [test_input, *aux_outputs] do
    sh "#{command :validator} < #{test_input}"
    sh "#{command :solution} < #{test_input} > #{test_output}"
    sh "bash -c '#{command :check} #{test_input} #{test_output} <(cat #{aux_outputs.join(" ")})'"
  end

  task :default => test_output
end

def packed
  yield

  packed_input = 'tests/test.in'
  packed_output = 'tests/test.out'
  inputs, outputs = [], []
  1.upto($sample_count) do |i|
    inputs << "samples/%03d" %[i]
    outputs << "samples/%03d.a" %[i]
  end
  1.upto($test_count) do |i|
    inputs << "tests/%03d" %[i]
    outputs << "tests/%03d.a" %[i]
  end

  file packed_input => inputs + [target(:validator)] do
    sh "cat #{inputs.join(' ')} > #{packed_input}"
    sh "#{command :validator} < #{packed_input}"
  end
  file packed_output => [packed_input, *outputs] do
    sh "#{command :solution} < #{packed_input} > #{packed_output}"
    sh "bash -c '#{command :check} #{packed_input} #{packed_output} <(cat #{outputs.join(" ")})'"
  end

  task :default => packed_output
end

task :clean do
  sh "rm -rf *.a *.class *.exe input output answer out ans aux samples tests"
  if /darwin/ =~ RUBY_PLATFORM
    sh "find . -perm +u+x -type f -delete"
  else
    sh "find . -executable -delete"
  end
end
