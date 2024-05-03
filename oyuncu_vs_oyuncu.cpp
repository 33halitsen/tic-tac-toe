#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int oyuncu_vs_oyuncu()
{
    int matris[3][3], sayac_1 = 0, sonuc[3];

    matrisi_initialize_et(&matris[0][0], 3, 3);

    for (int i = 0; i < 10; i++)
    {
        oyun_tahtasini_yazdir(matris);
        oyuncu(matris, 1);
        if (kazanan_kontrolu(matris, 1) > 0)
        {
            oyun_tahtasini_yazdir(matris);
            printf("Oyuncu 1 kazandı");
            return 1;
        }
        i++;
        oyun_tahtasini_yazdir(matris);
        oyuncu(matris, 2);

        if (kazanan_kontrolu(matris, 2) > 0)
        {
            oyun_tahtasini_yazdir(matris);
            printf("Oyuncu 2 kazandı");
            return 2;
        }
        if (i == 9)
        {
            oyun_tahtasini_yazdir(matris);
            break;
        }
    }

    return 0;
}
