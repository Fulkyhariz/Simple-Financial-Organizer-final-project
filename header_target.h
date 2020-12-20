#include <stdio.h>
#include <stdlib.h>

int settarget(){
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
