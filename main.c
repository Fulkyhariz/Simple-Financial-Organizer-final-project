#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

typedef struct uang{
    time_t waktu;
    long int uang;
    int kategori;
    char note[50];
}Data;

typedef struct linkedlist{
    Data data;
    struct linkedlist *next;
    struct linkedlist *prev;
}Node;

void getTime(Data *waktu){
    time_t t = time(NULL);
    time(&(waktu->waktu));
}

void swapAll(Node *current, Node *index){
    int temp;
    struct tm tmtemp;
    time_t ttemp;
    char stemp[20];

    temp = current->data.uang;  
    current->data.uang = index->data.uang;  
    index->data.uang = temp;
    temp = current->data.kategori;  
    current->data.kategori = index->data.kategori;  
    index->data.kategori = temp;  
    ttemp = current->data.waktu;  
    current->data.waktu = index->data.waktu;  
    index->data.waktu = ttemp;
    strcpy(stemp, current->data.note);
    strcpy(current->data.note, index->data.note);
    strcpy(index->data.note, stemp);
}

void sortUang(Node *head) {  
    Node *current = NULL, *index = NULL;  
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
                if(current->data.uang > index->data.uang) {  
                    swapAll(current, index);
                }  
            }  
        }  
    }  
}

void sortKategori(Node *head) {  
    Node *current = NULL, *index = NULL;  
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
                if(current->data.kategori > index->data.kategori) {  
                    swapAll(current, index);
                }  
            }  
        }  
    }  
}

void sortTime(Node *head) {  
    Node *current = NULL, *index = NULL;  
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
                if(difftime(current->data.waktu, index->data.waktu) > 0) {  
                    swapAll(current, index);
                }  
            }  
        }  
    }  
}

/* Given a reference (pointer to pointer) to the head of a list
   and an int, inserts a new node on the front of the list. */
void push(Node** head_ref)
{
    long int s;
    /* 1. allocate node */
    Node* new_node = (Node*)malloc(sizeof(Node));
 
    /* 2. put in the data  */
    scanf("%d", &s);
    new_node->data.uang  = s;

    getTime(&(new_node->data));

    new_node->data.kategori = 5;

    fflush(stdin);
    gets(new_node->data.note);
 
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
   and a key, deletes the first occurrence of key in Data list */
void deleteNode(Node **head_ref, int key) 
{ 
    // Store head node 
    Node* temp = *head_ref, *prev; 
  
    // If head node itself holds the key to be deleted 
    if (temp != NULL && temp->data.uang == key) 
    { 
        *head_ref = temp->next;   // Changed head 
        free(temp);               // free old head 
        return; 
    } 

    // Search for the key to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while (temp != NULL && temp->data.uang != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    // If key was not present in Data list 
    if (temp == NULL) return; 
  
    // Unlink the node from Data list 
    prev->next = temp->next; 
  
    free(temp);  // Free memory 
} 
  
// This function prints contents of Data list starting from  
// the given node 
void printList(Node *node) 
{ 
    Node* last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        printf(" %d %d %s %.19s\n", node->data.uang, node->data.kategori, node->data.note, ctime(&(node->data.waktu)));
        last = node;
        node = node->next;
    }
 
    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf(" %d %d %s %.19s\n", last->data.uang, last->data.kategori, last->data.note, ctime(&(last->data.waktu)));
        last = last->prev;
    }
}
  
// Driver code 
int main() 
{ 
    /* Start with the empty list */
    Node* head = NULL;

    push(&head); 
    push(&head); 
    push(&head); 
    push(&head);
    

    puts("Created Data List: "); 
    printList(head); 
    deleteNode(&head, 1); 
    puts("\nData List after Deletion of 1: "); 
    printList(head);
    printf("\n");
    sortUang(head);
    printList(head);
    printf("\n");
    sortTime(head);
    printList(head);

    return 0; 
}
