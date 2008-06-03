/* *****************************************************
   THIS IS AN AUTOMATICALLY GENERATED FILE. DO NOT EDIT.
   *****************************************************

   Generated by:
     scitbx.source_generators.array_family.generate_operator_functors
 */

#ifndef SCITBX_ARRAY_FAMILY_OPERATOR_FUNCTORS_H
#define SCITBX_ARRAY_FAMILY_OPERATOR_FUNCTORS_H

namespace scitbx { namespace fn {

  template <typename ResultType,
            typename ArgumentType>
  struct functor_logical_not {
    typedef ResultType result_type;
    ResultType operator()(ArgumentType const& x) const {
      return ResultType(!x);
    }
  };

  template <typename ResultType,
            typename ArgumentType>
  struct functor_negate {
    typedef ResultType result_type;
    ResultType operator()(ArgumentType const& x) const {
      return ResultType(-x);
    }
  };

  template <typename ResultType,
            typename ArgumentType1,
            typename ArgumentType2>
  struct functor_less_equal {
    typedef ResultType result_type;
    ResultType operator()(ArgumentType1 const& x,
                          ArgumentType2 const& y) const {
      return ResultType(x <= y);
    }
  };

  template <typename ResultType,
            typename ArgumentType1,
            typename ArgumentType2>
  struct functor_modulus {
    typedef ResultType result_type;
    ResultType operator()(ArgumentType1 const& x,
                          ArgumentType2 const& y) const {
      return ResultType(x % y);
    }
  };

  template <typename ResultType,
            typename ArgumentType1,
            typename ArgumentType2>
  struct functor_greater_equal {
    typedef ResultType result_type;
    ResultType operator()(ArgumentType1 const& x,
                          ArgumentType2 const& y) const {
      return ResultType(x >= y);
    }
  };

  template <typename ResultType,
            typename ArgumentType1,
            typename ArgumentType2>
  struct functor_equal_to {
    typedef ResultType result_type;
    ResultType operator()(ArgumentType1 const& x,
                          ArgumentType2 const& y) const {
      return ResultType(x == y);
    }
  };

  template <typename ResultType,
            typename ArgumentType1,
            typename ArgumentType2>
  struct functor_plus {
    typedef ResultType result_type;
    ResultType operator()(ArgumentType1 const& x,
                          ArgumentType2 const& y) const {
      return ResultType(x + y);
    }
  };

  template <typename ResultType,
            typename ArgumentType1,
            typename ArgumentType2>
  struct functor_multiplies {
    typedef ResultType result_type;
    ResultType operator()(ArgumentType1 const& x,
                          ArgumentType2 const& y) const {
      return ResultType(x * y);
    }
  };

  template <typename ResultType,
            typename ArgumentType1,
            typename ArgumentType2>
  struct functor_minus {
    typedef ResultType result_type;
    ResultType operator()(ArgumentType1 const& x,
                          ArgumentType2 const& y) const {
      return ResultType(x - y);
    }
  };

  template <typename ResultType,
            typename ArgumentType1,
            typename ArgumentType2>
  struct functor_divides {
    typedef ResultType result_type;
    ResultType operator()(ArgumentType1 const& x,
                          ArgumentType2 const& y) const {
      return ResultType(x / y);
    }
  };

  template <typename ResultType,
            typename ArgumentType1,
            typename ArgumentType2>
  struct functor_less {
    typedef ResultType result_type;
    ResultType operator()(ArgumentType1 const& x,
                          ArgumentType2 const& y) const {
      return ResultType(x < y);
    }
  };

  template <typename ResultType,
            typename ArgumentType1,
            typename ArgumentType2>
  struct functor_logical_and {
    typedef ResultType result_type;
    ResultType operator()(ArgumentType1 const& x,
                          ArgumentType2 const& y) const {
      return ResultType(x && y);
    }
  };

  template <typename ResultType,
            typename ArgumentType1,
            typename ArgumentType2>
  struct functor_not_equal_to {
    typedef ResultType result_type;
    ResultType operator()(ArgumentType1 const& x,
                          ArgumentType2 const& y) const {
      return ResultType(x != y);
    }
  };

  template <typename ResultType,
            typename ArgumentType1,
            typename ArgumentType2>
  struct functor_logical_or {
    typedef ResultType result_type;
    ResultType operator()(ArgumentType1 const& x,
                          ArgumentType2 const& y) const {
      return ResultType(x || y);
    }
  };

  template <typename ResultType,
            typename ArgumentType1,
            typename ArgumentType2>
  struct functor_greater {
    typedef ResultType result_type;
    ResultType operator()(ArgumentType1 const& x,
                          ArgumentType2 const& y) const {
      return ResultType(x > y);
    }
  };

  template <typename ArgumentType1,
            typename ArgumentType2>
  struct functor_ip_minus {
    ArgumentType1& operator()(ArgumentType1& x,
                              ArgumentType2 const& y) const {
      x -= y;
      return x;
    }
  };

  template <typename ArgumentType1,
            typename ArgumentType2>
  struct functor_ip_multiplies {
    ArgumentType1& operator()(ArgumentType1& x,
                              ArgumentType2 const& y) const {
      x *= y;
      return x;
    }
  };

  template <typename ArgumentType1,
            typename ArgumentType2>
  struct functor_ip_divides {
    ArgumentType1& operator()(ArgumentType1& x,
                              ArgumentType2 const& y) const {
      x /= y;
      return x;
    }
  };

  template <typename ArgumentType1,
            typename ArgumentType2>
  struct functor_ip_modulus {
    ArgumentType1& operator()(ArgumentType1& x,
                              ArgumentType2 const& y) const {
      x %= y;
      return x;
    }
  };

  template <typename ArgumentType1,
            typename ArgumentType2>
  struct functor_ip_plus {
    ArgumentType1& operator()(ArgumentType1& x,
                              ArgumentType2 const& y) const {
      x += y;
      return x;
    }
  };

}} // namespace scitbx::fn

#endif // SCITBX_ARRAY_FAMILY_OPERATOR_FUNCTORS_H
