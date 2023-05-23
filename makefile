CC = gcc
CFLAGS = -fopenmp
TARGET = primoNaive
SOURCES = Naive/primosNaive.c
OBJECTS = $(SOURCES:.c=.o)
NUM_RUNS = 5

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $^ $(CFLAGS) -o $@ -lm  

run: $(TARGET)
	for i in $$(seq $(NUM_RUNS)); do \
		./$(TARGET); \
	done

clean:
	rm -f $(OBJECTS) $(TARGET)
