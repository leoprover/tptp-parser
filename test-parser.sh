# calculates the diff of the reference and the output of the parser
diff <(./trim-problem.sh $1) <(./run-parser.sh $1 | ./trim-problem.sh)
