template <typename T>
T create()
{
    return *new(reinterpret_cast<T*>(malloc(sizeof(T)))) T;
}
