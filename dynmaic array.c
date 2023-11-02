#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ogrenci {
    int ogrenciNumarasi;
    char ogrenciIsmi[10];
};

int main() {
    struct Ogrenci Liste[1]; // Maksimum 10 öğrenci için bir array oluşturuyoruz.
    int i = 0; // İndeks
    struct Ogrenci *newArray;
    while (1) {
        printf("%d. ogrenci numarasi girin: ", i + 1);
        scanf("%d", &Liste[i].ogrenciNumarasi);

        printf("%d. ogrenci ismini girin: ", i + 1);
        char temp[10];
        scanf("%s",&temp);
        strcpy(Liste[i].ogrenciIsmi,temp);

        i++; // Bir sonraki öğrenciye geç


        printf("baska bir ogrenci eklemek ister misiniz? (E/H): ");
        char cevap;
        scanf(" %c", &cevap);
        if (cevap != 'E' && cevap != 'e') {
            if (i >= 1) {
                newArray = (struct Ogrenci *)malloc(1 * sizeof(struct Ogrenci));
                for (int n = 0; n < i+1; n++) {
                    newArray[n] = Liste[n];
                }
                break; // Maksimum öğrenci sayısına ulaşıldığında döngüyü sonlandır
            }
        }
    }

    // Eklenen öğrencilerin bilgilerini yazdır
    for (int j = 0; j < i; j++) {
        printf("%d. ogrenci numarasi: %d\n", j + 1, Liste[j].ogrenciNumarasi);
        printf("%d. ogrenci ismi: %s\n", j + 1, Liste[j].ogrenciIsmi);
    }

    return 0;
}
