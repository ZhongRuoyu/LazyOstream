#include "../lazy_ostream.h"

#include <iostream>
#include <string>

template <typename T> std::string Evaluate(const T &t) {
  std::clog << "Evaluate(\"" << t << "\") called" << std::endl;
  return t;
}

int main() {
  LAZY_COUT(false) << Evaluate("This will not be evaluated") << std::endl;
  LAZY_COUT(true) << Evaluate("This will be evaluated") << std::endl;
}
