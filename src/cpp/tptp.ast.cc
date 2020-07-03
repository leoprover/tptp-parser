#include "tptp.parser.hh"
#include "tptp.ast.hh"
#include <vector>
#include <ostream>
#include <sstream>

using namespace tptp::ast;

bool node::DEBUG_WITH_NESTING = false;
bool node::DEBUG_WITH_TYPE = false;
bool node::DEBUG_WITH_STRUCTURETYPE = false;

std::ostream& node::out(std::ostream& o) const {
    int size = this->numChildren;

    bool with_nested = node::DEBUG_WITH_NESTING ? size > 1 : false;
    bool with_type = node::DEBUG_WITH_TYPE;
    bool with_structure = node::DEBUG_WITH_STRUCTURETYPE;

    for (std::reverse_iterator<std::vector<node>::const_iterator> it = this->cleft.rbegin() ; it != this->cleft.rend(); ++it) {
        if(with_nested) o << "[";
        o << *it;
        if(with_nested) o << "]";
    }
    
    if (with_type | with_structure) 
    {
        o << "{";
        if (with_type) o << this->type;
        if (with_type & with_structure) o << ", ";
        if (with_structure) o << this->structure;
        o << "}";
    }
    o << this->value;
    
    for (std::vector<node>::const_iterator it = this->cright.begin() ; it != this->cright.end(); ++it) {
        if(with_nested) o << "[";
        o << *it;
        if(with_nested) o << "]";
    }

    // add a newline after each definition or import
    switch (this->type) {
        case nodetype::include:
        case nodetype::annotated_formula:
            o << '\n';
    }

    return o;
};

std::string node::toString()
{
    std::ostringstream oss;
    this->out(oss);
    return oss.str();
}

std::string node::typeString()
{
    std::ostringstream oss;
    oss << this->type;
    return oss.str();
}

node::node() {
    this->numChildren = 0;
}

node::node(const char* _value) {
    this->type = nodetype::terminal;
    this->value = _value;
    this->numChildren = 0;
}

node::node(std::string&& _value) {
    this->type = nodetype::terminal;
    this->value = _value;
    this->numChildren = 0;
}

node::node(nodetype _rule, structuretype _structure) {
    this->type = _rule;
    this->structure = _structure;
    this->numChildren = 0;
}
node::node(nodetype _rule, structuretype _structure, node&& c1) {
    this->type = _rule;
    this->structure = _structure;
    this->cright.push_back(c1);
    this->numChildren = 1;
}
node::node(nodetype _rule, structuretype _structure, node&& c1, node&& c2) {
    this->type = _rule;
    this->structure = _structure;
    this->cright.push_back(c1);
    this->cright.push_back(c2);
    this->numChildren = 2;
}
node::node(nodetype _rule, structuretype _structure, node&& c1, node&& c2, node&& c3) {
    this->type = _rule;
    this->structure = _structure;
    this->cright.push_back(c1);
    this->cright.push_back(c2);
    this->cright.push_back(c3);
    this->numChildren = 3;
}
node::node(nodetype _rule, structuretype _structure, node&& c1, node&& c2, node&& c3, node&& c4) {
    this->type = _rule;
    this->structure = _structure;
    this->cright.push_back(c1);
    this->cright.push_back(c2);
    this->cright.push_back(c3);
    this->cright.push_back(c4);
    this->numChildren = 4;
}
node::node(nodetype _rule, structuretype _structure, node&& c1, node&& c2, node&& c3, node&& c4, node&& c5) {
    this->type = _rule;
    this->structure = _structure;
    this->cright.push_back(c1);
    this->cright.push_back(c2);
    this->cright.push_back(c3);
    this->cright.push_back(c4);
    this->cright.push_back(c5);
    this->numChildren = 5;
}
node::node(nodetype _rule, structuretype _structure, node&& c1, node&& c2, node&& c3, node&& c4, node&& c5, node&& c6) {
    this->type = _rule;
    this->structure = _structure;
    this->cright.push_back(c1);
    this->cright.push_back(c2);
    this->cright.push_back(c3);
    this->cright.push_back(c4);
    this->cright.push_back(c5);
    this->cright.push_back(c6);
    this->numChildren = 6;
}
node::node(nodetype _rule, structuretype _structure, node&& c1, node&& c2, node&& c3, node&& c4, node&& c5, node&& c6, node&& c7) {
    this->type = _rule;
    this->structure = _structure;
    this->cright.push_back(c1);
    this->cright.push_back(c2);
    this->cright.push_back(c3);
    this->cright.push_back(c4);
    this->cright.push_back(c5);
    this->cright.push_back(c6);
    this->cright.push_back(c7);
    this->numChildren = 7;
}
node::node(nodetype _rule, structuretype _structure, node&& c1, node&& c2, node&& c3, node&& c4, node&& c5, node&& c6, node&& c7, node&& c8) {
    this->type = _rule;
    this->structure = _structure;
    this->cright.push_back(c1);
    this->cright.push_back(c2);
    this->cright.push_back(c3);
    this->cright.push_back(c4);
    this->cright.push_back(c5);
    this->cright.push_back(c6);
    this->cright.push_back(c7);
    this->cright.push_back(c8);
    this->numChildren = 8;
}

bool node::isTerminal() {
    return this->type == nodetype::terminal;
}

node&& node::addLeft(node&& c) {
    this->cleft.push_back(c);
    this->numChildren++;
    return std::move(*this);
}
node&& node::addRight(node&& c) {
    this->cright.push_back(c);
    this->numChildren++;
    return std::move(*this);
}
node&& node::setChild(int idx, node&& c) {
    const int l = this->cleft.size();
    if(idx < l) {
        this->cleft[idx] = std::move(c);
    }
    this->cright[idx - l] = std::move(c);

    return std::move(*this);

}
node&& node::addChild(int idx, node&& c) {
    const int l = this->cleft.size();
    if(idx < l) {
        this->cleft.insert(this->cleft.begin()+idx, std::move(c));
    }
    this->cright.insert(this->cright.begin()+idx-l, std::move(c));
    this->numChildren++;
    
    return std::move(*this);

}
node&& node::getChild(int idx) {
    const int l = this->cleft.size();
    if(idx < l) {
        return std::move(this->cleft[idx]);
    }
    return std::move(this->cright[idx - l]);
}

// iterator support for python
node& node::__iter__() {
    this->iter_index = 0;
    return *this;
}
node& node::__next__() {
    if(this->iter_index >= this->numChildren) {
        throw StopNodeIterator();
    }
    int l = this->cleft.size();
    if(this->iter_index < l) {
        // cleft is reversed
        return this->cleft[l - ++this->iter_index];
    }
    return this->cright[this->iter_index++ - l];
}

// removed for performance reasons together with std::move
/*
node::node(rule _name, std::initializer_list<node> l) {
    this->name = _name;
    this->children.insert(this->children.end(), l.begin(), l.end());
}
*/
