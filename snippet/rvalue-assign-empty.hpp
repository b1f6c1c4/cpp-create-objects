template <typename T>
T create()
{
    auto &&a = T();
    return a;
}
