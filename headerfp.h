#include <stdio.h>
#include <windows.h>
#include <conio.h>
/*void help();

void welcome(){
	int menu;
	mainMenu:
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
		case 1:
			start();
			break;
		case 2:
			setting();
			break;	
		case 3:
			help();
			break;
		case 4:
			exit(1);
		default:
			printf("\nMohon masukkan input yang benar.");
			Sleep(3000);
			system("cls");
			goto mainMenu;
			
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

int start(){
	char optstart;
	startmenu:
	system("cls");
	printf("\nApakah ini merupakan pertama kali anda menggunakan program ini? (Y/N)\n>> ");
	scanf("%s", &optstart);
	
	switch (optstart){
		case 'Y':
			setting();
			break;
		case 'N':
			mulai();
			break;
		default:
			printf("\nMohon masukkan input yang benar.");
			Sleep(3000);
			goto startmenu;
	}	
}

int mulai(){
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
			transaksi();
			break;
		case 2:
			system("cls");
			riwayat();
			break;
		case 3:
			system("cls");
			analisis();
			break;
		case 4:
			system("cls");
			welcome();
			break;
	}
}*/
