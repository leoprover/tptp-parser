from .tptp_parser import *

def dfs(node):
    yield node
    if node.numChildren > 0:
        for n in node:
            for nn in dfs(n):
                yield nn

def filter(node, by):
    for n in dfs(node):
        if n.rule == by:
            yield n

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