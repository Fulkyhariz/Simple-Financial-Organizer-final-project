#ifndef FOO_H_  
#define FOO_H_

void menuKategori();

/* program digunakan untuk memperoleh waktu lokal dan memasukannya ke linked list */
void getTime(Data *waktu){
    time_t t = time(NULL);
    waktu->tm = *localtime(&t);
    time(&(waktu->waktu));
}

/*fungsi untuk menentukan apakah mau di sort secara ascending atau descending*/
int ascdsc(){
    int s;
    printf("1. Ascending\n2. Descending\n>>");
    scanf("%d", &s);
    return s;
}
  
/*program untuk mengurutkan berdasarkan jumlah transaksi*/
Node* sortedMergeUang(Node* a, Node* b, int pick) 
{ 
    Node* result = NULL; 
  
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 

	if (pick == 1){
		
        if (a->data.uang <= b->data.uang) { 
            result = a; 
            result->next = sortedMergeUang(a->next, b, pick); 
        } 
        else { 
            result = b; 
            result->next = sortedMergeUang(a, b->next, pick); 
            } 
        return (result);
	}else if (pick == 2){
        
        if (a->data.uang >= b->data.uang) { 
            result = a; 
            result->next = sortedMergeUang(a->next, b, pick); 
        } 
        else { 
            result = b; 
            result->next = sortedMergeUang(a, b->next, pick); 
        } 
        return (result);
	}

} 

