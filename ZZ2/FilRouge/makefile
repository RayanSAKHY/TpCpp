# utilise le compilo par defaut de la machine
#CXX=g++-12
SRC=Cercle.cpp Rectangle.cpp Groupe.cpp Point.cpp Forme.cpp Couleur.cpp
SRCTEST= test_catch.cpp
#SRC=$(wildcard *.cpp)
EXE=filerouge
EXETEST=filerouge_test

CXXFLAGS+=-Wall -Wextra -MMD -g -fdiagnostics-color=auto -Werror
LDFLAGS= #-lSDL

OBJ=$(addprefix build/,$(SRC:.cpp=.o))
OBJTEST=$(addprefix build/,$(SRCTEST:.cpp=.o))
DEP=$(addprefix build/,$(SRC:.cpp=.d))

all: main test

main: $(OBJ) build/main.o
	$(CXX) -o $(EXE) $^ $(LDFLAGS) && ./filerouge

test: $(OBJ) build/main_catch.o $(SRCTEST)
	$(CXX) -o $(EXETEST) $^ $(LDFLAGS) && ./filerouge_test

build/%.o: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf build core *.gch

catch.hpp:
	wget https://raw.githubusercontent.com/catchorg/Catch2/v2.x/single_include/catch2/catch.hpp

-include $(DEP)