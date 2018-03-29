CC = g++
CFLAGS = -Wall
EXEC_NAME = modal
INCLUDES = main.cpp infix2postfix.cpp infix2postfix.h Arbre.cpp Arbre.h Regle.cpp Regle.h Monde.cpp Monde.h k.cpp k.h MondeContrainte.cpp MondeContrainte.h

all : $(EXEC_NAME)

clean :
	rm $(EXEC_NAME)

$(EXEC_NAME) :
	$(CC) -o $(EXEC_NAME) $(CFLAGS) $(INCLUDES) -std=c++11
