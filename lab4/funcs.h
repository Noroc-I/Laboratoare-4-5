#ifndef FUNCS_H
#define FUNCS_H
#include "structs.h"

Binary_Search_Tree *create_tree();

int bound_read(int low, int high);

Node *read_node();

int push_if_empty(Binary_Search_Tree *tree, Node *node);

void push(Binary_Search_Tree *tree, Node *node);

void push_mirror(Binary_Search_Tree *tree, Node *node);

void print_node(const Node *node);

void print_tree_inorder(Node *root);

void print_tree_preorder(Node *root);

void print_tree_postorder(Node *root);

void print_tree_BFS(Node *root);

int search_by_name(Node *root, char *name);

int search_by_name_mirror(Node *root, char *name);

void mirror_tree(Node *root);

void clear_tree(Node *root);

void free_tree(Binary_Search_Tree *tree);

#endif FUNCS_H
