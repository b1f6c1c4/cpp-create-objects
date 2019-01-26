template <typename T>
void create(check_t<T> check)
{
    T a[3];
    check(sizeof(a), &a);
}
