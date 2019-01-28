#include <memory>

template <typename T>
T create()
{
    return *std::make_shared<T>(std::initializer_list<int>{57257});
}
