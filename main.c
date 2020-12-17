#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct money{
    struct tm waktu;
    int uang;
    int kategori;
    char note[50];
    struct money *kiri, *kanan;
}Data;

void getTime(struct tm *waktu);
Data* newNode(int item);
void print(Data* root);
Data* insert(Data* node, int key);
void arrangeWaktu(Data* node, struct tm waktu, int key);
void arrangeUang(Data* node, int key);
void arrangeKategori(Data* node, int key);
int getCategory();

int main(){
    int duit;
    Data *root = NULL;
    scanf("%d", &duit);
    root = insert(root, duit);
    getTime(&(root->waktu));
    print(root);
}

void getTime(struct tm *waktu){
    time_t t = time(NULL);
    *waktu = *localtime(&t);
}

Data* newNode(int item){ 
    Data* temp = (Data*)malloc(sizeof(Data)); 
    temp->uang = item;
    temp->kategori = getCategory();
    fflush(stdin);
    gets(temp->note);
    temp->kiri = temp->kanan = NULL;
    return temp;
}

void print(Data* root){ 
    if (root != NULL){ 
        print(root->kiri); 
        printf("%d \n", root->uang);
        printf("%d %d %d\n", root->waktu.tm_hour);
        print(root->kanan);
    }
}

Data* insert(Data* node, int key){ 
    if (node == NULL) 
        return newNode(key);
    if (key < node->uang) 
        node->kiri = insert(node->kiri, key); 
    else if (key > node->uang) 
        node->kanan = insert(node->kanan, key);
    return node; 
}
void arrangeWaktu(Data* node, struct tm waktu, int key){
    Data* tmp = NULL;
    tmp = (Data*)malloc(sizeof(Data));
    if (key < node->uang) 
        node->kiri = insert(node->kiri, key);
    else if (key > node->uang) 
        node->kanan = insert(node->kanan, key);
}
int getCategory(){
    int s;
    printf("Pilih Kategori Transaksi\n" "1.Makanan & Minuman\n"
    "2.Transportasi\n" "3.Hiburan\n" "4.Kebutuhan Sehari-hari\n" "5.lainnya\n"
    ">>");
    scanf("%d ", &s);
    switch (s){
    case 1 || 2 || 3 || 4 || 5:
        return s;
        break;
    
    default:
        printf("Invalid input!!");
        Sleep(3000);
        getCategory();
        break;
    }
}
