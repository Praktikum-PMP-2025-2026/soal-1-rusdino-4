/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
 *   Modul               : 3
 *   Hari dan Tanggal    : Rabu, 29 April 2026
 *   Nama (NIM)          : Rusydi Noor Abdurrahman (13224030)
 *   Nama File           : soal1.c
 *   Deskripsi           : Deskripsi Soal
Sebuah museum penelitian sedang merapikan basis data artefaknya. Setiap artefak tercatat dengan nama, kategori, tahun penemuan, dan nilai pentingnya. Karena arsip akan dipakai oleh beberapa divisi sekaligus, data harus diurutkan dengan aturan yang konsisten dan cukup rinci. Tugas Anda adalah membantu sistem arsip menghasilkan urutan akhir yang sesuai dengan prioritas pengelompokan yang telah disepakati.
Urutkan data artefak dengan aturan multi-kriteria.
Kondisi/Aturan
1. Tiap artefak: nama kategori tahun nilai
2. Urutan:
EL2008 Pemecahan Masalah dengan Pemrograman - Laboratorium Dasar Teknik Elektro - STEI ITB |
2
• kategori alfabetis naik
• jika sama, tahun naik
• jika sama, nilai turun
• jika sama, nama alfabetis naik
 * 
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct artefak{
    char nama[100];
    char kategori[100];
    int tahun;
    int nilai;
}artefak;

void swap(artefak* x, artefak* y){
    artefak temp = *x;
    *x = *y;
    *y = temp;
}


int main(){
    char buff[1024]; 
    fgets(buff, sizeof(buff), stdin);
    int N = atoi(strtok(buff, " "));
    if(N!=0){
    artefak *x = (artefak*)calloc(10, sizeof(artefak));
    for(int i =0; i < N; i++){
        for(int j = 0; j <4; j++){
        char *temp = strtok(NULL, " ");
        if(temp != NULL){
            if(j%4 == 0){
                strcpy(x[i].nama, temp);
            }else if(j%4 == 1){
                strcpy(x[i].kategori, temp);
            }else if(j%4 == 2){
                x[i].tahun = atoi(temp);
            }else if(j%4 == 3){
                x[i].nilai = atoi(temp);
            }
            }
        }
        
        }
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (strcmp(x[j].kategori, x[j+1].kategori)>0){
                swap(&x[j], &x[j+1]);
            }else if(strcmp(x[j].kategori, x[j+1].kategori)==0 && (x[j].tahun > x[j+1].tahun)){
                swap(&x[j], &x[j+1]);
            }else if(strcmp(x[j].kategori, x[j+1].kategori)==0  && (x[j].tahun == x[j+1].tahun) && (x[j].nilai < x[j+1].nilai)){
                swap(&x[j], &x[j+1]);
            }else if(strcmp(x[j].kategori, x[j+1].kategori)==0  && (x[j].tahun == x[j+1].tahun) && (x[j].nilai == x[j+1].nilai) && strcmp(x[j].nama, x[j+1].nama)>0){
                swap(&x[j], &x[j+1]);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        printf("%s %s %d %d\n", x[i].nama, x[i].kategori, x[i].tahun, x[i].nilai);
    }
}
}
