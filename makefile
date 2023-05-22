CC = gcc
CFLAGS = -fopenmp
TARGET = primosNaive
NUM_RUNS = 5

.PHONY: all run clean

all: $(TARGET)

$(TARGET): primosNaive.c
   $(CC) $(CFLAGS) -o $@ $< -lm

run: $(TARGET)
    @for i in $$(seq $(NUM_RUNS)); do \
        echo "Running $$i..."; \
        ./$(TARGET); \
        echo; \
    done

clean:
    rm -f $(TARGET)

# CC: the C compiler (gcc in this case)
# CFLAGS: compiler flags (e.g., -Wall -Wextra)
# TARGET: the name of the output executable
# NUM_RUNS: the number of times the program should be executed