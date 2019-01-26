#include <iostream>
#include <initializer_list>

class stub
{
public:
    stub() : value(MAGIC_NUMBER) { invoke(""); }
    stub(int v) : value(v * 62) { invoke("int"); }
    stub(std::initializer_list<int> l) : value(*l.begin() * 2) { invoke("std::initializer_list<int>"); }

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

bool is_checked = false;
int check_result = 255;

void check(size_t sz, stub (*ptr)[3])
{
    if (is_checked)
    {
        std::cout << "Checking more than once is cheating" << std::endl;
        check_result = 8;
        return;
    }
    is_checked = true;

    if (sz != sizeof(stub) * 3)
    {
        std::cout << "Size incorrect, " << sz;
        std::cout << " is not " << sizeof(stub) * 3 << std::endl;
        check_result = 5;
        return;
    }

    if ((*ptr)[0].value != MAGIC_NUMBER)
    {
        std::cout << "Result[0] value incorrect, " << (*ptr)[0].value;
        std::cout << " is not " << MAGIC_NUMBER << std::endl;
        check_result = 1;
        return;
    }

    if ((*ptr)[1].value != MAGIC_NUMBER)
    {
        std::cout << "Result[1] value incorrect, " << (*ptr)[1].value;
        std::cout << " is not " << MAGIC_NUMBER << std::endl;
        check_result = 2;
        return;
    }

    if ((*ptr)[2].value != MAGIC_NUMBER)
    {
        std::cout << "Result[2] value incorrect, " << (*ptr)[2].value;
        std::cout << " is not " << MAGIC_NUMBER << std::endl;
        check_result = 3;
        return;
    }

    if (stub::invoke_count != 3)
    {
        std::cout << "Invoke count incorrect, " << stub::invoke_count;
        std::cout << " is not " << 3 << std::endl;
        check_result = 4;
        return;
    }

    check_result = 0;
}

int main()
{
    std::cout << "Testing " << SNIPPET_NAME << std::endl;
    std::cout << "This is " << COMPILER_NAME << std::endl;

    create<stub>(&check);

    if (!is_checked)
    {
        std::cout << "Not checking is cheating" << std::endl;
        return 7;
    }
    if (check_result == 0)
    {
        std::cout << "Passed" << std::endl;
        return 0;
    }
    return check_result;
}
