#include "tptp.parser.hh"
#include "tptp.ast.hh"
#include <vector>
#include <ostream>

using namespace tptp::ast;

std::ostream& node::print(std::ostream& o) const {
    int size = this->cleft.size() + this->cright.size();
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

node::node() {
}

node::node(std::string&& _value) {
    this->value = _value;
}

node::node(noderule _rule) {
    this->rule = _rule;
}
node::node(noderule _rule, node&& c1) {
    this->rule = _rule;
    this->cright.push_back(c1);
}
node::node(noderule _rule, node&& c1, node&& c2) {
    this->rule = _rule;
    this->cright.push_back(c1);
    this->cright.push_back(c2);
}
node::node(noderule _rule, node&& c1, node&& c2, node&& c3) {
    this->rule = rule;
    this->cright.push_back(c1);
    this->cright.push_back(c2);
    this->cright.push_back(c3);
}
node::node(noderule _rule, node&& c1, node&& c2, node&& c3, node&& c4) {
    this->rule = _rule;
    this->cright.push_back(c1);
    this->cright.push_back(c2);
    this->cright.push_back(c3);
    this->cright.push_back(c4);
}
node::node(noderule _rule, node&& c1, node&& c2, node&& c3, node&& c4, node&& c5) {
    this->rule = _rule;
    this->cright.push_back(c1);
    this->cright.push_back(c2);
    this->cright.push_back(c3);
    this->cright.push_back(c4);
    this->cright.push_back(c5);
}
node::node(noderule _rule, node&& c1, node&& c2, node&& c3, node&& c4, node&& c5, node&& c6) {
    this->rule = _rule;
    this->cright.push_back(c1);
    this->cright.push_back(c2);
    this->cright.push_back(c3);
    this->cright.push_back(c4);
    this->cright.push_back(c5);
    this->cright.push_back(c6);
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
}

node& node::add_left(node&& c) {
    this->cleft.push_back(c);
    return *this;
}
node& node::add_right(node&& c) {
    this->cright.push_back(c);
    return *this;
}

// removed for performance reasons together with std::move
/*
node::node(rule _name, std::initializer_list<node> l) {
    this->name = _name;
    this->children.insert(this->children.end(), l.begin(), l.end());
}
*/
