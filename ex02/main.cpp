#include <iostream>
#include <list>
#include "MutantStack.hpp"

static void printStack(const MutantStack<int> &mstack, const std::string &label)
{
    std::cout << label << ":";
    for (MutantStack<int>::const_iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;
}

int main()
{
    MutantStack<int> mstack;

    // Basic push/pop operations
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size after pop: " << mstack.size() << std::endl;

    // Fill more data
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Iterate forward
    printStack(mstack, "forward iteration");

    // Iterate backward
    std::cout << "reverse iteration:";
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
        std::cout << " " << *rit;
    std::cout << std::endl;

    // Compare with standard container
    std::list<int> lst(mstack.begin(), mstack.end());
    std::cout << "list copy:";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << " " << *it;
    std::cout << std::endl;

    return 0;
}

