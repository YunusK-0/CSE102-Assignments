all: clean compile run


compile:main.c util.h util.c
	@echo "Compiling..."
	@gcc main.c util.c -o main.out
run:
	@echo "compile is done"
	@echo "./main.out is running"
	./main.out
clean:
	@clear
	@rm -f *.out
