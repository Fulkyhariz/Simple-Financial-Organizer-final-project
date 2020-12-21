#ifndef FOO_H_  
#define FOO_H_


void help();
void errorHandle();

int setTarget(){
	int target;
	FILE *fptr;
	
	fptr = fopen("settarget.txt", "w");
	
	if(fptr == NULL){
		printf("Error! File text tidak ditemukan.");
		exit(1);
	}
	
	printf("Masukkan target pengeluaran (tidak perlu menuliskan mata uang dan tanda koma): ");
	scanf("%d", &target);
	printf("\nTarget pengeluaran berhasil diperbaharui.\n");
	
	fprintf(fptr, "%d", target);
	fclose(fptr);
	
	return 0;
}

void welcome(){
	int menu;
	mainMenu:
	printf("\n");
	printf("\t\t\t\t\tWELCOME TO FINANCIAL ORGANIZER PROGRAM\n");
	printf("\t\t\t\t\t======================================\n");
	printf("\t\t\t\t\t\t      MAIN MENU\n");
	printf("\t\t\t\t\t\t       1. Start\n");
	printf("\t\t\t\t\t\t       2. Set Target\n");
	printf("\t\t\t\t\t\t       3. Help\n");
	printf("\t\t\t\t\t\t       4. Exit\n");
	printf("\t\t\t\t\t\t       >> ");
	scanf("%d", &menu);
	
	switch (menu){
		case 1:
			start();
			break;
		case 2:
			settarget();
			break;	
		case 3:
			help();
			break;
		case 4:
			exit(1);
		default:
            errorHandle(1);
		    welcome();
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
int start(){
	char optstart;
	startmenu:
	system("cls");
	printf("\nApakah ini merupakan pertama kali anda menggunakan program ini? (Y/N)\n>> ");
	scanf("%c", &optstart);
	
	switch (optstart){
		case 'Y':
			settarget();
			break;
		case 'N':
			mulai();
			break;
            
		default:
            errorHandle(1);
            start();
		break;
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

void errorHandle(int pick){
	if (pick == 1){
		MessageBox(0, "Error!!", "Invalid Input", MB_OK); 
	}else if (pick == 2){
		MessageBox(0, "Error!!", "Memmory Not Allocated", MB_OK); 
	}
    
}

#endif
