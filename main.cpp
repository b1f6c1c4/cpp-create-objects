#include <iostream>
#include <initializer_list>

class stub
{
public:
    stub() : value(MAGIC_NUMBER) { invoke(""); }
    stub(int v) : value(v * 62) { invoke("int"); }
    stub(std::initializer_list<int> &l) : value(*l.begin() * 2) { invoke("std::initializer_list<int>"); }

    int value;
    static size_t invoke_count;
    static void invoke(const char *reason)
    {
        std::cout << "stub::stub(" << reason << ") is called, ";
        std::cout << "this is the " << ++invoke_count << "th time";
        std::cout << std::endl;
    };
};

size_t stub::invoke_count = 0;

int main()
{
    std::cout << "Testing " << SNIPPET_NAME << std::endl;
    std::cout << "This is " << COMPILER_NAME << std::endl;

    auto &&result = create<stub>();

    if (result.value != MAGIC_NUMBER)
    {
        std::cout << "Result value incorrect, " << result.value;
        std::cout << " is not " << MAGIC_NUMBER << std::endl;
        return 1;
    }

    if (stub::invoke_count != 1)
    {
        std::cout << "Invoke count incorrect, " << stub::invoke_count;
        std::cout << " is not " << 1 << std::endl;
        return 2;
    }

    std::cout << "Passed" << std::endl;
    return 0;
}
