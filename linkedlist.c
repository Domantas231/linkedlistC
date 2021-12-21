#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int list_print(node *head){
    if(head == NULL) return 1;

    int i = 0;
    while(head != NULL){
        printf("%d element data: ", i);
        node_print(head);

        i++;
        head = head->next;
    }
    printf("\n");

    return 0;
}

int node_print(node *el){
    if(el == NULL) return 1;

    printf("Name - %s, Surname - %s, Telephone number - %s, Email address - %s", el->name, el->surname, el->telnumber, el->email);
    printf("\n");

    return 0;
}

void list_addback(node **head, node *new){
    if(*head == NULL){
        *head = new;
        return;
    }

    node *iter = *head;
    while(iter->next != NULL) iter = iter->next;

    iter->next = new;
}

int list_add(node **head, node *new, int k){
    if(k < 0) return 1;

    if(k == 0) {
        new->next = *head;
        *head = new;
        return 0;
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

    return 0;
}

void list_delall(node **head){
    node *temp;

    while(*head != NULL){
        temp = *head;
        *head = (*head)->next;

        free(temp);
    }
}

node* list_getid(node *head, int k){
    if(k < 0) return NULL;

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

int list_delid(node **head, int k){
    if(k < 0) return 1;

    if(k == 0){
        node *tmp = *head;
        *head = (*head)->next;

        if(tmp != NULL) free(tmp);
        return 0;
    }
    
    node *iter = *head;
    int i = 0;
    
    while(i < (k - 1) && iter != NULL){
        iter = iter->next;
        i++;
    }
    
    node *tmp = iter->next;
    iter->next = tmp->next;

    if(tmp != NULL) free(tmp);

    return 0;
}