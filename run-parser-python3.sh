#!/bin/sh

HERE=`dirname $0`

(cd bin/python3; python3 test_run.py $HERE/../../$1 )
