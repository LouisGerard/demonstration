CC = g++
CFLAGS = -Wall
EXEC_NAME = modal
INCLUDES = main.cpp infix2postfix.cpp Arbre.cpp Regle.cpp Monde.cpp k.cpp MondeContrainte.cpp

all : $(EXEC_NAME)

clean :
	rm $(EXEC_NAME)

$(EXEC_NAME) :
	$(CC) -o $(EXEC_NAME) $(CFLAGS) $(INCLUDES) -std=c++11
