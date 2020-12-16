#include <cstdint>
#include <iostream>
#include <vector>
#include "stack.h"

namespace cpp_templates_the_complete_guide {

void run_default_stack() {
  stack<int16_t> stk;
  for (int16_t i = 1; i <= 10; ++i) {
    stk.push(i);
  }
  while (not stk.empty()) {
    std::cout << stk.top() << '\n';
    stk.pop();
  }
}

void run_vector_stack() {
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
