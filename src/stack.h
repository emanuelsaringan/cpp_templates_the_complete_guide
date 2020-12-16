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

}  // namespace cpp_templates_the_complete_guide

#endif // CPP_TEMPLATES_THE_COMPLETE_GUIDE_STACK_H_
