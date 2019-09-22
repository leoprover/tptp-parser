# A fast, portable TPTP parser
A TPTP parser written in C++ using the bison/flex parser generator. The parser supports native bindings for Python, Java and Scala using swig.
> :information_source: __Note:__ *Very early version. In the current state, the parser can only parse THF. No external bindings yet.*

## Setup
### install dependencies
* flex 
* bison >= 3.2

## Generate a tptp-parser
```$ ./generate-parser.sh ```
Generate the flex/bison parser (in cpp) for tptp to ```./tptp-parser-cpp/``` from the grammar in ```./tptp-parser-cpp``` using ```flex/bison```.

Additionally, builds a test parser executable in ```./tptp-parser-cpp/``` from the cpp sources.

## Test the tptp-parser c-implementation
### run
```$ ./test-cpp-parser.sh ```

## License
The TPTP-parser is licensed under the BSD 3-clause "New" or "Revised" License. See [LICENSE](LICENSE).
