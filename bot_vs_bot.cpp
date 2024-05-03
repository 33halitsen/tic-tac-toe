#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

void bot_vs_bot()
{
    int matris[3][3], sayac_1 = 0;
    matrisi_initialize_et(&matris[0][0], 3, 3); // Tüm oyun matrisini boş yerlerle, yani 0 değerleriyle başlat

    for (int i = 0; i < 10; i++)
    {
        oyun_tahtasini_yazdir(matris); // Oyun matrisini yazdır
        bot(matris, 1);                // Bot 1 için bir hamle yap

        if (kazanan_kontrolu(matris, 1) > 0) // Bot 1'in kazanıp kazanmadığını kontrol et
        {
            oyun_tahtasini_yazdir(matris);
            printf("Bot_1 kazandı");
            return;
        }
        i++;                           // Hamle sayısını arttır
        oyun_tahtasini_yazdir(matris); // Oyun matrisini yazdır
        bot(matris, 2);                // Bot 2 için bir hamle yap

        if (kazanan_kontrolu(matris, 1) > 0) // Bot 2'nin kazanıp kazanmadığını kontrol et
        {
            oyun_tahtasini_yazdir(matris);
            printf("Bot_2 kazandı");
            return;
        }
        if (i == 9) // Toplam 9 hamle yapıldıktan sonra kontrol et
        {
            oyun_tahtasini_yazdir(matris);
            return;
        }
    }

    return;
}
