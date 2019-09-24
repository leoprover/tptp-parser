// A Bison parser, made by GNU Bison 3.4.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2019 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "tptp.grammar.hh"


// Unqualified %code blocks.
#line 30 "tptp.yy"
 
    #include <iostream>
    #include "tptp.parser.hh"
    #include "tptp.ast.hh"

    using namespace tptp;

    // $$ = N(IDENTIFIER);
    //   -> 
    // $$ = ast::node(ast::IDENTIFIER);
    // $$ = N(IDENTIFIER, $1, $2);
    //   -> 
    // $$ = ast::node(ast::IDENTIFIER, $1, $2);
    #define N(t, ...) ast::node(t __VA_OPT__(,) __VA_ARGS__ )

#line 61 "tptp.grammar.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 155 "tptp.grammar.cc"


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  parser::parser (tptp::parser& drv_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | Symbol types.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_number_type
  parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 64: // root
      case 65: // TPTP_file
      case 66: // TPTP_input
      case 67: // annotated_formula
      case 68: // thf_annotated
      case 69: // annotations
      case 70: // formula_role
      case 71: // thf_formula
      case 72: // thf_logic_formula
      case 73: // thf_binary_formula
      case 74: // thf_unit_formula
      case 75: // thf_preunit_formula
      case 76: // thf_unitary_formula
      case 77: // thf_apply_formula
      case 78: // thf_quantified_formula
      case 79: // thf_quantification
      case 80: // thf_variable_list
      case 81: // thf_variable_list__HELPER0
      case 82: // thf_typed_variable
      case 83: // thf_prefix_unary
      case 84: // thf_atomic_formula
      case 85: // thf_plain_atomic
      case 86: // thf_defined_atomic
      case 87: // thf_system_atomic
      case 88: // thf_conditional
      case 89: // thf_let
      case 90: // thf_let_types
      case 91: // thf_let_types_list
      case 92: // thf_let_defns
      case 93: // thf_let_defns_list
      case 94: // thf_let_defn
      case 95: // thf_unitary_term
      case 96: // thf_tuple
      case 97: // thf_formula_list
      case 98: // thf_conn_term
      case 99: // thf_atom_typing
      case 100: // thf_top_level_type
      case 101: // thf_unitary_type
      case 102: // thf_apply_type
      case 103: // thf_binary_type
      case 104: // thf_mapping_type
      case 105: // thf_xprod_type
      case 106: // thf_union_type
      case 107: // thf_subtype
      case 108: // thf_sequent
      case 109: // thf_quantifier
      case 110: // th1_quantifier
      case 111: // th0_quantifier
      case 112: // thf_unary_connective
      case 113: // th1_unary_connective
      case 114: // fof_quantifier
      case 115: // nonassoc_connective
      case 116: // assoc_connective
      case 117: // unary_connective
      case 118: // atom
      case 119: // untyped_atom
      case 120: // constant
      case 121: // functor
      case 122: // system_constant
      case 123: // system_functor
      case 124: // defined_constant
      case 125: // defined_functor
      case 126: // defined_term
      case 127: // variable
      case 128: // source
      case 129: // optional_info
      case 130: // useful_info
      case 131: // include
      case 132: // formula_selection
      case 133: // name_list
      case 134: // general_term
      case 135: // general_function
      case 136: // general_data
      case 137: // formula_data
      case 138: // general_list
      case 139: // general_terms
      case 140: // name
      case 141: // atomic_word
      case 142: // atomic_defined_word
      case 143: // atomic_system_word
      case 144: // number
      case 145: // file_name
      case 146: // single_quoted
      case 147: // distinct_object
        value.YY_MOVE_OR_COPY< node > (YY_MOVE (that.value));
        break;

      case 3: // DefinitionTHF
      case 4: // DefinitionInclude
      case 5: // DefinitionEnd
      case 6: // Dollar_ite
      case 7: // Dollar_let
      case 8: // Dollar_thf
      case 9: // Dollar_tff
      case 10: // Dollar_fof
      case 11: // Dollar_cnf
      case 12: // Dollar_fot
      case 13: // Lower_word
      case 14: // Upper_word
      case 15: // Integer
      case 16: // Rational
      case 17: // Real
      case 18: // Assignment
      case 19: // And
      case 20: // Or
      case 21: // Nand
      case 22: // Nor
      case 23: // Impl
      case 24: // If
      case 25: // Iff
      case 26: // Niff
      case 27: // Infix_equality
      case 28: // Infix_inequality
      case 29: // Not
      case 30: // ForallComb
      case 31: // TyForall
      case 32: // Forall
      case 33: // ExistsComb
      case 34: // TyExists
      case 35: // Exists
      case 36: // Lambda
      case 37: // ChoiceComb
      case 38: // Choice
      case 39: // DescriptionComb
      case 40: // Description
      case 41: // EqComb
      case 42: // App
      case 43: // LParen
      case 44: // RParen
      case 45: // LBrkt
      case 46: // RBrkt
      case 47: // LCurly
      case 48: // RCurly
      case 49: // Comma
      case 50: // Colon
      case 51: // Double_quote
      case 52: // Single_quote
      case 53: // Do_string
      case 54: // Sq_string
      case 55: // Subtype_sign
      case 56: // Arrow
      case 57: // Less_sign
      case 58: // Star
      case 59: // Gentzen_arrow
      case 60: // Plus
      case 61: // Dollar_word
      case 62: // Dollar_dollar_word
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 64: // root
      case 65: // TPTP_file
      case 66: // TPTP_input
      case 67: // annotated_formula
      case 68: // thf_annotated
      case 69: // annotations
      case 70: // formula_role
      case 71: // thf_formula
      case 72: // thf_logic_formula
      case 73: // thf_binary_formula
      case 74: // thf_unit_formula
      case 75: // thf_preunit_formula
      case 76: // thf_unitary_formula
      case 77: // thf_apply_formula
      case 78: // thf_quantified_formula
      case 79: // thf_quantification
      case 80: // thf_variable_list
      case 81: // thf_variable_list__HELPER0
      case 82: // thf_typed_variable
      case 83: // thf_prefix_unary
      case 84: // thf_atomic_formula
      case 85: // thf_plain_atomic
      case 86: // thf_defined_atomic
      case 87: // thf_system_atomic
      case 88: // thf_conditional
      case 89: // thf_let
      case 90: // thf_let_types
      case 91: // thf_let_types_list
      case 92: // thf_let_defns
      case 93: // thf_let_defns_list
      case 94: // thf_let_defn
      case 95: // thf_unitary_term
      case 96: // thf_tuple
      case 97: // thf_formula_list
      case 98: // thf_conn_term
      case 99: // thf_atom_typing
      case 100: // thf_top_level_type
      case 101: // thf_unitary_type
      case 102: // thf_apply_type
      case 103: // thf_binary_type
      case 104: // thf_mapping_type
      case 105: // thf_xprod_type
      case 106: // thf_union_type
      case 107: // thf_subtype
      case 108: // thf_sequent
      case 109: // thf_quantifier
      case 110: // th1_quantifier
      case 111: // th0_quantifier
      case 112: // thf_unary_connective
      case 113: // th1_unary_connective
      case 114: // fof_quantifier
      case 115: // nonassoc_connective
      case 116: // assoc_connective
      case 117: // unary_connective
      case 118: // atom
      case 119: // untyped_atom
      case 120: // constant
      case 121: // functor
      case 122: // system_constant
      case 123: // system_functor
      case 124: // defined_constant
      case 125: // defined_functor
      case 126: // defined_term
      case 127: // variable
      case 128: // source
      case 129: // optional_info
      case 130: // useful_info
      case 131: // include
      case 132: // formula_selection
      case 133: // name_list
      case 134: // general_term
      case 135: // general_function
      case 136: // general_data
      case 137: // formula_data
      case 138: // general_list
      case 139: // general_terms
      case 140: // name
      case 141: // atomic_word
      case 142: // atomic_defined_word
      case 143: // atomic_system_word
      case 144: // number
      case 145: // file_name
      case 146: // single_quoted
      case 147: // distinct_object
        value.move< node > (YY_MOVE (that.value));
        break;

      case 3: // DefinitionTHF
      case 4: // DefinitionInclude
      case 5: // DefinitionEnd
      case 6: // Dollar_ite
      case 7: // Dollar_let
      case 8: // Dollar_thf
      case 9: // Dollar_tff
      case 10: // Dollar_fof
      case 11: // Dollar_cnf
      case 12: // Dollar_fot
      case 13: // Lower_word
      case 14: // Upper_word
      case 15: // Integer
      case 16: // Rational
      case 17: // Real
      case 18: // Assignment
      case 19: // And
      case 20: // Or
      case 21: // Nand
      case 22: // Nor
      case 23: // Impl
      case 24: // If
      case 25: // Iff
      case 26: // Niff
      case 27: // Infix_equality
      case 28: // Infix_inequality
      case 29: // Not
      case 30: // ForallComb
      case 31: // TyForall
      case 32: // Forall
      case 33: // ExistsComb
      case 34: // TyExists
      case 35: // Exists
      case 36: // Lambda
      case 37: // ChoiceComb
      case 38: // Choice
      case 39: // DescriptionComb
      case 40: // Description
      case 41: // EqComb
      case 42: // App
      case 43: // LParen
      case 44: // RParen
      case 45: // LBrkt
      case 46: // RBrkt
      case 47: // LCurly
      case 48: // RCurly
      case 49: // Comma
      case 50: // Colon
      case 51: // Double_quote
      case 52: // Single_quote
      case 53: // Do_string
      case 54: // Sq_string
      case 55: // Subtype_sign
      case 56: // Arrow
      case 57: // Less_sign
      case 58: // Star
      case 59: // Gentzen_arrow
      case 60: // Plus
      case 61: // Dollar_word
      case 62: // Dollar_dollar_word
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 64: // root
      case 65: // TPTP_file
      case 66: // TPTP_input
      case 67: // annotated_formula
      case 68: // thf_annotated
      case 69: // annotations
      case 70: // formula_role
      case 71: // thf_formula
      case 72: // thf_logic_formula
      case 73: // thf_binary_formula
      case 74: // thf_unit_formula
      case 75: // thf_preunit_formula
      case 76: // thf_unitary_formula
      case 77: // thf_apply_formula
      case 78: // thf_quantified_formula
      case 79: // thf_quantification
      case 80: // thf_variable_list
      case 81: // thf_variable_list__HELPER0
      case 82: // thf_typed_variable
      case 83: // thf_prefix_unary
      case 84: // thf_atomic_formula
      case 85: // thf_plain_atomic
      case 86: // thf_defined_atomic
      case 87: // thf_system_atomic
      case 88: // thf_conditional
      case 89: // thf_let
      case 90: // thf_let_types
      case 91: // thf_let_types_list
      case 92: // thf_let_defns
      case 93: // thf_let_defns_list
      case 94: // thf_let_defn
      case 95: // thf_unitary_term
      case 96: // thf_tuple
      case 97: // thf_formula_list
      case 98: // thf_conn_term
      case 99: // thf_atom_typing
      case 100: // thf_top_level_type
      case 101: // thf_unitary_type
      case 102: // thf_apply_type
      case 103: // thf_binary_type
      case 104: // thf_mapping_type
      case 105: // thf_xprod_type
      case 106: // thf_union_type
      case 107: // thf_subtype
      case 108: // thf_sequent
      case 109: // thf_quantifier
      case 110: // th1_quantifier
      case 111: // th0_quantifier
      case 112: // thf_unary_connective
      case 113: // th1_unary_connective
      case 114: // fof_quantifier
      case 115: // nonassoc_connective
      case 116: // assoc_connective
      case 117: // unary_connective
      case 118: // atom
      case 119: // untyped_atom
      case 120: // constant
      case 121: // functor
      case 122: // system_constant
      case 123: // system_functor
      case 124: // defined_constant
      case 125: // defined_functor
      case 126: // defined_term
      case 127: // variable
      case 128: // source
      case 129: // optional_info
      case 130: // useful_info
      case 131: // include
      case 132: // formula_selection
      case 133: // name_list
      case 134: // general_term
      case 135: // general_function
      case 136: // general_data
      case 137: // formula_data
      case 138: // general_list
      case 139: // general_terms
      case 140: // name
      case 141: // atomic_word
      case 142: // atomic_defined_word
      case 143: // atomic_system_word
      case 144: // number
      case 145: // file_name
      case 146: // single_quoted
      case 147: // distinct_object
        value.move< node > (that.value);
        break;

      case 3: // DefinitionTHF
      case 4: // DefinitionInclude
      case 5: // DefinitionEnd
      case 6: // Dollar_ite
      case 7: // Dollar_let
      case 8: // Dollar_thf
      case 9: // Dollar_tff
      case 10: // Dollar_fof
      case 11: // Dollar_cnf
      case 12: // Dollar_fot
      case 13: // Lower_word
      case 14: // Upper_word
      case 15: // Integer
      case 16: // Rational
      case 17: // Real
      case 18: // Assignment
      case 19: // And
      case 20: // Or
      case 21: // Nand
      case 22: // Nor
      case 23: // Impl
      case 24: // If
      case 25: // Iff
      case 26: // Niff
      case 27: // Infix_equality
      case 28: // Infix_inequality
      case 29: // Not
      case 30: // ForallComb
      case 31: // TyForall
      case 32: // Forall
      case 33: // ExistsComb
      case 34: // TyExists
      case 35: // Exists
      case 36: // Lambda
      case 37: // ChoiceComb
      case 38: // Choice
      case 39: // DescriptionComb
      case 40: // Description
      case 41: // EqComb
      case 42: // App
      case 43: // LParen
      case 44: // RParen
      case 45: // LBrkt
      case 46: // RBrkt
      case 47: // LCurly
      case 48: // RCurly
      case 49: // Comma
      case 50: // Colon
      case 51: // Double_quote
      case 52: // Single_quote
      case 53: // Do_string
      case 54: // Sq_string
      case 55: // Subtype_sign
      case 56: // Arrow
      case 57: // Less_sign
      case 58: // Star
      case 59: // Gentzen_arrow
      case 60: // Plus
      case 61: // Dollar_word
      case 62: // Dollar_dollar_word
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << '\n';

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case 64: // root
      case 65: // TPTP_file
      case 66: // TPTP_input
      case 67: // annotated_formula
      case 68: // thf_annotated
      case 69: // annotations
      case 70: // formula_role
      case 71: // thf_formula
      case 72: // thf_logic_formula
      case 73: // thf_binary_formula
      case 74: // thf_unit_formula
      case 75: // thf_preunit_formula
      case 76: // thf_unitary_formula
      case 77: // thf_apply_formula
      case 78: // thf_quantified_formula
      case 79: // thf_quantification
      case 80: // thf_variable_list
      case 81: // thf_variable_list__HELPER0
      case 82: // thf_typed_variable
      case 83: // thf_prefix_unary
      case 84: // thf_atomic_formula
      case 85: // thf_plain_atomic
      case 86: // thf_defined_atomic
      case 87: // thf_system_atomic
      case 88: // thf_conditional
      case 89: // thf_let
      case 90: // thf_let_types
      case 91: // thf_let_types_list
      case 92: // thf_let_defns
      case 93: // thf_let_defns_list
      case 94: // thf_let_defn
      case 95: // thf_unitary_term
      case 96: // thf_tuple
      case 97: // thf_formula_list
      case 98: // thf_conn_term
      case 99: // thf_atom_typing
      case 100: // thf_top_level_type
      case 101: // thf_unitary_type
      case 102: // thf_apply_type
      case 103: // thf_binary_type
      case 104: // thf_mapping_type
      case 105: // thf_xprod_type
      case 106: // thf_union_type
      case 107: // thf_subtype
      case 108: // thf_sequent
      case 109: // thf_quantifier
      case 110: // th1_quantifier
      case 111: // th0_quantifier
      case 112: // thf_unary_connective
      case 113: // th1_unary_connective
      case 114: // fof_quantifier
      case 115: // nonassoc_connective
      case 116: // assoc_connective
      case 117: // unary_connective
      case 118: // atom
      case 119: // untyped_atom
      case 120: // constant
      case 121: // functor
      case 122: // system_constant
      case 123: // system_functor
      case 124: // defined_constant
      case 125: // defined_functor
      case 126: // defined_term
      case 127: // variable
      case 128: // source
      case 129: // optional_info
      case 130: // useful_info
      case 131: // include
      case 132: // formula_selection
      case 133: // name_list
      case 134: // general_term
      case 135: // general_function
      case 136: // general_data
      case 137: // formula_data
      case 138: // general_list
      case 139: // general_terms
      case 140: // name
      case 141: // atomic_word
      case 142: // atomic_defined_word
      case 143: // atomic_system_word
      case 144: // number
      case 145: // file_name
      case 146: // single_quoted
      case 147: // distinct_object
        yylhs.value.emplace< node > ();
        break;

      case 3: // DefinitionTHF
      case 4: // DefinitionInclude
      case 5: // DefinitionEnd
      case 6: // Dollar_ite
      case 7: // Dollar_let
      case 8: // Dollar_thf
      case 9: // Dollar_tff
      case 10: // Dollar_fof
      case 11: // Dollar_cnf
      case 12: // Dollar_fot
      case 13: // Lower_word
      case 14: // Upper_word
      case 15: // Integer
      case 16: // Rational
      case 17: // Real
      case 18: // Assignment
      case 19: // And
      case 20: // Or
      case 21: // Nand
      case 22: // Nor
      case 23: // Impl
      case 24: // If
      case 25: // Iff
      case 26: // Niff
      case 27: // Infix_equality
      case 28: // Infix_inequality
      case 29: // Not
      case 30: // ForallComb
      case 31: // TyForall
      case 32: // Forall
      case 33: // ExistsComb
      case 34: // TyExists
      case 35: // Exists
      case 36: // Lambda
      case 37: // ChoiceComb
      case 38: // Choice
      case 39: // DescriptionComb
      case 40: // Description
      case 41: // EqComb
      case 42: // App
      case 43: // LParen
      case 44: // RParen
      case 45: // LBrkt
      case 46: // RBrkt
      case 47: // LCurly
      case 48: // RCurly
      case 49: // Comma
      case 50: // Colon
      case 51: // Double_quote
      case 52: // Single_quote
      case 53: // Do_string
      case 54: // Sq_string
      case 55: // Subtype_sign
      case 56: // Arrow
      case 57: // Less_sign
      case 58: // Star
      case 59: // Gentzen_arrow
      case 60: // Plus
      case 61: // Dollar_word
      case 62: // Dollar_dollar_word
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2:
#line 148 "tptp.yy"
    { drv.ast = YY_MOVE (yystack_[0].value.as < node > ()); }
#line 1166 "tptp.grammar.cc"
    break;

  case 3:
#line 174 "tptp.yy"
    { yylhs.value.as < node > () = std::move(YY_MOVE (yystack_[0].value.as < node > ()).add_left(YY_MOVE (yystack_[1].value.as < node > ()))); }
#line 1172 "tptp.grammar.cc"
    break;

  case 4:
#line 175 "tptp.yy"
    { yylhs.value.as < node > () = N(TPTP_file, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1178 "tptp.grammar.cc"
    break;

  case 5:
#line 178 "tptp.yy"
    { yylhs.value.as < node > () = N(TPTP_input, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1184 "tptp.grammar.cc"
    break;

  case 6:
#line 179 "tptp.yy"
    { yylhs.value.as < node > () = N(TPTP_input, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1190 "tptp.grammar.cc"
    break;

  case 7:
#line 183 "tptp.yy"
    { yylhs.value.as < node > () = N(annotated_formula, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1196 "tptp.grammar.cc"
    break;

  case 8:
#line 192 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_annotated, YY_MOVE (yystack_[7].value.as < std::string > ()), YY_MOVE (yystack_[6].value.as < node > ()), YY_MOVE (yystack_[5].value.as < std::string > ()), YY_MOVE (yystack_[4].value.as < node > ()), YY_MOVE (yystack_[3].value.as < std::string > ()), YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < node > ()), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1202 "tptp.grammar.cc"
    break;

  case 9:
#line 196 "tptp.yy"
    { yylhs.value.as < node > () = N(annotations, YY_MOVE (yystack_[2].value.as < std::string > ()), YY_MOVE (yystack_[1].value.as < node > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1208 "tptp.grammar.cc"
    break;

  case 10:
#line 197 "tptp.yy"
    {}
#line 1214 "tptp.grammar.cc"
    break;

  case 11:
#line 214 "tptp.yy"
    { yylhs.value.as < node > () = N(formula_role, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1220 "tptp.grammar.cc"
    break;

  case 12:
#line 264 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_formula, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1226 "tptp.grammar.cc"
    break;

  case 13:
#line 265 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_formula, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1232 "tptp.grammar.cc"
    break;

  case 14:
#line 266 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_formula, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1238 "tptp.grammar.cc"
    break;

  case 15:
#line 267 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_formula, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1244 "tptp.grammar.cc"
    break;

  case 16:
#line 278 "tptp.yy"
    { yylhs.value.as < node > () = N(YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1250 "tptp.grammar.cc"
    break;

  case 17:
#line 282 "tptp.yy"
    { yylhs.value.as < node > () = N(YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1256 "tptp.grammar.cc"
    break;

  case 18:
#line 294 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_binary_formula, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1262 "tptp.grammar.cc"
    break;

  case 19:
#line 295 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_binary_formula, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1268 "tptp.grammar.cc"
    break;

  case 20:
#line 296 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_binary_formula, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1274 "tptp.grammar.cc"
    break;

  case 21:
#line 297 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_binary_formula, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1280 "tptp.grammar.cc"
    break;

  case 22:
#line 298 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_binary_formula, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1286 "tptp.grammar.cc"
    break;

  case 23:
#line 299 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_binary_formula, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1292 "tptp.grammar.cc"
    break;

  case 24:
#line 300 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_binary_formula, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1298 "tptp.grammar.cc"
    break;

  case 25:
#line 301 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_binary_formula, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1304 "tptp.grammar.cc"
    break;

  case 26:
#line 302 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_binary_formula, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1310 "tptp.grammar.cc"
    break;

  case 27:
#line 303 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_binary_formula, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1316 "tptp.grammar.cc"
    break;

  case 28:
#line 304 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_binary_formula, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1322 "tptp.grammar.cc"
    break;

  case 29:
#line 305 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_binary_formula, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1328 "tptp.grammar.cc"
    break;

  case 30:
#line 306 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_binary_formula, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1334 "tptp.grammar.cc"
    break;

  case 31:
#line 307 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_binary_formula, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1340 "tptp.grammar.cc"
    break;

  case 32:
#line 316 "tptp.yy"
    { yylhs.value.as < node > () = N(YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1346 "tptp.grammar.cc"
    break;

  case 33:
#line 324 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_unit_formula, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1352 "tptp.grammar.cc"
    break;

  case 34:
#line 325 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_unit_formula, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1358 "tptp.grammar.cc"
    break;

  case 35:
#line 326 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_unit_formula, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1364 "tptp.grammar.cc"
    break;

  case 36:
#line 330 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_preunit_formula, YY_MOVE (yystack_[1].value.as < node > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1370 "tptp.grammar.cc"
    break;

  case 37:
#line 334 "tptp.yy"
    { yylhs.value.as < node > () = N(YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1376 "tptp.grammar.cc"
    break;

  case 38:
#line 337 "tptp.yy"
    { yylhs.value.as < node > () = N(YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1382 "tptp.grammar.cc"
    break;

  case 39:
#line 344 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_apply_formula, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1388 "tptp.grammar.cc"
    break;

  case 40:
#line 345 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_apply_formula, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1394 "tptp.grammar.cc"
    break;

  case 41:
#line 373 "tptp.yy"
    { N(thf_quantified_formula, YY_MOVE (yystack_[1].value.as < node > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1400 "tptp.grammar.cc"
    break;

  case 42:
#line 377 "tptp.yy"
    { N(thf_quantification, YY_MOVE (yystack_[4].value.as < node > ()), YY_MOVE (yystack_[3].value.as < std::string > ()), YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1406 "tptp.grammar.cc"
    break;

  case 43:
#line 383 "tptp.yy"
    { yylhs.value.as < node > () = YY_MOVE (yystack_[0].value.as < node > ()); }
#line 1412 "tptp.grammar.cc"
    break;

  case 44:
#line 384 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_variable_list); }
#line 1418 "tptp.grammar.cc"
    break;

  case 45:
#line 387 "tptp.yy"
    { yylhs.value.as < node > () = std::move(YY_MOVE (yystack_[0].value.as < node > ()).add_left(YY_MOVE (yystack_[2].value.as < node > ()))); }
#line 1424 "tptp.grammar.cc"
    break;

  case 46:
#line 388 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_variable_list, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1430 "tptp.grammar.cc"
    break;

  case 47:
#line 392 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_typed_variable, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1436 "tptp.grammar.cc"
    break;

  case 48:
#line 402 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_prefix_unary, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1442 "tptp.grammar.cc"
    break;

  case 49:
#line 403 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_prefix_unary, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1448 "tptp.grammar.cc"
    break;

  case 50:
#line 412 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_atomic_formula, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1454 "tptp.grammar.cc"
    break;

  case 51:
#line 413 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_atomic_formula, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1460 "tptp.grammar.cc"
    break;

  case 52:
#line 414 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_atomic_formula, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1466 "tptp.grammar.cc"
    break;

  case 53:
#line 419 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_plain_atomic, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1472 "tptp.grammar.cc"
    break;

  case 54:
#line 420 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_plain_atomic, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1478 "tptp.grammar.cc"
    break;

  case 55:
#line 424 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_defined_atomic, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1484 "tptp.grammar.cc"
    break;

  case 56:
#line 425 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_defined_atomic, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1490 "tptp.grammar.cc"
    break;

  case 57:
#line 426 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_defined_atomic, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1496 "tptp.grammar.cc"
    break;

  case 58:
#line 427 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_defined_atomic, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1502 "tptp.grammar.cc"
    break;

  case 59:
#line 428 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_defined_atomic, YY_MOVE (yystack_[2].value.as < std::string > ()), YY_MOVE (yystack_[1].value.as < node > ()), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1508 "tptp.grammar.cc"
    break;

  case 60:
#line 437 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_system_atomic, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1514 "tptp.grammar.cc"
    break;

  case 61:
#line 462 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_conditional, YY_MOVE (yystack_[7].value.as < std::string > ()), YY_MOVE (yystack_[6].value.as < std::string > ()), YY_MOVE (yystack_[5].value.as < node > ()), YY_MOVE (yystack_[4].value.as < std::string > ()), YY_MOVE (yystack_[3].value.as < node > ()), YY_MOVE (yystack_[2].value.as < std::string > ()), YY_MOVE (yystack_[1].value.as < node > ()), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1520 "tptp.grammar.cc"
    break;

  case 62:
#line 466 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_let, YY_MOVE (yystack_[7].value.as < std::string > ()), YY_MOVE (yystack_[6].value.as < std::string > ()), YY_MOVE (yystack_[5].value.as < node > ()), YY_MOVE (yystack_[4].value.as < std::string > ()), YY_MOVE (yystack_[3].value.as < node > ()), YY_MOVE (yystack_[2].value.as < std::string > ()), YY_MOVE (yystack_[1].value.as < node > ()), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1526 "tptp.grammar.cc"
    break;

  case 63:
#line 470 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_let_types, YY_MOVE (yystack_[2].value.as < std::string > ()), YY_MOVE (yystack_[1].value.as < node > ()), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1532 "tptp.grammar.cc"
    break;

  case 64:
#line 471 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_let_types, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1538 "tptp.grammar.cc"
    break;

  case 65:
#line 475 "tptp.yy"
    { yylhs.value.as < node > () = std::move(YY_MOVE (yystack_[0].value.as < node > ()).add_left(YY_MOVE (yystack_[2].value.as < node > ()))); }
#line 1544 "tptp.grammar.cc"
    break;

  case 66:
#line 476 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_let_types_list, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1550 "tptp.grammar.cc"
    break;

  case 67:
#line 480 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_let_defns, YY_MOVE (yystack_[2].value.as < std::string > ()), YY_MOVE (yystack_[1].value.as < node > ()), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1556 "tptp.grammar.cc"
    break;

  case 68:
#line 481 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_let_defns, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1562 "tptp.grammar.cc"
    break;

  case 69:
#line 485 "tptp.yy"
    { yylhs.value.as < node > () = std::move(YY_MOVE (yystack_[0].value.as < node > ()).add_left(YY_MOVE (yystack_[2].value.as < node > ()))); }
#line 1568 "tptp.grammar.cc"
    break;

  case 70:
#line 486 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_let_defns_list, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1574 "tptp.grammar.cc"
    break;

  case 71:
#line 490 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_let_defn, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1580 "tptp.grammar.cc"
    break;

  case 72:
#line 494 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_unitary_term, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1586 "tptp.grammar.cc"
    break;

  case 73:
#line 495 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_unitary_term, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1592 "tptp.grammar.cc"
    break;

  case 74:
#line 496 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_unitary_term, YY_MOVE (yystack_[2].value.as < std::string > ()), YY_MOVE (yystack_[1].value.as < node > ()), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1598 "tptp.grammar.cc"
    break;

  case 75:
#line 500 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_tuple, YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1604 "tptp.grammar.cc"
    break;

  case 76:
#line 501 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_tuple, YY_MOVE (yystack_[2].value.as < std::string > ()), YY_MOVE (yystack_[1].value.as < node > ()), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1610 "tptp.grammar.cc"
    break;

  case 77:
#line 504 "tptp.yy"
    { yylhs.value.as < node > () = std::move(YY_MOVE (yystack_[0].value.as < node > ()).add_left(YY_MOVE (yystack_[2].value.as < node > ()))); }
#line 1616 "tptp.grammar.cc"
    break;

  case 78:
#line 505 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_formula_list, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1622 "tptp.grammar.cc"
    break;

  case 79:
#line 509 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_conn_term, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1628 "tptp.grammar.cc"
    break;

  case 80:
#line 510 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_conn_term, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1634 "tptp.grammar.cc"
    break;

  case 81:
#line 511 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_conn_term, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1640 "tptp.grammar.cc"
    break;

  case 82:
#line 512 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_conn_term, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1646 "tptp.grammar.cc"
    break;

  case 83:
#line 537 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_atom_typing, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1652 "tptp.grammar.cc"
    break;

  case 84:
#line 538 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_atom_typing, YY_MOVE (yystack_[2].value.as < std::string > ()), YY_MOVE (yystack_[1].value.as < node > ()), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1658 "tptp.grammar.cc"
    break;

  case 85:
#line 542 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_top_level_type, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1664 "tptp.grammar.cc"
    break;

  case 86:
#line 543 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_top_level_type, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1670 "tptp.grammar.cc"
    break;

  case 87:
#line 544 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_top_level_type, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1676 "tptp.grammar.cc"
    break;

  case 88:
#line 548 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_unitary_type, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1682 "tptp.grammar.cc"
    break;

  case 89:
#line 570 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_apply_type, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1688 "tptp.grammar.cc"
    break;

  case 90:
#line 574 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_binary_type, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1694 "tptp.grammar.cc"
    break;

  case 91:
#line 575 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_binary_type, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1700 "tptp.grammar.cc"
    break;

  case 92:
#line 576 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_binary_type, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1706 "tptp.grammar.cc"
    break;

  case 93:
#line 580 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_mapping_type, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1712 "tptp.grammar.cc"
    break;

  case 94:
#line 581 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_mapping_type, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1718 "tptp.grammar.cc"
    break;

  case 95:
#line 585 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_xprod_type, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1724 "tptp.grammar.cc"
    break;

  case 96:
#line 586 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_xprod_type, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1730 "tptp.grammar.cc"
    break;

  case 97:
#line 590 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_union_type, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1736 "tptp.grammar.cc"
    break;

  case 98:
#line 591 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_union_type, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1742 "tptp.grammar.cc"
    break;

  case 99:
#line 595 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_subtype, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1748 "tptp.grammar.cc"
    break;

  case 100:
#line 599 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_sequent, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1754 "tptp.grammar.cc"
    break;

  case 101:
#line 600 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_sequent, YY_MOVE (yystack_[2].value.as < std::string > ()), YY_MOVE (yystack_[1].value.as < node > ()), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1760 "tptp.grammar.cc"
    break;

  case 102:
#line 831 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_quantifier, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1766 "tptp.grammar.cc"
    break;

  case 103:
#line 832 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_quantifier, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1772 "tptp.grammar.cc"
    break;

  case 104:
#line 833 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_quantifier, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1778 "tptp.grammar.cc"
    break;

  case 105:
#line 837 "tptp.yy"
    { yylhs.value.as < node > () = N(th1_quantifier, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1784 "tptp.grammar.cc"
    break;

  case 106:
#line 838 "tptp.yy"
    { yylhs.value.as < node > () = N(th1_quantifier, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1790 "tptp.grammar.cc"
    break;

  case 107:
#line 842 "tptp.yy"
    { yylhs.value.as < node > () = N(th0_quantifier, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1796 "tptp.grammar.cc"
    break;

  case 108:
#line 843 "tptp.yy"
    { yylhs.value.as < node > () = N(th0_quantifier, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1802 "tptp.grammar.cc"
    break;

  case 109:
#line 844 "tptp.yy"
    { yylhs.value.as < node > () = N(th0_quantifier, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1808 "tptp.grammar.cc"
    break;

  case 110:
#line 848 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_unary_connective, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1814 "tptp.grammar.cc"
    break;

  case 111:
#line 849 "tptp.yy"
    { yylhs.value.as < node > () = N(thf_unary_connective, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1820 "tptp.grammar.cc"
    break;

  case 112:
#line 853 "tptp.yy"
    { yylhs.value.as < node > () = N(th1_unary_connective, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1826 "tptp.grammar.cc"
    break;

  case 113:
#line 854 "tptp.yy"
    { yylhs.value.as < node > () = N(th1_unary_connective, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1832 "tptp.grammar.cc"
    break;

  case 114:
#line 855 "tptp.yy"
    { yylhs.value.as < node > () = N(th1_unary_connective, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1838 "tptp.grammar.cc"
    break;

  case 115:
#line 856 "tptp.yy"
    { yylhs.value.as < node > () = N(th1_unary_connective, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1844 "tptp.grammar.cc"
    break;

  case 116:
#line 857 "tptp.yy"
    { yylhs.value.as < node > () = N(th1_unary_connective, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1850 "tptp.grammar.cc"
    break;

  case 117:
#line 861 "tptp.yy"
    { yylhs.value.as < node > () = N(fof_quantifier, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1856 "tptp.grammar.cc"
    break;

  case 118:
#line 862 "tptp.yy"
    { yylhs.value.as < node > () = N(fof_quantifier, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1862 "tptp.grammar.cc"
    break;

  case 119:
#line 866 "tptp.yy"
    { yylhs.value.as < node > () = N(nonassoc_connective, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1868 "tptp.grammar.cc"
    break;

  case 120:
#line 867 "tptp.yy"
    { yylhs.value.as < node > () = N(nonassoc_connective, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1874 "tptp.grammar.cc"
    break;

  case 121:
#line 868 "tptp.yy"
    { yylhs.value.as < node > () = N(nonassoc_connective, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1880 "tptp.grammar.cc"
    break;

  case 122:
#line 869 "tptp.yy"
    { yylhs.value.as < node > () = N(nonassoc_connective, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1886 "tptp.grammar.cc"
    break;

  case 123:
#line 870 "tptp.yy"
    { yylhs.value.as < node > () = N(nonassoc_connective, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1892 "tptp.grammar.cc"
    break;

  case 124:
#line 871 "tptp.yy"
    { yylhs.value.as < node > () = N(nonassoc_connective, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1898 "tptp.grammar.cc"
    break;

  case 125:
#line 875 "tptp.yy"
    { yylhs.value.as < node > () = N(assoc_connective, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1904 "tptp.grammar.cc"
    break;

  case 126:
#line 876 "tptp.yy"
    { yylhs.value.as < node > () = N(assoc_connective, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1910 "tptp.grammar.cc"
    break;

  case 127:
#line 880 "tptp.yy"
    { yylhs.value.as < node > () = N(unary_connective, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1916 "tptp.grammar.cc"
    break;

  case 128:
#line 919 "tptp.yy"
    { yylhs.value.as < node > () = N(atom, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1922 "tptp.grammar.cc"
    break;

  case 129:
#line 920 "tptp.yy"
    { yylhs.value.as < node > () = N(atom, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1928 "tptp.grammar.cc"
    break;

  case 130:
#line 924 "tptp.yy"
    { yylhs.value.as < node > () = N(untyped_atom, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1934 "tptp.grammar.cc"
    break;

  case 131:
#line 925 "tptp.yy"
    { yylhs.value.as < node > () = N(untyped_atom, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1940 "tptp.grammar.cc"
    break;

  case 132:
#line 947 "tptp.yy"
    { yylhs.value.as < node > () = N(constant, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1946 "tptp.grammar.cc"
    break;

  case 133:
#line 951 "tptp.yy"
    { yylhs.value.as < node > () = N(functor, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1952 "tptp.grammar.cc"
    break;

  case 134:
#line 955 "tptp.yy"
    { yylhs.value.as < node > () = N(system_constant, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1958 "tptp.grammar.cc"
    break;

  case 135:
#line 959 "tptp.yy"
    { yylhs.value.as < node > () = N(system_functor, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1964 "tptp.grammar.cc"
    break;

  case 136:
#line 963 "tptp.yy"
    { yylhs.value.as < node > () = N(defined_constant, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1970 "tptp.grammar.cc"
    break;

  case 137:
#line 967 "tptp.yy"
    { yylhs.value.as < node > () = N(defined_functor, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1976 "tptp.grammar.cc"
    break;

  case 138:
#line 971 "tptp.yy"
    { yylhs.value.as < node > () = N(defined_term, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1982 "tptp.grammar.cc"
    break;

  case 139:
#line 972 "tptp.yy"
    { yylhs.value.as < node > () = N(defined_term, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 1988 "tptp.grammar.cc"
    break;

  case 140:
#line 976 "tptp.yy"
    { yylhs.value.as < node > () = N(variable, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 1994 "tptp.grammar.cc"
    break;

  case 141:
#line 1018 "tptp.yy"
    { yylhs.value.as < node > () = N(YY_MOVE (yystack_[0].value.as < node > ())); }
#line 2000 "tptp.grammar.cc"
    break;

  case 142:
#line 1077 "tptp.yy"
    { yylhs.value.as < node > () = N(optional_info, YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 2006 "tptp.grammar.cc"
    break;

  case 143:
#line 1081 "tptp.yy"
    { yylhs.value.as < node > () = N(useful_info, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 2012 "tptp.grammar.cc"
    break;

  case 144:
#line 1085 "tptp.yy"
    { yylhs.value.as < node > () = N(include, YY_MOVE (yystack_[3].value.as < std::string > ()), YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < node > ()), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 2018 "tptp.grammar.cc"
    break;

  case 145:
#line 1089 "tptp.yy"
    { yylhs.value.as < node > () = N(formula_selection, YY_MOVE (yystack_[3].value.as < std::string > ()), YY_MOVE (yystack_[2].value.as < std::string > ()), YY_MOVE (yystack_[1].value.as < node > ()), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 2024 "tptp.grammar.cc"
    break;

  case 146:
#line 1090 "tptp.yy"
    {}
#line 2030 "tptp.grammar.cc"
    break;

  case 147:
#line 1094 "tptp.yy"
    { yylhs.value.as < node > () = N(name_list, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 2036 "tptp.grammar.cc"
    break;

  case 148:
#line 1095 "tptp.yy"
    { yylhs.value.as < node > () = N(name_list, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 2042 "tptp.grammar.cc"
    break;

  case 149:
#line 1114 "tptp.yy"
    { yylhs.value.as < node > () = N(general_term, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 2048 "tptp.grammar.cc"
    break;

  case 150:
#line 1115 "tptp.yy"
    { yylhs.value.as < node > () = N(general_term, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 2054 "tptp.grammar.cc"
    break;

  case 151:
#line 1116 "tptp.yy"
    { yylhs.value.as < node > () = N(general_term, YY_MOVE (yystack_[2].value.as < node > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < node > ())); }
#line 2060 "tptp.grammar.cc"
    break;

  case 152:
#line 1120 "tptp.yy"
    { yylhs.value.as < node > () = N(general_function, YY_MOVE (yystack_[3].value.as < node > ()), YY_MOVE (yystack_[2].value.as < std::string > ()), YY_MOVE (yystack_[1].value.as < node > ()), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 2066 "tptp.grammar.cc"
    break;

  case 153:
#line 1123 "tptp.yy"
    { yylhs.value.as < node > () = N(general_data, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 2072 "tptp.grammar.cc"
    break;

  case 154:
#line 1124 "tptp.yy"
    { yylhs.value.as < node > () = N(general_data, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 2078 "tptp.grammar.cc"
    break;

  case 155:
#line 1125 "tptp.yy"
    { yylhs.value.as < node > () = N(general_data, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 2084 "tptp.grammar.cc"
    break;

  case 156:
#line 1126 "tptp.yy"
    { yylhs.value.as < node > () = N(general_data, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 2090 "tptp.grammar.cc"
    break;

  case 157:
#line 1127 "tptp.yy"
    { yylhs.value.as < node > () = N(general_data, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 2096 "tptp.grammar.cc"
    break;

  case 158:
#line 1128 "tptp.yy"
    { yylhs.value.as < node > () = N(general_data, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 2102 "tptp.grammar.cc"
    break;

  case 159:
#line 1132 "tptp.yy"
    { yylhs.value.as < node > () = N(formula_data, YY_MOVE (yystack_[3].value.as < std::string > ()), YY_MOVE (yystack_[2].value.as < std::string > ()), YY_MOVE (yystack_[1].value.as < node > ()), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 2108 "tptp.grammar.cc"
    break;

  case 160:
#line 1140 "tptp.yy"
    { yylhs.value.as < node > () = N(general_list, YY_MOVE (yystack_[1].value.as < std::string > ()), N(), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 2114 "tptp.grammar.cc"
    break;

  case 161:
#line 1141 "tptp.yy"
    { yylhs.value.as < node > () = N(general_list, YY_MOVE (yystack_[2].value.as < std::string > ()), YY_MOVE (yystack_[1].value.as < node > ()), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 2120 "tptp.grammar.cc"
    break;

  case 162:
#line 1145 "tptp.yy"
    { yylhs.value.as < node > () = std::move(YY_MOVE (yystack_[0].value.as < node > ()).add_left(YY_MOVE (yystack_[2].value.as < node > ()))); }
#line 2126 "tptp.grammar.cc"
    break;

  case 163:
#line 1146 "tptp.yy"
    { yylhs.value.as < node > () = N(general_terms, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 2132 "tptp.grammar.cc"
    break;

  case 164:
#line 1154 "tptp.yy"
    { yylhs.value.as < node > () = N(name, YY_MOVE (yystack_[0].value.as < node > ()));}
#line 2138 "tptp.grammar.cc"
    break;

  case 165:
#line 1155 "tptp.yy"
    { yylhs.value.as < node > () = N(name, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 2144 "tptp.grammar.cc"
    break;

  case 166:
#line 1159 "tptp.yy"
    { yylhs.value.as < node > () = N(atomic_word, YY_MOVE (yystack_[0].value.as < std::string > ()));}
#line 2150 "tptp.grammar.cc"
    break;

  case 167:
#line 1160 "tptp.yy"
    { yylhs.value.as < node > () = N(atomic_word, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 2156 "tptp.grammar.cc"
    break;

  case 168:
#line 1192 "tptp.yy"
    { yylhs.value.as < node > () = N(atomic_defined_word, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 2162 "tptp.grammar.cc"
    break;

  case 169:
#line 1196 "tptp.yy"
    { yylhs.value.as < node > () = N(atomic_system_word, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 2168 "tptp.grammar.cc"
    break;

  case 170:
#line 1200 "tptp.yy"
    { yylhs.value.as < node > () = N(number, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 2174 "tptp.grammar.cc"
    break;

  case 171:
#line 1201 "tptp.yy"
    { yylhs.value.as < node > () = N(number, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 2180 "tptp.grammar.cc"
    break;

  case 172:
#line 1202 "tptp.yy"
    { yylhs.value.as < node > () = N(number, YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 2186 "tptp.grammar.cc"
    break;

  case 173:
#line 1206 "tptp.yy"
    { yylhs.value.as < node > () = N(file_name, YY_MOVE (yystack_[0].value.as < node > ())); }
#line 2192 "tptp.grammar.cc"
    break;

  case 174:
#line 1246 "tptp.yy"
    { yylhs.value.as < node > () = N(single_quoted, YY_MOVE (yystack_[2].value.as < std::string > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 2198 "tptp.grammar.cc"
    break;

  case 175:
#line 1258 "tptp.yy"
    { yylhs.value.as < node > () = N(distinct_object, YY_MOVE (yystack_[2].value.as < std::string > ()), YY_MOVE (yystack_[1].value.as < std::string > ()), YY_MOVE (yystack_[0].value.as < std::string > ())); }
#line 2204 "tptp.grammar.cc"
    break;


#line 2208 "tptp.grammar.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -208;

  const short parser::yytable_ninf_ = -132;

  const short
  parser::yypact_[] =
  {
      16,    21,   -12,    27,  -208,    16,  -208,  -208,  -208,  -208,
    -208,    -6,    30,  -208,  -208,    31,  -208,  -208,  -208,    44,
      65,    52,   102,  -208,  -208,    69,    21,  -208,   380,    76,
      74,    83,    87,  -208,  -208,  -208,  -208,  -208,  -208,  -208,
    -208,  -208,  -208,  -208,  -208,  -208,  -208,  -208,  -208,  -208,
     380,   296,   672,    79,  -208,  -208,    93,  -208,   552,  -208,
     239,  -208,   422,  -208,  -208,  -208,  -208,  -208,  -208,  -208,
    -208,    91,  -208,    12,  -208,  -208,    80,    86,  -208,  -208,
     103,  -208,  -208,  -208,  -208,  -208,  -208,    14,    26,  -208,
      59,  -208,  -208,  -208,  -208,  -208,  -208,  -208,  -208,  -208,
    -208,  -208,    21,   422,     1,   107,   109,   113,   108,   422,
    -208,   112,  -208,   117,  -208,  -208,  -208,  -208,  -208,  -208,
    -208,  -208,  -208,  -208,  -208,   116,  -208,  -208,  -208,   114,
     214,   162,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   506,   506,   422,  -208,  -208,   422,  -208,    10,
     123,   506,   506,   506,   506,   506,   155,   422,    13,  -208,
     121,   100,   100,   122,  -208,  -208,  -208,  -208,  -208,  -208,
     422,  -208,  -208,  -208,   130,   164,  -208,   126,  -208,  -208,
     133,  -208,  -208,   141,  -208,  -208,  -208,     3,    89,   190,
      24,   658,   647,   631,   620,   604,   593,    29,   265,  -208,
     548,   548,  -208,  -208,   134,  -208,  -208,  -208,  -208,  -208,
     140,  -208,   142,   139,   153,   338,   157,  -208,   134,  -208,
    -208,  -208,  -208,  -208,   422,   160,   152,   464,  -208,   380,
    -208,   165,   167,   166,  -208,   214,   214,  -208,  -208,   170,
     155,   422,   422,   422,   174,  -208,     1,   296,   207,   187,
    -208,   193,   214,  -208,  -208,  -208,  -208,   197,  -208,  -208,
    -208,  -208,  -208,   422,  -208,     0,   202,   200,   422,   380,
    -208,  -208,  -208,   206,  -208,   464,  -208,   213,  -208,  -208,
    -208
  };

  const unsigned char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     2,     4,     5,     7,     6,   166,
     165,     0,     0,   164,   167,   146,   173,     1,     3,     0,
       0,     0,     0,   174,    11,     0,     0,   144,     0,     0,
     147,     0,     0,   140,   170,   171,   172,   127,   112,   105,
     117,   113,   106,   118,   107,   114,   108,   115,   109,   116,
       0,     0,     0,     0,   168,   169,    10,    12,    17,    49,
      30,    37,     0,    16,    72,    50,    51,    52,    56,    57,
      38,    54,    13,     0,    31,    90,    91,    92,    14,    15,
       0,   104,   103,    48,   111,   102,   110,     0,    53,   132,
      60,   134,    55,   136,    58,    73,   133,   137,   135,   138,
     139,   145,     0,     0,     0,     0,     0,     0,     0,     0,
      75,    78,    54,     0,    53,    60,   126,   125,   124,   123,
     120,   121,   119,   122,    81,     0,    82,    79,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    41,    32,    33,    38,
       0,     0,     0,     0,     0,     0,    44,     0,     0,   148,
       0,     0,     0,     0,    64,   130,   131,    74,    84,   101,
       0,    76,    59,   175,     0,     0,   155,     0,   141,   154,
     149,   158,   150,   153,   156,   157,     8,    19,    30,    22,
      23,    24,    25,    26,    27,    28,    29,    20,    21,    18,
       0,     0,   100,    88,    93,    94,    95,    97,    96,    98,
       0,    43,    46,     0,     0,    88,    89,    83,    85,    87,
      86,    99,   128,   129,     0,     0,    66,     0,    77,     0,
     160,   163,     0,     0,     9,     0,     0,    34,    35,     0,
       0,     0,     0,     0,     0,    63,     0,     0,     0,     0,
      68,     0,     0,   161,   142,   143,   151,     0,    42,    45,
      47,    40,    39,     0,    65,    78,     0,    70,     0,     0,
     159,   162,   152,     0,    67,     0,    71,     0,    61,    69,
      62
  };

  const short
  parser::yypgoto_[] =
  {
    -208,  -208,   253,  -208,  -208,  -208,  -208,  -208,  -207,   -42,
     582,   -55,  -208,   -49,  -208,  -208,  -208,  -208,    20,  -208,
      -3,  -208,  -208,  -208,  -208,  -208,  -208,    15,  -208,   -13,
    -208,    17,   -45,   -26,    97,  -208,   -46,    22,  -122,  -208,
    -208,  -141,  -208,  -208,  -208,   231,  -208,  -208,  -208,   233,
    -208,  -208,  -208,  -208,  -208,  -208,   -25,   -27,  -208,   -22,
    -208,   129,  -208,  -208,  -115,  -208,  -208,  -208,  -208,  -208,
     186,  -118,  -208,  -208,  -208,    56,  -197,   293,    -1,  -208,
    -208,  -125,  -208,   294,   -76
  };

  const short
  parser::yydefgoto_[] =
  {
      -1,     3,     4,     5,     6,     7,   131,    25,    56,    57,
      58,   214,    59,    60,   216,    61,    62,   210,   211,   212,
      63,    64,    65,    66,    67,    68,    69,   163,   225,   249,
     266,   250,    70,   112,   113,   125,    72,   217,    73,   219,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,   127,   128,    86,   221,   108,   114,    89,   115,
      91,    92,    93,    94,    95,   177,   234,   254,     8,    22,
      29,   231,   179,   180,   181,   182,   232,    30,    96,    97,
      98,    99,    15,    14,   100
  };

  const short
  parser::yytable_[] =
  {
      13,    88,    71,    87,   106,   184,    90,   146,   105,   111,
     205,   144,   178,   147,     9,   176,   220,   149,   268,     1,
       2,   132,   251,    88,    71,    13,     9,    17,    90,   204,
     206,   207,   208,   209,     9,   218,    10,   200,   201,   257,
      11,   213,   132,   133,   161,   143,   162,   132,    19,   170,
     184,   141,   142,    11,   185,   271,  -132,   145,   164,   148,
     176,   160,   277,    55,   157,    11,   143,   105,   151,   158,
     152,   143,   153,    11,    54,    55,  -130,   165,    24,    20,
      21,  -130,   166,   188,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   188,   144,    23,    26,   144,   185,
     220,    13,   203,   203,   203,   203,   203,    27,   215,  -131,
     184,   184,   149,     9,  -131,   106,   226,   256,    28,   218,
     176,   176,   101,   102,   202,   213,   103,   184,   111,   183,
     104,   165,   129,   222,   165,   165,   166,   176,   154,   166,
     166,   145,   130,   161,   145,   -88,   155,   -88,   156,   -88,
     150,   167,    11,   168,   148,   237,   238,   169,   157,   185,
     185,   170,    55,   171,   172,   173,   144,   186,    51,    33,
     224,   227,   174,   229,   183,   233,   185,     9,    33,    34,
      35,    36,   244,   235,   236,   248,   239,   261,   262,   241,
     151,   240,   215,   147,   147,   242,   149,   149,   149,   243,
     164,   246,    88,    71,    87,   265,   245,    90,   132,   175,
     230,   175,   145,   253,   252,    53,    11,   141,   142,   165,
     258,   273,   174,   263,   166,   268,   276,     9,    33,    34,
      35,    36,   143,   248,   183,   183,   269,   270,   148,   148,
     148,   272,    88,    71,    87,    31,    32,    90,   274,   275,
     278,   183,     9,    33,    34,    35,    36,   280,    18,   175,
     259,   264,   279,   260,   267,    53,    11,   228,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,   107,   109,   132,    51,   126,    52,   223,   159,   255,
      53,    11,   141,  -132,    12,   -88,    16,   -88,     0,   -88,
      54,    55,    31,    32,     0,     0,     0,   143,     0,     9,
      33,    34,    35,    36,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,     0,   109,
       0,    51,   110,    52,    31,    32,     0,    53,    11,     0,
       0,     9,    33,    34,    35,    36,     0,    54,    55,     0,
       0,     0,     0,     0,     0,     0,     0,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
     -32,   109,     0,    51,     0,    52,    31,    32,     0,    53,
      11,     0,     0,     9,    33,    34,    35,    36,     0,    54,
      55,     0,     0,     0,     0,     0,     0,     0,     0,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,     0,    50,     0,    51,     0,    52,    31,    32,
       0,    53,    11,     0,     0,     9,    33,    34,    35,    36,
       0,    54,    55,     0,     0,     0,     0,     0,     0,     0,
       0,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,     0,   109,     0,    51,     0,    52,
      31,    32,     0,    53,    11,     0,     0,     9,    33,    34,
      35,    36,     0,    54,    55,     0,     0,     0,     0,     0,
       0,     0,     0,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,     0,   109,     0,   247,
       0,    52,    31,    32,     0,    53,    11,     0,     0,     9,
      33,    34,    35,    36,     0,    54,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    39,    40,     0,
      42,    43,    44,     0,    46,     0,    48,     0,     0,   109,
       0,    51,     0,    52,    31,    32,     0,    53,    11,     0,
       0,     9,    33,    34,    35,    36,     0,    54,    55,     0,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,     0,    51,   143,    52,     0,     0,     0,    53,
      11,     0,     0,     0,     0,     0,     0,     0,     0,    54,
      55,   132,   133,   134,   135,   136,   137,   138,   139,  -132,
     141,   142,   132,   133,   134,   135,   136,   137,   138,  -132,
       0,   141,   142,     0,     0,   143,     0,     0,   132,   133,
     134,   135,   136,   137,  -132,     0,   143,   141,   142,   132,
     133,   134,   135,   136,  -132,     0,     0,     0,   141,   142,
       0,     0,   143,     0,     0,   132,   133,   134,   135,  -132,
       0,     0,     0,   143,   141,   142,   132,   133,   134,  -132,
       0,     0,     0,     0,     0,   141,   142,     0,     0,   143,
       0,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     143,    37,    38,     0,     0,    41,     0,     0,     0,    45,
       0,    47,     0,    49,   187,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199
  };

  const short
  parser::yycheck_[] =
  {
       1,    28,    28,    28,    50,   130,    28,    62,    50,    51,
     151,    60,   130,    62,    13,   130,   157,    62,    18,     3,
       4,    18,   229,    50,    50,    26,    13,     0,    50,   151,
     152,   153,   154,   155,    13,   157,    15,    27,    28,   236,
      52,   156,    18,    19,    43,    42,    45,    18,    54,    49,
     175,    27,    28,    52,   130,   252,    27,    60,   104,    62,
     175,   103,   269,    62,    50,    52,    42,   109,    56,    55,
      58,    42,    60,    52,    61,    62,    50,   104,    13,    49,
      49,    55,   104,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,    52,    45,   147,   175,
     241,   102,   151,   152,   153,   154,   155,     5,   157,    50,
     235,   236,   157,    13,    55,   161,   162,   235,    49,   241,
     235,   236,    46,    49,   150,   240,    43,   252,   170,   130,
      43,   158,    53,   158,   161,   162,   158,   252,    58,   161,
     162,   144,    49,    43,   147,    56,    60,    58,    45,    60,
      59,    44,    52,    44,   157,   200,   201,    44,    50,   235,
     236,    49,    62,    46,    48,    51,   215,     5,    45,    14,
      49,    49,     8,    43,   175,    49,   252,    13,    14,    15,
      16,    17,   224,    50,    43,   227,    46,   242,   243,    50,
      56,    49,   241,   242,   243,    42,   241,   242,   243,    42,
     246,    49,   229,   229,   229,   247,    46,   229,    18,    45,
      46,    45,   215,    46,    49,    51,    52,    27,    28,   246,
      50,   263,     8,    49,   246,    18,   268,    13,    14,    15,
      16,    17,    42,   275,   235,   236,    49,    44,   241,   242,
     243,    44,   269,   269,   269,     6,     7,   269,    46,    49,
      44,   252,    13,    14,    15,    16,    17,    44,     5,    45,
     240,   246,   275,   241,   247,    51,    52,   170,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    50,    43,    18,    45,    52,    47,   158,   102,   233,
      51,    52,    27,    28,     1,    56,     2,    58,    -1,    60,
      61,    62,     6,     7,    -1,    -1,    -1,    42,    -1,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    43,
      -1,    45,    46,    47,     6,     7,    -1,    51,    52,    -1,
      -1,    13,    14,    15,    16,    17,    -1,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    45,    -1,    47,     6,     7,    -1,    51,
      52,    -1,    -1,    13,    14,    15,    16,    17,    -1,    61,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    43,    -1,    45,    -1,    47,     6,     7,
      -1,    51,    52,    -1,    -1,    13,    14,    15,    16,    17,
      -1,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    -1,    43,    -1,    45,    -1,    47,
       6,     7,    -1,    51,    52,    -1,    -1,    13,    14,    15,
      16,    17,    -1,    61,    62,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    -1,    45,
      -1,    47,     6,     7,    -1,    51,    52,    -1,    -1,    13,
      14,    15,    16,    17,    -1,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      34,    35,    36,    -1,    38,    -1,    40,    -1,    -1,    43,
      -1,    45,    -1,    47,     6,     7,    -1,    51,    52,    -1,
      -1,    13,    14,    15,    16,    17,    -1,    61,    62,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    -1,    45,    42,    47,    -1,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,
      62,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    -1,    -1,    42,    -1,    -1,    18,    19,
      20,    21,    22,    23,    24,    -1,    42,    27,    28,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    27,    28,
      -1,    -1,    42,    -1,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    42,    27,    28,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    42,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      42,    29,    30,    -1,    -1,    33,    -1,    -1,    -1,    37,
      -1,    39,    -1,    41,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     4,    64,    65,    66,    67,    68,   131,    13,
      15,    52,   140,   141,   146,   145,   146,     0,    65,    54,
      49,    49,   132,    52,    13,    70,    45,     5,    49,   133,
     140,     6,     7,    14,    15,    16,    17,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      43,    45,    47,    51,    61,    62,    71,    72,    73,    75,
      76,    78,    79,    83,    84,    85,    86,    87,    88,    89,
      95,    96,    99,   101,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   117,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   141,   142,   143,   144,
     147,    46,    49,    43,    43,    72,    99,   108,   119,    43,
      46,    72,    96,    97,   120,   122,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    98,   112,   115,   116,    53,
      49,    69,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    42,    76,    83,    74,    76,    83,    95,
      59,    56,    58,    60,    58,    60,    45,    50,    55,   133,
      72,    43,    45,    90,    99,   120,   122,    44,    44,    44,
      49,    46,    48,    51,     8,    45,   127,   128,   134,   135,
     136,   137,   138,   141,   144,   147,     5,    73,    76,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      27,    28,    96,    76,   101,   104,   101,   101,   101,   101,
      80,    81,    82,   127,    74,    76,    77,   100,   101,   102,
     104,   118,   119,   124,    49,    91,    99,    49,    97,    43,
      46,   134,   139,    49,   129,    50,    43,    95,    95,    46,
      49,    50,    42,    42,    72,    46,    49,    45,    72,    92,
      94,    71,    49,    46,   130,   138,   134,   139,    50,    81,
     100,    74,    74,    49,    90,    72,    93,    94,    18,    49,
      44,   139,    44,    72,    46,    49,    72,    71,    44,    92,
      44
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    63,    64,    65,    65,    66,    66,    67,    68,    69,
      69,    70,    71,    71,    71,    71,    72,    72,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    74,    74,    74,    74,    75,    76,    76,    77,
      77,    78,    79,    80,    80,    81,    81,    82,    83,    83,
      84,    84,    84,    85,    85,    86,    86,    86,    86,    86,
      87,    88,    89,    90,    90,    91,    91,    92,    92,    93,
      93,    94,    95,    95,    95,    96,    96,    97,    97,    98,
      98,    98,    98,    99,    99,   100,   100,   100,   101,   102,
     103,   103,   103,   104,   104,   105,   105,   106,   106,   107,
     108,   108,   109,   109,   109,   110,   110,   111,   111,   111,
     112,   112,   113,   113,   113,   113,   113,   114,   114,   115,
     115,   115,   115,   115,   115,   116,   116,   117,   118,   118,
     119,   119,   120,   121,   122,   123,   124,   125,   126,   126,
     127,   128,   129,   130,   131,   132,   132,   133,   133,   134,
     134,   134,   135,   136,   136,   136,   136,   136,   136,   137,
     138,   138,   139,   139,   140,   140,   141,   141,   142,   143,
     144,   144,   144,   145,   146,   147
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     1,     8,     3,
       0,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     3,     3,     2,     1,     1,     3,
       3,     2,     5,     1,     0,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     8,     8,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     3,     2,     3,     3,     1,     1,
       1,     1,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     4,     4,     0,     1,     3,     1,
       1,     3,     4,     1,     1,     1,     1,     1,     1,     4,
       2,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "END_OF_FILE", "error", "$undefined", "DefinitionTHF",
  "DefinitionInclude", "DefinitionEnd", "Dollar_ite", "Dollar_let",
  "Dollar_thf", "Dollar_tff", "Dollar_fof", "Dollar_cnf", "Dollar_fot",
  "Lower_word", "Upper_word", "Integer", "Rational", "Real", "Assignment",
  "And", "Or", "Nand", "Nor", "Impl", "If", "Iff", "Niff",
  "Infix_equality", "Infix_inequality", "Not", "ForallComb", "TyForall",
  "Forall", "ExistsComb", "TyExists", "Exists", "Lambda", "ChoiceComb",
  "Choice", "DescriptionComb", "Description", "EqComb", "App", "LParen",
  "RParen", "LBrkt", "RBrkt", "LCurly", "RCurly", "Comma", "Colon",
  "Double_quote", "Single_quote", "Do_string", "Sq_string", "Subtype_sign",
  "Arrow", "Less_sign", "Star", "Gentzen_arrow", "Plus", "Dollar_word",
  "Dollar_dollar_word", "$accept", "root", "TPTP_file", "TPTP_input",
  "annotated_formula", "thf_annotated", "annotations", "formula_role",
  "thf_formula", "thf_logic_formula", "thf_binary_formula",
  "thf_unit_formula", "thf_preunit_formula", "thf_unitary_formula",
  "thf_apply_formula", "thf_quantified_formula", "thf_quantification",
  "thf_variable_list", "thf_variable_list__HELPER0", "thf_typed_variable",
  "thf_prefix_unary", "thf_atomic_formula", "thf_plain_atomic",
  "thf_defined_atomic", "thf_system_atomic", "thf_conditional", "thf_let",
  "thf_let_types", "thf_let_types_list", "thf_let_defns",
  "thf_let_defns_list", "thf_let_defn", "thf_unitary_term", "thf_tuple",
  "thf_formula_list", "thf_conn_term", "thf_atom_typing",
  "thf_top_level_type", "thf_unitary_type", "thf_apply_type",
  "thf_binary_type", "thf_mapping_type", "thf_xprod_type",
  "thf_union_type", "thf_subtype", "thf_sequent", "thf_quantifier",
  "th1_quantifier", "th0_quantifier", "thf_unary_connective",
  "th1_unary_connective", "fof_quantifier", "nonassoc_connective",
  "assoc_connective", "unary_connective", "atom", "untyped_atom",
  "constant", "functor", "system_constant", "system_functor",
  "defined_constant", "defined_functor", "defined_term", "variable",
  "source", "optional_info", "useful_info", "include", "formula_selection",
  "name_list", "general_term", "general_function", "general_data",
  "formula_data", "general_list", "general_terms", "name", "atomic_word",
  "atomic_defined_word", "atomic_system_word", "number", "file_name",
  "single_quoted", "distinct_object", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short
  parser::yyrline_[] =
  {
       0,   148,   148,   174,   175,   178,   179,   183,   192,   196,
     197,   214,   264,   265,   266,   267,   278,   282,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   316,   324,   325,   326,   330,   334,   337,   344,
     345,   373,   377,   383,   384,   387,   388,   392,   402,   403,
     412,   413,   414,   419,   420,   424,   425,   426,   427,   428,
     437,   462,   466,   470,   471,   475,   476,   480,   481,   485,
     486,   490,   494,   495,   496,   500,   501,   504,   505,   509,
     510,   511,   512,   537,   538,   542,   543,   544,   548,   570,
     574,   575,   576,   580,   581,   585,   586,   590,   591,   595,
     599,   600,   831,   832,   833,   837,   838,   842,   843,   844,
     848,   849,   853,   854,   855,   856,   857,   861,   862,   866,
     867,   868,   869,   870,   871,   875,   876,   880,   919,   920,
     924,   925,   947,   951,   955,   959,   963,   967,   971,   972,
     976,  1018,  1077,  1081,  1085,  1089,  1090,  1094,  1095,  1114,
    1115,  1116,  1120,  1123,  1124,  1125,  1126,  1127,  1128,  1132,
    1140,  1141,  1145,  1146,  1154,  1155,  1159,  1160,  1192,  1196,
    1200,  1201,  1202,  1206,  1246,  1258
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2914 "tptp.grammar.cc"

#line 1316 "tptp.yy"


void
yy::parser::error (const location_type& l, const std::string& m)
{
    std::cerr << l << ": " << m << '\n';
}
