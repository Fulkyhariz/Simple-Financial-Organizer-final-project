/*Fungsi set target digunakan untuk mengatur target maksimal
pengeluaran dalam satu bulan*/
void setTarget(){
	system("cls");
	FILE *ftarget;
	int target;
	ftarget = fopen("settarget.txt", "w"); //program untuk membaca file settarget.txt
	
	if(ftarget == NULL){
		errorHandle(2);
		exit(1);
	}
	
	printf("Masukkan target pengeluaran (misal : 2000000)\nMasukan 0 jika ingin kembali ke menu utama\n>> ");
	scanf("%d", &target);
	
	if(target == '0'){
		welcome();
	}else{	
		fprintf(ftarget, "%d", target); //melakukan penulisan ke file
		fclose(ftarget);
	
		printf("\nTarget pengeluaran berhasil diperbaharui.\n");
	}
	printf("Tekan tombol apapun untuk melanjutkan");
	getch();
	mulai();

}

/*fungsi yang digunakan untuk menggambarkan perbedaan antara target pengeluaran 
dan total transaksi dalam waktu tersebut*/
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

/*menganalisa jumlah pengeluaran dalam satu bulan*/
void analisis(Node *header){
	FILE *ftarget;
	Node *temp = header;
	long int money, sum;
	float target, persentase;
	struct tm *pukul;
	
	time_t Tpukul;
	Tpukul = time(NULL);
	pukul = localtime(&Tpukul); //mengambil waktu sekarang untuk memperoleh bulan
	
	/*menambahkan semua transaksi total pada bulan yg sama dengan localtime*/
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
	
	printf("Besarnya pengeluaran yang telah dikeluarkan adalah sebesar Rp %d,00.\n\n", sum);
	printf("Dengan target yang telah ditetapkan sebelumnya\npersentase pengeluaran yang dihasilkan sebesar %.2f%%\n\n", persentase);
	
	if(persentase > 100){
		printf("Besarnya pengeluaran anda sudah melebihi dari target yang telah ditetapkan\nMohon untuk lebih bijak dalam mengelola keuangan anda.");
	}
	
}
