filename="festival"

input="\
4
6 3
1 2 3 1 2 3
6 2
1 2 3 1 2 3
6 3
1 2 3 1 2 3
6 2
1 2 3 1 2 3"

echo "$input" | cargo test $filename -- --nocapture
