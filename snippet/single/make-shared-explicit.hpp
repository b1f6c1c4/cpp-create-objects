#include <memory>
template <typename T>
T create()
{
    return *std::make_shared<T>(1847);
}
