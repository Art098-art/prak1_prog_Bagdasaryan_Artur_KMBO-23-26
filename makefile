CC      = gcc
CFLAGS  = -std=c99 -Wall -Wextra -Wpedantic -g
TARGET  = cmdcalculate
SRCS    = maincalc.c calc.c decoder.c errors.c
OBJS    = $(SRCS:.c=.o)
HEADERS = calc.h decoder.h errors.h

# Входные данные для `make run` (программа читает их из стандартного ввода).
# Можно заменить: make run INPUT="1 + 2 -k 0"
INPUT   = 41 + 33 111 - 8 22 '*' 5 221 % 111 100 + 13 -k 2

.PHONY: all run clean

all: $(TARGET)

# Линковка: пересобирается, если изменился хотя бы один .o
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Компиляция: каждый .o зависит от своего .c и от всех заголовков
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	echo "$(INPUT)" | ./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
