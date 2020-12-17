#include <cstdint>
#include <iostream>
#include <vector>
#include "stack.h"

namespace cpp_templates_the_complete_guide {

void run_default_stack() {
  std::cout << "Testing default container" << '\n';
  stack<int16_t> stk;
  for (int16_t i = 1; i <= 10; ++i) {
    stk.push(i);
  }
  while (not stk.empty()) {
    std::cout << stk.top() << '\n';
    stk.pop();
  }

  std::cout << "Testing assignment" << '\n';
  stack<float> other;
  other.push(1.5);
  other.push(2.4);
  other.push(5.1);
  stk = other;
  while (not stk.empty()) {
    std::cout << stk.top() << '\n';
    stk.pop();
  }
}

void run_vector_stack() {
  std::cout << "Testing vector container" << '\n';
  stack<int16_t, std::vector> stk;
  for (int16_t i = 1; i <= 10; ++i) {
    stk.push(i);
  }
  while (not stk.empty()) {
    std::cout << stk.top() << '\n';
    stk.pop();
  }
}

}  // namespace cpp_templates_the_complete_guide

int main() {
  cpp_templates_the_complete_guide::run_default_stack();
  cpp_templates_the_complete_guide::run_vector_stack();
  return 0;
}
