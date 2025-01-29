#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * Next;
};

void Traversal(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("Element : %d\n",ptr->data);
        ptr = ptr ->Next;
    }
    
}

int main(void){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * forth;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    forth = (struct Node *) malloc(sizeof(struct Node));


    head ->data = 7;
    head -> Next = second;
    second ->data = 11;
    second-> Next = third;
    third ->data = 66;
    third -> Next = forth;
    forth ->data = 100;
    forth -> Next = NULL;

    Traversal(head);
    return 0;
}
