CXX = 		g++
LD = 			g++
LDFLAGS = 	-lsfml-graphics -lsfml-window -lsfml-system

SRC =		main.cpp 

OBJ = 	$(SRC:.c=.o)	


BIN = 	DiesIrae

OBJ = 	$(SRC:.cpp=.o)
DEP = 	$(SRC:.cpp=.d)

%.o: %.cpp
	$(CXX) -g -o $@ -c $<

%.d: %.cpp
	$(CXX) $< -MM -o $@

all: $(BIN)

$(BIN): $(OBJ)
	$(LD) $(LDFLAGS) -o $@ $+

clean:
	@rm *.o *.d

-include $(DEP)