from .tptp_parser import *

def traverse_inorder(node, filter=None):
    if filter is None or node.rule == filter:
        yield node
    if node.numChildren > 0:
        for n in node:
            for nn in traverse_inorder(n, filter):
                yield nn

def tree(node, depth=0, filter=None):
    if node.rule == filter:
        filter = None
        depth = 0

    if depth > 0:
        prefix = ((depth)*2)*' '
    else:
        prefix = ''

    if filter is None:
        if node.isTerminal():
            print(prefix + node.toString())
        else:
            print(prefix + '[' + node.ruleString() + ']')
        
    if node.numChildren > 0:
        for n in node:
            tree(n, depth=depth+1, filter=filter)