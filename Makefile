TARGET = hybrid-benchmark

CC = gcc
CFLAGS = -Wall -Wextra -O2 
# Nota: -O2 otimiza o código. Se quiser debug puro, use -g
# Para benchmark real, -O2 é mais justo com a capacidade da máquina

LIBS = -lm

SRCS = main.c sorts.c utils.c

all:
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LIBS)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET) *.o