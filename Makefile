# the compiler: gcc for C program
CC = gcc

# compiler flags:
CFLAGS  = -lreadline

# the build target executable:
TARGET = main
LIBRARY = config.h execinstr.h execinstr.c hashtable.c hashtable.h instr.c instr.h list.c list.h parse.c parse.h  utils.c utils.h 

#all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(LIBRARY) -o $(TARGET) $(TARGET).c $(CFLAGS)

clean:
	$(RM) $(TARGET)
	$(RM) config.h.gch execinstr.h.gch hashtable.h.gch instr.h.gch list.h.gch parse.h.gch utils.h.gch 
