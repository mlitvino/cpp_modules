#include "Span.hpp"
#include <iostream>
#include <array>

int main()
{
    std::cout << "=== Span Tests ===" << std::endl;

    // Test 1: Basic functionality
    Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(14);
	sp.addNumber(11);
    std::cout << "ShortestSpan: " << sp.shortestSpan() << std::endl;
    std::cout << "LongestSpan: " << sp.longestSpan() << std::endl;

    // Test 2: Exception when adding beyond capacity
    try {
        sp.addNumber(42);
    } catch (const std::exception& e) {
        std::cout << "Expected exception (addNumber): " << e.what() << std::endl;
    }

    // Test 3: Exception on spans with insufficient elements
    Span sp2(1);
    sp2.addNumber(100);
    try {
        sp2.shortestSpan();
    } catch (const std::exception& e) {
        std::cout << "Expected exception (shortestSpan): " << e.what() << std::endl;
    }
    try {
        sp2.longestSpan();
    } catch (const std::exception& e) {
        std::cout << "Expected exception (longestSpan): " << e.what() << std::endl;
    }

    // Test 4: Large span with addManyNumbers
    Span sp3(10000);
    sp3.addManyNumbers(10000);
    std::cout << "Large Span - ShortestSpan: " << sp3.shortestSpan() << std::endl;
    std::cout << "Large Span - LongestSpan: " << sp3.longestSpan() << std::endl;

    return 0;
}
