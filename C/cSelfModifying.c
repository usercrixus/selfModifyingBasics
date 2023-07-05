#include <stdio.h>
#include <stdint.h>

#define SECTION_ENCRYPTED __attribute__((section(".encrypted")))

extern char _start_encrypted[];
extern char _end_encrypted[];

SECTION_ENCRYPTED void test() {
    printf("This is the 'test' function in the 'encrypted' section.\n");
}

void decrypt() {
    uint8_t key = 0xAA;
    printf("%p, %p\n", (void*)_start_encrypted, (void*)_end_encrypted);
    char* ptr = _start_encrypted;
    while (ptr != _end_encrypted) {
        *ptr ^= key;
        ptr++;
    }
}

int main() {
    printf("This is the 'main' function in the '.text' section.\n");
    decrypt();
    test();
    return 0;
}
