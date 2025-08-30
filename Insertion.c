//Insertion in Linked List: Insert at the beginning, end, and after a given location
// This code demonstrates how to insert nodes in a linked list


#include <stdio.h>
#include <stdlib.h>

//Insertion in Linked List: Insert at the beginning
// This code creates a new node and inserts it at the 
//beginning of the linked list.
void insertBeginning(struct node **head_ref, int new_data) {
    struct node {
    int data;
    struct node *next;
};

struct node *head, *newnode;
newnode = (struct node *) malloc(sizeof(struct node));

printf ("Enter data: ");
scanf ("%d", &newnode->data);
newnode->next = head; // Pointing to the head node
head = newnode; // New node becomes the head
}

//Insertion in Linked List: Insert at the end
// This code creates a new node and inserts it at the
//end of the linked list.
void insertEnd (struct node **head_ref, int new_data) {

   struct node {
    int data;
    struct node *next;
};

struct node *head, *newnode, *temp;
newnode = (struct node *) malloc(sizeof(struct node));

printf ("Enter data: ");
scanf ("%d", &newnode->data);
newnode->next = head; // Pointing to the head node
head = newnode=0; // New node becomes the head
temp = head;
while (temp->next != 0) {
    temp = temp->next; // Traverse to the end of the list
}
temp->next = newnode; // Link the new node at the end
}

//Insertion in Linked List: Insert after a given location
// This code creates a new node and inserts it after a 
//given location in the linked list.
void insertAfter(struct node *prev_node, int new_data) {
    int Pos; int i = 1;
    struct node {
        int data;
        struct node *next;
    };
    struct node *head, *newnode, *temp;
    newnode = (struct node *) malloc(sizeof(struct node));
    printf("Enter the Position: ");
    scanf("%d", &Pos);

    if (Pos<0){
        printf("Invalid Position\n");
        return;
    } else {
        temp=head;
        while  (i<Pos){
            temp = temp->next;
            i++;
        }
        printf ("Enter data: ");
        scanf ("%d", &newnode->data);
        newnode->next = temp->next; // Link the new node to the next node
        temp->next = newnode; // Link the previous node to the new node
    }
}

int main (){

}
