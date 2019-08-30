CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o menu.o game.o space.o normalSpace.o pokemonSpace.o itemSpace.o

SRCS = main.cpp menu.cpp game.cpp space.cpp normalSpace.cpp pokemonSpace.cpp itemSpace.cpp

HEADERS = menu.hpp game.hpp space.hpp normalSpace.hpp pokemonSpace.hpp itemSpace.hpp

all: prog

prog: ${OBJS}
	${CXX} ${CXXFLAGS} ${OBJS} -o prog

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o prog
