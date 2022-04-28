all: clean compile run

compile: main.c
	@echo "----------------COMPILING----------------"
	@gcc main.c -lm
run:
	@./a.out
clean:
	@rm -f temp.txt
	@rm -f *.o
	@rm -f *.out
