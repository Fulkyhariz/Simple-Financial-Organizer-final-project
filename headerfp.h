#include <stdio.h>
#include <windows.h>
#include <conio.h>
void help();

void welcome(){
	int menu;
	printf("\n");
	printf("\t\t\t\t\tWELCOME TO FINANCIAL ORGANIZER PROGRAM\n");
	printf("\t\t\t\t\t======================================\n");
	printf("\t\t\t\t\t\t      MAIN MENU\n");
	printf("\t\t\t\t\t\t       1. Start\n");
	printf("\t\t\t\t\t\t       2. Setting\n");
	printf("\t\t\t\t\t\t       3. Help\n");
	printf("\t\t\t\t\t\t       4. Exit\n");
	printf("\t\t\t\t\t\t       >> ");
	scanf("%d", &menu);
	
	switch (menu){
		case 3:
			help();
			break;
	}
}

void help(){
	system("cls");
	printf("\n================================================== ");
	printf("ABOUT THIS PROGRAM =================================================\n");
	printf("\n>> Program ini merupakan suatu program yang dapat membantu para pengguna (user) untuk mengatur keuangan mereka.\n");
	printf(">> Pada program ini, user diminta untuk menginput pemasukan tetap serta target pengeluaran dalam kurun waktu satu bulan.\n");
	printf(">> Selanjutnya, user dapat menambah transaksi pengeluaran dalam kategori tertentu.\n");
	printf(">> Nantinya, program dapat menganalisis berapa pengeluaran yang telah dikeluarkan oleh user dalam bentuk persentase.\n");
	printf(">> Selain itu, user juga dapat melihat riwayat pengeluaran serta mengubah target pengeluaran.\n");
	printf("\nTekan tombol apapun untuk kembali ke menu awal.\n>> ");
	getch();
	system("cls");
	welcome();
}
