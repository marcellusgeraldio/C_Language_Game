#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void cls() {
    system("cls"); // fungsi ini memanggil sistem untuk membersihkan layar pada terminal dengan menggunakan cls 
}

typedef struct {
    char ingredient1[30];
    char ingredient2[30];
    char result[30];
} Recipe;
/** fungsi ini digunakan untuk menyimpan resep masakan, terdiri dari struktur yang bernaama recipe yang terdiri dari tiga tipe data char dengan urutan ingredient1, ingridient2 lalu result 
 berfungsi untuk menyimpan bahan bahan dan hasil makanannya **/

int daftarmakanan(const char *bahanmasakan[], int numbahanmakanan) {
    printf("================= DAPUR COGIL =================\n");
    printf("Daftar Bahan Masakan:\n");

    for (int i = 0; i < numbahanmakanan; ++i)
        printf("%d. %s\n", i + 1, bahanmasakan[i]);

    printf("\n");
}
/*membuat suatu fungsi untuk menampilkan bahan bahan masakan yang nantinya akan ditambahkan.  */

// fungsi main
int main() {
    char ready;
    srand(time(NULL));

    printf("==== SELAMAT DATANG DI GAME COOKING COGIL ====\n");
    sleep(1);
    printf("Daftar bahan masakan akan tertera saat game dimulai.\n");
    sleep(1);
    /*mencetak pesan selamat datang dan intruksi menggunakan printf. sleep digunakan untuk memberi jeda 1 detik pada terminal*/

    printf("Apakah anda siap? (y) / (n) \n");
    ready = getchar();
    // membuat suatu pilihan untuk melanjutkan permainan atau tidak 

    switch (ready) {
        case 'y': { // pilihan y untuk memulai game
            printf("Memulai program: Loading");
            sleep(1);

            for (int i = 0; i <= 4; i++) {
                if (i <= 2) {
                    printf(".");
                    fflush(stdout);
                    sleep(1);
                } else {
                    printf(" READY!!\n");
                }
            } // membuat tampilan loading dengan titik titik dan tulisan ready menggunakan for untuk membuat animasi titik titik dan sleep untuk menjeda setiap titik

            cls(); // menggunakan cls untuk membersihkan terminal agar tampilan lebih bersih

            const char *bahanmasakan[] = {"Daging", "Roti", "Keju", "Tomat", "Tepung Terigu", 
                                          "Nasi", "Telur", "Bawang", "Lada", "Kentang"};
            //menyimpan bahan bahan pada array, menggunakan const agar array pada bahanmasakan bersifat konstan

            int numbahanmakanan = sizeof(bahanmasakan) / sizeof(bahanmasakan[0]);
            /* Menghitung berapa kali ukuran satu elemen yg muat dalam ukuran array, sehingga memberikan jumlah elemen dalam array tersebut */

            Recipe recipes[] = {
                {"Daging", "Roti", "Burger"},
                {"Roti", "Keju", "Roti Bakar Keju"},
                {"Nasi", "Bawang", "Nasi Goreng"},
                {"Daging", "Tomat", "Sop Iga"},
                {"Daging", "Telur", "Omelet"},
                {"Kentang", "Telur", "Perkedel"},
                {"Tepung Terigu", "Telur", "Mie"},
                {"Telur", "Kentang", "Takoyaki"},
                {"Nasi", "Telur", "Nasi Goreng Telur"},
                {"Daging", "Lada", "Sate"},
                
            }; /*menggunakan struktur recipe yang tadinya telah kita buat untuk menyimpannya sesuai format. contohnya daging roti burger dalam format ingridient1 ingridident2 result
            fungsi ini dapat memudahkan kita dalam menambah resep baru tanpa mengubah fungsi lainnya*/

            daftarmakanan(bahanmasakan, numbahanmakanan); // memanggil fungsi daftarmakanan

            int selectedbahanmasakan[2];

            printf("Pilih dua bahan untuk digabungkan (1-%d): ", numbahanmakanan); // mencetak pesan untuk meminta user menginput dua bahan untuk digabungkan

            for (int i = 0; i < 2; ++i){
                scanf("%d", &selectedbahanmasakan[i]);
                // menggunakan loop dan meminta input dari pengguna dua kali dan menyimpannya di dalam array selectedbahanmasakan.
            }

           // membuat fungsi pilihan dari user valid atau tidak
            if (selectedbahanmasakan[0] < 1 || selectedbahanmasakan[0] > numbahanmakanan ||
                selectedbahanmasakan[1] < 1 || selectedbahanmasakan[1] > numbahanmakanan){
                printf("Pilihan tidak valid.\n");
                return 1; /* menggunakan operator OR || untuk mengecek jika salah satu kondisi true
                selectedbahanmasakan[0] > numbahanmakanan kondisi untuk mengecek apakah input user tidak lebih dari jumlah bahan makananan pada numbahanmakanan yang tadinya telah kita tambahkan
                selectedbahanmasakan[0] < 1 kondisi untuk memeriksa input kurang dari 1 atau tidak
                jika salah satu kondisi true maka akan mencetak "Pilihan tidak valid."
                */
            }

 
            for (int i = 0; i < sizeof(recipes) / sizeof(recipes[0]); ++i) { // loop akan berjalan sesuai dengan jumlah recipe dari penghitungan sizeof
                if ((strcmp(bahanmasakan[selectedbahanmasakan[0] - 1], recipes[i].ingredient1) == 0 &&
                     strcmp(bahanmasakan[selectedbahanmasakan[1] - 1], recipes[i].ingredient2) == 0) ||
                    (strcmp(bahanmasakan[selectedbahanmasakan[1] - 1], recipes[i].ingredient1) == 0 &&
                     strcmp(bahanmasakan[selectedbahanmasakan[0] - 1], recipes[i].ingredient2) == 0)) {
                    printf("Hasil kombinasi: %s\n", recipes[i].result);
                    return 0;
                } /*menggunakan strcmp untuk membandingkan string bahan pertama dan kedua dari user dengan bahan pertama dan kedua dari salah satu resep yang sudah tersedia
                menggunakan && AND untuk memastikan jika kedua kondisi sesuai atau dalam logika ini artinya kedua bahan sesuai dengan resep makanan
                menggunakan || OR agar posisi input bahan tidak berpengaruh seperti daging pada input 1 dan roti pada input 2 dengan daging pada input 2 dan roti pada input 1
                jika kondisi sesuai maka akan mencetak hasil kombinasi
                */
            }

            printf("Kombinasi tidak menghasilkan makanan.\n"); 
            // jika loop selesai namun tetap tidak ada kombinasi yang sesuai. maka akan mencetak pesan "Kombinasi tidak menghasilkan makanan."

            break;
        }
        case 'n': // pilihan n untuk keluar dari game
            printf("Yasudah bye.\n");
            break;
        default: // tampilan error untuk inputan user yang tidak menginput y maupun n
            printf("ERROR: Input tidak valid.\n");
    }

    return 0;
}