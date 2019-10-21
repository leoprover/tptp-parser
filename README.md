# A fast, portable TPTP parser
A TPTP parser written in C++ using the bison/flex parser generator. The parser supports native bindings for Python, Java and Scala using swig.
> :information_source: __Note:__ *Early version. In the current state, the parser can only parse THF. Also their exists only a echo binary and a python3.7 binding.

## Setup
### install dependencies
* flex 
* bison >= 3.2

## Generate a tptp-parser
```Shell
$ ./generate-parser.sh
```

Generates the parser for various targets (python3, binary, ..) to different folders in ```./bin/``` using the parser and lexer defined in ```tptp-parser/*```. 

## Testrun
### cpp
```$ ./run-parser.sh PROBLEM_FILE```

### python3
```$ ./run-parser-python3.sh PROBLEM_FILE```

## License
The TPTP-parser is licensed under the BSD 3-clause "New" or "Revised" License. See [LICENSE](LICENSE).
