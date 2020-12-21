#include <stdio.h>
#include <stdlib.h>

int settarget(){
	FILE *ftarget;
	
	ftarget = fopen("settarget.txt", "w");
	
	if(ftarget == NULL){
		printf("Error! File text tidak ditemukan.");
		exit(1);
	}
	
	printf("Masukkan target pengeluaran (tidak perlu menuliskan mata uang dan tanda koma): ");
	scanf("%d", &target);
	printf("\nTarget pengeluaran berhasil diperbaharui.\n");
	
	fprintf(ftarget, "%d", target);
	fclose(ftarget);
	
	return 0;
}

int analisis(Node *header){
	Node *temp = header;
	int jml[20];
	long int money;
	long int sum;
	float persentase;
	struct tm *pukul;
	time_t Tpukul;
	Tpukul = time(NULL);
	pukul = localtime(&Tpukul);
	FILE *fanalisis;
	
	while (temp != NULL){
		if(node->data.tm.tm_mon == pukul->tm_mon){	
			money = temp->data.uang;
			sum = sum + money;
			temp = temp.next;
		}
	}
	ftarget = fopen("settarget.txt", "r");
	fread(&target,sizeof(target),1,ftarget); //fread(&target,sizeof(target),1,fptr);
	
	persentase = (sum/target)*100;
	
	printf("Besarnya pengeluaran yang telah dikeluarkan adalah sebesar Rp %d,00.\n", sum);
	printf("Dengan target yang telah ditetapkan sebelumnya, persentase pengeluaran yang dihasilkan sebesar %.2f%%", persentase);
	
	if(persentase > 100){
		printf("Besarnya pengeluaran anda sudah melebihi dari target yang telah ditetapkan. Mohon untuk lebih bijak dalam mengelola keuangan anda.");
	}
}
