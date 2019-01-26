SNIPPETS=$(wildcard snippet/**/*.hpp)
CFLAGS=-x c++ -std=c++17 -Wall -Werror -Wextra -O0 -DMAGIC_NUMBER=114514 -DCOMPILER_NAME=\"$(CXX)\"

.PHONY: all test clean

all: $(patsubst snippet/%.hpp, build/%.o, $(SNIPPETS))

test: $(patsubst snippet/%.hpp, result/%, $(SNIPPETS))

build/single/%.o: header.hpp snippet/single/%.hpp snippet/single.cpp
	mkdir -p $(dir $@)
	cat $^ | $(CXX) $(CFLAGS) -o $@ -DSNIPPET_NAME=\"$<\" -

build/array/%.o: header.hpp snippet/array/%.hpp snippet/array.cpp
	mkdir -p $(dir $@)
	cat $^ | $(CXX) $(CFLAGS) -o $@ -DSNIPPET_NAME=\"$<\" -

result/%: build/%.o
	mkdir -p $(dir $@)
	./$^ | tee $@

clean:
	rm -rf build result
