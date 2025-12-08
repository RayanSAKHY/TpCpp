 SRC = main.cpp A.cpp B.cpp

 EXE=main

 CXXFLAGS+=-Wall -Wextra -MMD -g -fdiagnostics-color=auto -Werror

 OBJ=$(addprefix build/,$(SRC:.cpp=.o))
 DEP=$(addprefix build/,$(SRC:.cpp=.d))

all: $(OBJ)
	g++ -o $(EXE) $^ $(LDFLAGS)

build/%.o: %.cpp
	@mkdir -p build
	g++ $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf build core *.gch