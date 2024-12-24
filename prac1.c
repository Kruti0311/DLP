#include <stdio.h>
#include <string.h>

int isValidString(char* str) {
    int len = strlen(str);

    if (len < 2 || str[len - 1] != 'b' || str[len - 2] != 'b') {
        return 0;
    }

    for (int i = 0; i < len - 2; i++) {
        if (str[i] != 'a') {
            return 0;
        }
    }

    return 1;
}

int main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        char s[100];
        printf("Enter string %d: ", i + 1);
        scanf("%s", s);

        if (isValidString(s)) {
            printf("Valid String\n");
        } else {
            printf("Invalid String\n");
        }
    }

    return 0;
}
