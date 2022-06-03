CXXFLAGS += -std=c++17

HEADER = lazy_ostream.h

EXAMPLE_SRCS = $(wildcard examples/*.cc)
EXAMPLE_BINS = $(addprefix bin/,$(subst .cc,,$(EXAMPLE_SRCS)))

all: $(EXAMPLE_BINS)

bin/examples/%: examples/%.cc $(HEADER) bin/examples/.keep
	$(CXX) $(CXXFLAGS) -o $@ $<

bin/examples/.keep:
	mkdir -p $(@D)
	touch $@

clean:
	$(RM) example

.PHONY: clean
