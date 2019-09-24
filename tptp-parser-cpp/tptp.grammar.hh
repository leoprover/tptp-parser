// A Bison parser, made by GNU Bison 3.4.1.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file tptp.grammar.hh
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.

#ifndef YY_YY_TPTP_GRAMMAR_HH_INCLUDED
# define YY_YY_TPTP_GRAMMAR_HH_INCLUDED
// //                    "%code requires" blocks.
#line 8 "tptp.yy"

    // This is a parser-grammar file for TPTP language Version 7.2.0.1 using the flex/bison 
    // parser generator.
    // The BNF specification of the TPTP language was provided by Geoff Sutcliffe.
    // The grammar file is created by Marco Träger, inspired by the ANTLR grammer
    // (https://github.com/leoprover/Leo-III/blob/master/contrib/tptp.g4) written by 
    // Alexander Steen and Tobias Gleißner.
    // Date: Aug 2019
    // Last updated: Sep 2019

    #include <string>
    #include "tptp.ast.hh"

    using namespace tptp::ast;
    namespace tptp {
        class parser;
    }

#line 67 "tptp.grammar.hh"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"

#ifndef YYASSERT
# include <cassert>
# define YYASSERT assert
#endif


#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace yy {
#line 182 "tptp.grammar.hh"




  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
    {
      YYASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
    /// Prohibit blind copies.
    self_type& operator= (const self_type&);
    semantic_type (const self_type&);

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // root
      // TPTP_file
      // TPTP_input
      // annotated_formula
      // thf_annotated
      // annotations
      // formula_role
      // thf_formula
      // thf_logic_formula
      // thf_binary_formula
      // thf_unit_formula
      // thf_preunit_formula
      // thf_unitary_formula
      // thf_apply_formula
      // thf_quantified_formula
      // thf_quantification
      // thf_variable_list
      // thf_variable_list__HELPER0
      // thf_typed_variable
      // thf_prefix_unary
      // thf_atomic_formula
      // thf_plain_atomic
      // thf_defined_atomic
      // thf_system_atomic
      // thf_conditional
      // thf_let
      // thf_let_types
      // thf_let_types_list
      // thf_let_defns
      // thf_let_defns_list
      // thf_let_defn
      // thf_unitary_term
      // thf_tuple
      // thf_formula_list
      // thf_conn_term
      // thf_atom_typing
      // thf_top_level_type
      // thf_unitary_type
      // thf_apply_type
      // thf_binary_type
      // thf_mapping_type
      // thf_xprod_type
      // thf_union_type
      // thf_subtype
      // thf_sequent
      // thf_quantifier
      // th1_quantifier
      // th0_quantifier
      // thf_unary_connective
      // th1_unary_connective
      // fof_quantifier
      // nonassoc_connective
      // assoc_connective
      // unary_connective
      // atom
      // untyped_atom
      // constant
      // functor
      // system_constant
      // system_functor
      // defined_constant
      // defined_functor
      // defined_term
      // variable
      // source
      // optional_info
      // useful_info
      // include
      // formula_selection
      // name_list
      // general_term
      // general_function
      // general_data
      // formula_data
      // general_list
      // general_terms
      // name
      // atomic_word
      // atomic_defined_word
      // atomic_system_word
      // number
      // file_name
      // single_quoted
      // distinct_object
      char dummy1[sizeof (node)];

      // DefinitionTHF
      // DefinitionInclude
      // DefinitionEnd
      // Dollar_ite
      // Dollar_let
      // Dollar_thf
      // Dollar_tff
      // Dollar_fof
      // Dollar_cnf
      // Dollar_fot
      // Lower_word
      // Upper_word
      // Integer
      // Rational
      // Real
      // Assignment
      // And
      // Or
      // Nand
      // Nor
      // Impl
      // If
      // Iff
      // Niff
      // Infix_equality
      // Infix_inequality
      // Not
      // ForallComb
      // TyForall
      // Forall
      // ExistsComb
      // TyExists
      // Exists
      // Lambda
      // ChoiceComb
      // Choice
      // DescriptionComb
      // Description
      // EqComb
      // App
      // LParen
      // RParen
      // LBrkt
      // RBrkt
      // LCurly
      // RCurly
      // Comma
      // Colon
      // Double_quote
      // Single_quote
      // Do_string
      // Sq_string
      // Subtype_sign
      // Arrow
      // Less_sign
      // Star
      // Gentzen_arrow
      // Plus
      // Dollar_word
      // Dollar_dollar_word
      char dummy2[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        END_OF_FILE = 0,
        DefinitionTHF = 258,
        DefinitionInclude = 259,
        DefinitionEnd = 260,
        Dollar_ite = 261,
        Dollar_let = 262,
        Dollar_thf = 263,
        Dollar_tff = 264,
        Dollar_fof = 265,
        Dollar_cnf = 266,
        Dollar_fot = 267,
        Lower_word = 268,
        Upper_word = 269,
        Integer = 270,
        Rational = 271,
        Real = 272,
        Assignment = 273,
        And = 274,
        Or = 275,
        Nand = 276,
        Nor = 277,
        Impl = 278,
        If = 279,
        Iff = 280,
        Niff = 281,
        Infix_equality = 282,
        Infix_inequality = 283,
        Not = 284,
        ForallComb = 285,
        TyForall = 286,
        Forall = 287,
        ExistsComb = 288,
        TyExists = 289,
        Exists = 290,
        Lambda = 291,
        ChoiceComb = 292,
        Choice = 293,
        DescriptionComb = 294,
        Description = 295,
        EqComb = 296,
        App = 297,
        LParen = 298,
        RParen = 299,
        LBrkt = 300,
        RBrkt = 301,
        LCurly = 302,
        RCurly = 303,
        Comma = 304,
        Colon = 305,
        Double_quote = 306,
        Single_quote = 307,
        Do_string = 308,
        Sq_string = 309,
        Subtype_sign = 310,
        Arrow = 311,
        Less_sign = 312,
        Star = 313,
        Gentzen_arrow = 314,
        Plus = 315,
        Dollar_word = 316,
        Dollar_dollar_word = 317
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned char token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that);
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, node&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const node& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_number_type yytype = this->type_get ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yytype)
        {
       default:
          break;
        }

        // Type destructor.
