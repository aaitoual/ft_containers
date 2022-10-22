/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:53:54 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/20 01:31:06 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <vector>
# include <iterator>

template<long FROM, long TO>
class Range {
public:
    // member typedefs provided through inheriting from std::iterator
    class iterator: public std::iterator<
                        std::input_iterator_tag,   // iterator_category
                        long,                      // value_type
                        const long*,               // pointer
                        long                       // reference
                                      >{
        long num = FROM;
    public:
        explicit iterator(long _num = 0) : num(_num) {}
        iterator& operator++() {num = TO >= FROM ? num + 1: num - 1; return *this;}
        iterator operator++(int) {iterator retval = *this; ++(*this); return retval;}
        bool operator==(iterator other) const {return num == other.num;}
        bool operator!=(iterator other) const {return !(*this == other);}
        reference operator*() const {return num;}
    };
    iterator begin() {return iterator(FROM);}
    iterator end() {return iterator(TO >= FROM? TO+1 : TO-1);}
};
 
int main() {
    // std::find requires an input iterator
    Range<15, 25> range;
    Range<15, 25>::iterator itr = std::find(range.begin(), range.end(), 18);
    std::cout << *itr << '\n'; // 18
 
    // Range::iterator also satisfies range-based for requirements
    // for(long l : Range<3, 5>()) {
    //     std::cout << l << ' '; // 3 4 5
    // }
    std::cout << '\n';
}