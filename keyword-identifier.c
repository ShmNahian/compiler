#include <stdio.h>
#include <ctype.h>
#include <string.h>

char *keywords[4] = {"int", "float", "char", "double"};

int isKeyword(char *word) {
    for (int i = 0; i < 4; i++) {
        if (strcmp(word, keywords[i]))
            return 1;
    }
    return 0;
}

void scanFile(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char ch, word[100];
    int index = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch) || ch == '_')
            word[index++] = ch;
        else {
            if (index > 0) {
                word[index] = '\0';
                if (isKeyword(word))
                    printf("Keyword: %s\n", word);
                else
                    printf("Identifier: %s\n", word);
                index = 0;
            }
        }
    }

    fclose(file);
}

int main() {
    scanFile("input.txt");
    return 0;
}
