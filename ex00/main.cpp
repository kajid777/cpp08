#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

static void printResult(const std::string &label, int value, bool success)
{
    std::cout << label << ": value " << value << (success ? " found" : " not found") << std::endl;
}

int main()
{
    std::vector<int> vec;
    for (int i = 0; i < 5; ++i)
        vec.push_back(i * 10);

    std::list<int> lst;
    lst.push_back(42);
    lst.push_back(21);
    lst.push_back(84);

    try
    {
        easyfind(vec, 20);
        printResult("vector", 20, true);
        easyfind(vec, 100);
        printResult("vector", 100, true);
    }
    catch (const std::exception &e)
    {
        printResult("vector", 100, false);
        std::cout << "  reason: " << e.what() << std::endl;
    }

    try
    {
        easyfind(lst, 84);
        printResult("list", 84, true);
        easyfind(lst, -1);
        printResult("list", -1, true);
    }
    catch (const std::exception &e)
    {
        printResult("list", -1, false);
        std::cout << "  reason: " << e.what() << std::endl;
    }

    return 0;
}

