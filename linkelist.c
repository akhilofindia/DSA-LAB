//main file
#include "linkedlist.h"
#include <stdio.h>

int main() {
    linkedL ll;
    int choice, data, pos;

    Create_LL(&ll);

    while (1) {
        printf("\n===============Menu:===============\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at position\n");
        printf("3. Delete at beginning\n");
        printf("4. Delete at position\n");
        printf("5. Print list\n");
        printf("6. Exit\n");
        printf("==============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("==============================\n");
                printf("Enter data to insert: ");
                scanf("%d", &data);
                InsertAtBeg_LL(&ll, data);
                printf("==============================\n");
                printf("Data added to the Beginning position\n");
                printf("==============================\n");
                break;
            case 2:
                printf("==============================\n");
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                InsertAtPos_LL(&ll, pos, data);
                printf("==============================\n");
                printf("Data added to the position %d\n",pos);
                printf("==============================\n");
                break;
            case 3:
                printf("==============================\n");
                DeleteAtBeg_LL(&ll);
                printf("Data is delete from the Beginning position\n");
                printf("==============================\n");
                break;
            case 4:
                printf("==============================\n");
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                DeleteAtPos_LL(&ll, pos);
                printf("Data is delete from the position %d\n",pos);
                printf("==============================\n");
                break;
            case 5:
                printf("==============================\n");
                printf("Linked List Status:\n");
                Print_LL(&ll);
                printf("==============================\n");
                break;
            case 6:
                printf("==============================\n");
                printf("Exiting.....\n");
              printf("==============================\n");
              return 0;
            default:
              printf("==============================\n");
              printf("Invalid choice\n"); 
              printf("==============================\n"); 
        }
    }
    return 0;
}

//linkedlist.h file
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct linkedL {
    node *head;
    int size;
} linkedL;

void Create_LL(linkedL *ll);
void InsertAtBeg_LL(linkedL *ll, int data);
void InsertAtPos_LL(linkedL *ll, int pos, int data);
void DeleteAtBeg_LL(linkedL *ll);
void DeleteAtPos_LL(linkedL *ll, int pos);
void Print_LL(linkedL *ll);

#endif


//linkedlist.c file
#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void Create_LL(linkedL *ll) {
    ll->head = NULL;
    ll->size = 0;
}

void InsertAtBeg_LL(linkedL *ll, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = ll->head;
    ll->head = new_node;
    ll->size++;
}

void InsertAtPos_LL(linkedL *ll, int pos, int data) {
    if (pos < 1 || pos > ll->size + 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        InsertAtBeg_LL(ll, data);
        return;
    }
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    node *curr = ll->head;
    for (int i = 1; i < pos - 1; i++) {
        curr = curr->next;
    }
    new_node->next = curr->next;
    curr->next = new_node;
    ll->size++;
}

void DeleteAtBeg_LL(linkedL *ll) {
    if (ll->size == 0) {
        printf("List is empty\n");
        return;
    }
    node *temp = ll->head;
    ll->head = ll->head->next;
    free(temp);
    ll->size--;
}

void DeleteAtPos_LL(linkedL *ll, int pos) {
    if (pos < 1 || pos > ll->size) {
        printf("Invalid position\n");
        return;
    }
    if (ll->size == 0) {
        printf("List is empty\n");
        return;
    }
    if (pos == 1) {
        DeleteAtBeg_LL(ll);
        return;
    }
    node *curr = ll->head;
    for (int i = 1; i < pos - 1; i++) {
        curr = curr->next;
    }
    node *temp = curr->next;
    curr->next = temp->next;
    free(temp);
    ll->size--;
}

void Print_LL(linkedL *ll) {
   if(ll -> size == 0){
      printf("List is empty\n");
      return ;
   }
   printf("List: ");
   for(node* curr=ll -> head; curr!=NULL; curr=curr -> next){
      printf("%d-> ",curr -> data);
   }
   printf("NULL\n");
}