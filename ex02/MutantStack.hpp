/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kajid777 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 00:00:00 by kajid777          #+#    #+#             */
/*   Updated: 2025/11/26 00:00:00 by kajid777         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack() : std::stack<T>() {}
    MutantStack(const MutantStack &other) : std::stack<T>(other) {}
    MutantStack &operator=(const MutantStack &other)
    {
        std::stack<T>::operator=(other);
        return *this;
    }
    ~MutantStack() {}

    typename std::deque<T>::iterator begin() { return this->c.begin(); }
    typename std::deque<T>::iterator end() { return this->c.end(); }

    typename std::deque<T>::const_iterator begin() const { return this->c.begin(); }
    typename std::deque<T>::const_iterator end() const { return this->c.end(); }
};

#endif // MUTANTSTACK_HPP

