//Deletion from Linked List
//Delete from the beginning and end of a linked list

/*
struct node {
    int data;
    struct node *next;
};

struct node *head, *temp;

DeletefromBeg(){
//struct node *temp;
 temp = head;
 head = head->next; // Move head to the next node
    free(temp); // Free the memory of the deleted node
}

DeletefromEnd(){
struct node *prevnode;
 temp=head;

 while (temp->next !=0){
    prevnode = temp; // Keep track of the previous node
    temp = temp->next; // Move to the next node
 }
if (temp ==head){
head = 0; // If the list is empty, set head to NULL
} else {
    prevnode->next = 0; // Set the next of the previous node to NULL
} 
free(temp); // Free the memory of the deleted node
}

DeletefromPos(int Pos){
struct node *nextnode;
int Pos, i = 1;
temp = head;
printf("Enter the Position: ");
scanf("%d", &Pos);

while (i<Pos=1){
temp = temp->next; // Move to the next node
    i++;
} nextnode = temp->next; // Store the next node
temp->next = nextnode->next; // Link the current node to the next node
free(nextnode); // Free the memory of the deleted node
}

*/