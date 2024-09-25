#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void reverse(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;  
        current = next;
    }
    *head_ref = prev;
}

int main() {
    struct Node* head = NULL;

    push(&head, 10);
    push(&head, 40);
    push(&head, 20);

    printf("Lista original: ");
    printList(head);

    reverse(&head);

    printf("Lista invertida: ");
    printList(head);

    return 0;
}
