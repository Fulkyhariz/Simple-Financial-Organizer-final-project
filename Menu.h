void help();
void errorHandle();
void riwayat(Node *head);
void setTarget();
void analisis(Node *header);

void welcome(){
	system("cls");
	int menu;
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
	
	if (menu == 1){
		start();
	}else if(menu == 2){
		setTarget();
	}else if(menu == 3){
		help();
	}else if(menu == 4){
		exit(1);
	}else{
		errorHandle(1);
		welcome();
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
	welcome();
}

void mulai(){
    Node *head = NULL;
    head = readFile(head);
    fflush(stdin);
	int menu;
	system("cls");
	printf("Apa yang ingin ada lakukan pada program ini?\n");
	printf("1. Tambah Transaksi\n");
	printf("2. Lihat Riwayat\n");
	printf("3. Lihat analisis pengeluaran\n");
	printf("4. Kembali ke menu awal\n>> ");
	scanf("%d", &menu);
	
	if (menu == 1){
		system("cls");
		push(&head);
		writeFile(head);
		mulai();
	}else if(menu == 2){
		system("cls");
		riwayat(head);
		printList(head);
		printf("\nTekan enter untuk melanjutkan");
		getch();
		mulai();
	}else if(menu == 3){
		system("cls");
		analisis(head);
		printf("\nTekan enter untuk melanjutkan");
		getch();
		mulai();
	}else if(menu == 4){
		system("cls");
		welcome();
	}else{
		errorHandle(1);
		mulai();
	}
	
}

int start(){
	char optstart;
	startmenu:
	system("cls");
	printf("\nApakah ini merupakan pertama kali anda menggunakan program ini? (Y/N)\n>> ");
	fflush(stdin);
	scanf("%c", &optstart);
	
	switch (optstart){
		case 'Y':
			setTarget();
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

int hapus(){
	int s;
	printf("Masukan nominal yang ingin dihapus dari riwayat\n>>");
	scanf("%d", &s);
	return s;
}

void riwayat(Node *head){
    int pick, asc;
	system("cls");
	printf("Urutkan Bedasarkan?\n");
	printf("1. Jumlah Transaksi\n");
	printf("2. Waktu input\n");
	printf("3. Kategori\n");
	printf("\natau:\n");
	printf("4. Hapus data\n");
	printf("5. Kembali ke menu awal\n>> ");
	scanf("%d", &pick);

    if(pick == 3){
        mergeSort(&head, 5);
    }else if (pick == 1 || pick == 2){
    	asc = ascdsc();
    }else if (pick == 1 && asc == 1){
        mergeSort(&head, 1);
    }else if (pick == 1 && asc == 2){
        mergeSort(&head, 2);
    }else if (pick == 2 && asc == 1){
        mergeSort(&head, 3);
    }else if (pick == 2 && asc == 2){
        mergeSort(&head, 4);
    }else if (pick == 4){
    	deleteNode(&head, hapus());
    	printList(head);
    	getch();
    	mulai();
	}else{
        errorHandle(1);
        riwayat(head);
    }
}

void errorHandle(int pick){
	if (pick == 1){
		MessageBox(0, "Invalid Input", "Error!!", MB_OK); 
	}else if (pick == 2){
		MessageBox(0, "Memmory Not Allocated", "Error!!", MB_OK); 
	}
    
}
