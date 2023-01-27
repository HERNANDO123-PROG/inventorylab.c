#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct inventory
{
    char nama_lab[50];
    char nama_barang[50];
    char merk_barang[50];
    char spek_barang[1000];
    int jumlah_barang;
};

void lihatdatabarang();
void tambahdatabarang();
void caridatabarang();
void editdatabarang();
void urutkandatabarang();
void hapusdatabarang(); 

void lihatdatabarang (){
    FILE *fptr;
    struct inventory data;
    fptr = fopen("pendataan inventory lab.txt", "r");
    printf("Nama Lab\tNama Barang\tMerk barang\tspek barang\tJumlah\n");
    while (fscanf(fptr, "%s %s %s %s %d", data.nama_lab, data.nama_barang, data.merk_barang, data.spek_barang, &data.jumlah_barang) != EOF)
    {
        printf("%s\t\t%s\t\t%s\t\t%s\t\t%d\n", data.nama_lab, data.nama_barang, data.merk_barang, data.spek_barang, data.jumlah_barang);
    }
    fclose(fptr);
    printf("\nTekan enter untuk kembali ke menu\n");
    getchar();
    getchar();
}
       
void tambahdatabarang (){
    FILE*fptr;
    struct inventory data;
    fptr = fopen ("pendataan inventory lab.txt","a");
    printf("==================================================\n");
    printf ("Masukkan Nama Lab ITTS : ");
    scanf ("%s", data.nama_lab);
    printf ("Masukkan nama barang yang ingin di tambahkan :");
    scanf ("%s", data.nama_barang);
    printf ("Masukkan merk barang yang ingin di tambahkan :");
    scanf ("%s", data.merk_barang);
    printf ("Masukkan spek barang yang ingin di tambahkan :");
    scanf ("%s", data.spek_barang);
    printf ("Masukkan jumlah barang yang ingin di tambahkan :");
    scanf ("%d", &data.jumlah_barang);
    fprintf (fptr,"%s %s %s %s %d\n",data.nama_lab,data.nama_barang,data.merk_barang,data.spek_barang,data.jumlah_barang);
    fclose (fptr);
    printf ("\nData telah sukses di tambahkan\n");
    printf("\nEnter untuk kembali ke menu\n");
    getchar();
    getchar();
}

int main(){
int pilih;
while (1)
{   printf("|=====================================|\n");
    printf("|====Pendataan Inventory Lab ITTS=====|\n");
    printf("|=====================================|\n");
    printf("Select Menu : \n");
    printf("1. Lihat Data \n");
    printf("2. Tambah Data \n");
    printf("3. Cari Data \n");
    printf("4. Urutkan Data \n");
    printf("5. Edit Data \n");
    printf("6. Hapus Data \n");
    printf("7. Exit\n");
    printf("======================================\n");
    printf("Menu : ");
    scanf ("%d", &pilih);

    switch (pilih)
    {
    case 1 : 
            lihatdatabarang();
        break;
    
    case 2 : 
            tambahdatabarang();
        break;
    
    case 3 :
            caridatabarang();
        break;
    
    case 4 :
            urutkandatabarang();
        break;
    
    case 5 :
            editdatabarang();
        break;
    case 6 :
            hapusdatabarang();
        break;
    case 7 : return 0;
        break;
    default :
        printf ("Pilihan Yang anda masukkan tidak tersedia\n");
        break;
    }
  }   
}

void urutkandatabarang()
{
    FILE *fptr;
    struct inventory data[100];
    int a = 0, b, min_idx;
    fptr = fopen("pendataan inventory lab.txt", "r");
    while (fscanf(fptr, "%s %s %s %s %d", data[a].nama_lab,data[a].nama_barang,data[a].merk_barang,data[a].spek_barang,&data[a].jumlah_barang) != EOF)
    {
        a++;
    }
    fclose(fptr);
    int c = a;
    for (a = 0; a < c - 1; a++)
    {
        min_idx = a;
        for (b = a + 1; b < c; b++)
        {
            if (strcmp(data[b].nama_lab, data[min_idx].nama_lab) < 0)
            {
                min_idx = b;
            }
        }
        struct inventory temp = data[min_idx];
        data[min_idx] = data[a];
        data[a] =temp;
    }
    fptr = fopen("pendataan inventory lab.txt", "w");
    for (a = 0; a < b; a++)
    {
        fprintf(fptr, "%s %s %s %s %d\n", data[a].nama_lab, data[a].nama_barang,data[a].merk_barang,data[a].spek_barang,data[a].jumlah_barang);
    }
    fclose(fptr);
    printf("Data berhasil diurutkan\n");
    printf("Tekan enter untuk kembali ke menu\n");
    getchar();
    getchar();
}

