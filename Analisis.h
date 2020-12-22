void gotoxy(short x, short y) {
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setTarget(){
	system("cls");
	FILE *ftarget;
	int target;
	ftarget = fopen("settarget.txt", "w");
	
	if(ftarget == NULL){
		errorHandle(2);
		exit(1);
	}
	
	printf("Masukkan target pengeluaran (misal : 2000000)\nMasukan 0 jika ingin kembali ke menu utama\n>> ");
	scanf("%d", &target);
	
	if(target == '0'){
		welcome();
	}else{	
		fprintf(ftarget, "%d", target);
		fclose(ftarget);
	
		printf("\nTarget pengeluaran berhasil diperbaharui.\n");
	}
	printf("Tekan tombol apapun untuk melanjutkan");
	getch();
	mulai();

}

void visualize(int x,float y){
	x = x/10000;y = y/10000;
    printf("\n");
    for(x;x<y;y--){
    	if(y == 0){
    		break;
		}
    	printf("   **              \n");
    }
    for(x;x>y;x--){
    	if(x == 0){
    		break;
		}
	    printf("**                 \n");
    }
    for(x;x<=y;x--){
    	if (x ==0){
    		break;
		}
   		printf("**               **\n");
    }
    printf("pengeluaran      target\n\n");
}

void analisis(Node *header){
	Node *temp = header;
	long int money;
	long int sum;
	float target;
	float persentase;
	struct tm *pukul;
	time_t Tpukul;
	Tpukul = time(NULL);
	pukul = localtime(&Tpukul);
	FILE *ftarget;
	
	
	while (temp != NULL){
		if(temp->data.tm.tm_mon == pukul->tm_mon){	
			money = temp->data.uang;
			sum = sum + money;
			temp = temp->next;
		}
	}
	ftarget = fopen("settarget.txt", "r");
	fscanf(ftarget, "%f", &target);
	fclose(ftarget);
	persentase = (sum/target)*100;
	
	visualize(sum, target);
	
	printf("Besarnya pengeluaran yang telah dikeluarkan adalah sebesar Rp %d,00.\n", sum);
	printf("Dengan target yang telah ditetapkan sebelumnya\npersentase pengeluaran yang dihasilkan sebesar %.2f %\n", persentase);
	
	if(persentase > 100){
		printf("Besarnya pengeluaran anda sudah melebihi dari target yang telah ditetapkan\nMohon untuk lebih bijak dalam mengelola keuangan anda.");
	}
	
}

