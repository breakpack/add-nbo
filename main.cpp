#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>

uint32_t fileread(const char *filename) {
    FILE *file = fopen(filename, "rb");

    uint32_t num;
    if (fread(&num, sizeof(uint32_t), 1, file) != 1) {
        perror("File Read Error");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fclose(file);

    return ntohl(num);
}

int main(int argc, char *argv[]) {
    
    uint32_t num1 = fileread(argv[1]);
    uint32_t num2 = fileread(argv[2]);

    uint32_t sum = num1 + num2;

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, sum, sum);

    return EXIT_SUCCESS;
}

