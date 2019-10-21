#ifndef TPTP_AST_HH
# define TPTP_AST_HH
# include <vector>
# include <ostream> 
# include <iostream>
# include <string>
# include <sstream>

// found at https://stackoverflow.com/a/23404302
// allowing a simple enum to string conversion
#define MAKE_ENUM(name, ...) enum class name { __VA_ARGS__, __COUNT}; \
inline std::ostream& operator<<(std::ostream& os, name value) { \
std::string enumName = #name; \
std::string str = #__VA_ARGS__; \
int len = str.length(); \
std::vector<std::string> strings; \
std::ostringstream temp; \
for(int i = 0; i < len; i ++) { \
if(isspace(str[i])) continue; \
        else if(str[i] == ',') { \
        strings.push_back(temp.str()); \
        temp.str(std::string());\
        } \
        else temp<< str[i]; \
} \
strings.push_back(temp.str()); \
os << strings[static_cast<int>(value)]; \
return os;} 

namespace tptp {
namespace ast {

MAKE_ENUM(nodetype,
    none, terminal,
    TPTP_file, TPTP_input,
    annotated_formula,
    thf_annotated, tff_annotated, tcf_annotated, fof_annotated, cnf_annotated, tpi_annotated,
    thf_formula, tff_formula, tcf_formula, fof_formula, cnf_formula, tpi_formula,
    thf_logic_formula, thf_binary_formula, thf_unit_formula, thf_preunit_formula, thf_unitary_formula, thf_apply_formula,
    thf_quantified_formula, thf_quantification, thf_variable_list, thf_typed_variable, 
    thf_prefix_unary, thf_atomic_formula, thf_plain_atomic, 
    thf_defined_atomic, thf_system_atomic, 
    thf_conditional, thf_unitary_term, thf_let, thf_let_types, thf_let_types_list, 
    thf_let_defn, thf_let_defns, thf_let_defns_list, thf_tuple, thf_formula_list, thf_conn_term,
    thf_top_level_type, thf_atom_typing, thf_binary_type, thf_mapping_type, thf_xprod_type, thf_union_type, thf_subtype, thf_sequent,
    thf_unitary_type, thf_apply_type,
    thf_quantifier, th1_quantifier, th0_quantifier, fof_quantifier,
    thf_unary_connective, th1_unary_connective, unary_connective, nonassoc_connective, assoc_connective,
    atom, untyped_atom, 
    constant, functor, system_constant, system_functor, defined_constant, defined_functor, defined_term, variable,
    source, optional_info, useful_info,
    include, formula_selection, name_list,
    general_function, general_data, formula_data, general_term, general_list, general_terms,
    name, formula_role, annotations,
    atomic_defined_word, atomic_system_word, number, file_name,
    atomic_word, single_quoted, distinct_object
);

enum class structuretype{
    none,
    OPERATOR,            /* c1 IND c2 */
    SEQUENCE,            /* c1 c2 c3 .. */
    SEPERATED_SEQUENCE,  /* c1 PLC c2 PLC c3 .. */
    LIST,                /* PLC c1 PLC c2 PLC c3 .. PLC */
    NAMED_LIST,          /* IND PLC c1 PLC c2 PLC c3 .. PLC */
    SINGLE,              /* c1 */
    ANNONTATED,          /* IND c1 PLC c2 PLC c3 optional PLC */
    ANNONTATED_OPTION,   /* PLC c1 c2 */ 
    PREFIX,              /* IND c1 */
    SUFFIX,              /* c1 INC */
    BINDER,              /* IND PLC c1 PLC PLC */
    BRACKET,             /* PLC c1 c2 c3 .. PLC */
    NAMED_BRACKET        /* INC PLC c1 c2 c3 .. PLC */
};

class StopNodeIterator {};

class node
{
public:
    node();
    node(const char*);
    node(std::string&&);
    
    // enforce default assigment operators to get compiler errors if we fuck up the member attributes of the class
    node(const node&) = default;
    node(node&&) = default; 
    node& operator=(const node&) = delete;
    node& operator=(node&&) = default;
    ~node() = default; 

    // TODO/REMOVED: does this make problems with std::move? if not, use std::initializer_list<node> implementation again.
    // list initializer, to be able to write
    // node n1 = node(name, {c1, c2, c3})
    // node(nodetype, std::initializer_list<node>);
    node(nodetype, structuretype);
    node(nodetype, structuretype, node&&);
    node(nodetype, structuretype, node&&, node&&);
    node(nodetype, structuretype, node&&, node&&, node&&);
    node(nodetype, structuretype, node&&, node&&, node&&, node&&);
    node(nodetype, structuretype, node&&, node&&, node&&, node&&, node&&);
    node(nodetype, structuretype, node&&, node&&, node&&, node&&, node&&, node&&);
    node(nodetype, structuretype, node&&, node&&, node&&, node&&, node&&, node&&, node&&);
    node(nodetype, structuretype, node&&, node&&, node&&, node&&, node&&, node&&, node&&, node&&);

    // all manipulation have move semantics, hence the object is manipulated and a point on the object is returned (for chaining).
    // add a child as the leftmost child, return the node itself for method-chaining
    node&& addLeft(node&&);
    // add a child as the rightmost child, return the node itself for method-chaining
    node&& addRight(node&&);
    // set child at given index
    node&& setChild(int, node&&);
    // adds a new child at the given position, moves all children right of the newly inserted one to the right (increasing their index).
    node&& addChild(int, node&&);
    // get child at given index
    node&& getChild(int);

    // iterator support for python
    node& __iter__();
    node& __next__();

    // toString
    virtual std::ostream& out(std::ostream& o) const;
    friend std::ostream& operator<<(std::ostream& o, const node& n) { return n.out(o); }
    std::string toString();
    std::string typeString();

    bool isTerminal();

    structuretype structure = structuretype::none;
    nodetype type = nodetype::none;
    std::string value;
    int numChildren;
private:
    // For efficient child insert O(1), we use two vectors instead of one to store our children. 
    // One left- and one right-expanding.
    // Left expanding child vector, used for children inserted left
    std::vector<node> cleft;
    // Right expanding child vector, used for children inserted right
    std::vector<node> cright;
    int iter_index;
};

} // ! namespace ast
} // ! namespace tptp

#endif // ! TPTP_AST
