#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

typedef struct money{
    time_t waktu;
    int uang;
    int kategori;
    char note[50];
    struct money *kiri, *kanan;
}Data;

Data* newNode(int item);
void print(Data* root);
Data* insert(Data* node, int key);
void arrangeWaktu(Data* node, struct tm waktu, int key);
void arrangeUang(Data* node, int key);
void arrangeKategori(Data* node, int key);
int getCategory();
void menuKategori();

int main(){
    while(1){
    int duit;
    Data *root = NULL;
    scanf("%d", &duit);
    root = insert(root, duit);
    (root->kategori) = getCategory();
    printf("\nTambahkan Catatan\n");
    fflush(stdin);
    gets(root->note);
    time(&(root->waktu));
    print(root);
    }
}

Data* newNode(int item){ 
    Data* temp = (Data*)malloc(sizeof(Data)); 
    temp->uang = item;
    temp->kiri = temp->kanan = NULL;
    return temp;
}

void print(Data* root){ 
    if (root != NULL){ 
        print(root->kiri); 
        printf("%d \n", root->uang);
        printf("%d\n", root->kategori);
        printf("%s", ctime(&(root->waktu)));
        printf("%s ", root->note);
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
    int s = 0;
    menuKategori();
    scanf("%d", &s);
    if (s == 1 || s == 2 || s == 3 || s == 4 || s == 5){
        return s;
    }else{
        printf("Invalid input!!");
        Sleep(3000);
        getCategory();
    }
}
void menuKategori(){
    printf("\nPilih Kategori Transaksi\n");
    printf("1.Makanan & Minuman\n");
    printf("2.Transportasi\n"); 
    printf("3.Hiburan\n");
    printf("4.Kebutuhan Sehari-hari\n");
    printf("5.lainnya\n>> ");
}
