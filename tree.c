/* creat a binary tree */
/* traversal in inorder,preorder,postorder */
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TNod {
    char ic[11];
    int ii;
    struct TNod *dr, *st;
};

struct TNod* tnt = NULL;

void inserare(struct TNod**, char*, int);
void afisare(void);
void preordine(struct TNod*);
void postordine(struct TNod*);
void inordine(struct TNod*);
void afisare_info(struct TNod*);

// Helper function to clear the input buffer
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Consume leftover chars
}

int main() {
    char c;
    char str[11];
    int i;

    do {
        printf("\nI)nsert, S)how, F)inish: ");
        scanf(" %c", &c);  // Space before %c skips whitespace
        c = toupper(c);

        switch (c) {
            case 'I':
                printf("String: ");
                scanf("%10s", str);
                clear_input_buffer(); // Clear any extra input (like \n)
                printf("Number: ");
                scanf("%d", &i);
                clear_input_buffer(); // Clear again after reading the number
                inserare(&tnt, str, i);
                break;
            case 'S':
                afisare();
                break;
            case 'F':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Try again.\n");
        }
    } while (c != 'F');
    return 0;
}

void inserare(struct TNod** n, char* pc, int i) {
    if (*n == NULL) {
        *n = (struct TNod*)malloc(sizeof(struct TNod));
        strcpy((*n)->ic, pc);
        (*n)->ii = i;
        (*n)->dr = NULL;
        (*n)->st = NULL;
    } else {
        int t = strcmp(pc, (*n)->ic);
        if (t > 0)
            inserare(&((*n)->dr), pc, i);
        else
            inserare(&((*n)->st), pc, i);
    }
}

void afisare(void) {
    printf("\nPREORDER:\n");
    preordine(tnt);
    printf("\nINORDER:\n");
    inordine(tnt);
    printf("\nPOSTORDER:\n");
    postordine(tnt);
}

void preordine(struct TNod* n) {
    if (!n) return;
    afisare_info(n);
    preordine(n->st);
    preordine(n->dr);
}

void postordine(struct TNod* n) {
    if (!n) return;
    postordine(n->st);
    postordine(n->dr);
    afisare_info(n);
}

void inordine(struct TNod* n) {
    if (!n) return;
    inordine(n->st);
    afisare_info(n);
    inordine(n->dr);
}

void afisare_info(struct TNod* n) {
    printf("String: %s\nNumber: %d\n", n->ic, n->ii);
}
