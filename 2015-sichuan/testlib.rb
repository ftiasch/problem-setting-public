class Cleanroom
    def make(*a)
    end

    def sh(*a)
    end

    def test(*a)
        puts "test #{a.to_s[1..-2]}"
    end
end

def doall(&blk)
    puts "require_relative '../../common'"
    puts
    puts "sample '001.hand'"
    puts "sample '002.hand'"
    puts

    Cleanroom.new.tap do |e|
        e.instance_eval(&blk)
    end
end
