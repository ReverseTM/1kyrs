#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct tree
{
    int key;
    struct tree *left;
    struct tree *right;
} *Tree;

/*int is_digit(char c) {
    return (c >= '0' && c <= '9');
}*/

Tree *tree_create(int key)
{
    Tree tree = (Tree) malloc(sizeof(Tree));
    if(!tree) {
        fprintf(stderr, "%s\n", "Error: no memory");
        exit(1);
    }
    tree -> key = key;
    tree -> left = NULL;
    tree -> right = NULL;

    return tree;
}

Tree *tree_find(Tree root, int key) {
    if (!root) {
        return NULL;
    }

    if (root -> key == key) {
        return root;
    }

    Tree *result = NULL;

    if (root -> left) {
        result = tree_find(root -> left, key);
        if (result) return result;
    }

    if (root -> right) {
        result = tree_find(root -> right, key);
        if (result) return result;
    }
}

/*void tree_add_node(Tree root, int parent, int key) {
    Tree parent_node = tree_find(root, parent);
    if (parent_node) {
        if (!parent_node -> left) {
            parent_node -> left = tree_create(key);
        } else {
            parent_node -> right = tree_create(key);
        }
    } else {
        printf("The specified parent vertex was not found.\n");
    }
}
*/
void print(Tree root, int level)
{
    if (root -> left) {
        print(root -> left, level + 1);
    }
    for (int i = 0; i < level; i++) {
        printf(" ");
    }
    printf("%d\n", root -> key);
    if (root -> right) {
        print(root -> right, level + 1);
    }
}

void tree_destroy(Tree root)
{

    if (root -> left) {
        tree_destroy(root -> left);
    }
    if (root -> right) {
        tree_destroy(root -> right);
    }
    free(root);
    root = NULL;
}

void tree_delete_node(Tree root, int value)
{
    if (root -> left) {
        if (root -> left -> key == value) {
            Tree tmp = root -> left;
            root -> left = root -> left -> right;
            if (tmp -> left) {
                tree_destroy(tmp -> left);
            }
            free(tmp);
            tmp = NULL;
            return;
        } else {
            tree_delete_node(root -> left, value);
        }
    }


    if (root -> right) {
        if (root -> right -> key == value) {
            Tree tmp = root -> right;
            root -> right = root -> right -> right;
            if (tmp -> left) {
                tree_destroy(tmp -> left);
            }
            free(tmp);
            tmp = NULL;
            return;
        } else {
            tree_delete_node(root -> right, value);
        }
    }
}

bool check_symmetrical(Tree left, Tree right) {
    if (left == NULL && right == NULL)
        return true;
    if (left == NULL || right == NULL)
        return false;
    return left -> key == right -> key
           && check_symmetrical(left -> left, right -> right)
           && check_symmetrical(left -> right, right -> left);
}

bool symmetrical(Tree root) {
    if (root == NULL)
        return true;
    return check_symmetrical(root -> left, root -> right);
}

/*void add_node(Tree root) {
    Tree tmp = root;

    int key = 0;

    char *string;

    size_t size = 10;

    string = (char*) malloc (size);

    char **string_ptr = &string;

    size_t characters = getline(string_ptr, &size, stdin);

    for (int i = 0; string[i] != '\0'; i++) {
        if (is_digit(string[i])) {
            key = key * 10 + (string[i] - '0');
        }
    }

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == 'l') {
            if (!tmp -> left) {
                tmp -> left = tree_create(key);
            } else {
                tmp = tmp -> left;
            }
        }
        if (string[i] == 'r') {
            if (!tmp -> right) {
                tmp -> right = tree_create(key);
            } else {
                tmp = tmp -> right;
            }
        }
    }
    printf("A vertex has been added.\n");
}*/

void add_node(Tree root, int key) {

    typedef enum {
        left, right, nothing
    } Way;

    Way way = nothing;

    Tree tmp = root;

    char symbol = ' ';

    printf("Enter the path where to insert the vertex (l - is the left node, r - is the right node):\n");
    while (symbol != '-') {
        switch (way) {
            case nothing:
                symbol = getchar();

                if (symbol == 'l') {
                    way = left;
                }
                if (symbol == 'r') {
                    way = right;
                }
                break;
            case left:
                if (!tmp -> left) {
                    tmp -> left = tree_create(key);
                } else {
                    tmp = tmp -> left;
                }
                way = nothing;
                break;
            case right:
                if (!tmp -> right) {
                    tmp -> right = tree_create(key);
                } else {
                    tmp = tmp -> right;
                }
                way = nothing;
                break;
        }
    }
    printf("A vertex has been added.\n");
}

int main(int argc, char **argv) {
    Tree tree = NULL;

    char command[8];
    int key = 0;

    printf("\n\nThe 'create' command creates the root of the tree.\n\n");
    printf("The 'insert' command add vertices to the tree.\n\n");
    printf("The 'delete' command delete the vertex and all its children.\n\n");
    printf("The 'destroy' command delete the entire tree.\n\n");
    printf("The 'print' command print the tree vertices.\n\n");
    printf("The 'run' command checks whether the tree is symmetrical.\n\n");
    printf("The command 'quit' terminate the program.\n\n");
    printf("Enter the command:\n");

    while (1) {
        scanf("%8s", command);
        if (!strcmp(command, "create")) {
            if (!tree) {
                printf("Enter the value of the tree root:\n");
                scanf("%d", &key);
                tree = tree_create(key);
                if (tree) printf("The tree was successfully created.\n");
            } else {
                printf("The tree has already been created.\n");
            }
        } else if (!strcmp(command, "insert")) {
            if (!tree) {
                printf("Before adding vertices, create a tree.\n");
            } else {
                printf("Enter the new vertex:\n");
                scanf("%d", &key);
                add_node(tree, key);
            }
        } else if (!strcmp(command, "print")) {
            if (!tree) printf("The tree does not exist.\n");
            else {
                printf("\nBinary tree:\n");
                printf("-------------------\n");
                print(tree, 0);
                printf("-------------------\n");
            }
        } else if (!strcmp(command, "delete")) {
            if (!tree) printf("The tree does not exist.\n");
            else {
                printf("Enter which vertex you want to delete:\n");
                scanf("%d", &key);
                tree_delete_node(tree, key);
                printf("Vertex %d removed.\n", key);
            }
        } else if (!strcmp(command, "destroy")) {
            if (!tree) printf("The tree does not exist.\n");
            else {
                tree_destroy(tree);
                tree = NULL;
                printf("The tree has been removed\n");
            }
        } else if (!strcmp(command, "run")) {
            if (!tree) printf("The tree does not exist.\n");
            else {
                if (symmetrical(tree)) {
                    printf("Tree is symmetrical\n");
                } else {
                    printf("Tree isn't symmetrical\n");
                }
            }
        } else if (!strcmp(command, "quit")) {
            if (tree) {
                tree_destroy(tree);
            }
            break;
            }
        }
    return 0;
}