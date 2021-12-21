#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void list_print(node *head){
    int i = 0;
    while(head != NULL){
        printf("%d elemento duomenys: ", i);
        node_print(head);

        i++;
        head = head->next;
    }
    printf("\n");
}

void node_print(node *el){
    printf("Vardas - %s, Pavarde - %s, Telefono numeris - %s, El. pastas - %s", el->name, el->surname, el->telnumber, el->email);
    printf("\n");
}

void list_addback(node **head, node *new){
    if(*head == NULL){
        (*head) = new;
        return;
    }

    node *iter = *head;
    while(iter->next != NULL) iter = iter->next;

    iter->next = new;
}

void list_add(node **head, node *new, int k){
    if(k < 0){
        printf("Netinkamas elemento numeris");
        return;
    }
    
    if(k == 0) {
        new->next = *head;
        *head = new;
    }

    node *iter = *head;
    int i = 0;
    while(i < (k - 1) && iter != NULL) {
        iter = iter->next;
        i++;
    }

    node *temp = iter->next;
    iter->next = new;
    new->next = temp;
}

void list_delall( node *head){
     node *temp;

    while(head != NULL){
        temp = head;
        head = head->next;

        free(temp);
    }
}

 node* list_getid( node *head, int k){
     node *iter = head;
    int i = 0;
    
    while(i < k && iter != NULL){
        iter = iter->next;
        i++;
    }

    return iter;
}

node* list_getname(node *head, char* name){
    node *iter = head; 
    while(iter != NULL){
        if(strcmp(iter->name, name) == 0) break;

        iter = iter->next;
    }

    return iter;
}

void list_delid(node **head, int k){
    if(k < 0){
        printf("Netinkamas elemento numeris");
        return;
    }
    if(k == 0){
        node *temp = *head;
        *head = (*head)->next;

        free(temp);
        return;
    }
    
    node *iter = *head;
    int i = 0;
    
    while(i < (k - 1) && iter != NULL){
        iter = iter->next;
        i++;
    }
    
    node *temp = iter->next;
    iter->next = temp->next;

    free(temp);
}