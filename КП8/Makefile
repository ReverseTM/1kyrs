TARGET = run
CC = gcc
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))


$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o : %.c
	$(CC) -c $< -o $@
clean :
	del $(TARGET).exe *.o
