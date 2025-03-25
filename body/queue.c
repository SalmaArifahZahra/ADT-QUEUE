/*File body untuk ADT Queue*/
//Dibuat tanggal 28-3-2013
#define MAX_QUEUE 50 
#include "../header/queue.h"

/*Membuat sebuah queue baru dengan Front dan Rear NULL*/
void CreateQueue (Queue *Q) {
    CreateList(Q); 
}

/*Memeriksa apakah queue kosong */
boolean is_Empty (Queue Q)
{
	return ListEmpty(Q);
}

/*Memeriksa apakah queue penuh */
boolean is_Full (Queue Q)
{
	return HitungElm(Q) >= MAX_QUEUE;
}

/*Melekukan insertion pada queue*/
void EnQueue (Queue *Q, infotype X)
{
	if (!is_Full(*Q)) {
        InsVLast((List *) Q, X); 
    } else {
        printf("Queue penuh! Tidak ada yang bisa ditambah.\n");
    }
}

/*Melakukan deletion pada queue*/
void deQueue (Queue *Q, infotype *X)
{  
	if (!is_Empty(*Q)) {
        DelVFirst((List *) Q, X);  // Cast ke List *
    } else {
        printf("Queue kosong.\n");
    }
}

/* Menampilkan daftar antrian */
void CetakQueue (Queue Q) {
	if (is_Empty(Q)) {
        printf("Queue kosong.\n");
    } else {
        PrintInfo(Q);  
    }
}

/* Menghitung jumlah elemen dalam queue */
int HitungElm(Queue Q) {
    int count = 0;
    address temp = First(Q);  // Gunakan First(Q) langsung, bukan Q->First

    while (temp != Nil) {
        count++;
        temp = temp->next;  // Gunakan "next" bukan "Next"
    }
    return count;
}


// void TampilanMenu() {
//     printf("\n=== Sistem Antrian Bank ===\n");
//     printf("1. Ambil Antrian\n");
//     printf("2. Proses Antrian\n");
//     printf("3. Cetak Antrian\n");
//     printf("4. Keluar\n");
//     printf("Pilih menu: ");
// }