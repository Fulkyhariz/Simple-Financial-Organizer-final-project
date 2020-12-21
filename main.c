#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "menu.h"
#include "Linked.h"

typedef struct uang{
    time_t waktu;
    long int uang;
    int kategori;
    char note[50];
    struct tm tm;
}Data;

typedef struct linkedlist{
    Data data;
    struct linkedlist *next;
}Node;

void mulai();
void riwayat(Node *head);

int main(){
    while (1){
    welcome();
    }
}

void mulai(){
    Node *head = NULL;
    readFile(head);
	int optmulai;
	system("cls");
	printf("Apa yang ingin ada lakukan pada program ini?\n");
	printf("1. Tambah Transaksi\n");
	printf("2. Lihat Riwayat\n");
	printf("3. Lihat analisis pengeluaran\n");
	printf("4. Kembali ke menu awal\n>> ");
	scanf("%d", &optmulai);
	
	switch (optmulai){
		case 1:
			system("cls");
			push(&head);
			break;
		case 2:
			system("cls");
			riwayat(head);
			break;
		case 3:
			system("cls");
			analisis();
			break;
		case 4:
			system("cls");
			welcome();
			break;

        default:
            errorHandle(1);
            mulai();
	}
}

void riwayat(Node *head){
    int pick, asc;
	system("cls");
	printf("Urutkan Bedasarkan?\n");
	printf("1. Jumlah Transaksi\n");
	printf("2. Waktu input\n");
	printf("3. Kategori\n");
	printf("4. Kembali ke menu awal\n>> ");
	scanf("%d", &pick);

    if(pick == 3){
        mergeSort(head, 5);
    }else if (pick == 1 || pick == 2){
        if (pick == 1 && ascdsc() == 1){
            mergeSort(head, 1);
        }else if (pick == 1 && ascdsc() == 2){
            mergeSort(head, 2);
        }else if (pick == 2 && ascdsc() == 1){
            mergeSort(head, 3);
        }else if (pick == 2 && ascdsc() == 2){
            mergeSort(head, 4);
        }
	}else{
        errorHandle(1);
        riwayat(head);
    }
}