switch (yytype)
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
        value.template destroy< node > ();
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
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_type (by_type&& that);
#endif

      /// Copy constructor.
      by_type (const by_type& that);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The token.
      token_type token () const YY_NOEXCEPT;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_type>
    {
      /// Superclass.
      typedef basic_symbol<by_type> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
      {
        YYASSERT (tok == token::END_OF_FILE);
      }
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
      {
        YYASSERT (tok == token::END_OF_FILE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
      {
        YYASSERT (tok == token::DefinitionTHF || tok == token::DefinitionInclude || tok == token::DefinitionEnd || tok == token::Dollar_ite || tok == token::Dollar_let || tok == token::Dollar_thf || tok == token::Dollar_tff || tok == token::Dollar_fof || tok == token::Dollar_cnf || tok == token::Dollar_fot || tok == token::Lower_word || tok == token::Upper_word || tok == token::Integer || tok == token::Rational || tok == token::Real || tok == token::Assignment || tok == token::And || tok == token::Or || tok == token::Nand || tok == token::Nor || tok == token::Impl || tok == token::If || tok == token::Iff || tok == token::Niff || tok == token::Infix_equality || tok == token::Infix_inequality || tok == token::Not || tok == token::ForallComb || tok == token::TyForall || tok == token::Forall || tok == token::ExistsComb || tok == token::TyExists || tok == token::Exists || tok == token::Lambda || tok == token::ChoiceComb || tok == token::Choice || tok == token::DescriptionComb || tok == token::Description || tok == token::EqComb || tok == token::App || tok == token::LParen || tok == token::RParen || tok == token::LBrkt || tok == token::RBrkt || tok == token::LCurly || tok == token::RCurly || tok == token::Comma || tok == token::Colon || tok == token::Double_quote || tok == token::Single_quote || tok == token::Do_string || tok == token::Sq_string || tok == token::Subtype_sign || tok == token::Arrow || tok == token::Less_sign || tok == token::Star || tok == token::Gentzen_arrow || tok == token::Plus || tok == token::Dollar_word || tok == token::Dollar_dollar_word);
      }
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
      {
        YYASSERT (tok == token::DefinitionTHF || tok == token::DefinitionInclude || tok == token::DefinitionEnd || tok == token::Dollar_ite || tok == token::Dollar_let || tok == token::Dollar_thf || tok == token::Dollar_tff || tok == token::Dollar_fof || tok == token::Dollar_cnf || tok == token::Dollar_fot || tok == token::Lower_word || tok == token::Upper_word || tok == token::Integer || tok == token::Rational || tok == token::Real || tok == token::Assignment || tok == token::And || tok == token::Or || tok == token::Nand || tok == token::Nor || tok == token::Impl || tok == token::If || tok == token::Iff || tok == token::Niff || tok == token::Infix_equality || tok == token::Infix_inequality || tok == token::Not || tok == token::ForallComb || tok == token::TyForall || tok == token::Forall || tok == token::ExistsComb || tok == token::TyExists || tok == token::Exists || tok == token::Lambda || tok == token::ChoiceComb || tok == token::Choice || tok == token::DescriptionComb || tok == token::Description || tok == token::EqComb || tok == token::App || tok == token::LParen || tok == token::RParen || tok == token::LBrkt || tok == token::RBrkt || tok == token::LCurly || tok == token::RCurly || tok == token::Comma || tok == token::Colon || tok == token::Double_quote || tok == token::Single_quote || tok == token::Do_string || tok == token::Sq_string || tok == token::Subtype_sign || tok == token::Arrow || tok == token::Less_sign || tok == token::Star || tok == token::Gentzen_arrow || tok == token::Plus || tok == token::Dollar_word || tok == token::Dollar_dollar_word);
      }
#endif
    };

    /// Build a parser object.
    parser (tptp::parser& drv_yyarg);
    virtual ~parser ();

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END_OF_FILE (location_type l)
      {
        return symbol_type (token::END_OF_FILE, std::move (l));
      }
#else
      static
      symbol_type
      make_END_OF_FILE (const location_type& l)
      {
        return symbol_type (token::END_OF_FILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DefinitionTHF (std::string v, location_type l)
      {
        return symbol_type (token::DefinitionTHF, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DefinitionTHF (const std::string& v, const location_type& l)
      {
        return symbol_type (token::DefinitionTHF, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DefinitionInclude (std::string v, location_type l)
      {
        return symbol_type (token::DefinitionInclude, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DefinitionInclude (const std::string& v, const location_type& l)
      {
        return symbol_type (token::DefinitionInclude, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DefinitionEnd (std::string v, location_type l)
      {
        return symbol_type (token::DefinitionEnd, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DefinitionEnd (const std::string& v, const location_type& l)
      {
        return symbol_type (token::DefinitionEnd, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Dollar_ite (std::string v, location_type l)
      {
        return symbol_type (token::Dollar_ite, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Dollar_ite (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Dollar_ite, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Dollar_let (std::string v, location_type l)
      {
        return symbol_type (token::Dollar_let, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Dollar_let (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Dollar_let, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Dollar_thf (std::string v, location_type l)
      {
        return symbol_type (token::Dollar_thf, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Dollar_thf (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Dollar_thf, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Dollar_tff (std::string v, location_type l)
      {
        return symbol_type (token::Dollar_tff, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Dollar_tff (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Dollar_tff, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Dollar_fof (std::string v, location_type l)
      {
        return symbol_type (token::Dollar_fof, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Dollar_fof (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Dollar_fof, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Dollar_cnf (std::string v, location_type l)
      {
        return symbol_type (token::Dollar_cnf, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Dollar_cnf (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Dollar_cnf, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Dollar_fot (std::string v, location_type l)
      {
        return symbol_type (token::Dollar_fot, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Dollar_fot (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Dollar_fot, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Lower_word (std::string v, location_type l)
      {
        return symbol_type (token::Lower_word, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Lower_word (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Lower_word, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Upper_word (std::string v, location_type l)
      {
        return symbol_type (token::Upper_word, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Upper_word (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Upper_word, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Integer (std::string v, location_type l)
      {
        return symbol_type (token::Integer, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Integer (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Integer, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Rational (std::string v, location_type l)
      {
        return symbol_type (token::Rational, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Rational (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Rational, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Real (std::string v, location_type l)
      {
        return symbol_type (token::Real, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Real (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Real, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Assignment (std::string v, location_type l)
      {
        return symbol_type (token::Assignment, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Assignment (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Assignment, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_And (std::string v, location_type l)
      {
        return symbol_type (token::And, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_And (const std::string& v, const location_type& l)
      {
        return symbol_type (token::And, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Or (std::string v, location_type l)
      {
        return symbol_type (token::Or, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Or (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Or, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Nand (std::string v, location_type l)
      {
        return symbol_type (token::Nand, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Nand (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Nand, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Nor (std::string v, location_type l)
      {
        return symbol_type (token::Nor, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Nor (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Nor, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Impl (std::string v, location_type l)
      {
        return symbol_type (token::Impl, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Impl (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Impl, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_If (std::string v, location_type l)
      {
        return symbol_type (token::If, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_If (const std::string& v, const location_type& l)
      {
        return symbol_type (token::If, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Iff (std::string v, location_type l)
      {
        return symbol_type (token::Iff, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Iff (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Iff, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Niff (std::string v, location_type l)
      {
        return symbol_type (token::Niff, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Niff (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Niff, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Infix_equality (std::string v, location_type l)
      {
        return symbol_type (token::Infix_equality, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Infix_equality (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Infix_equality, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Infix_inequality (std::string v, location_type l)
      {
        return symbol_type (token::Infix_inequality, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Infix_inequality (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Infix_inequality, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Not (std::string v, location_type l)
      {
        return symbol_type (token::Not, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Not (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Not, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ForallComb (std::string v, location_type l)
      {
        return symbol_type (token::ForallComb, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ForallComb (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ForallComb, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TyForall (std::string v, location_type l)
      {
        return symbol_type (token::TyForall, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TyForall (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TyForall, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Forall (std::string v, location_type l)
      {
        return symbol_type (token::Forall, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Forall (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Forall, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ExistsComb (std::string v, location_type l)
      {
        return symbol_type (token::ExistsComb, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ExistsComb (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ExistsComb, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TyExists (std::string v, location_type l)
      {
        return symbol_type (token::TyExists, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_TyExists (const std::string& v, const location_type& l)
      {
        return symbol_type (token::TyExists, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Exists (std::string v, location_type l)
      {
        return symbol_type (token::Exists, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Exists (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Exists, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Lambda (std::string v, location_type l)
      {
        return symbol_type (token::Lambda, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Lambda (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Lambda, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ChoiceComb (std::string v, location_type l)
      {
        return symbol_type (token::ChoiceComb, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ChoiceComb (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ChoiceComb, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Choice (std::string v, location_type l)
      {
        return symbol_type (token::Choice, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Choice (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Choice, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DescriptionComb (std::string v, location_type l)
      {
        return symbol_type (token::DescriptionComb, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DescriptionComb (const std::string& v, const location_type& l)
      {
        return symbol_type (token::DescriptionComb, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Description (std::string v, location_type l)
      {
        return symbol_type (token::Description, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Description (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Description, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EqComb (std::string v, location_type l)
      {
        return symbol_type (token::EqComb, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EqComb (const std::string& v, const location_type& l)
      {
        return symbol_type (token::EqComb, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_App (std::string v, location_type l)
      {
        return symbol_type (token::App, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_App (const std::string& v, const location_type& l)
      {
        return symbol_type (token::App, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LParen (std::string v, location_type l)
      {
        return symbol_type (token::LParen, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LParen (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LParen, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RParen (std::string v, location_type l)
      {
        return symbol_type (token::RParen, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RParen (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RParen, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LBrkt (std::string v, location_type l)
      {
        return symbol_type (token::LBrkt, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LBrkt (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LBrkt, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RBrkt (std::string v, location_type l)
      {
        return symbol_type (token::RBrkt, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RBrkt (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RBrkt, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LCurly (std::string v, location_type l)
      {
        return symbol_type (token::LCurly, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_LCurly (const std::string& v, const location_type& l)
      {
        return symbol_type (token::LCurly, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RCurly (std::string v, location_type l)
      {
        return symbol_type (token::RCurly, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_RCurly (const std::string& v, const location_type& l)
      {
        return symbol_type (token::RCurly, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Comma (std::string v, location_type l)
      {
        return symbol_type (token::Comma, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Comma (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Comma, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Colon (std::string v, location_type l)
      {
        return symbol_type (token::Colon, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Colon (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Colon, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Double_quote (std::string v, location_type l)
      {
        return symbol_type (token::Double_quote, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Double_quote (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Double_quote, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Single_quote (std::string v, location_type l)
      {
        return symbol_type (token::Single_quote, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Single_quote (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Single_quote, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Do_string (std::string v, location_type l)
      {
        return symbol_type (token::Do_string, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Do_string (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Do_string, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Sq_string (std::string v, location_type l)
      {
        return symbol_type (token::Sq_string, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Sq_string (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Sq_string, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Subtype_sign (std::string v, location_type l)
      {
        return symbol_type (token::Subtype_sign, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Subtype_sign (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Subtype_sign, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Arrow (std::string v, location_type l)
      {
        return symbol_type (token::Arrow, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Arrow (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Arrow, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Less_sign (std::string v, location_type l)
      {
        return symbol_type (token::Less_sign, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Less_sign (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Less_sign, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Star (std::string v, location_type l)
      {
        return symbol_type (token::Star, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Star (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Star, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Gentzen_arrow (std::string v, location_type l)
      {
        return symbol_type (token::Gentzen_arrow, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Gentzen_arrow (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Gentzen_arrow, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Plus (std::string v, location_type l)
      {
        return symbol_type (token::Plus, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Plus (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Plus, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Dollar_word (std::string v, location_type l)
      {
        return symbol_type (token::Dollar_word, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Dollar_word (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Dollar_word, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_Dollar_dollar_word (std::string v, location_type l)
      {
        return symbol_type (token::Dollar_dollar_word, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_Dollar_dollar_word (const std::string& v, const location_type& l)
      {
        return symbol_type (token::Dollar_dollar_word, v, l);
      }
#endif


  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short yypact_ninf_;
    static const short yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (token_type t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned char yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short yytable_[];

  static const short yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned char yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned char yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::reverse_iterator iterator;
      typedef typename S::const_reverse_iterator const_iterator;
      typedef typename S::size_type size_type;

      stack (size_type n = 200)
        : seq_ (n)
      {}

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (size_type i)
      {
        return seq_[size () - 1 - i];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (int i)
      {
        return operator[] (size_type (i));
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (size_type i) const
      {
        return seq_[size () - 1 - i];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (int i) const
      {
        return operator[] (size_type (i));
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (int n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      size_type
      size () const YY_NOEXCEPT
      {
        return seq_.size ();
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.rbegin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.rend ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, int range)
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (int i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        int range_;
      };

    private:
      stack (const stack&);
      stack& operator= (const stack&);
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 725,     ///< Last index in yytable_.
      yynnts_ = 85,  ///< Number of nonterminal symbols.
      yyfinal_ = 17, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 63  ///< Number of tokens.
    };


    // User arguments.
    tptp::parser& drv;
  };

  inline
  parser::token_number_type
  parser::yytranslate_ (token_type t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62
    };
    const unsigned user_token_number_max_ = 317;
    const token_number_type undef_token_ = 2;

    if (static_cast<int> (t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
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
        value.move< node > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
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
        value.copy< node > (YY_MOVE (that.value));
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
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
        value.move< node > (YY_MOVE (s.value));
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  inline
  parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
  }

  inline
  parser::token_type
  parser::by_type::token () const YY_NOEXCEPT
  {
    // YYTOKNUM[NUM] -- (External) token number corresponding to the
    // (internal) symbol number NUM (which must be that of a token).  */
    static
    const unsigned short
    yytoken_number_[] =
    {
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317
    };
    return token_type (yytoken_number_[type]);
  }

} // yy
#line 2867 "tptp.grammar.hh"





#endif // !YY_YY_TPTP_GRAMMAR_HH_INCLUDED
