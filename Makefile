# Nome do executável final
TARGET = hybrid-benchmark

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Arquivos fontes
SRCS = main.c sorts.c utils.c

# Regra padrão (o que acontece quando digita 'make')
all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Regra para rodar
run: all
	./$(TARGET)

# Regra para limpar arquivos compilados (útil antes de enviar pro git)
clean:
	rm -f $(TARGET) *.o