echo >Makefile "NAME= $1"
echo >>Makefile "SRC= $1.cpp"
echo >>Makefile 'CC= c++'
echo >>Makefile 'FLAG= -g -Wall -Wextra -Werror -std=c++98'
echo >>Makefile
echo -e >>Makefile 'all:\t$(NAME)'
echo >>Makefile

echo -e >>Makefile '$(NAME):	$(SRC)'
echo -e >>Makefile '	$(CC) $(FLAG) -o $@ $^'

echo >>Makefile
echo -e >>Makefile 'clean:'
echo >>Makefile

echo -e >>Makefile 'fclean: clean'
echo -e >>Makefile '	rm -rf $(NAME)'
echo >>Makefile

echo -e >>Makefile 're: fclean all'
echo >>Makefile

echo -e >>Makefile '.PHONY: all clean fclean re test'
