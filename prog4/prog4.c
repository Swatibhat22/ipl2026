#include <stdio.h>

// Define a structure with bitfields
struct Bitfield {
    unsigned int firstbit  : 1;  // 1 bit (values 0–1)
    unsigned int secondbit : 2;  // 2 bits (values 0–3)
    unsigned int thirdbit  : 5;  // 5 bits (values 0–31)
};

int main() {
    struct Bitfield a;

    // Assign values to bitfields
    a.firstbit = 1;   // fits in 1 bit
    a.secondbit = 3;  // fits in 2 bits
    a.thirdbit = 17;  // fits in 5 bits

    // Print values
    printf("firstbit  = %u\n", a.firstbit);
    printf("secondbit = %u\n", a.secondbit);
    printf("thirdbit  = %u\n", a.thirdbit);

    return 0;
}
