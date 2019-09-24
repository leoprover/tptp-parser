import sys
import time

from . import tptp_parser

def main(argv):
    time_init = time.time_ns()

    ast = tptp_parser.parse(argv[1])
    time_afterparse = time.time_ns()
    
    print(ast)

    time_afterast = time.time_ns()

    print('{parse} parse[ms]'.format(
        parse=int((time_init-time_afterparse)/1000000),
    ))

if __name__ == '__main__':
    main(sys.argv)
