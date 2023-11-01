/*
    Implementation of Tree using Array
*/

#include <stdio.h>

char tree[10];

int root(char key) {
    if (tree[0] != '\0') {
        printf("Root Exists\n");
    } else {
        tree[0] = key;
        printf("Root Created\n");
    }
}

void setLeft(char key, int parent) {
    if (tree[parent] == '\0') {
        printf("No Parent Found\n");
    } else {
        tree[(parent*2)+1] = key;
        printf("Left Child Set at %d\n", (parent*2)+1);
    }
}

void setRight(char key, int parent) {
    if (tree[parent] == '\0') {
        printf("No Parent Found\n");
    } else {
        tree[(parent*2)+2] = key;
        printf("Right Child Set at %d\n", (parent*2)+2);
    }
}

void print() {
    for (int i = 0; i< 10; i++) {
        if (tree[i] != '\0') {
            printf("%c", tree[i]);
        } else {
            printf("-");
        }
    }
}

int main() {
    root('A');
    setLeft('B', 0);
    setRight('C', 0);
    setLeft('D', 1);
    setRight('E', 1);
    setRight('F', 2);
    print();
    return 0;
}
