#ifndef COMPOSER_H
#define COMPOSER_H

#include <functional>

namespace chen {

/// @brief  组合两个一元函数
/// @tparam f(x) 
/// @tparam g(x)
template <class Operation1, class Operation2>
class unary_compose : public std::unary_function<typename Operation2::argument_type,
                                            typename Operation1::result_type> {
 protected:
  Operation1 op1;
  Operation2 op2;

 public:
  // constructor
  unary_compose(const Operation1& x, const Operation2& y) : op1(x), op2(y) {}

  typename Operation1::result_type operator()(
      const typename Operation1::argument_type& x) const {
    return op1(op2(x));  // compose
  }
};

/// @brief 辅助函数，组合一元函数，f(g(x))
/// @tparam f(x)
/// @tparam g(x)
/// @param 一元函数f 
/// @param 一元函数g 
/// @return 函数f的返回值
template <class Operation1, class Operation2>
inline unary_compose<Operation1, Operation2> compose1(const Operation1& op1,
                                                      const Operation2& op2) {
  return unary_compose<Operation1, Operation2>(op1, op2);
}

/// @brief 组合三个函数
/// @tparam 二元函数f(x, y)
/// @tparam 一元函数g(x)
/// @tparam 一元函数h(x)
template <class Operation1, class Operation2, class Operation3>
class binary_compose
    : public std::binary_function<typename Operation2::argument_type,
                             typename Operation3::argument_type,
                             typename Operation1::result_type> {
 protected:
  Operation1 op1;
  Operation2 op2;
  Operation3 op3;

 public:
  binary_compose(const Operation1& x, const Operation2& y, const Operation3& z)
      : op1(x), op2(y), op3(z) {}

  typename Operation1::result_type operator()(
      const typename Operation2::argument_type x) const {
    return op1(op2(x), op3(x));  // compose
  }
};

/// @brief 辅助函数，组合三个函数，f(g(x), h(x))
/// @tparam f(x,y)
/// @tparam g(x)
/// @tparam h(x)
/// @param 二元函数f
/// @param 一元函数g
/// @param 一元函数h
/// @return 函数f的返回值
template <class Operation1, class Operation2, class Operation3>
inline binary_compose<Operation1, Operation2, Operation3> compose2(
    const Operation1& op1, const Operation2& op2, const Operation3& op3) {
  return binary_compose<Operation1, Operation2, Operation3>(op1, op2, op3);
}

}  // namespace chen

#endif  // COMPOSER_H