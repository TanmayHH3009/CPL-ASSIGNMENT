all: driver.o symbolTable.o
	gcc driver.o symbolTable.o -o out

driver.o: driver.c
	gcc -c driver.c

symbolTable.o: symbolTable.c
	gcc -c symbolTable.c

clean:
	rm -f driver.o symbolTable.o out
