# suffix rules don't allow pre-requisites to be used and are deprecated for
# this reason.  The right way to do this is to use patterns.  The "%" pattern
# allows any file to be matched.
OBJS = main.o Returns.o Label.o Popscal.o Pushscal.o Poparr.o Pusharr.o Gosub.o Gosublabel.o Jump.o Pop.o JumpZero.o JumpNZero.o Add.o Line.o InstructionBuffer.o Stmt.o Start.o Exit.o Pushi.o Prints.o Div.o Dup.o Mul.o Negate.o SymbolTable.o
CC = g++
INCLUDE = 
LIBS = 
CFLAGS = -Wall -g 
EXECUTABLE = comp
COMMANDLINE = 

.PHONY : run
run : $(EXECUTABLE)
	./$(EXECUTABLE) $(COMMANDLINE)

cleanmake : clean main

.PHONY : $(EXECUTABLE)
$(EXECUTABLE) :  $(OBJS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJS) $(INCLUDE) $(LIBS)

%.o : %.c 
	$(CC) $(CFLAGS) -c $@ $(INCLUDE) $(LIBS)

clean :
	rm $(EXECUTABLE) ${OBJS} 
