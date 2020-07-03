from .tptp_parser import *
from . import tptp_parser as _tptp_parser

def traverse(node, filter=None):
    if filter is None or node.type == filter:
        yield node
    if node.numChildren > 0:
        for n in node:
            for nn in traverse(n, filter):
                yield nn

def tree(node, filter=None, prefix=''):
    if filter:
        if node.type == filter:
            tree(node)    
        for n in node:
            tree(n, filter=filter)
        return

    if prefix:
        draw_prefix = prefix[:-1] + ('└' if prefix[-1] == ' ' else '├')
    else:
        draw_prefix = prefix

    if node.isTerminal():
        print(draw_prefix + '"' + str(node) + '"')
    else:
        print(draw_prefix + node.typeString())
        
    if node.numChildren > 0:
        for i in range(0,node.numChildren-1):
            tree(node[i], prefix=prefix+'│')
        tree(node[node.numChildren-1], prefix=prefix+' ')

class ParserEnum():
    def __init__(self, prefix):
        self.prefix = prefix

    def __getattr__(self, key):
        return getattr(_tptp_parser, self.prefix + '_' + key)

nodetype = ParserEnum('nodetype')
structuretype = ParserEnum('structuretype')
