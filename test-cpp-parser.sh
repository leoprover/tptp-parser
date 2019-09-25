#!/bin/sh

bin/tptp problems/thf.p
bin/tptp problems/SYN036^7.p
(cd bin/python3; python3 -m tptp_parser ../../problems/SYN036^7.p )
