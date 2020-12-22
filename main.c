#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

typedef struct uang{//Struct
    time_t waktu;
    long int uang;
    int kategori;
    char note[50];
    struct tm tm;
}Data;

typedef struct linkedlist{ //Linked list
    Data data;
    struct linkedlist *next;
}Node;

#include "Linked.h"
#include "Menu.h"
#include "Analisis.h"

void main(){
    while (1){
    welcome();
    }
}
