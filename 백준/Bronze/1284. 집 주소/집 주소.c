#include <stdio.h>

int main() {
    int n;
    int size;

    while (scanf("%d", &n) != EOF && n != 0){
        size = 0;
        while (n > 0){
            int digit = n % 10;
            if (digit == 0)
                size += 5;
            else if (digit == 1)
                size += 3;
            else
                size += 4;
            n /= 10;
        }
        printf("%d\n", size+1);
    }
}
