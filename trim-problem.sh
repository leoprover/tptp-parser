# trim comments and formatting space form any TPTP-problem file
# 1. remove comments
# 2. remove all whitespaces and newlines
# 3. add newline after each entry (marked by ). )
cat $1 | sed '/^%/d' | tr -d ' \n' | sed 's/)\./)\.\n/g'
