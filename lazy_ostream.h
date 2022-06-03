#include <iostream>

class Voidifier {
public:
  template <typename T> void operator=(const T) {}
};

class LazyOstream {
private:
  std::ostream &ostream_;

public:
  LazyOstream(std::ostream &ostream) : ostream_(ostream) {}

  LazyOstream &operator<<(std::ostream &(*f)(std::ostream &)) {
    (*f)(this->ostream_);
    return *this;
  }

  template <typename T> LazyOstream &operator<<(const T &t) {
    this->ostream_ << t;
    return *this;
  }
};

#define LAZY_OSTREAM(ostream, enabled)                                         \
  (!enabled) ? (void)0 : Voidifier() = LazyOstream(ostream)
#define LAZY_COUT(enabled) LAZY_OSTREAM(std::cout, enabled)
#define LAZY_CERR(enabled) LAZY_OSTREAM(std::cerr, enabled)
#define LAZY_CLOG(enabled) LAZY_OSTREAM(std::clog, enabled)
