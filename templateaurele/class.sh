echo -n > "$1.class.hpp" "#ifndef "
echo >> "$1.class.hpp" $1_CLASS_H | tr '[:lower:]' '[:upper:]'
echo -n >> "$1.class.hpp" "# define "
echo >> "$1.class.hpp" $1_CLASS_H | tr '[:lower:]' '[:upper:]'
echo >> "$1.class.hpp"
echo >> "$1.class.hpp"
echo >> "$1.class.hpp" "classe $1"
echo >> "$1.class.hpp" "{"
echo >> "$1.class.hpp"
echo >> "$1.class.hpp" "public:"
echo >> "$1.class.hpp"
echo >> "$1.class.hpp" "$1( void )"
echo >> "$1.class.hpp" "~$1( void )"
echo >> "$1.class.hpp"
echo >> "$1.class.hpp" "};"
echo >> "$1.class.hpp"
echo >> "$1.class.hpp"
echo >> "$1.class.hpp" "#endif"

echo  > "$1.class.cpp" "#include <iostrean>"
echo  >> "$1.class.cpp" "#include $1.class.hpp"
echo >> "$1.class.cpp"
echo >> "$1.class.cpp"
echo >> "$1.class.cpp" "$1::$1( void )"
echo >> "$1.class.cpp" "{"
echo >> "$1.class.cpp"
echo >> "$1.class.cpp" "std::cout << Constructor Called << std::endl"
echo >> "$1.class.cpp" "return;"
echo >> "$1.class.cpp"
echo >> "$1.class.cpp" "}"
echo >> "$1.class.cpp"
echo >> "$1.class.cpp"
echo >> "$1.class.cpp" "$1::~$1( void )"
echo >> "$1.class.cpp" "{"
echo >> "$1.class.cpp"
echo >> "$1.class.cpp" "std::cout << \"Destructor Called\" << std::endl"
echo >> "$1.class.cpp" "return;"
echo >> "$1.class.cpp"
echo >> "$1.class.cpp" "}"
