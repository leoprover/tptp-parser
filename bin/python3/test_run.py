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

    print()
    print('% select specific child:')
    print(ast.child(0))
    print(ast.child(0).ruleString())

    print()
    print('% iterate children:')
    for n in ast:
        print(n)

    print()
    print('% tree:')
    tptp_parser.tree(ast)

    print()
    print('% filtered tree:')
    tptp_parser.tree(ast, filter=tptp_parser.noderule_thf_binary_formula)

    print()
    print('% inorder traversal:')
    for n in tptp_parser.traverse(ast):
        print(n, n.ruleString())

    print()
    print('% inorder inorder with filter:')
    for n in tptp_parser.traverse(ast, filter=tptp_parser.noderule_thf_binary_formula):
        print(n, n.ruleString())

    time_afterast = time.time_ns()

    print('{parse} parse[ms]'.format(
        parse=int((time_afterast-time_init)/1000000),
    ))

if __name__ == '__main__':
    main(sys.argv)
