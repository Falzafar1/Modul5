/** EL2208 Praktikum Pemecahan Masalah dengan C 2023/2024
 *   Modul               : 05
 *   Hari dan Tanggal    : Senin, 1 April 2024
 *   Nama (NIM)          : Naufal Afiq Muzaffar (13222025)
 *   Nama File           : main.c
 *   Deskripsi           : Program yang dibuat untuk memilih siapa saja kader yang lolos sebagai anggota DPRAK 
 *
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct untuk menyimpan informasi kader partai
typedef struct {
    char name[50];
    char party[50];
    int votes;
} Candidate;

// Fungsi untuk memeriksa apakah seorang kader memiliki suara lebih dari 10 %
int isPartyWinner(Candidate* candidates, int n, int total) {
    double persen;

    for (int i = 0; i < n; i++){
        persen =(double)candidates[i].votes/total;
        if (persen > 0.1){
            printf("%s %s %d\n", candidates[i].name, candidates[i].party, candidates[i].votes);
        }    
    }
    return 0;  
}

// Fungsi untuk mencari total suara 
int findTotalPartyVotes(Candidate* candidates, int i, int total) { 
    return total+ candidates[i].votes;
}

int main() {
    int i,j,n;
    int total = 0;
    int totalelemen = 0;
    int VoteTertinggi = 0;

    // membuat input jumlah kader partai
    printf("Masukkan jumlah kader partai: ");
    scanf("%d", &n);

    // Membuat array of struct untuk menyimpan informasi kader partai
    Candidate* candidates = (Candidate*)malloc(n * sizeof(Candidate));

    // Membaca baris input informasi kader partai dan menyimpannya dalam array of struct
    for ( i = 0; i < n; i++){
        printf("Informasi kader ke-%d : ", i+1);
        scanf("%s%s%d", candidates[i].name, candidates[i].party, &candidates[i].votes);
        total = findTotalPartyVotes(candidates,i,total);
        totalelemen = totalelemen +1;

        for ( j = 0; j < totalelemen; j++){
            if (strcmp(candidates[i].party, candidates[j].party) == 0){
                if (candidates[i].votes > VoteTertinggi){
                    VoteTertinggi = candidates[i].votes;
                }
                if (candidates[j].votes < VoteTertinggi){
                    strcpy(candidates[j].name, "A");
                    strcpy(candidates[j].party, "J");
                    candidates[j].votes = 0;
                }
            }
        }
    }
    
    printf("\nAnggota Dewan Perwakilan Rakyat Anti Korupsi (DPRAK) tahun 2024\n");
    // Mencari kader yang lolos DPRAK
    isPartyWinner(candidates,n,total);
    printf("Semoga amanah Anti Korupsi #WakandaForever\n");

    // // // Membebaskan memori yang dialokasikan untuk array of struct
    free(candidates);

    return 0;
}
