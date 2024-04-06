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
    int isPartyWinner(Candidate* candidates, int n, int total, char *partai) {
        int pemenang = 0;
        int indexpemenang = 0;
        double persen;
        for (int i = 0; i < n; i++){
            if (strcmp(candidates[i].party, partai) == 0){
                if(candidates[i].votes > pemenang){
                    pemenang = candidates[i].votes;
                    indexpemenang = i;
                }
            }
        }
        persen =(double)candidates[indexpemenang].votes/total;
        if (persen > 0.1){
            printf("%s %s %d\r\n", candidates[indexpemenang].name, candidates[indexpemenang].party, candidates[indexpemenang].votes);
        }    
        return 0;  
    }

    // Fungsi untuk mencari total suara 
    int findTotalPartyVotes(int x, int total) { 
        return total + x;
    }

    int main() {
        int i,j,n;
        int kondisi = 0;
        int total = 0;
        int totalkandidat = 0;
        int totalpartai =0;

        // membuat input jumlah kader partai
        printf("Masukkan jumlah kader partai: \r\n");
        scanf("%d", &n);

        // Membuat array of struct untuk menyimpan informasi kader partai
        Candidate* candidates = (Candidate*)malloc(n * sizeof(Candidate));
        Candidate* Partai = (Candidate*)malloc(n * sizeof(Candidate));

        // Membaca baris input informasi kader partai dan menyimpannya dalam array of struct
        for ( i = 0; i < n; i++){
            printf("Informasi kader ke-%d : \r\n", i+1);
            scanf("%s%s%d", candidates[i].name, candidates[i].party, &candidates[i].votes);
            totalkandidat = totalkandidat +1;
            total = findTotalPartyVotes(candidates[i].votes,total);
            for ( j = 0; j < totalkandidat; j++){
                if (strcmp(candidates[i].party, Partai[j].party) == 0){
                    kondisi = 1;
                }
            }
            if (kondisi == 0){
                totalpartai = totalpartai +1;
                Partai = (Candidate*)realloc(Partai, totalpartai * sizeof(Candidate));
                strcpy(Partai[totalpartai-1].party,candidates[i].party);
            }
            else{
                kondisi = 0;
            }
        }

        printf("\r\nAnggota Dewan Perwakilan Rakyat Anti Korupsi (DPRAK) tahun 2024\r\n");
        // Mencari kader yang lolos DPRAK
        for (i = 0; i < totalpartai; i++){
            isPartyWinner(candidates, n, total, Partai[i].party);
        }
        printf("Semoga amanah Anti Korupsi #WakandaForever");

        // // // Membebaskan memori yang dialokasikan untuk array of struct
        free(candidates);
        free(Partai);

        return 0;
    }
