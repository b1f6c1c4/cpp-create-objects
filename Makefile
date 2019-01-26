SNIPPETS=$(wildcard snippet/*.hpp)
CFLAGS=-x c++ -std=c++17 -Wall -Werror -Wextra -O0 -DMAGIC_NUMBER=114514 -DCOMPILER_NAME=\"$(CXX)\"

.PHONY: all test clean

all: $(patsubst snippet/%.hpp, build/%.o, $(SNIPPETS))

test: $(patsubst snippet/%.hpp, result/%, $(SNIPPETS))

build/%.o: snippet/%.hpp main.cpp
	mkdir -p build
	cat $^ | $(CXX) $(CFLAGS) -o $@ -DSNIPPET_NAME=\"$<\" -

result/%: build/%.o
	mkdir -p result
	./$^ | tee $@

clean:
	rm -rf build result
