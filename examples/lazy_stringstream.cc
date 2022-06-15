#include <iostream>
#include <sstream>
#include <string>

#include "../lazy_ostream.h"

template <typename T>
std::string Evaluate(const T &t) {
    std::clog << "Evaluate(\"" << t << "\") called" << std::endl;
    return t;
}

int main() {
    std::stringstream sstream;
    LAZY_OSTREAM(sstream, false)
        << Evaluate("This will not be evaluated") << std::endl;
    LAZY_OSTREAM(sstream, true)
        << Evaluate("This will be evaluated") << std::endl;
    std::cout << sstream.str();
}
