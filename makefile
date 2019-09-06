CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = menu.o game.o space.o normalSpace.o pokemonSpace.o itemSpace.o

SRCS = menu.cpp game.cpp space.cpp normalSpace.cpp pokemonSpace.cpp itemSpace.cpp

HEADERS = menu.hpp game.hpp space.hpp normalSpace.hpp pokemonSpace.hpp itemSpace.hpp

OUTPUT_FILES = prog menu_test

all: prog

prog: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} main.cpp -o prog

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

menu_test: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} menu_test.cpp -o menu_test
	./menu_test

test: menu_test

clean:
	# -f option allows rm to ignore files that don't exist.
	rm -f *.o ${OUTPUT_FILES}
