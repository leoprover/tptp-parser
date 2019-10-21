import sys
import time

import tptp_parser

def main(argv):
    time_init = time.time_ns()

    ast = tptp_parser.parse(argv[1])
    time_afterparse = time.time_ns()
    
    # to string
    print('% to string:')
    print(ast)

    time_afterast = time.time_ns()

    print('{parse} parse[ms]'.format(
        parse=int((time_afterparse-time_init)/1000000),
    ))
    print('{parse} parse+print[ms]'.format(
        parse=int((time_afterast-time_init)/1000000),
    ))

    print()
    print('% select specific child:')
    print(ast[0])
    print(ast[0].typeString())

    print()
    print('% iterate children:')
    for n in ast:
        print(n)

    print()
    print('% tree:')
    tptp_parser.tree(ast)

    print()
    print('% filtered tree:')
    tptp_parser.tree(ast, filter=tptp_parser.nodetype.thf_binary_formula)

    print()
    print('% inorder traversal:')
    for n in tptp_parser.traverse(ast):
        print(n, n.typeString())

    print()
    print('% inorder inorder with filter:')
    for n in tptp_parser.traverse(ast, filter=tptp_parser.nodetype.thf_binary_formula):
        print(n, n.typeString())

    print()
    print('% add stuff:')
    for n in tptp_parser.traverse(ast, filter=tptp_parser.nodetype.thf_binary_formula):
        n.addLeft(tptp_parser.node('*F'))
        n.addRight(tptp_parser.node('*B'))
    tptp_parser.tree(ast, filter=tptp_parser.nodetype.thf_binary_formula)

if __name__ == '__main__':
    main(sys.argv)
