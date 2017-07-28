CFLAGS := -std=c99
ARCHIVOS = archivo.o ciudades.o
PROGRAMA = main

all: $(ARCHIVOS) $(PROGRAMA).o
	gcc -o $(PROGRAMA) $^ -lm
	./$(PROGRAMA)

%.o: %.c
	gcc -c $< -o $@ 

clean:
	rm -f $(PROGRAMA) *.o

.PHONY: clean