/*program untuk mengurutkan berdasarkan kategori*/
Node* sortedMergeKategori(Node* a, Node* b) 
{ 
    Node* result = NULL; 
  
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    if (a->data.kategori <= b->data.kategori) { 
        result = a; 
        result->next = sortedMergeKategori(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = sortedMergeKategori(a, b->next); 
    } 
    return (result); 
} 

/*program untuk mengurutkan berdasarkan waktu input*/
Node* sortedMergeTanggal(Node* a, Node* b, int pick) 
{ 
    Node* result = NULL; 
  
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
	if (pick == 1){
		if (difftime(a->data.waktu, b->data.waktu) <=0) { 
            result = a; 
            result->next = sortedMergeTanggal(a->next, b, pick); 
        } 
        else { 
            result = b; 
            result->next = sortedMergeTanggal(a, b->next, pick); 
        } 
        return (result); 
	}else if (pick == 2){
		if (difftime(a->data.waktu, b->data.waktu) >=0) { 
            result = a; 
        	result->next = sortedMergeTanggal(a->next, b, pick); 
        } 
        else { 
            result = b; 
            result->next = sortedMergeTanggal(a, b->next, pick); 
        } 
        return (result); 
	}
} 
  
/*digunakan dalam mergesort untuk membagi data menjadi dua bagian*/
void frontBackSplit(Node* source, Node** frontRef, Node** backRef) 
{ 
    Node* fast; 
    Node* slow; 
    slow = source; 
    fast = source->next; 
  
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
    *frontRef = source; 
    *backRef = slow->next; 
    slow->next = NULL; 
} 

/*fungsi untuk melakukan merge sort*/
void mergeSort(Node** headRef, int pick) //sorting
{ 
    Node* head = *headRef; 
    Node* a; 
    Node* b; 
  	int s;
    if ((head == NULL) || (head->next == NULL)) { 
    	printf("memori tidak mencukupi");
        exit(1);
    } 
  
    frontBackSplit(head, &a, &b); 
   
    mergeSort(&a, pick); //program rekursi untk melakukan mergesort pada data yang sudah di split
    mergeSort(&b, pick);
  
    if(pick == 1){
        *headRef = sortedMergeUang(a, b, 1);
	}else if(pick == 2){
        *headRef = sortedMergeUang(a, b, 2);
    }else if(pick == 3){
        *headRef = sortedMergeTanggal(a, b, 1);
	}else if(pick == 4){
        *headRef = sortedMergeTanggal(a, b, 2);
	}else if(pick == 5){
		*headRef = sortedMergeKategori(a, b);
	}else{
		printf("invalid input");
		return;
    }
}

/*program untuk mendapatkan kategori yang ada*/
int getCategory(){
    int s = 0;
    menuKategori();
    scanf("%d", &s);
    if (s == 1 || s == 2 || s == 3 || s == 4 || s == 5){
        return s;
    }else{
        printf("Invalid input!!");
        Sleep(3000);
        fflush(stdin);
        getCategory();
    }
}

/*program untuk memasukan data ke linked list*/
void push(Node** head_ref)
{
    long int s;
   
    Node* new_node = (Node*)malloc(sizeof(Node)); //dynamic memory allocation
    system("cls");
	printf("\nMasukan Nominal Transaksi\n>>");
    scanf("%d", &s);
    new_node->data.uang  = s;
	
    getTime(&(new_node->data));
	
	system("cls");
    new_node->data.kategori = getCategory();
	
	system("cls");
	printf("\nTambahkan Catatan\n");
    fflush(stdin);
    gets(new_node->data.note);
    system("cls");
 
    new_node->next = (*head_ref); 
   
    (*head_ref) = new_node;
}

/*program untuk menghapus sebuah node*/
void deleteNode(Node **head_ref, int key) 
{ 
    Node* temp = *head_ref, *prev; 
  
    if (temp != NULL && temp->data.uang == key)  //Searching
    { 
        *head_ref = temp->next;   
        free(temp);               
        return; 
    } 

    while (temp != NULL && temp->data.uang != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL) return; 
    prev->next = temp->next; 
    free(temp);  
}

/*program untuk menampilkan semua data yang ada*/
void printList(Node *node) 
{ 
    int i = 0;
    printf("  no.\t    Besar Transaksi\t    Kategori                Waktu Input\t\tCatatan\n\n");
    Node* last;
    char string[20];
    while (node != NULL) {
    	if(node->data.kategori == 1){
    		strcpy(string, "Makanan & Minuman    ");
		}else if(node->data.kategori == 2){
    		strcpy(string, "Transportasi         ");
		}else if(node->data.kategori == 3){
    		strcpy(string, "Hiburan              ");
		}else if(node->data.kategori == 4){
    		strcpy(string, "Kebutuhan Sehari-hari");
		}else{
			strcpy(string, "Kategori lain        ");
		}
        printf("  %d\t    Rp %ld.%.3ld\t\t    %.24s   %.16s\t%s   \n", i+1, node->data.uang/1000, node->data.uang%1000, string, ctime(&(node->data.waktu)), node->data.note);
        node = node->next;
        i++;
    }
}

/*program untuk membaca semua data dari file*/
Node* readFile(Node *head) 
{ 
    Node db, read, *data; 
    FILE *fp; 
    int banyak, j;
    fp = fopen("database.txt","r");
    if(fp == NULL){
        printf("gagal");
    }
	while (fread(&(read.data), sizeof(read.data),1,fp) > 0){//digunakan untuk menghitung jumlah node yang ada di linked list
    	j++;
    	banyak++;
	}
	fclose(fp);
	
	data = (Node*)malloc(banyak * sizeof(Node));
   	fp = fopen("database.txt", "r");
   	j = 0;
   	while (fread(&(read.data), sizeof(read.data),1,fp) > 0 && j<banyak){//membaca file dan memindahkan isinya ke linked list
        Node* new_node = (Node*)malloc(sizeof(Node));
  		strcpy(new_node->data.note, read.data.note);
	   	new_node->data.kategori = read.data.kategori;
   		new_node->data.uang = read.data.uang;
     	new_node->data.waktu = read.data.waktu;
     	new_node->data.tm = read.data.tm;
     	j++;
     	printf("reading data");
        new_node->next = (head); 
        (head) = new_node;
    }

    fclose(fp);
    return head;
}

/*program untuk menuliskan data dari node ke file*/
void writeFile(Node *head){
    FILE *fp;
    Node *temp = head;
    fp = fopen("database.txt", "w");

    while(temp != NULL){
        fwrite(&(temp->data), sizeof(temp->data), 1, fp);
        printf("writing file");
        temp = temp->next;
    }
    fclose(fp);
}

#endif
