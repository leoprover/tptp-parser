#ifndef TPTP_AST_HH
# define TPTP_AST_HH
# include <vector>
# include <ostream> 
# include <iostream>

namespace tptp {
namespace ast {

enum noderule {
    TPTP_file, TPTP_input,
    annotated_formula,
    thf_annotated, tff_annotated, tcf_annotated, fof_annotated, cnf_annotated, tpi_annotated,
    thf_formula, tff_formula, tcf_formula, fof_formula, cnf_formula, tpi_formula,
    // thf
    thf_logic_formula, thf_binary_formula, thf_unit_formula, thf_preunit_formula, thf_unitary_formula, thf_apply_formula,
    thf_quantified_formula, thf_quantification, thf_variable_list, thf_typed_variable, 
    /*thf_unary_formula,*/ thf_prefix_unary, /*thf_infix_unary,*/ thf_atomic_formula, thf_plain_atomic, 
    thf_defined_atomic, /*thf_defined_infix,*/ thf_system_atomic, 
    thf_conditional, thf_unitary_term, thf_let, thf_let_types, thf_let_types_list, 
    thf_let_defn, thf_let_defns, thf_let_defns_list, thf_tuple, thf_formula_list, thf_conn_term,
    thf_top_level_type, thf_atom_typing, thf_binary_type, thf_mapping_type, thf_xprod_type, thf_union_type, thf_subtype, thf_sequent,
    thf_unitary_type, thf_apply_type,
    // quantifier
    thf_quantifier, th1_quantifier, th0_quantifier, fof_quantifier,
    thf_unary_connective, th1_unary_connective, unary_connective, nonassoc_connective, assoc_connective,
    // general 
    atom, untyped_atom, /*defined_infix_pred,*/
    constant, functor, system_constant, system_functor, defined_constant, defined_functor, defined_term, variable,
    source, optional_info, useful_info,
    include, formula_selection, name_list,
    general_function, general_data, formula_data, general_term, general_list, general_terms,
    name, formula_role, annotations,
    atomic_defined_word, atomic_system_word, number, file_name,
    atomic_word, single_quoted, distinct_object
};

class node
{
public:
    node();
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
    // node(noderule, std::initializer_list<node>);
    node(noderule);
    node(noderule, node&&);
    node(noderule, node&&, node&&);
    node(noderule, node&&, node&&, node&&);
    node(noderule, node&&, node&&, node&&, node&&);
    node(noderule, node&&, node&&, node&&, node&&, node&&);
    node(noderule, node&&, node&&, node&&, node&&, node&&, node&&);
    node(noderule, node&&, node&&, node&&, node&&, node&&, node&&, node&&);
    node(noderule, node&&, node&&, node&&, node&&, node&&, node&&, node&&, node&&);

    // add a child as the leftmost child, return the node itself for method-chaining
    node& add_left(node&&);
    // add a child as the rightmost child, return the node itself for method-chaining
    node& add_right(node&&);

    // toString
    virtual std::ostream& print(std::ostream& o) const;
    friend std::ostream& operator<<(std::ostream& o, const node& n) { return n.print(o); }

    noderule rule;
    std::string value;
private:
    // For effient child insert O(1), we use two vectors instead of one to store our children. One left- and one right-expanding.
    // Left expanding child vector, used for children inserted left
    std::vector<node> cleft;
    // Right expanding child vector, used for children inserted right
    std::vector<node> cright;
};

} // ! namespace ast
} // ! namespace tptp

#endif // ! TPTP_AST