void editdatabarang()
{
    FILE*fptr;
    struct inventory data;
    char gantilab[100];
    printf("Masukkan nama lab yang ingin di ganti : ");
    scanf("%s", gantilab);
    fptr = fopen ("pendataan inventory lab.txt","r");  
    FILE*temp = fopen("temp.txt","w");
    while (fscanf(fptr, "%s %s %s %s %d", data.nama_lab, data.nama_barang, data.merk_barang, data.spek_barang, &data.jumlah_barang) != EOF)
    {
        if (strcmp(data.nama_lab, gantilab) ==0 )
        {
            printf("Masukkan nama lab baru : ");
            scanf("%s", data.nama_lab);
            printf("Masukkan nama barang baru :");
            scanf("%s", data.nama_barang);
            printf("Masukkan merk barang baru :");
            scanf("%s", data.merk_barang);
            printf("Masukkan spek barang baru :");
            scanf("%s", data.spek_barang);
            printf("Masukkan jumlah barang :");
            scanf("%d", &data.jumlah_barang);
        }
        fprintf(temp, "%s %s %s %s %d\n", data.nama_lab, data.nama_barang, data.merk_barang, data.spek_barang, data.jumlah_barang);
    }
    fclose(fptr);
    fclose(temp);
    remove("pendataan inventory lab.txt");
    rename("temp.txt", "pendataan inventory lab.txt");
    printf("\ndata berhasil ditambahkan\n");
    printf("Tekan enter kembali ke menu\n");
    getchar();
    getchar();
}

int compare(const void *a, const void*b)
{
    struct inventory *ia = (struct inventory *)a;
    struct inventory *ib = (struct inventory *)b;
    return strcmp(ia->nama_lab, ib->nama_lab);
}

void caridatabarang()
{
    FILE *fptr;
    struct inventory data[100];
    char gantilab[100];
    int x = 0, low, high, mid, flag = 0;
    fptr = fopen("pendataan inventory lab.txt","r");
    while(fscanf(fptr,"%s %s %s %s %d", data[x].nama_lab, data[x].nama_barang, data[x].merk_barang, data[x].spek_barang, &data[x].jumlah_barang) != EOF)
    {
        x++;
    }
    fclose(fptr);
    int y = x;
    qsort(data,y, sizeof(struct inventory), compare);
    printf("Masukkan nama lab : ");
    scanf("%s", gantilab);
    low = 0;
    high = y - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if(strcmp(data[mid].nama_lab, gantilab) == 0)
        {
            printf("Data ditemukan\n");
            printf("Nama Lab : %s\nNama Barang : %s\nMerk Barang : %s\nSpek Barang : %s\nJumlah Barang ; %d\n",data[mid].nama_lab, data[mid].nama_barang, data[mid].merk_barang, data[mid].spek_barang, data[mid].jumlah_barang);
            flag = 1;
            break;
        }
        else if (strcmp(data[mid].nama_lab, gantilab) > 0)
        {
            high = mid - 1;
        }
        else
        {
            low = mid +1;
        }
    }
    if (flag == 0)
    {
        printf("Data tidak ditemukan");
    }
    printf("Tekan enter untuk kembali ke menu\n");
    getchar();
    getchar();

}

void hapusdatabarang()
{
    FILE *fptr;
    struct inventory data;
    char lab_hapus[100];
    int flag = 0;
    printf("Masukkan nama lab yang ingin dihapus: ");
    scanf("%s", lab_hapus);
    fptr = fopen("pendataan inventory lab.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    while (fscanf(fptr, "%s %s %s %s %d", data.nama_lab, data.nama_barang, data.merk_barang, data.spek_barang,&data.jumlah_barang) != EOF)
    {
        if (strcmp(data.nama_lab, lab_hapus) != 0)
        {
            fprintf(temp, "%s %s %s %s %d\n", data.nama_lab, data.nama_barang, data.merk_barang, data.spek_barang,&data.jumlah_barang);
        }
        else
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        printf("Data berhasil dihapus\n");
    }
    else
    {
        printf("Data tidak ditemukan\n");
    }
    fclose(fptr);
    fclose(temp);
    remove("pendataan inventory lab.txt");
    rename("temp.txt", "pendataan inventory lab.txt");
    printf("Tekan enter untuk kembali ke menu\n");
    getchar();
    getchar();

}