template <typename T>
T create()
{
    auto gen = [](T a) { return a; };
    return gen(T());
}
