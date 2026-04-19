#include <stdio.h>
#include <string.h>
#include <stdint.h>

void set(uint8_t *word, uint8_t n){
    *word = *word | (1u << n); 
}

void clear(uint8_t *word, uint8_t n){
    *word = *word & ~(1u << n);
}

void toggle(uint8_t *word, uint8_t n){
    *word = *word ^ (1u << n);
}

int8_t read(uint8_t *word, uint8_t n){
    return ((*word >> n) & 1u);
}

void print_binary(uint8_t byte) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (byte >> i) & 1);
    }
    printf("\n");
}


int main()
{
    uint8_t x = 0b00000011;
    uint8_t y = 0b00000001;
    print_binary(x + y);

    uint8_t *x1 = &x;
    printf("%d \n",*x1);
    printf("%p \n",x1);
    *x1 = 6;
    printf("%d",x);
    return 0;
}