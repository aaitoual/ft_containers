/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 05:05:06 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/23 05:24:26 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <type_traits>

int main() {
    std::cout << (std::enable_if<true, int>::type * = NULL);
}