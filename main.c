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

    printf("Pradinis listas: \n");
    list_print(head);

    list_addback(&head, new_node());
    add_node(&head);

    printf("Listas, pridejus nauju elementu: \n");
    list_print(head);


    find_nodenum(head);
    find_nodename(head);

    del_node(&head);
    printf("Listas, istrynus tam tikra elementus: \n");

    list_print(head);
    list_delall(head);

    return 0;
}

void find_nodename(node *head){
    printf("Iveskite elemento varda, kuri noretumet atskirai atspaudinti: ");

    char name[20];
    scanf("%s", name);

    node_print(list_getname(head, name));
}

void find_nodenum(node *head){
    printf("Iveskite indeksa elemento, kuri noretumet atskirai atspaudinti: ");

    int k;
    scanf("%d", &k);

    node_print(list_getid(head, k));
}

void add_node(node **head){
    printf("Iveskite i kuria vieta norit prideti elementa: ");

    int k;
    scanf("%d", &k);
    list_add(head, new_node(), k);
}

void del_node(node **head){
    printf("Iveskite kuri elementa norit istrinti: ");

    int k;
    scanf("%d", &k);

    list_delid(head, k);
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
    
    printf("Iveskite naujo elemento varda: ");
    scanf("%s", new->name);

    printf("Iveskite naujo elemento pavarde: ");
    scanf("%s", new->surname);

    printf("Iveskite naujo elemento tel numeri: ");
    scanf("%s", new->telnumber);

    printf("Iveskite naujo elemento el pasta: ");
    scanf("%s", new->email);

    return new;
}