#include <stdio.h>
#include "funcs.h"
#include <stdlib.h>
#include <string.h>
#include "structs.h"

int bound_read(int low, int high) {
    int num;
    do{
        fflush(stdin);
        scanf("%d",&num);
    } while(num<low || num>high);
    return num;
}

Binary_Search_Tree *create_tree(){
    Binary_Search_Tree *tree = calloc(1,sizeof(Binary_Search_Tree));
    tree->search_mode = 0;
    return tree;
}
Node *read_node(){
    Country *country = calloc(1, sizeof(Country));
    printf(" Country name: ");
    fflush(stdin);
    country->name = calloc(50, 1);
    scanf("%s", country->name);
    printf(" Population: ");
    fflush(stdin);
    scanf("%d", &country->population);
    printf(" Area: ");
    fflush(stdin);
    scanf("%d", &country->surface);
    printf(" Currency: ");
    fflush(stdin);
    country->currency = calloc(50, 1);
    scanf("%s", country->currency);
    printf(" GDP: ");
    fflush(stdin);
    scanf("%d", &country->GDP);
    Node *node = calloc(1, sizeof(Node));
    node->country = country;
    return node;
}

int push_if_empty(Binary_Search_Tree *tree, Node *node) {
    if (tree->root == NULL) {
        tree->root = node;
        return 1;
    }
    return 0;
}

void push(Binary_Search_Tree *tree, Node *node) {
    if(push_if_empty(tree, node))
        return;
    Node *current = tree->root;
    while (current != NULL) {
        if(strcmp(current->country->name, node->country->name) == 0) {
            return;
        }
        if(strcmp(node->country->name, current->country->name) < 0) {
            if(current->left == NULL) {
                current->left = node;
                return;
            }
                current = current->left;
        }
        else{
            if(current->right == NULL) {
                current->right = node;
                return;
            }
                current = current->right;
        }
    }
}

void push_mirror(Binary_Search_Tree *tree, Node *node) {
    if(push_if_empty(tree, node))
        return;
    Node *current = tree->root;
    while (current != NULL) {
        if(strcmp(current->country->name, node->country->name) == 0) {
            return;
        }
        if(strcmp(node->country->name, current->country->name) < 0) {
            if(current->right == NULL) {
                current->right = node;
                return;
            }
                current = current->right;
        }
        else{
            if(current->left == NULL) {
                current->left = node;
                return;
            }
                current = current->left;
        }
    }
}

void print_node(const Node *node){
    printf("Country name: %s\n", node->country->name);
    printf("Population: %d\n", node->country->population);
    printf("Area: %d\n", node->country->surface);
    printf("Currency: %s\n", node->country->currency);
    printf("GDP: %d\n\n", node->country->GDP);
}

void print_tree_inorder(Node *root) {
    if(!root)
        return;
    print_tree_inorder(root->left);
    print_node(root);
    print_tree_inorder(root->right);
}

void print_tree_preorder(Node *root){
    if(!root)
        return;
    print_node(root);
    print_tree_preorder(root->left);
    print_tree_preorder(root->right);
}

void print_tree_postorder(Node *root){
    if(!root)
        return;
    print_tree_postorder(root->left);
    print_tree_postorder(root->right);
    print_node(root);
}

void print_tree_BFS(Node *root){
    Node **queue1 = malloc(sizeof(Node*));
    Node **queue2 = malloc(sizeof(Node*));
    int size1 = 1, size2 = 0, count = 1;
    queue1[0] = root;
    queue1[1] = NULL;
    printf("Level 0:\n");
    print_node(root);
    while(size1){
        printf("Level %d:\n", count);
        int i = 0;
        while(queue1[i]) {
            if(queue1[i]->left) {
                ++size2;
                queue2 = realloc(queue2, sizeof(Node*)*size2);
                queue2[size2-1] = queue1[i]->left;
                queue2[size2] = NULL;
                print_node(queue2[size2-1]);
            }
            if(queue1[i]->right) {
                ++size2;
                queue2 = realloc(queue2, sizeof(Node*)*size2);
                queue2[size2-1] = queue1[i]->right;
                queue2[size2] = NULL;
                print_node(queue2[size2-1]);
            }
            ++i;
        }
        ++count;
        size1 = size2;
        size2 = 0;
        queue1 = realloc(queue1, sizeof(Node*)*size1);
        i = 0;
        while(i<size1) {
            queue1[i] = queue2[i];
            ++i;
        }
        queue1[size1] = NULL;
    }
    free(&queue1);
    free(&queue2);
}

int search_by_name(Node *root, char *name) {
    if(!root)
        return 0;
    if(strcmp(root->country->name, name) == 0) {
        print_node(root);
        printf("\n");
        return 1;
    }
    if(strcmp(root->country->name,name)<0)
        search_by_name(root->left, name);
    else search_by_name(root->right, name);
    return 0;
}

int search_by_name_mirror(Node *root, char *name) {
    if(!root)
        return 0;
    if(strcmp(root->country->name, name) == 0) {
        print_node(root);
        printf("\n");
        return 1;
    }
    if(strcmp(root->country->name,name)<0)
        search_by_name_mirror(root->right, name);
    else search_by_name_mirror(root->left, name);
    return 0;
}

void mirror_tree(Node *root) {
    if(root == NULL)
        return;
    Node *temp = root->right;
    root->right = root->left;
    root->left = temp;
    mirror_tree(root->left);
    mirror_tree(root->right);
}
void clear_tree(Node *root) {
    if(!root)
        return;
    clear_tree(root->left);
    clear_tree(root->right);
    free(root);
}
void free_tree(Binary_Search_Tree *tree) {
    if(!tree->root)
        return;
    clear_tree(tree->root);
    free(tree);
    tree = NULL;
}
