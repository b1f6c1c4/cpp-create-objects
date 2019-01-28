#include <memory>
template <typename T>
T create()
{
    std::allocator<int> alloc;
    return *std::allocate_shared<int>(alloc, 1847);
}
