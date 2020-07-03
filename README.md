# A fast, portable TPTP parser
A TPTP parser written in C++ using the bison/flex parser generator. The parser supports native bindings for Python, Java and Scala using swig.
> :information_source: __Note:__ *Early version. In the current state, the parser can only parse THF. Also their exists only a echo binary and a python3.7 binding.

## Setup
### install dependencies
* flex 
* bison >= 3.2

## Generate a TPTP parser
```Shell
$ ./build.sh
```

Generates the parser for various targets (binary, python3 for now) to different folders in ```./bin/``` using the parser and lexer defined in ```src/*```. 

## Testrun
### check parser consistency
makes a diff of the origial problem and the output of the parser (creating the parse tree and flatten it again)
```$ ./test-parser.sh PROBLEM_FILE```

### trim problem
trims a problem file to its essential content. Removed whitespaces, newlines and comments. Adds exactly one newline after each import and definition (after each ").").
```$ ./trim-problem.sh PROBLEM_FILE```

### cpp
```$ ./run-parser.sh PROBLEM_FILE```

### python3
```$ ./run-parser-python3.sh PROBLEM_FILE```

## License
The TPTP-parser is licensed under the BSD 3-clause "New" or "Revised" License. See [LICENSE](LICENSE).
