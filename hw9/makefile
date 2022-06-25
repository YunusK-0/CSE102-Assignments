all: clean compile run

compile: main.c
	@echo "compiling..."
	@gcc main.c -c
	@gcc main.o -o  main.out
run:
	@echo ---------------------------
	@./main.out
clean:
	@echo ---------------------------
	@clear
	@rm -f *.o

