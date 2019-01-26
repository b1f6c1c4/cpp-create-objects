# How many ways to create object(s) in C++?

Only heard of `T a` and `new T()`? You are not a REAL™ C++ programmer.

Checkout how many ways you can think of to create some objects.

# Rules

* Write your snippet in `snippet/*.hpp`:
    * It should have one (1) function definition named `create`:
        * with template `typename T`;
        * of signature `T ()`;
        * invoke the constructor of `T` exactly once (1);
            * copy-constructor and move-constructor are NOT included
        * return an instance of `T`.
    * You may use auxilliary typedef, function, etc.
    * You may NOT do anything irrelevent to the object creation.
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

# Example

`snippet/default.hpp`:
```c++
template <typename T>
T create()
{
    T a;
    return a;
}
```

`snippet/new-default.hpp`:
```c++
template <typename T>
T create()
{
    return *new T();
}
```
