#include <stdio.h>
#include <stdlib.h>

int main() {
    float num1, num2;
    char op;
    printf("Calculator [Enter q to quit]\n");
    while(1) {
        printf("Enter operation (e.g. 5 + 3): ");
        if(scanf("%f %c %f", &num1, &op, &num2) != 3) break;

        switch(op) {
            case '+': printf("= %.2f\n", num1 + num2); break;
            case '-': printf("= %.2f\n", num1 - num2); break;
            case '*': printf("= %.2f\n", num1 * num2); break;
            case '/':
                if(num2 == 0) printf("Error: Division by zero!\n");
                else printf("= %.2f\n", num1 / num2);
                break;
            default: printf("Invalid operator!\n");
        }
        while(getchar() != '\n'); // Clear input buffer
    }
    return 0;
}
