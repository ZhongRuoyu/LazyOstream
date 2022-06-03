#include <iostream>
#include <ostream>

class Voidifier {
public:
  template <typename T> void operator=(const T) {}
};

template <class CharT, class Traits> class LazyOstream {
private:
  using OstreamT = std::basic_ostream<CharT, Traits>;

  OstreamT &ostream_;

public:
  LazyOstream(OstreamT &ostream) : ostream_(ostream) {}

  LazyOstream &operator<<(OstreamT &(*f)(OstreamT &)) {
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
