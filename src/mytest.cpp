#include <algorithm>
#include <any>
#include <bits/c++config.h>
#include <cinttypes>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <memory>
#include <ratio>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>
using namespace std;

#if __cplusplus == 201103L
template <typename T, typename... Args>
std::unique_ptr<T> make_unique(Args &&...args) {
  cout << "self make unique" << endl;
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
#endif

void func() {
  int c[100];
  c[4] = 100;
  c[5] = 110;
  c[6] = 170;
}

// template <std::size_t Idx, typename Head, bool =
// __empty_not_final<Head>::value> class HeadBase;

// template <size_t Idx, typename Head>
// class HeadBase<Idx, Head, true> : public Head {
// public:
//   constexpr HeadBase() : Head() {}
//   constexpr HeadBase(const HeadBase &head) : Head(head) {}
//   template <typename UHead>
//   constexpr HeadBase(UHead &&head) : Head(std::forward<UHead>(head)) {}
//   constexpr HeadBase(const Head &) = default;
//   constexpr HeadBase(Head &&) = default;

//   static constexpr Head &M_head(HeadBase &b) noexcept { return b; }
//   static constexpr const Head &M_head(const HeadBase &b) noexcept { return b;
//   }
// };

// template <size_t Idx, typename Head> class HeadBase<Idx, Head, false> {
// public:
//   constexpr HeadBase() : head_impl() {}
//   constexpr HeadBase(const Head &h) : head_impl(h) {}
//   template <typename UHead>
//   constexpr HeadBase(UHead &&head) : head_impl(std::forward<UHead>(head)) {}

//   constexpr HeadBase(const HeadBase &) = default;
//   constexpr HeadBase(HeadBase &&) = default;

//   static constexpr Head &M_head(HeadBase &b) noexcept { return b.head_impl; }
//   static constexpr const Head &M_head(const HeadBase &b) noexcept {
//     return b.head_impl;
//   }

//   Head head_impl;
// };

// template <size_t Idx, typename... Elements> class TupleImpl;

// template <size_t Idx, typename Head, typename... Tail>
// class TupleImpl<Idx, Head, Tail...> : public TupleImpl<Idx + 1, Tail...>,
//                                       private HeadBase<Idx, Head> {
//   template <std::size_t, typename...> friend class TupleImpl;
//   using Inherited = TupleImpl<Idx + 1, Tail...>;
//   using Base = HeadBase<Idx, Head>;

// public:
//   static constexpr Head &M_head(TupleImpl &t) noexcept {
//     return Base::M_head(t);
//   }

//   static constexpr const Head &M_head(const TupleImpl &t) noexcept {
//     return Base::M_head(t);
//   }

//   static constexpr Inherited &M_tail(TupleImpl &t) noexcept { return t; }
//   static constexpr const Inherited &M_tail(const TupleImpl &t) noexcept {
//     return t;
//   }

//   constexpr TupleImpl() : Inherited() {}

//   explicit constexpr TupleImpl(const Head &head, const Tail &... tail)
//       : Inherited(tail...), Base(head) {}

//   template <
//       typename UHead, typename... UTail,
//       typename = typename enable_if<sizeof...(Tail) ==
//       sizeof...(UTail)>::type>
//   explicit constexpr TupleImpl(UHead &&head, UTail &&... tail)
//       : Inherited(std::forward<UTail>(tail)...),
//         Base(std::forward<UHead>(head)) {}
// };

// template <std::size_t Idx, typename Head>
// class TupleImpl<Idx, Head> : private HeadBase<Idx, Head> {
//   template <std::size_t, typename...> friend class TupleImpl;
//   using Base = HeadBase<Idx, Head>;

// public:
//   static constexpr Head &M_head(TupleImpl &t) noexcept {
//     return Base::M_head(t);
//   }

//   static constexpr const Head &M_head(const TupleImpl &t) noexcept {
//     return Base::M_head(t);
//   }

//   constexpr TupleImpl() : Base() {}

//   explicit constexpr TupleImpl(const Head &head) : Base(head) {}

//   template <typename UHead>
//   explicit constexpr TupleImpl(UHead &&head)
//       : Base(std::forward<UHead>(head)) {}

//   constexpr TupleImpl(const TupleImpl &) = default;
//   TupleImpl &operator=(const TupleImpl &) = delete;
// };

// template <typename... Elements> class Tuple : public TupleImpl<0,
// Elements...> {
//   using Inherited = TupleImpl<0, Elements...>;

// public:
//   Tuple() : Inherited() {}
//   Tuple(Elements... elements) : Inherited(elements...) {}
// };

// template <typename T1, typename T2> struct Pair {
//   T1 first;
//   T2 second;
//   Pair() : first(), second() {}
//   Pair(T1 f, T2 s) : first(f), second(s) {}
// };
// template <class... Args1> struct zip {
//   template <class... Args2> struct with {
//     typedef Tuple<Pair<Args1, Args2>...> type;
//   };
// };

// typedef zip<short, int>::with<unsigned short, unsigned>::type T1;

// template <std::size_t i, typename Tp> struct TupleElement;

// template <std::size_t i, typename Tp>
// using TupleElement_t = typename TupleElement<i, Tp>::type;

// template <std::size_t i, typename Tp> struct TupleElement<i, const Tp> {
//   typedef typename add_const<TupleElement_t<i, Tp>>::type type;
// };

// template <std::size_t i, typename Tp> struct TupleElement<i, volatile Tp> {
//   typedef typename add_volatile<TupleElement_t<i, Tp>>::type type;
// };

// template <typename Tp> struct TupleSize;

// template <typename Tp, std::size_t Nm>
// struct TupleSize<std::array<Tp, Nm>>
//     : public integral_constant<std::size_t, Nm> {};

// template <typename... Elements>
// struct TupleSize<Tuple<Elements...>>
//     : public integral_constant<std::size_t, sizeof...(Elements)> {};

// template <std::size_t i, typename Tp>
// struct TupleElement<i, const volatile Tp> {
//   typedef typename add_cv<TupleElement_t<i, Tp>>::type type;
// };

// template <std::size_t i, typename Head, typename... Tail>
// struct TupleElement<i, Tuple<Head, Tail...>>
//     : TupleElement<i - 1, Tuple<Tail...>> {};

// template <typename Head, typename... Tail>
// struct TupleElement<0, tuple<Head, Tail...>> {
//   typedef Head type;
// };

// template <std::size_t i> struct TupleElement<i, Tuple<>> {
//   // static_assert(i < TupleSize<Tuple<>>::value, "tuple index is in range");
// };

// template <size_t i, typename Tp>
// using TupleElement_t = typename TupleElement<i, Tp>::type;

// template <std::size_t i, typename Head, typename... Tail>
// constexpr Head &get_helper(TupleImpl<i, Head, Tail...> &t) noexcept {
//   return TupleImpl<i, Head, Tail...>::m_head(t);
// }

// template <std::size_t i, typename Head, typename... Tail>
// constexpr const Head &
// get_helper(const TupleImpl<i, Head, Tail...> &t) noexcept {
//   return TupleImpl<i, Head, Tail...>::m_head(t);
// }

// template <std::size_t i, typename... Elements>
// constexpr TupleElement_t<i, Tuple<Elements...>> &
// M_get(Tuple<Elements...> &t) noexcept {
//   return get_helper<i>(t);
// }

// template <std::size_t i, typename... Elements>
// constexpr const TupleElement_t<i, Tuple<Elements...>> &
// M_get(const Tuple<Elements...> &t) noexcept {
//   return get_helper<i>(t);
// }

// template <std::size_t i, typename... Elements>
// constexpr TupleElement_t<i, Tuple<Elements...>> &&
// M_get(Tuple<Elements...> &&t) noexcept {
//   using ElementType = TupleElement_t<i, Tuple<Elements...>>;
//   return std::forward<ElementType &&>(M_get<i>(t));
// }

// template <std::size_t i, typename... Elements>
// constexpr const TupleElement_t<i, Tuple<Elements...>> &&
// M_get(const Tuple<Elements...> &&t) noexcept {
//   using ElementType = TupleElement_t<i, Tuple<Elements...>>;
//   return std::forward<const ElementType &&>(M_get<i>(t));
// }

template <typename... Args> struct Tuple;

template <typename Head, typename... Tail>
struct Tuple<Head, Tail...> : public Tuple<Tail...> {
  using Inherited = Tuple<Tail...>;
  using Base = Head;

  Tuple() : head() {}

  Tuple(const Head &h, const Tail &...t) : Inherited(t...), head(h) {}

  template <typename UHead, typename... UTail>
  Tuple(UHead &&h, UTail &&...t)
      : Inherited(std::forward<UTail>(t)...), head(std::forward<UHead>(h)) {}
  Base head;
};

template <> struct Tuple<> {};

template <typename T1, typename T2> struct Pair {
  T1 first;
  T2 second;
  Pair(T1 f, T2 s) : first(f), second(s) {}
};

template <class... Args1> struct zip {
  template <class... Args2> struct with {
    typedef Tuple<Pair<Args1, Args2>...> type;
  };
};
typedef zip<short, int>::with<unsigned short, unsigned>::type T1;
// Pair<Args1, Args2>... 展开为
// Pair<short, unsigned short>, Pair<int, unsigned int>
// T1 的类型是 Tuple<Pair<short, unsigned short>, Pair<int, unsigned int>>

template <size_t N, typename... Tps> struct Elements;

template <size_t N> struct Elements<N> {
  static_assert(N > 0, "Index overflow");
};

template <size_t N, typename Tp, typename... Tps>
struct Elements<N, Tp, Tps...> : public Elements<N - 1, Tps...> {};

template <typename Tp, typename... Tps> struct Elements<0, Tp, Tps...> {
  using tuple_t = Tuple<Tp, Tps...>;
};

template <size_t N, typename... Tps> auto get(const Tuple<Tps...> &ttuple) {
  using tuple_t = typename Elements<N, Tps...>::tuple_t;
  return static_cast<const tuple_t &>(ttuple).head;
}

template <size_t N, typename... Tps> auto get(Tuple<Tps...> &ttuple) {
  using tuple_t = typename Elements<N, Tps...>::tuple_t;
  return static_cast<tuple_t &>(ttuple).head;
}

template <std::size_t N, typename... Tps> auto get(Tuple<Tps...> &&t) {
  using Tuple_t = typename Elements<N, Tps...>::tuple_t;
  return static_cast<Tuple_t &&>(t).head;
}

constexpr long double operator"" _deg_to_rad(long double deg) {
  return deg * 3.14 / 180;
}

struct B1 {
  B1(int b, ...) : b(b) { std::cout << "b1" << std::endl; }
  int b;
};

int get();

struct D1 : B1 {
  using B1::B1;
  int y = get();

  explicit D1(int x, int y) : B1(x), y(y) { std::cout << "b2" << std::endl; }
};

void test() {
  // D1 d(1, 2, 3);

  D1 e(1);
}

int get() { return 5; }

int main(int argc, char const *argv[]) {
  Tuple<int, int> tp(1, 2);
  T1 t({1, 2}, {3, 4});
  auto ans = get<0>(T1{{5, 6}, {3, 4}});
  std::cout << ans.first << std::endl;
  std::cout << ans.second << std::endl;
  auto ans2 = get<1>(t);
  std::cout << ans2.first << std::endl;
  std::cout << ans2.second << std::endl;
  // std::cout << ans2.first << "," << ans2.second << std::endl;
  auto rad_x = 90.0_deg_to_rad;
  std::cout << rad_x << std::endl;

  std::any var = 100;
  std::cout << var.type().name() << ":" << any_cast<int>(var) << std::endl;
  var = string("hello");
  std::cout << var.type().name() << ":" << any_cast<string>(var) << std::endl;
  return 0;
}
