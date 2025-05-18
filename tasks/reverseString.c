#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main() {
    char str[100];
    printf("Enter string to reverse: ");
    scanf(" %[^\n]", str);

    int len = strlen(str);
    for(int i=0; i<len/2; i++) {
        char temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
    printf("Reversed: %s\n", str);
    sleep(2);
    return 0;
}
