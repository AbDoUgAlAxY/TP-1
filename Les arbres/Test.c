#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    struct tree_node* left;
    struct tree_node* right;
} tree_node;

tree_node* create_node(int value) {
    tree_node* new_node = malloc(sizeof(tree_node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
int main() {
    tree_node* n1 = create_node(10);
    tree_node* n2 = create_node(11);
    tree_node* n3 = create_node(12);
    tree_node* n4 = create_node(13);

    printf("Node 1 value: %d\n", n1->value);
    printf("Node 2 value: %d\n", n2->value);
    printf("Node 3 value: %d\n", n3->value);
    printf("Node 4 value: %d\n", n4->value);
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    return 0;
}