#!/bin/sh

cd tptp-parser
make -f Makefile.parser clean
make -f Makefile.parser $1
