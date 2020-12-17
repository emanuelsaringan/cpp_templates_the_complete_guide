#ifndef CPP_TEMPLATES_THE_COMPLETE_GUIDE_STACK_H_
#define CPP_TEMPLATES_THE_COMPLETE_GUIDE_STACK_H_

#include <cassert>
#include <deque>

namespace cpp_templates_the_complete_guide {

template <typename T, template <typename> class Cont = std::deque>
class stack {
 public:
  void pop();
  const T& top() const;
  bool empty() const { return cont_.empty(); }
  void push(const T&);
  template <typename T2, template <typename> class Cont2>
  stack<T, Cont>& operator=(const stack<T2, Cont2>&);
 public:
  template <typename, template <typename> class> friend class stack;
 private:
  Cont<T> cont_;
};

template <typename T, template <typename> class Cont>
void stack<T, Cont>::pop() {
  assert(!empty());
  cont_.erase(cont_.end() - 1);
}

template <typename T, template <typename> class Cont>
const T& stack<T, Cont>::top() const {
  assert(!empty());
  return *(cont_.end() - 1);
}

template <typename T, template <typename> class Cont>
void stack<T, Cont>::push(const T& elem) {
  cont_.insert(cont_.end(), elem);
}

template <typename T, template <typename> class Cont>
template <typename T2, template <typename> class Cont2>
stack<T, Cont>& stack<T, Cont>::operator=(const stack<T2, Cont2>& other) {
  cont_.clear();
  cont_.insert(cont_.begin(), other.cont_.begin(), other.cont_.end());
  return *this;
}

}  // namespace cpp_templates_the_complete_guide

#endif // CPP_TEMPLATES_THE_COMPLETE_GUIDE_STACK_H_
