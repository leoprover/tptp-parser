#include "tptp.parser.hh"
#include "tptp.ast.hh"
#include <vector>
#include <ostream>
#include <sstream>

using namespace tptp::ast;

std::ostream& node::out(std::ostream& o) const {
    int size = this->numChildren;
    bool nested = size > 1;
    nested = false;

    for (std::reverse_iterator<std::vector<node>::const_iterator> it = this->cleft.rbegin() ; it != this->cleft.rend(); ++it) {
        if(nested) o << "[";
        o << *it;
        if(nested) o << "]";
    }
    //o << " " << this->rule << " ";
    o << this->value;
    for (std::vector<node>::const_iterator it = this->cright.begin() ; it != this->cright.end(); ++it) {
        if(nested) o << "[";
        o << *it;
        if(nested) o << "]";
    }
    return o;
};

std::string node::toString()
{
    std::ostringstream oss;
    this->out(oss);
    return oss.str();
}

std::string node::ruleString()
{
    std::ostringstream oss;
    oss << this->rule;
    return oss.str();
}

node::node() {
    this->numChildren = 0;
}

node::node(std::string&& _value) {
    this->rule = noderule::terminal;
    this->value = _value;
    this->numChildren = 0;
}

node::node(noderule _rule) {
    this->rule = _rule;
    this->numChildren = 0;
}
node::node(noderule _rule, node&& c1) {
    this->rule = _rule;
    this->cright.push_back(c1);
    this->numChildren = 1;
}
node::node(noderule _rule, node&& c1, node&& c2) {
    this->rule = _rule;
    this->cright.push_back(c1);
    this->cright.push_back(c2);
    this->numChildren = 2;
}
node::node(noderule _rule, node&& c1, node&& c2, node&& c3) {
    this->rule = _rule;
    this->cright.push_back(c1);
    this->cright.push_back(c2);
    this->cright.push_back(c3);
    this->numChildren = 3;
}
node::node(noderule _rule, node&& c1, node&& c2, node&& c3, node&& c4) {
    this->rule = _rule;
    this->cright.push_back(c1);
    this->cright.push_back(c2);
    this->cright.push_back(c3);
    this->cright.push_back(c4);
    this->numChildren = 4;
}
node::node(noderule _rule, node&& c1, node&& c2, node&& c3, node&& c4, node&& c5) {
    this->rule = _rule;
    this->cright.push_back(c1);
    this->cright.push_back(c2);
    this->cright.push_back(c3);
    this->cright.push_back(c4);
    this->cright.push_back(c5);
    this->numChildren = 5;
}
node::node(noderule _rule, node&& c1, node&& c2, node&& c3, node&& c4, node&& c5, node&& c6) {
    this->rule = _rule;
    this->cright.push_back(c1);
    this->cright.push_back(c2);
    this->cright.push_back(c3);
    this->cright.push_back(c4);
    this->cright.push_back(c5);
    this->cright.push_back(c6);
    this->numChildren = 6;
}
node::node(noderule _rule, node&& c1, node&& c2, node&& c3, node&& c4, node&& c5, node&& c6, node&& c7) {
    this->rule = _rule;
    this->cright.push_back(c1);
    this->cright.push_back(c2);
    this->cright.push_back(c3);
    this->cright.push_back(c4);
    this->cright.push_back(c5);
    this->cright.push_back(c6);
    this->cright.push_back(c7);
    this->numChildren = 7;
}
node::node(noderule _rule, node&& c1, node&& c2, node&& c3, node&& c4, node&& c5, node&& c6, node&& c7, node&& c8) {
    this->rule = _rule;
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
    return this->rule == noderule::terminal;
}

node& node::add_left(node&& c) {
    this->cleft.push_back(c);
    this->numChildren++;
    return *this;
}
node& node::add_right(node&& c) {
    this->cright.push_back(c);
    this->numChildren++;
    return *this;
}
node& node::child(int idx) {
    int l = this->cleft.size();
    if(idx < l) {
        return this->cleft[idx];
    }
    return this->cright[idx - l];
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
