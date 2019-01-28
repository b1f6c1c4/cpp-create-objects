#include <memory>

template <typename T>
T create()
{
    return *std::make_unique<T>(std::initializer_list<int>{57257});
}
