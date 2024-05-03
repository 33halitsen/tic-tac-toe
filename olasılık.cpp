#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

void olasılık_2(int matris[3][3], int sayac[2], int oyuncu_degiskeni)
{
    int klon[3][3], olasılıklar_2[2][9], sayac_3;
    matrisi_kopyala(matris, klon);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (klon[i][j] == 0)
            {
                klon[i][j] = oyuncu_degiskeni;
                sayac_3 = kazanan_kontrolu(klon, oyuncu_degiskeni);
                if (sayac_3 == 1)
                {
                    sayac[0]++;
                    return;
                }
                if (sayac_3 == 2)
                {
                    sayac[1]++;
                    return;
                }
            }
            olasılık_2(klon, sayac, 3 - oyuncu_degiskeni);
            klon[i][j] = 0;
        }
    }
}

void en_iyi_olasılık(int olasılıklar[2][9], int sonuc[3], int oyuncu_degiskeni)
{
    int en_iyi, en_kötü, sayac = 0;
    for (int i = 0; i < 9; i++)
    {
        if (olasılıklar[0][i] == 0 ^ olasılıklar[1][0] == 0)
        {
            if (olasılıklar[0][i] == 0)
            {
                sayac = 1;
                en_iyi = i;
            }
            if (olasılıklar[1][i] == 0)
            {
                sayac = 1;
                en_kötü = i;
            }
        }
    }
    if (sayac == 1)
    {
        if (oyuncu_degiskeni == 1)
        {
            sonuc[0] = 1;
            sonuc[1] = en_iyi / 3;
            sonuc[2] = en_iyi % 3;
            return;
        }
        else
        {
            sonuc[0] = 1;
            sonuc[1] = en_kötü / 3;
            sonuc[2] = en_kötü % 3;
            return;
        }
    }

    float oran_1, oran_2, en_iyi_oran = 0, en_kötü_oran = 0;

    for (int i = 0; i < 3; i++)
    {
        if (olasılıklar[0][i] != 0 && olasılıklar[1][0] != 0)
        {
            oran_1 = olasılıklar[0][i];
            oran_2 = olasılıklar[1][i];

            if (oran_1 / oran_2 > en_iyi_oran)
            {
                sayac = 1;
                en_iyi_oran = oran_1 / oran_2;
                en_iyi = i;
            }
            if (oran_1 / oran_2 < en_kötü_oran)
            {
                sayac = 1;
                en_kötü_oran = oran_1 / oran_2;
                en_kötü = i;
            }
        }
    }
    if (sayac == 1)
    {
        if (oyuncu_degiskeni == 1)
        {
            sonuc[0] = 1;
            sonuc[1] = en_iyi / 3;
            sonuc[2] = en_iyi % 3;
            return;
        }
        else
        {
            sonuc[0] = 1;
            sonuc[1] = en_kötü / 3;
            sonuc[2] = en_kötü % 3;
            return;
        }
    }
}

void olasılık(int matris[3][3], int sonuc[3], int oyuncu_degiskeni)
{
    int klon[3][3], olasılıklar[2][9], sayac[2];
    matrisi_kopyala(matris, klon);
    matrisi_initialize_et(&olasılıklar[0][0], 2, 9);
    sayac[0] = 0;
    sayac[1] = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (klon[i][j] == 0)
            {
                klon[i][j] = oyuncu_degiskeni;
                olasılık_2(klon, sayac, 3 - oyuncu_degiskeni);
                olasılıklar[0][3 * i + j] = sayac[0];
                olasılıklar[1][3 * i + j] = sayac[1];
                klon[i][j] = 0;
            }
        }
    }
    en_iyi_olasılık(olasılıklar, sonuc, oyuncu_degiskeni);
}