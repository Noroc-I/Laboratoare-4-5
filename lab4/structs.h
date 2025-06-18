#ifndef STRUCTS_H
#define STRUCTS_H
typedef struct Country{
    int population;
    int GDP;
    int surface;
    char *name;
    char *currency;
} Country;
typedef struct Node{
    Country *country;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Binary_Search_Tree{
    Node *root;
    int search_mode;
} Binary_Search_Tree;



#endif STRUCTS_H
