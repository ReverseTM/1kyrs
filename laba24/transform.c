#include "tree.h"
#include "transform.h"
#include <math.h>

int mult_left(Tree *t)
{
    return ((*t) != NULL) && ((*t)->node.type == OPERATOR)
           && ((*t)->node.data.operator_name == '*')
           && ((*t)->left->node.data.value_int == 1 || (*t)->left->node.data.value_float == 1);
}

int mult_right(Tree *t)
{
    return ((*t) != NULL) && ((*t)->node.type == OPERATOR)
           && ((*t)->node.data.operator_name == '*')
           && ((*t)->right->node.data.value_int == 1 || (*t)->right->node.data.value_float == 1);
}

void transform_mult_left(Tree *t)
{
    if (((*t)->right->node.type == INTEGER) || (*t)->right->node.type == FLOATING) {
        (*t)->node = (*t)->right->node;
        (*t)->left = NULL;
        (*t)->right = NULL;
    } else {
        (*t)->node = (*t)->right->node;
        (*t)->left = (*t)->right->left;
        (*t)->right = (*t)->right->right;
        
    }
}
    
void transform_mult_right(Tree *t)
{
    if (((*t)->left->node.type == INTEGER) || (*t)->left->node.type == FLOATING) {
        (*t)->node = (*t)->left->node;
        (*t)->left = NULL;
        (*t)->right = NULL;
    } else {
        (*t)->node = (*t)->left->node;
        (*t)->right = (*t)->left->right;
        (*t)->left = (*t)->left->left;
    }
}

void tree_transform(Tree *t)
{
    if ((*t) != NULL) {    
        tree_transform(&((*t)->left));
        tree_transform(&((*t)->right));

        if (mult_left(t)) {
            transform_mult_left(t);
        }
        if (mult_right(t)) {
            transform_mult_right(t);
        }
    }
}