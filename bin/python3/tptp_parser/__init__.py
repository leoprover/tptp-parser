from .tptp_parser import *

def traverse(node, filter=None):
    if filter is None or node.rule == filter:
        yield node
    if node.numChildren > 0:
        for n in node:
            for nn in traverse(n, filter):
                yield nn

def tree(node, filter=None, prefix=''):
    if filter:
        if node.rule == filter:
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
        print(draw_prefix + node.ruleString())
        
    if node.numChildren > 0:
        for i in range(0,node.numChildren-1):
            tree(node.child(i), prefix=prefix+'│')
        tree(node.child(node.numChildren-1), prefix=prefix+' ')
