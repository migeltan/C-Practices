/*Linear Linked List
- Dynamic data structure where each element called a node,
is made up of two items: data and a pointer to the next node.

Different Types:
1. Stacks
2. Queues
3. Unidirectional Linked List - Focus
4. Bidirectional Linked List
5. Circular Linked List
6. Sorted Linked List

//Definition of a node in a linear linked list:
int main(){
struct node{
    int data;
    struct node *next;
};

//Head Pointer:
struct node *head, *newnode, *temp;
head = 0; int choice;

//Mallocating a node:
while(choice){ //node creation loop
newnode = (struct node *) malloc(sizeof(struct node));

//Input:
printf("Enter data: ");
scanf("%d", &newnode->data);
newnode->next= 0;

if (head == 0){
head = newnode = temp = newnode;
} else {
 temp->next= newnode;
 temp = newnode;
}

//Creating a new node:
printf ("Do you want to continue? (0||1): ");
scanf ("%d", &choice);
}
temp = head;
while (temp !=0){
    printf("%d ", temp->data); // Displaying the data of nodes
    temp = temp->next;
}
}
*/


