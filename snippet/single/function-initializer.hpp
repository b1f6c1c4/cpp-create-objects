template <typename T>
T identity(T a)
{
    return a;
}

template <typename T>
T create()
{
    return identity<T>({57257});
}
