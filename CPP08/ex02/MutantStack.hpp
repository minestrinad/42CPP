/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:52:30 by everonel          #+#    #+#             */
/*   Updated: 2024/02/01 16:32:20 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <deque>
# include <stack>

template<class T, class Container = std::deque<T> >
class MutantStack {
    protected:
        Container C;

    public:
        // Member Functions:
        MutantStack( ) : C(std::deque<T>()){ }

        MutantStack( const MutantStack &src ){ *this = src; };

        MutantStack& operator=(const MutantStack& src) {
            if (this != &src)
                C = src.C;
            return *this;
        }

        T& top() { return C.front(); }

        bool empty() { return C.empty(); }

        int size() { return C.size(); }

        void push(T elem) { C.push_front(elem); }

        void pop( ) { C.pop_front( ); }

        typedef typename Container::iterator iterator;
        iterator begin( ) { return C.begin( ); }
        iterator end( ) { return C.end( ); }

        typedef typename Container::reverse_iterator reverse_iterator;
        reverse_iterator rbegin( ) { return C.rbegin( ); }
        reverse_iterator rend( ) { return C.rend( ); }
};

#endif
