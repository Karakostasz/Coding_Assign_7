
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <memory_size_in_MB>\n", argv[0]);
        return 1;
    }
    int memory_size_MB = atoi(argv[1]);// make the command-line arg to an int of MB
    size_t memory_size_bytes = (size_t)memory_size_MB * 1024 * 1024;// no# of bytes to allocate
    char *memory_block = (char *)malloc(memory_size_bytes);// Allocating memory

    if (memory_block == NULL) {
        perror("Memory allocation failed");
        return 1;
    }
    printf("pid: %d\n", getpid()); 
    printf("Allocated %d MB of memory.\n", memory_size_MB);

    while (1) {// Constantly stream theought &  access memory
        for (size_t i = 0; i < memory_size_bytes; i++) {
            memory_block[i] = 0; // Touch each every entry
        }
    }

    //free the allocated memory
    free(memory_block);

    return 0;
}
