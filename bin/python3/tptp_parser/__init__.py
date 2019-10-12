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
