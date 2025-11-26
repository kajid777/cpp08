/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kajid777 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 00:00:00 by kajid777          #+#    #+#             */
/*   Updated: 2025/11/26 00:00:00 by kajid777         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _capacity(n), _values()
{
    _values.reserve(n);
}

Span::Span(const Span &other) : _capacity(other._capacity), _values(other._values)
{
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _capacity = other._capacity;
        _values = other._values;
    }
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int value)
{
    if (_values.size() >= _capacity)
        throw std::out_of_range("Span is full");
    _values.push_back(value);
}

unsigned int Span::shortestSpan() const
{
    if (_values.size() < 2)
        throw std::logic_error("Span needs at least two numbers");

    std::vector<int> sorted(_values);
    std::sort(sorted.begin(), sorted.end());

    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    for (std::vector<int>::size_type i = 1; i < sorted.size(); ++i)
    {
        unsigned int diff = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const
{
    if (_values.size() < 2)
        throw std::logic_error("Span needs at least two numbers");

    std::vector<int>::const_iterator minIt = std::min_element(_values.begin(), _values.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_values.begin(), _values.end());
    return static_cast<unsigned int>(*maxIt - *minIt);
}

unsigned int Span::size() const
{
    return static_cast<unsigned int>(_values.size());
}

unsigned int Span::capacity() const
{
    return _capacity;
}

