#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define MAX_TELLER 2 
#define MAX_ANTRIAN_TELLER 7 

void MenuUtama() {
    printf("\n=========================\n");
    printf("  SISTEM ANTRIAN BANK\n");
    printf("=========================\n");
    printf("1. Ambil Antrian\n");
    printf("2. Proses Antrian\n");
    printf("3. Cetak Antrian\n");
    printf("4. Keluar\n");
    printf("=========================\n");
    printf("Pilih menu: ");
}

int main() {
    Queue Q;
    int pilihan;
    int nomorAntrian = 0; 
    infotype temp;
    
    CreateQueue(&Q);
    
    do {
        MenuUtama();
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 1:
                nomorAntrian++;
                EnQueue(&Q, nomorAntrian);
                printf("\nNomor Antrian %d telah ditambahkan ke antrian utama.\n", nomorAntrian);
                printf("\nAntrian Sekarang: ");
                CetakQueue(Q);
                break;

            case 2:
                if (!is_Empty(Q)) {
                    deQueue(&Q, &temp);
                    printf("\nNomor Antrian %d sedang diproses dan telah dihapus dari antrian.\n", temp);
                    printf("\nAntrian Sekarang: ");
                    CetakQueue(Q);
                } else {
                    printf("\nTidak ada antrian untuk diproses.\n");
                }
                break;

            case 3:
                printf("\nAntrian Saat Ini: ");
                CetakQueue(Q);
                break;

            case 4:
                printf("\nTerima kasih! Program selesai.\n");
                break;

            default:
                printf("\nPilihan tidak valid. Silakan coba lagi.\n");
        }
    } while (pilihan != 4);
    
    return 0;
}
