#include <stdio.h>

void printBits(unsigned int n);
int countOnes(unsigned int n);
void checkEndian();
void printNegativeInt(int n);
void printFloatBits(float f);
void printNegativeFloatBits(float f);

int main() {
    unsigned int num = 29;   // positive integer
    int negNum = -29;        // negative integer
    float fl = 5.75f;
    float negFl = -5.75f;

    printf("Bits of integer %u: ", num);
    printBits(num);

    printf("Number of 1 bits in %u: %d\n", num, countOnes(num));

    checkEndian();

    printf("Bits of negative integer %d: ", negNum);
    printNegativeInt(negNum);

    printf("Bits of float %.2f: ", fl);
    printFloatBits(fl);

    printf("Bits of negative float %.2f: ", negFl);
    printNegativeFloatBits(negFl);

    return 0;
}

void printBits(unsigned int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int countOnes(unsigned int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

void checkEndian() {
    unsigned int x = 0x12345678;
    unsigned char *p = (unsigned char*)&x;
    printf("Endian check: ");
    for (int i = 0; i < sizeof(x); i++) {
        printf("%02X ", p[i]);
    }
    printf("\n");
    if (p[0] == 0x78)
        printf("System is Little Endian\n");
    else
        printf("System is Big Endian\n");
}

void printNegativeInt(int n) {
    unsigned int u = (unsigned int)n; // reinterpret as unsigned
    printBits(u);
}

void printFloatBits(float f) {
    union {
        float f;
        unsigned int u;
    } val;
    val.f = f;
    printBits(val.u);
}

void printNegativeFloatBits(float f) {
    union {
        float f;
        unsigned int u;
    } val;
    val.f = f;
    printBits(val.u);
}
