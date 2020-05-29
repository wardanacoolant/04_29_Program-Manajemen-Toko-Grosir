/*
Anggota kelompok:
- Widya Dharma Sidi (1608561004)
- I Made Wardana (1608561029)

Nama program : Program Manajemen Sederhana Toko Grosir
Deskripsi program : Program ini menawarkan kemudahan dalam hal memanajemen transaksi khususnya
                    pada toko grosir. Dibuat dalam bahasa C, program ini memanfaatkan linked list
                    sebagai struktur datanya.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

int akun = 0, hitung_masuk = 0, hitung_keluar = 0, stok;
char yakin, pilih_exit;

struct simpul_info_toko
{
    char nama_toko[20];
    char alamat[50];
    char kota[20];
    char npwp[20];
    char nama_barang[20];
    char satuan_grosir[10];
    int harga_beli;
    int harga_jual;
    int kapasitas_max;
    char mata_uang[3];
}info_toko;

struct password
{
    char password_admin[8];
    char password_supervisor[8];
    char pil_ganti_password;
    char admin_sementara[8];
    char supervisor_sementara[8];
}head_password;

struct simpul_masuk
{
    int ID;
    char nama[20];
    int jml;
    struct simpul_masuk *next;
}*front_masuk = NULL,*rear_masuk = NULL,*head_data_barang_masuk = NULL;

struct simpul_masuk *temp_data_barang_masuk = NULL;
struct simpul_masuk *temp_data_barang_keluar = NULL;

struct simpul_keluar
{
    int ID;
    char nama[20];
    int jml;
    struct simpul_keluar *next;
}*front_keluar = NULL, *rear_keluar = NULL,*head_data_barang_keluar = NULL;

struct simpul_supervisor
{
    int nomor_data_diedit;
    int pil_edit_data;
    struct simpul *next;
}*supervisor = NULL;

int main()
{
    baca_data();
    selamat_datang();
    while (akun == 0)
    {
        system("cls");
        header();
        list_akun();
        akun = pilihan_akun();
        switch(akun)
        {
        case 1:
                system("cls");
                header();
                akun_administrator();
                akun = 0;
                break;
        case 2:
            system("cls");
            header();
            akun_supervisor();
            akun = 0;
            break;
        case 3:
            system("cls");
            header();
            akun_user();
            akun = 0;
            break;
        case 4:
            exit_prompt();
            break;
        default:
            printf("\nMaaf, inputan salah!\n");
            system("pause");
            akun = 0;
            break;
        }
    }
    return 0;
}

void selamat_datang()
{
    system("cls");
printf("      Selamat datang di Program Manajemen Sederhana...\n\n");
printf("               ooooo        8             \n");
printf("                 8          8             \n");
printf("                 8   .oPYo. 8  .o  .oPYo. \n");
printf("                 8   8    8 8oP'   8    8 \n");
printf("                 8   8    8 8 `b.  8    8 \n");
printf("                 8   `YooP' 8  `o. `YooP' \n");
printf("               ::..:::.....:..::...:.....:\n");
printf("               :::::::::::::::::::::::::::\n");
printf("               :::::::::::::::::::::::::::\n");
printf("                                               \n");
printf("           .oPYo.                      o       \n");
printf("           8    8                              \n");
printf("           8      oPYo. .oPYo. .oPYo. o8 oPYo. \n");
printf("           8   oo 8  `' 8    8 Yb..    8 8  `' \n");
printf("           8    8 8     8    8   'Yb.  8 8     \n");
printf("           `YooP8 8     `YooP' `YooP'  8 8     \n");
printf("           :....8 ..:::::.....::.....::....::::\n");
printf("           :::::8 :::::::::::::::::::::::::::::\n");
printf("           :::::..:::::::::::::::::::::::::::::\n\n");
printf("       Nama toko : %s | Menjual %s!\n\n", info_toko.nama_toko, info_toko.nama_barang);
    system("pause");
}

void header()
{

printf("           _____    _          ___            _     \n");
printf(" Program  |_   _|__| |_____   / __|_ _ ___ __(_)_ _ \n");
printf(" Manajemen  | |/ _ %c / / _ %c | (_ | '_/ _ (_-< | '_|\n", 92,92);
printf("            |_|%c___/_%c_%c___/  %c___|_| %c___/__/_|_|  \n", 92,92,92,92,92);
printf("==========================================================\n\n");
}

void list_akun()
{
    printf("Pilihan:\n");
    printf("1. Konfigurasi Program\n");
    printf("2. Penghapusan Data Barang\n");
    printf("3. Penginputan Data Barang\n");
    printf("4. Keluar\n\n");
    printf("Pilih nomor : ");
}

int pilihan_akun()
{
    int pil_akun;
    scanf("%d", &pil_akun);
    return pil_akun;
}

void akun_administrator()
{
    system("cls");
    header();
    int pil_admin;
    printf("Pilihan:\n");
    printf("1. Lihat informasi toko\n");
    printf("2. Ubah informasi toko\n");
    printf("3. Simpan pencapaian terkini\n");
    printf("4. Kembali\n\n");
    printf("Pilih nomor : ");
    scanf("%d", &pil_admin);
    switch(pil_admin)
    {
    case 1:
        lihat_info_toko();
        break;
    case 2:
        ubah_info_toko();
        break;
    case 3:
        simpan_data();
        break;
    case 4:
        return 0;
        break;
    default:
        printf("Maaf, inputan salah.");
        break;
    }

}

void akun_supervisor()
{
    int pil_supervisor;
        system("cls");
        header();
        printf("Pilihan:\n1. Hapus data barang\n2. Kembali\n\nPilih nomor : ");
        scanf("%d", &pil_supervisor);
        switch(pil_supervisor)
        {

            case 1:
                system("cls");
                header();
                int pil_hapus_data;
                printf("Pilihan:\n1. Hapus data barang masuk\n2. Hapus data barang keluar\n3. Kembali\n\nPilih nomor : ");
                scanf("%d", &pil_hapus_data);
                switch(pil_hapus_data)
                {
                case 1:
                    delete_masuk();
                    break;
                case 2:
                    delete_keluar();
                    break;
                case 3:
                    return akun_supervisor();
                    break;
                default:
                    printf("Maaf, inputan salah!");
                    system("pause");
                    return akun_supervisor();
                    break;
                }
                break;
            case 2:
                return list_akun();
                break;
        }
        system("pause");
        akun = 0;
}

void akun_user()
{
    int pilihan_akun_user;
    system("cls");
    header();
    printf("Pilihan:\n1. Manajemen data barang\n2. Lihat semua transaksi\n3. Kembali\n\nPilih nomor : ");
    scanf("%d", &pilihan_akun_user);
    switch(pilihan_akun_user)
    {
    case 1:
        system("cls");
        header();
        int pil_manajemen, jml;
        char name[20];
        printf("Pilihan:\n1. Barang masuk (pembelian)\n2. Barang keluar (penjualan)\n3. Kembali\n\nPilih nomor : ");
        scanf("%d", &pil_manajemen);
        switch(pil_manajemen)
        {
        case 1:
            system("cls");
            header();
            printf("Masukkan nama supplier : ");
            fflush(stdin);
            gets(name);
            printf("Masukkan jumlah barang masuk (%s) : ", info_toko.satuan_grosir);
            scanf("%d", &jml);
            FILE *fsss;
            fsss = fopen("stok.txt", "r");
            fscanf(fsss, "%d", &stok);
            fclose(fsss);
            if(stok <= info_toko.kapasitas_max)
            {
                input_barang_masuk(name, jml);
            }
            else
            {
                printf("Maaf, stok barang penuh!\n");
                system("pause");
            }
            break;
        case 2:
            system("cls");
            header();
            printf("Masukkan nama supplier : ");
            fflush(stdin);
            gets(name);
            printf("Masukkan jumlah barang masuk (%s) : ", info_toko.satuan_grosir);
            scanf("%d", &jml);
            stok = stok - jml;
            input_barang_keluar(name, jml);
            break;
        case 3:
            system("pause");
            break;
        }
        break;
    case 2:
        system("cls");
        header();
        int pil_tampilkan;
        printf("Pilihan:\n1. Tampilkan daftar barang masuk (pembelian)\n2. Tampilkan daftar barang keluar (penjualan)\n3. Kembali\n\nPilih nomor : ");
        scanf("%d", &pil_tampilkan);
        switch(pil_tampilkan)
        {
        case 1:
            system("cls");
            header();
            display_masuk();
            break;
        case 2:
            system("cls");
            header();
            display_keluar();
            break;
        case 3:
            break;
        }
    }
}

exit_prompt()
{
    do
    {
        system("cls");
        printf("Yakin ingin keluar dari program?\nTekan 'Y' untuk melanjutkan : ");
        fflush(stdin);
        scanf("%c", &pilih_exit);
        pilih_exit = toupper(pilih_exit);
    }
    while (pilih_exit != 'Y');
    if(pilih_exit == 'Y')
        exit(1);
}

void ubah_info_toko()
{
    FILE *fptr;
    fptr = fopen("info_toko.txt", "w+");
    printf("Nama toko : ");
    fflush(stdin);
    gets(info_toko.nama_toko);
    fprintf(fptr, "Nama toko: %s\n", info_toko.nama_toko);
    printf("Alamat : ");
    fflush(stdin);
    gets(info_toko.alamat);
    fprintf(fptr, "Alamat: %s\n", info_toko.alamat);
    printf("Kota : ");
    fflush(stdin);
    gets(info_toko.kota);
    fprintf(fptr, "Kota: %s\n", info_toko.kota);
    printf("NPWP : ");
    fflush(stdin);
    gets(info_toko.npwp);
    fprintf(fptr, "NPWP: %s\n", info_toko.npwp);
    printf("Nama barang : ");
    fflush(stdin);
    gets(info_toko.nama_barang);
    fprintf(fptr, "Nama_barang: %s\n", info_toko.nama_barang);
    printf("Satuan grosir : ");
    fflush(stdin);
    gets(info_toko.satuan_grosir);
    fprintf(fptr, "Satuan_grosir: %s\n", info_toko.satuan_grosir);
    printf("Harga beli (per %s) : ", info_toko.satuan_grosir);
    scanf("%d", &info_toko.harga_beli);
    fprintf(fptr, "Harga_beli: %d\n", info_toko.harga_beli);
    printf("Harga jual (per %s) : ", info_toko.satuan_grosir);
    scanf("%d", &info_toko.harga_jual);
    fprintf(fptr, "Harga_jual: %d\n", info_toko.harga_jual);
    printf("Kapasitas stok barang maksimum (%s) : ", info_toko.satuan_grosir);
    scanf("%d", &info_toko.kapasitas_max);
    fprintf(fptr, "Kapasitas_stok_barang_maksimum: %d\n", info_toko.kapasitas_max);
    printf("Mata uang : ");
    fflush(stdin);
    gets(info_toko.mata_uang);
    fprintf(fptr, "Mata_uang: %s\n", info_toko.mata_uang);
    fclose(fptr);

    fptr = fopen("nama_toko.txt", "w+");
    fputs(info_toko.nama_toko, (FILE *)fptr);
    fclose(fptr);
    fptr = fopen("nama_barang.txt", "w+");
    fputs(info_toko.nama_barang, (FILE *)fptr);
    fclose(fptr);
    fptr = fopen("satuan_grosir.txt", "w+");
    fputs(info_toko.satuan_grosir, (FILE *)fptr);
    fclose(fptr);
    fptr = fopen("harga_beli.txt", "w+");
    fprintf(fptr, "%d", info_toko.harga_beli);
    fclose(fptr);
    fptr = fopen("harga_jual.txt", "w+");
    fprintf(fptr, "%d", info_toko.harga_jual);
    fclose(fptr);
    fptr = fopen("kapasitas_max.txt", "w+");
    fprintf(fptr, "%d", info_toko.kapasitas_max);
    fclose(fptr);
    fptr = fopen("mata_uang.txt", "w+");
    fputs(info_toko.mata_uang, (FILE *)fptr);
    fclose(fptr);

    printf("\nInformasi toko berhasil disimpan!");
    system("pause");
}

void lihat_info_toko()
{
    FILE *fptr;
    char ch;
    fptr = fopen("info_toko.txt", "r");
    if(fptr == NULL)
    {
        printf("Maaf, informasi toko tidak ditemukan!\n");
        system("pause");
    }
    else
    {
        printf("Informasi toko :\n\n");
        ch = fgetc(fptr);
        while(ch != EOF)
        {
            printf("%c", ch);
            ch = fgetc(fptr);
        }
        system("pause");
    }
    fclose(fptr);
}

int apakah_linkedlist_databarang_ada(int jenis_data)
{
    switch(jenis_data)
    {
    case 1:
        if(head_data_barang_masuk == NULL)
            return 0;
        else
            return 1;
        break;
    case 2:
        if(head_data_barang_keluar == NULL)
            return 0;
        else
            return 1;
        break;
    }
}

void edit_data_barang()
{
        system("cls");
        header();
        int pil_edit_data;
        printf("Pilihan:\n1. Edit data barang masuk\n2. Edit data barang keluar\n3. Kembali\n\nPilih nomor : ");
        scanf("%d", &pil_edit_data);
        switch(pil_edit_data)
        {
        case 1:
            system("cls");
            header();
            switch(apakah_linkedlist_databarang_ada(1))
            {
            case 0:
                printf("Data barang masih kosong!\n");
                break;
            case 1:
                display_masuk();
                printf("\nPilih nomor data yang ingin diedit : ");
                scanf("%d", &supervisor -> nomor_data_diedit);
                if(supervisor -> nomor_data_diedit <= 0 || supervisor -> nomor_data_diedit > hitung_masuk)
                    printf("Maaf, inputan salah!");
                else
                {
                    edit_barang_spesifik(1, supervisor -> nomor_data_diedit);
                    printf("Edit data barang masuk nomor %d berhasil!", supervisor -> nomor_data_diedit);
                }
                system("pause");
                break;
            }
        case 2:
            system("cls");
            header();
            switch(apakah_linkedlist_databarang_ada(1))
            {
            case 0:
                printf("Data barang masih kosong!");
                break;
            case 1:
                display_keluar();
                printf("\nPilih nomor data yang ingin diedit : ");
                scanf("%d", &supervisor -> nomor_data_diedit);
                if(supervisor -> nomor_data_diedit <= 0)
                    printf("Maaf, inputan salah!");
                else
                {
                    edit_barang_spesifik(2, supervisor -> nomor_data_diedit);
                    printf("Edit data barang masuk nomor %d berhasil!", supervisor -> nomor_data_diedit);
                }
                system("pause");
                break;
            }
        case 3:
            return;
            break;
        }
    system("pause");
}

void input_barang_masuk(char nama_[], int byk)
{
    struct simpul_masuk *newNode;
    newNode = (struct simpul_masuk*)malloc(sizeof(struct simpul_masuk));
    hitung_masuk++;
    if(1)
    {
        newNode->ID = hitung_masuk;
    newNode->nama[20] = nama_[20];
    newNode->jml = byk;
    newNode -> next = NULL;
    if(front_masuk == NULL)
        front_masuk = rear_masuk = newNode;
    else{
        rear_masuk -> next = newNode;
        rear_masuk = newNode;
    }
    printf("\nInput data barang masuk sukses!\n");
    FILE *fss;
    fss = fopen("stok.txt", "w+");
    fprintf(fss, "%d", stok+byk);
    fclose(fss);
    }
    else{
        printf("Maaf, data gagal dimasukkan!");
    hitung_masuk--;
    }


    system("pause");
}

void input_barang_keluar(char nama_[20], int byk)
{
   struct simpul_keluar *newNode;
   newNode = (struct simpul_keluar*)malloc(sizeof(struct simpul_keluar));
   hitung_keluar++;
   newNode->ID = hitung_keluar;
   newNode->nama[20] = nama_[20];
   newNode->jml = byk;
   newNode -> next = NULL;
   if(front_keluar == NULL)
      front_keluar = rear_keluar = newNode;
   else{
      rear_keluar -> next = newNode;
      rear_keluar = newNode;
   }
   printf("\nInput data barang keluar sukses!\n");
   FILE *fss;
    fss = fopen("stok.txt", "w+");
    fprintf(fss, "%d", (stok-byk));
    fclose(fss);
   system("pause");
}

void display_masuk()
{
   if(front_masuk == NULL)
   {
       printf("\nData barang masuk kosong!\n");
       system("pause");
   }
   else{
      struct simpul_masuk *temp = front_masuk;
      while(temp->next != NULL)
        {
            printf("   %d (%d)", temp->ID, temp->jml);
            printf("\n\n     v\n     v\n\n");
            temp = temp -> next;
      }
      printf("   %d (%d)", temp->ID, temp->jml);
      printf("\n\n     v\n     v\n\n  (NULL)\n\n");
      system("pause");
   }
}

void display_keluar()
{
   if(front_keluar == NULL)
   {
       printf("\nData barang keluar kosong!\n");
       system("pause");
   }
   else{
      struct simpul_keluar *temp = front_keluar;
      while(temp->next != NULL)
        {
            printf("   %d (%d)", temp->ID, temp->jml);
            printf("\n\n     v\n     v\n\n");
            temp = temp -> next;
        }
      printf("   %d (%d)", temp->ID, temp->jml);
      printf("\n\n     v\n     v\n\n  (NULL)\n\n");
      system("pause");
   }
}

int edit_barang_spesifik(int jenis_data, int nomor)
{
    struct simpul_masuk *search_data_barang_masuk;
    struct simpul_keluar *search_data_barang_keluar;
    switch(jenis_data)
    {
    case 1:
        search_data_barang_masuk = head_data_barang_masuk;
        if(search_data_barang_masuk -> ID == nomor)
        {
            printf("Masukkan nama supplier baru : ");
            fflush(stdin);
            gets(search_data_barang_masuk -> nama);
            printf("Masukkan jumlah barang masuk baru (%s) : ", info_toko.satuan_grosir);
            scanf("%d", &search_data_barang_masuk -> jml);
        }
        else
        {
            while((search_data_barang_masuk =search_data_barang_masuk -> next) != NULL)
            {
                search_data_barang_masuk = search_data_barang_masuk -> next;
                if(search_data_barang_masuk -> ID == nomor)
                {
                    search_data_barang_masuk = search_data_barang_masuk -> next;
                    printf("Masukkan nama supplier baru : ");
                    fflush(stdin);
                    gets(search_data_barang_masuk -> nama);
                    printf("Masukkan jumlah barang masuk baru (%s) : ", info_toko.satuan_grosir);
                    scanf("%d", &search_data_barang_masuk -> jml);
                }
                else
                    search_data_barang_masuk = search_data_barang_masuk -> next;
            }
            printf("Data barang masuk bernomor %d tidak ditemukan!", nomor);
            system("cls");
        }
        break;
    case 2:
        search_data_barang_keluar = head_data_barang_keluar;
        if(search_data_barang_keluar -> ID == nomor)
        {
            printf("Masukkan nama pembeli baru : ");
            fflush(stdin);
            gets(search_data_barang_keluar -> nama);
            printf("Masukkan jumlah barang keluar baru (%s) : ", info_toko.satuan_grosir);
            scanf("%d", &search_data_barang_keluar -> jml);
        }
        else
        {
            while((search_data_barang_keluar = search_data_barang_keluar -> next) != NULL)
            {
                search_data_barang_keluar = search_data_barang_keluar -> next;
                if(search_data_barang_keluar -> ID == nomor)
                {
                    search_data_barang_keluar = search_data_barang_keluar -> next;
                    printf("Masukkan nama pembeli baru : ");
                    fflush(stdin);
                    gets(search_data_barang_keluar -> nama);
                    printf("Masukkan jumlah barang keluar baru (%s) : ", info_toko.satuan_grosir);
                    scanf("%d", &search_data_barang_keluar -> jml);
                }
                else
                    search_data_barang_keluar = search_data_barang_keluar -> next;
            }
            printf("Data barang keluar bernomor %d tidak ditemukan!", nomor);
            system("cls");
        }
        break;
    }
}

void cetak_garis(int panj_garis)
{
    int i;
    for(i=1;i<=panj_garis;i++)
        printf("-");
    printf("\n");
}

void header_tabel()
{
    printf(" No\t| Nama\t\t| Jml\t| Harga\n");
}

void simpan_data()
{
    FILE *fsd;
    fsd = fopen("hitung_masuk.txt", "w+");
    fprintf(fsd, "%d", hitung_masuk);
    fclose(fsd);
    fsd = fopen("hitung_keluar.txt", "w+");
    fprintf(fsd, "%d", hitung_keluar);
    fclose(fsd);

    printf("Data pencapaian terkini berhasil disimpan!\n");
    system("pause");
}

void delete_masuk()
{
   if(front_masuk == NULL)
   {
        printf("\nData barang masuk kosong!\n");
        system("pause");
   }
   else{
      struct simpul_masuk *temp = front_masuk;
      front_masuk = front_masuk -> next;
      printf("\nData barang masuk yang dihapus: %d\n", temp->ID);
      free(temp);
   }
}

void delete_keluar()
{
   if(front_keluar == NULL)
      printf("\nData barang keluar kosong!\n");
   else{
      struct simpul_keluar *temp = front_keluar;
      front_keluar = front_keluar -> next;
      printf("\nData barang keluar yang dihapus: %d\n", temp->ID);
      free(temp);
   }
}

int baca_data()
{
    int e = 0;
    FILE *fbd, *fdd;
    fbd = fopen("nama_toko.txt", "r");
    if(NULL == fbd)
    {
        e++;
        fclose(fbd);
        fdd = fopen("nama_toko.txt", "a");
        fputs("Nama toko Anda", (FILE*)fdd);
        fclose(fdd);
    }
    fread(info_toko.nama_toko, 1, 20, fbd);
    fclose(fbd);

    fbd = fopen("harga_beli.txt", "r");
    if(NULL == fbd)
    {
        e++;
        fclose(fbd);
        fdd = fopen("harga_beli.txt", "a");
        fprintf(fdd, "%d", 1000);
        fclose(fdd);
    }
    fscanf(fbd, "%d", &info_toko.harga_beli);
    fclose(fbd);

    fbd = fopen("harga_jual.txt", "r");
    if(NULL == fbd)
    {
        e++;
        fclose(fbd);
        fdd = fopen("harga_jual.txt", "a");
        fprintf(fdd, "%d", 2000);
        fclose(fdd);
    }
    fscanf(fbd, "%d", &info_toko.harga_jual);
    fclose(fbd);

    fbd = fopen("kapasitas_max.txt", "r");
    if(NULL == fbd)
    {
        e++;
        fclose(fbd);
        fdd = fopen("kapasitas_max.txt", "a");
        fprintf(fdd, "%d", 5);
        fclose(fdd);
    }
    fscanf(fbd, "%d", &info_toko.kapasitas_max);
    fclose(fbd);

    fbd = fopen("hitung_masuk.txt", "r");
    if(NULL == fbd)
    {
        e++;
        fclose(fbd);
        fdd = fopen("hitung_masuk.txt", "a");
        fprintf(fdd, "%d", 0);
        fclose(fdd);
    }
    fscanf(fbd, "%d", &hitung_masuk);
    fclose(fbd);

    fbd = fopen("hitung_keluar.txt", "r");
    if(NULL == fbd)
    {
        e++;
        fclose(fbd);
        fdd = fopen("hitung_keluar.txt", "a");
        fprintf(fdd, "%d", 0);
        fclose(fdd);
    }
    fscanf(fbd, "%d", &hitung_keluar);
    fclose(fbd);

    fbd = fopen("nama_barang.txt", "r");
    if(NULL == fbd)
    {
        e++;
        fclose(fbd);
        fdd = fopen("nama_barang.txt", "a");
        fputs("Nama barang Anda", (FILE*)fdd);
        fclose(fdd);
    }
    fread(info_toko.nama_barang, 1, 20, fbd);
    fclose(fbd);

    fbd = fopen("mata_uang.txt", "r");
    if(NULL == fbd)
    {
        e++;
        fclose(fbd);
        fdd = fopen("mata_uang.txt", "a");
        fputs("Rp", (FILE*)fdd);
        fclose(fdd);
    }
    fread(info_toko.mata_uang, 1, 3, fbd);
    fclose(fbd);

    fbd = fopen("satuan_grosir.txt", "r");
    if(NULL == fbd)
    {
        e++;
        fclose(fbd);
        fdd = fopen("satuan_grosir.txt", "a");
        fputs("satuan", (FILE*)fdd);
        fclose(fdd);
    }
    fread(info_toko.satuan_grosir, 1, 10, fbd);
    fclose(fbd);

    if(e>0)
    {
        system("cls");
        header();
        printf("Perhatian!\nSalah satu file informasi toko tidak terbaca.\nHarap meninjau kembali seluruh informasi toko.\n\n");
        system("pause");
    }

}
