/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class_in_class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 02:13:21 by aaitoual          #+#    #+#             */
/*   Updated: 2022/10/20 02:23:19 by aaitoual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

class base {
    public :
    	class derive {
    	    public :
    	    void    print (void) {
    	        std::cout << value << std::endl;
    	    }
    	};
		base (int i) : value(i) {};
	friend void	derive::print();
    protected :
    int value;
};

int main () {
    base::derive test;

    test.print();    
}