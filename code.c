#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 6
#define COL 12
#define TOTAL_CHARS 3

enum letter_enum { _, B, __, D, E };

typedef struct letter_struct {
    char *line[ROW];
} letter_type;

letter_type chars[TOTAL_CHARS];

int init_letter(enum letter_enum letter) {
    int i;

    for (i = 0; i < ROW; i++) {
        chars[letter].line[i] = (char *)malloc(COL);
        if (chars[letter].line[i] == NULL) {
            printf("memory allocation failed \n");
            return 0;
        }
    }

    switch (letter) {
        case B:
            strcpy(chars[letter].line[0], "   _______ ");
            strcpy(chars[letter].line[1], "  /       \\");
            strcpy(chars[letter].line[2], " |       '_");
            strcpy(chars[letter].line[3], "  >      '_");
            strcpy(chars[letter].line[4], " |       '_");
            strcpy(chars[letter].line[5], "  \\_______/");
            break;
        case D:
            strcpy(chars[letter].line[0], " _______  ");
            strcpy(chars[letter].line[1], "|       \\ ");
            strcpy(chars[letter].line[2], "         |");
            strcpy(chars[letter].line[3], "        - ");
            strcpy(chars[letter].line[4], "         |");
            strcpy(chars[letter].line[5], "|_______/ ");
            break;
        case E:
            strcpy(chars[letter].line[0], "           ");
            strcpy(chars[letter].line[1], "___________");
            strcpy(chars[letter].line[2], "           ");
            strcpy(chars[letter].line[3], "           ");
            strcpy(chars[letter].line[4], "___________");
            strcpy(chars[letter].line[5], "           ");
            break;
        case _:
        case __:
            break;
    }

    return 0;
}

int print_str(char word[]) {
    int i, j;

    printf("\n");
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < strlen(word); j++) {
            printf("%s", chars[word[j] % 'A'].line[i]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}

int main(void) {
    init_letter(B);
    init_letter(D);
    init_letter(E);

    int junk_size, Es_to_add;

    printf("Your junk size (in inches): ");
    scanf("%d", &junk_size);

    if (!(junk_size > 0)) {
        printf("Your junk is weird!\n");
        return 1;
    } else if (junk_size > 26) {
        printf("Error: Junk too big! Failing to visualize...\n");
        return 1;
    }

    Es_to_add = (junk_size / 2) - 1;
    int word_length = 1 + Es_to_add + 1 + 1; // "B" + "E"s + "D" + null terminator

    char *word = (char *)malloc(word_length);
    if (word == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    strcpy(word, "B");
    for (int i = 0; i < Es_to_add; i++) {
        if (strlen(word) < word_length - 1) {
            strcat(word, "E");
        } else {
            break;
        }
    }
    strcat(word, "D");

    printf("BEHOLD! YOUR JUNK:");
    print_str(word);

    for (int i = 0; i < TOTAL_CHARS; i++) {
        for (int j = 0; j < ROW; j++) {
            free(chars[i].line[j]);
        }
    }
    free(word);

    return 0;
}
