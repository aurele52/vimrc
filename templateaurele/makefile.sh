echo >Makefile "NAME= $1"
echo >>Makefile "SRC=	main.cpp"
echo >>Makefile 'CC= c++'
echo >>Makefile 'FLAG= -g -Wall -Wextra -Werror -std=c++98'
echo >>Makefile
echo >>Makefile 'all:	$(NAME)'
echo >>Makefile

echo >>Makefile '$(NAME):	$(SRC)'
echo >>Makefile '	$(CC) $(FLAG) -o $@ $^'

echo >>Makefile
echo >>Makefile 'clean:'
echo >>Makefile

echo >>Makefile 'fclean:	clean'
echo >>Makefile '	rm -rf $(NAME)'
echo >>Makefile

echo >>Makefile 're:	fclean all'
echo >>Makefile

echo >>Makefile '.PHONY: all clean fclean re test'

echo >main.hpp "#ifndef MAIN_H"
echo >>main.hpp	"# define MAIN_H"
echo >>main.hpp
echo >>main.hpp "#include <string>"
echo >>main.hpp "#include <iostream>"
echo >>main.hpp
echo >>main.hpp "#endif"

echo >main.cpp "#include \"main.hpp\""
echo >>main.cpp ""
echo >>main.cpp "int	main()"
echo >>main.cpp "{"
echo >>main.cpp 
echo >>main.cpp "}"
