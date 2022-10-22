/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 21:41:16 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/20 19:55:01 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <vector>
# include <string>
# include <iostream>
# include <exception>

int main () {
    std::vector<int> test;
    std::vector<int>::iterator it;
    // test.push_back (1);
    // it = test.begin();
    // std::cout << test[0] << std::endl;
    // std::cout << *it << std::endl;
    // test[0] = 10;
    // std::cout << test[0] << std::endl;
    try {
        std::cout << *it << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what();
        puts ("yppp");
    }
}