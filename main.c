#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

typedef struct uang{
    struct tm tm;
    time_t waktu;
    int uang;
    int kategori;
    char note[50];
    struct uang *next;
}LinkedList;

typedef struct money{
    struct tm tm;
    time_t waktu;
    int uang;
    int kategori;
    char note[50];
    struct money *kiri, *kanan;
}Tree;

Tree* newNode(int item);
void print(Tree* root);
Tree* insert(Tree* node, int key);
void arrangeWaktu(Tree* node, struct tm waktu, int key);
void arrangeKategori(Tree* node, int key);
int getCategory();
void menuKategori();
void getTime(Tree *waktu);
Tree* passBST(Tree *old);
Tree* arrangeCat(Tree *node, Tree *old, int key);

int main(){
    int i;
    int duit;
    Tree *root = NULL;
    Tree *arrange = NULL;
    for(i = 0; i<3; i++){
        scanf("%d", &duit);
        root = insert(root, duit);
    }
    arrange = arrangeCat(arrange, root, root->kategori);
    print(root);
    print(arrange);
    getch();
}

void getTime(Tree *waktu){
    time_t t = time(NULL);
    waktu->tm = *localtime(&t);
    time(&(waktu->waktu));
}

Tree* newNode(int item){ 
    Tree* temp = (Tree*)malloc(sizeof(Tree)); 
    temp->uang = item;
    (temp->kategori) = getCategory();
    printf("\nTambahkan Catatan\n");
    fflush(stdin);
    gets(temp->note);
    getTime(temp);
    temp->kiri = temp->kanan = NULL;
    return temp;
}

void print(Tree* root){ 
    if (root != NULL){ 
        print(root->kiri); 
        printf("%d ", root->uang);
        printf("%d ", root->kategori);
        printf(" %.19s", ctime(&(root->waktu)));
        printf(" %s\n", root->note);
        print(root->kanan);
    }
}

Tree* insert(Tree* node, int key){ 
    if (node == NULL) 
        return newNode(key);
    if (key < node->uang) 
        node->kiri = insert(node->kiri, key); 
    else if (key > node->uang) 
        node->kanan = insert(node->kanan, key);
    return node; 
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
        fflush(stdin);
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
Tree* passBST(Tree *old){ 
    Tree* new = (Tree*)malloc(sizeof(Tree)); 
    new->uang = old->uang;
    new->kategori = old->kategori;
    strcpy(new->note, old->note);
    new->tm = old->tm;
    new->waktu = old->waktu;
    new->kiri = new->kanan = NULL;
    return new;
}

Tree* arrangeCat(Tree *node, Tree *old, int key){ 
    if (node == NULL) 
        return passBST(old);
    if (key < node->uang) 
        node->kiri = arrangeCat(node->kiri, old->kiri, old->kiri->kategori); 
    else if (key > node->uang) 
        node->kanan = arrangeCat(node->kanan, old->kanan, old->kanan->kategori);
    return node; 
}
