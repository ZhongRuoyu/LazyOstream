#include "../lazy_ostream.h"

#include <iostream>
#include <string>

template <typename T> std::string Evaluate(const T &t) {
  std::clog << "Evaluate(\"" << t << "\") called" << std::endl;
  return t;
}

int main() {
  {
    bool debug = true;
    std::clog << "debug set to true" << std::endl;
    LAZY_CLOG(debug) << Evaluate("This will be evaluated") << std::endl;
  }
  {
    bool debug = false;
    std::clog << "debug set to false" << std::endl;
    LAZY_CLOG(debug) << Evaluate("This will not be evaluated") << std::endl;
  }
}
