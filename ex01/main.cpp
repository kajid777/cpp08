#include <iostream>
#include <vector>
#include <cstdlib>
#include "Span.hpp"

static void printSpanInfo(const Span &sp, const std::string &label)
{
    std::cout << label << " size=" << sp.size() << "/" << sp.capacity();
    if (sp.size() >= 2)
    {
        std::cout << " shortest=" << sp.shortestSpan();
        std::cout << " longest=" << sp.longestSpan();
    }
    std::cout << std::endl;
}

int main()
{
    // Basic scenario
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    printSpanInfo(sp, "basic span");

    // Exception: adding beyond capacity
    try
    {
        sp.addNumber(42);
    }
    catch (const std::exception &e)
    {
        std::cout << "Expected overflow: " << e.what() << std::endl;
    }

    // Exception: querying span with insufficient data
    Span tiny(1);
    tiny.addNumber(10);
    try
    {
        tiny.shortestSpan();
    }
    catch (const std::exception &e)
    {
        std::cout << "Expected insufficient data: " << e.what() << std::endl;
    }

    return 0;
}

