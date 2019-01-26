#include <stdlib.h>

template <typename T>
using check_t = void (*)(size_t, T (*)[3]);
