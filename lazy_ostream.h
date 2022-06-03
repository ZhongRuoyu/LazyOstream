#include <iostream>

class Voidifier {
public:
  template <typename T> void operator=(T &) {}
};

#define LAZY_OSTREAM(ostream, enabled)                                         \
  (!enabled) ? (void)0 : Voidifier() = ostream
#define LAZY_COUT(enabled) LAZY_OSTREAM(std::cout, enabled)
#define LAZY_CERR(enabled) LAZY_OSTREAM(std::cerr, enabled)
#define LAZY_CLOG(enabled) LAZY_OSTREAM(std::clog, enabled)
