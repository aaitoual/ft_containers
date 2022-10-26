# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaitoual <aaitoual@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 20:56:55 by aaitoual          #+#    #+#              #
#    Updated: 2022/10/26 12:18:41 by aaitoual         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

CC = c++

CFLAGS = -std=c++98

OBJ_PATH = ./__Obj_Tmp_Fils/

VECTOR_EXCEP_ = __exceptions.cpp

VECTOR_HEADERS = ./vector/vector.hpp ./vector/iterators/__vec_iterator.hpp

SRC = main.cpp __exceptions.cpp vector.cpp

OBJ = $(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))


################################VECTOR############################
$(OBJ_PATH)%.o : %.cpp containers.hpp
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_PATH)%.o : ./vector/exceptions/%.cpp ./vector/exceptions/__exceptions.hpp
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJ_PATH)%.o : ./vector/%.cpp  ./vector/vector.hpp
	@$(CC) $(CFLAGS) -o $@ -c $<

##################################################################

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all