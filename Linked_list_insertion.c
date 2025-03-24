#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to traverse and print the linked list
void Traversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf(" Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Function to insert at the beginning of the linked list
struct Node *insatfirst(struct Node *head, int data) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// Function to insert at a specific index
struct Node *insatindex(struct Node *head, int data, int index) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1 ) {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Function to create a user-defined linked list
struct Node *createLinkedList(int n) {
    struct Node *head = NULL, *temp, *newNode;
    int data, i;

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

int main() {
    struct Node *head = NULL;
    int n, op, po, choice;

    // Creating user-defined linked list
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);
    head = createLinkedList(n);

    while (1) {
        // Menu for insertion operations
        printf("\nChoose an operation:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Index\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at the beginning: ");
                scanf("%d", &op);
                head = insatfirst(head, op);
                printf("the element %d was inserted",op); 
                break;

            case 2:
                printf("Enter the element: ");
                scanf("%d", &op);
                printf("Enter the index: ");
                scanf("%d", &po);
                head = insatindex(head, op, po);
                break;

            case 3:
                printf("\nUpdated Linked List:\n");
                Traversal(head);
                break;

            case 4:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
