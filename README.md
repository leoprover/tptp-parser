# A fast, portable TPTP parser
A TPTP parser written in C++ using the bison/flex parser generator. The parser supports native bindings for Python, Java and Scala using swig.
> :information_source: __Note:__ *Very early version. In the current state, the parser can only parse THF. No external bindings yet.*

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
### run
```$ ./test-parser.sh ```

## License
The TPTP-parser is licensed under the BSD 3-clause "New" or "Revised" License. See [LICENSE](LICENSE).
