# A fast, portable TPTP parser
A TPTP parser written in C++ using the bison/flex parser generator. The parser supports native bindings for Python, Java and Scala using swig.
> :information_source: __Note:__ *Early version. In the current state, the parser can only parse THF. Their exists only a python3.7 binding - a distutil setup will be implemented next.

## Setup
### install dependencies
* flex 
* bison >= 3.2

## Generate a tptp-parser
```Shell
$ ./generate-parser.sh
```

Generate the parser to ```./tptp-parser/``` from the grammar defined in ```tptp.ll``` and ```tptp.yy``` using ```flex/bison```. 
Additionally, builds a test parser executable ```./tptp-parser/tptp```.

## Testrun
### cpp
```$ ./run-parser.sh PROBLEM_FILE```

### python3
```$ ./run-parser-python3.sh PROBLEM_FILE```

## License
The TPTP-parser is licensed under the BSD 3-clause "New" or "Revised" License. See [LICENSE](LICENSE).
