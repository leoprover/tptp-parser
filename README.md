# A fast, portable TPTP parser
A TPTP parser written in C++ using the bison/flex parser generator. The parser supports native bindings for Python, Java and Scala using swig.
> :information_source: __Note:__ *Early version. In the current state, the parser can only parse THF. Also their exists only a echo binary and a python3 binding.

## Setup
### build dependencies
* cmake >= 3.16
* bison >= 3.2
* flex 

#### to build the python3 version additionally
* python >= 3.0
* swig

## Generate a TPTP parser
```Shell
$ ./build.sh
```

Generates the parser for various targets (binary, python3 for now) to different folders in ```./bin/``` using the parser and lexer defined in ```src/*```. 

## Testrun
### binary (parses and print the result)
```$ ./run-parser.sh PROBLEM_FILE```

### python3
```$ ./run-parser-python3.sh PROBLEM_FILE```

### check parser consistency
```$ ./test-parser.sh PROBLEM_FILE```
Makes a diff of the origial problem and the output of the parser (creating the parse tree and flatten it again)

### trim problem
```$ ./trim-problem.sh PROBLEM_FILE```
Trims a problem file to its essential content. Removes whitespaces, newlines and comments. Adds exactly one newline after each import and definition (after each ").").

## License
The TPTP-parser is licensed under the BSD 3-clause "New" or "Revised" License. See [LICENSE](LICENSE).
