#include <stdio.h>
#include "structs.h"
#include "funcs.h"

   int main() {
       Binary_Search_Tree *tree = NULL;
       int option = 0;
       while(1){
           printf("1.Create tree\n");
           printf("2.Print Inorder traversal\n");
           printf("3.Print Preorder traversal\n");
           printf("4.Print Postorder traversal\n");
           printf("5.New node\n");
           printf("6.Search\n");
           printf("7.BFS traversal\n");
           printf("8.Mirror tree\n");
           printf("9.Clear tree\n");
           printf("10.Free tree\n");
           printf("11.Exit\n");
           printf("Option: ");
           option = bound_read(0,11);
           switch(option){
               case 1:{
                   if(tree) {
                       printf("Tree already exists\n");
                       break;
                   }
                   tree = create_tree();
               } break;
               case 2:{
                   if(!tree) {
                       printf("Empty tree\n");
                       break;
                   }
                   print_tree_inorder(tree->root);
               } break;
               case 3:{
                   if(!tree) {
                       printf("Empty tree\n");
                       break;
                   }
                   print_tree_preorder(tree->root);
               } break;
               case 4:{
                   if(!tree) {
                       printf("Empty tree\n");
                       break;
                   }
                   print_tree_postorder(tree->root);
               } break;
               case 5:{
                   if(!tree) {
                       printf("Empty tree\n");
                       break;
                   }
                   Node *node = read_node();
                   if(tree->search_mode)
                       push_mirror(tree, node);
                   else push(tree, node);
               } break;
               case 6:{
                   if(!tree) {
                       printf("Empty tree\n");
                       break;
                   }
                   char name[50];
                   fflush(stdin);
                   printf("Country name: ");
                   scanf("%s", name);
                   if(tree->search_mode)
                       search_by_name_mirror(tree->root,name);
                   else search_by_name(tree->root,name);

               } break;
               case 7:{
                   if(!tree) {
                       printf("Empty tree\n");
                       break;
                   }
                   print_tree_inorder(tree->root);
               } break;
               case 8:{
                   if(!tree) {
                       printf("Empty tree\n");
                       break;
                   }
                   mirror_tree(tree->root);
                   if(tree->search_mode)
                       tree->search_mode = 0;
                   else tree->search_mode = 1;
               } break;
               case 9:{
                   if(!tree) {
                       printf("Empty tree\n");
                       break;
                   }
                   clear_tree(tree->root);
               } break;
               case 10:{
                   if(!tree) {
                       printf("Empty tree\n");
                       break;
                   }
                   free_tree(tree);
                   tree->search_mode = 0;
               } break;
               case 11: return 0;
               default: break;
           }
           printf("\n\n\n\n\n");
       }
   }
