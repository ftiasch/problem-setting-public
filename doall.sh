#!/bin/bash
set -o errexit

if [[ "$#" != 1 ]]; then
    echo "Usage: $0 CONTEST_NAME"
    exit 1
fi

contest_name=$1
if [[ ! -d "$contest_name" ]]; then
    echo "Contest '$contest_name' does not exists."
    exit 1
fi

cd $contest_name

RELEASE='release'

mkdir -p $RELEASE

STATEMENT=$RELEASE/statement.md
echo $STATEMENT
echo '' > $STATEMENT

problem_count=64
for problem in $(cat PROBLEMS); do
    problem_count=$(($problem_count + 1))
    code=$(echo $problem_count | awk '{printf("%c", $1)}')

    (cd $problem && rake -m)

    problem_release=$RELEASE/$code
    mkdir -p $problem_release

    cp $problem/solution.cpp  $problem_release/solution.cpp
    cp $problem/check.cpp     $problem_release/check.cpp
    if [ -f $problem/slow.cpp ]; then
        cp $problem/slow.cpp      $problem_release/slow.cpp
    fi
    cp -r $problem/samples $problem_release
    cp -r $problem/tests   $problem_release

    if test -f $problem/statement.cn.md; then
        cat $problem/statement.cn.md >> $STATEMENT
        {
            printf "\n## 样例输入\n\`\`\`\n"
            cat $problem/samples/???
            printf "\`\`\`\n\n## 样例输出\n\`\`\`\n"
            cat $problem/samples/???.a
            printf "\`\`\`\n\n"
        } | python -c "import sys; sys.stdout.write(open('$STATEMENT').read().replace('<!--SAMPLES-->', sys.stdin.read()))" > $STATEMENT.new
    else
        cat $problem/statement.md >> $STATEMENT
        {
            printf "\n## Sample Input\n\`\`\`\n"
            cat $problem/samples/???
            printf "\`\`\`\n\n## Sample Output\n\`\`\`\n"
            cat $problem/samples/???.a
            printf "\`\`\`\n\n"
        } | python -c "import sys; sys.stdout.write(open('$STATEMENT').read().replace('<!--SAMPLES-->', sys.stdin.read()))" > $STATEMENT.new
    fi
    mv $STATEMENT.new $STATEMENT

    printf "\n\\\newpage\n\n" >> $STATEMENT
done

if [[ `uname -s` == "Darwin" ]]; then
    engine_prefix='--latex-engine'
    font='Hiragino Sans GB'
else
    engine_prefix='--pdf-engine'
    font='Source Han Sans CN'
fi
pandoc $STATEMENT $engine_prefix=xelatex -V CJKmainfont="$font" --template=../template.tex -o"$RELEASE/statement.pdf"

cd ..
