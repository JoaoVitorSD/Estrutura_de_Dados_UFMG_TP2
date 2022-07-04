CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/tp2.o $(OBJ)/lexicographical.o  $(OBJ)/word.o $(OBJ)/wordCell.o $(OBJ)/list.o
HDRS = $(INC)/lexicographical.h $(INC)/word.h $(INC)/wordCell.h $(INC)/list.h 
CFLAGS = -Wall -c -I$(INC)
INP = input

EXE = $(BIN)/tp2.exe
all: $(EXE)
	$(EXE) < $(SRC)/entrada.txt > $(SRC)/saida.txt;\


$(BIN)/tp2.exe: $(OBJS)
	$(CC) -pg -o $(BIN)/tp2.exe $(OBJS) $(LIBS)

$(OBJ)/tp2.o: $(HDRS) $(SRC)/tp2.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/tp2.o $(SRC)/tp2.cpp

$(OBJ)/lexicographical.o: $(HDRS) $(SRC)/lexicographical.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/lexicographical.o $(SRC)/lexicographical.cpp

$(OBJ)/word.o: $(HDRS) $(SRC)/word.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/word.o $(SRC)/word.cpp
	
$(OBJ)/wordCell.o: $(HDRS) $(SRC)/wordCell.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/wordCell.o $(SRC)/wordCell.cpp

$(OBJ)/list.o: $(HDRS) $(SRC)/list.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/list.o $(SRC)/list.cpp

clean:
	rm -f $(EXE) $(OBJS)