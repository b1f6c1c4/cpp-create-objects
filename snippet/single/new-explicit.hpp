template <typename T>
T create()
{
    return *new T(1847);
}
