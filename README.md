# A fast protable TPTP parser
A TPTP parser written C++, generated using bison/flex with native bindings for Python, Java and Scala using swig.
> :information_source: __Note:__ *Very early version. In the current state, the parser can only parse THF. No external bindings yet.*

## Setup
### install dependencies
* flex 
* bison >= 3.2

## Generate a tptp-parser
```$ ./generate-parser.sh ```
Generate a bison parser (in cpp) for tptp to ```./tptp-parser-cpp/``` from the grammar in ```./tptp-parser-cpp``` using ```flex/bison```.

Additionally, builds a test parser executable in ```./tptp-parser-cpp/``` from the cpp sources.

## Test the tptp-parser c-implementation
### run
```$ ./test-cpp-parser.sh ```

## License
The TPTP-parser is licensed under the BSD 3-clause "New" or "Revised" License. See [LICENSE](LICENSE).
