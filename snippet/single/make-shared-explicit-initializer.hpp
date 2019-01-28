#include <memory>
template <typename T>
T create()
{
    auto list = std::initializer_list<int>{57257};
    return *std::make_shared<T>(list);
}
