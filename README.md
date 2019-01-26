# How many ways to create object(s) in C++?
[![Build Status](https://img.shields.io/travis/com/b1f6c1c4/cpp-create-objects/master.svg?style=flat-square)](https://travis-ci.com/b1f6c1c4/cpp-create-objects)
[![License](https://img.shields.io/badge/license-CC0-ff69b4.svg?style=flat-square)](https://creativecommons.org/publicdomain/zero/1.0/)

Only heard of `T a` and `new T()`? You are not a REAL™ C++ programmer.

Checkout how many ways you can think of to create some objects.

# Rules

* Write your snippet in `snippet/**/*.hpp`:
    * We will `#include <stdlib.h>` for you at the beginning.
    * It should have one (1) function definition named `create`:
    * You may use auxilliary typedef, function, etc.
    * You may NOT do anything irrelevent to the object creation.
    * You MUST use `auto` whenever possible.
    * The creation method should be universal - not just for our `stub`.
* Checkout `main.cpp` and see what is considered valid.
    * Remember, `MAGIC_NUMBER` is 114514.
* Two creation methods are considered identical if they:
    * are lexically the same (adding comments); or
    * are syntactically the same (adding parentheses); or
    * are (trivially) semantically the same (`1+1` v.s. `2`); or
    * are identical after preprocessor;
    * only differ quantitatively (repeating something)
* Two methods are NEVER considered identical if they:
    * call different constructors
* Dirty methods are allowed as long as they:
    * are not identical to previous methods;
    * are compilable by both g++ and clang++ on ubunut xenial;
    * don't triggering any warnings (`-Wextra`);
    * are not "evil" (`rm -rf /*`)
* Additional rules for `single`:
    * with template `typename T`;
    * of signature `T ()`;
    * invoke the constructor of `T` exactly once (1);
        * copy-constructor and move-constructor are NOT included
    * return an instance of `T`.
* Additional rules for `array`:
    * with template `typename T`;
    * of signature `void (check_t<T>)`, where `check_t<T> = void (*)(size_t, T (*)[3]))`;
    * invoke the constructor of `T` exactly three (3) times
        * copy-constructor and move-constructor are NOT included
    * treat the three values equally (i.e., construct them the same way)
    * invoke the function pointer exactly once (1):
        * the first parameter should be the `sizeof` of the array
        * the second parameter should be the pointer to the created array

# Example

`snippet/single/named-default.hpp`:
```c++
template <typename T>
T create()
{
    T a;
    return a;
}
```

`snippet/single/new-empty.hpp`:
```c++
template <typename T>
T create()
{
    return *new T();
}
```

`snippet/array/named-default.hpp`:
```c++
template <typename T>
void create(check_t check)
{
    T a[3];
    check(sizeof(a), &a);
}
```

# License

We don't want you to think about legal consequence every time before creating an object.
This project is proudly licensed as
*Creative Commons Zero v1.0 Universal*
