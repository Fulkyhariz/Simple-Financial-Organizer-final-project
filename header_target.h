#include <stdio.h>
#include <stdlib.h>

int target;

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
/*
int analisis(){
	float persentase;
	int total;
	FILE *fanalisis;
	
	fanalisis = fopen("analisis.txt", "a");
	
	if(fanalisis == NULL){
		printf("Error! File text tidak ditemukan.");
		exit(1);
	}
	persentase = (total/target)*100
	printf("Besarnya pengeluaran yang telah dikeluarkan adalah sebesar Rp %d,00.\n", total);
	printf("Dengan target yang telah ditetapkan sebelumnya, persentase pengeluaran yang dihasilkan sebesar %.2f%%", persentase);
	
	if(persentase > 100){
		printf("Besarnya pengeluaran anda sudah melebihi dari target yang telah ditetapkan. Mohon untuk lebih bijak dalam mengelola keuangan anda.");
	}
	
	fprintf(fanalisis, "Persentase pengeluaran: %.2f%%", persentase);
	fclose(fanalisis);
	
	return 0;
} */ 
