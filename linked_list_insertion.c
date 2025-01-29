    #include<stdio.h>
    #include<stdlib.h>

    struct Node
    {
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

    struct Node* insertatfirst(struct Node *head, int data)
    {
        struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
        ptr -> Next = head;
        ptr -> data = data;
        return ptr;
    };

    struct Node* insertatbetween(struct Node *head, int data,int index)
    {
        struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
        struct Node *p = head;
        int i = 0;
        while (i != index-1)
        {
            p = p -> Next;
            i++;
        }
        ptr -> data = data;
        ptr ->Next = p->Next;
        p->Next = ptr;
        return head;
        
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

        //head = insertatfirst( head,69);
        head =insertatbetween( head,69,2);
        Traversal(head);


        return 0;
    }
