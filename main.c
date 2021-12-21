#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedlist.h"

node* new_node();
void list_example(node **head);
void add_node(node **head);
void del_node(node **head);
void add_node(node **head);
void find_nodenum(node *head);
void find_nodename(node *head);

int main(){
    node* head = NULL;

    list_example(&head);

    printf("The starting list: \n");
    if(list_print(head) == 1) printf("Empty list");

    list_addback(&head, new_node());
    add_node(&head);

    printf("The list with new added elements: \n");
    if(list_print(head) == 1) printf("Empty list");


    find_nodenum(head);
    find_nodename(head);

    del_node(&head);
    printf("The list without the specified element: \n");

    list_print(head);
    list_delall(&head);

    return 0;
}

void find_nodename(node *head){
    printf("Enter the element's name, which you want to print separately: ");

    char name[20];
    scanf("%s", name);

    if(node_print(list_getname(head, name)) == 1) printf("(!!) Node is empty or doesn't exist (NULL) \n");
}

void find_nodenum(node *head){
    printf("Enter the index of the element, which you want to print separately: ");

    int k;
    scanf("%d", &k);

    if(node_print(list_getid(head, k)) == 1) printf("(!!) Node is empty (NULL) \n");
}

void add_node(node **head){
    printf("Enter the index of where you want to add this element: ");

    int k;
    scanf("%d", &k);
    if(list_add(head, new_node(), k) == 1) printf("(!!) Bad node index\n");
}

void del_node(node **head){
    printf("Enter the index of the element you want to delete: ");

    int k;
    scanf("%d", &k);

    if(list_delid(head, k) == 1) printf("(!!) Bad node index \n");
}

void list_example(node **head){
    for(int i = 0; i < 10; i++){
        node *new = malloc(sizeof(node));

        sprintf(new->name, "%d", i);
        list_addback(head, new);
    }
}

node* new_node(){
    node *new = malloc(sizeof(node));
    
    printf("Node name: ");
    scanf("%s", new->name);

    printf("Node surname: ");
    scanf("%s", new->surname);

    printf("Node telephone number: ");
    scanf("%s", new->telnumber);

    printf("Node email address: ");
    scanf("%s", new->email);

    return new;
}