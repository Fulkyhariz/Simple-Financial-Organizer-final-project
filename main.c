
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

typedef struct uang{
    struct tm tm;
    time_t waktu;
    long int uang;
    int kategori;
    char note[50];
    struct uang *next;
    struct uang *prev;
}Linked;

void getTime(Linked *waktu){
    time_t t = time(NULL);
    waktu->tm = *localtime(&t);
    time(&(waktu->waktu));
}

void swapAll(Linked *current, Linked *index){
    int temp;
    struct tm tmtemp;
    time_t ttemp;
    char stemp[20];

    temp = current->uang;  
    current->uang = index->uang;  
    index->uang = temp;
    temp = current->kategori;  
    current->kategori = index->kategori;  
    index->kategori = temp;  
    tmtemp = current->tm;  
    current->tm = index->tm;  
    index->tm = tmtemp;
    ttemp = current->waktu;  
    current->waktu = index->waktu;  
    index->waktu = ttemp;
    strcpy(stemp, current->note);
    strcpy(current->note, index->note);
    strcpy(index->note, stemp);
}

void sortList(Linked *head) {  
    Linked *current = NULL, *index = NULL;  
    //Check whether list is empty  
    if(head == NULL) {  
        return;  
    }  
    else {  
        //Current will point to head  
        for(current = head; current->next != NULL; current = current->next) {  
            //Index will point to node next to current  
            for(index = current->next; index != NULL; index = index->next) {  
                //If current's data is greater than index's data, swap the data of current and index  
                if(current->uang > index->uang) {  
                    swapAll(current, index);
                }  
            }  
        }  
    }  
}

/* Given a reference (pointer to pointer) to the head of a list
   and an int, inserts a new node on the front of the list. */
void push(Linked** head_ref)
{
    long int s;
    /* 1. allocate node */
    Linked* new_node = (Linked*)malloc(sizeof(Linked));
 
    /* 2. put in the data  */
    scanf("%d", &s);
    new_node->uang  = s;

    getTime(new_node);

    new_node->kategori = 5;

    fflush(stdin);
    gets(new_node->note);
 
    /* 3. Make next of new node as head and previous as NULL */
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    /* 4. change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    /* 5. move the head to point to the new node */
    (*head_ref) = new_node;
}
  
/* Given a reference (pointer to pointer) to the head of a list 
   and a key, deletes the first occurrence of key in linked list */
void deleteNode(Linked **head_ref, int key) 
{ 
    // Store head node 
    Linked* temp = *head_ref, *prev; 
  
    // If head node itself holds the key to be deleted 
    if (temp != NULL && temp->uang == key) 
    { 
        *head_ref = temp->next;   // Changed head 
        free(temp);               // free old head 
        return; 
    } 

    // Search for the key to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while (temp != NULL && temp->uang != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    // If key was not present in linked list 
    if (temp == NULL) return; 
  
    // Unlink the node from linked list 
    prev->next = temp->next; 
  
    free(temp);  // Free memory 
} 
  
// This function prints contents of linked list starting from  
// the given node 
void printList(Linked *node) 
{ 
    Linked* last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        printf(" %d %d %s %.19s\n", node->uang, node->kategori, node->note, ctime(&(node->waktu)));
        last = node;
        node = node->next;
    }
 
    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf(" %d %d %s %.19s\n", last->uang, last->kategori, last->note, ctime(&(last->waktu)));
        last = last->prev;
    }
}
  
// Driver code 
int main() 
{ 
    /* Start with the empty list */
    Linked* head = NULL;

    push(&head); 
    push(&head); 
    push(&head); 
    push(&head);
    

    puts("Created Linked List: "); 
    printList(head); 
    deleteNode(&head, 1); 
    puts("\nLinked List after Deletion of 1: "); 
    printList(head);
    printf("\n");
    sortList(head);
    printList(head);

    return 0; 
}
