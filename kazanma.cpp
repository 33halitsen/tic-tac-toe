#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

void satir_kontrolu(int matris[3][3], int *sayac_1, int oyuncu_degiskeni)
{
    int sayac_2 = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matris[i][j] == oyuncu_degiskeni)
            {
                sayac_2++;
            }
        }
        if (sayac_2 == 3)
        {
            if (oyuncu_degiskeni == 1)
            {
                (*sayac_1) = 1;
            }
            else
            {
                (*sayac_1) = 2;
            }
        }
        sayac_2 = 0;
    }
}

void sutun_kontrolu(int matris[3][3], int *sayac_1, int oyuncu_degiskeni)
{
    int sayac_2 = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matris[j][i] == oyuncu_degiskeni)
            {
                sayac_2++;
            }
        }
        if (sayac_2 == 3)
        {
            if (oyuncu_degiskeni == 1)
            {
                (*sayac_1) = 1;
            }
            else
            {
                (*sayac_1) = 2;
            }
        }
        sayac_2 = 0;
    }
}

// 'diyagonal_kontrol_1' fonksiyonu, (0, 0), (1, 1), (2, 2) indislerindeki diyagonali kontrol eder.
void diyagonal_kontrol_1(int matris[3][3], int *sayac_1, int oyuncu_degiskeni)
{
    int sayac_2 = 0;

    for (int i = 0; i < 3; i++)
    {
        if (matris[i][i] == oyuncu_degiskeni)
        {
            sayac_2++;
        }
    }
    if (sayac_2 == 3)
    {
        if (oyuncu_degiskeni == 1)
        {
            (*sayac_1) = 1;
        }
        else
        {
            (*sayac_1) = 2;
        }
    }
}

/* 'diyagonal_kontrol_2' fonksiyonu, (0, 2), (1, 1), (2, 0) indislerindeki diyagonali kontrol eder.
   'diyagonal_kontrol_1' fonksiyonuyla benzer bir mantığa sahiptir. */
void diyagonal_kontrol_2(int matris[3][3], int *sayac_1, int oyuncu_degiskeni)
{
    int sayac_2 = 0;

    for (int i = 0; i < 3; i++)
    {
        if (matris[i][2 - i] == oyuncu_degiskeni)
        {
            sayac_2++;
        }
    }
    if (sayac_2 == 3)
    {
        if (oyuncu_degiskeni == 1)
        {
            (*sayac_1) = 1;
        }
        else
        {
            (*sayac_1) = 2;
        }
    }
}

int kazanan_kontrolu(int matris[3][3], int oyuncu_degiskeni)
{
    int sayac_1 = 0;
    satir_kontrolu(matris, &sayac_1, oyuncu_degiskeni);
    sutun_kontrolu(matris, &sayac_1, oyuncu_degiskeni);
    diyagonal_kontrol_1(matris, &sayac_1, oyuncu_degiskeni);
    diyagonal_kontrol_2(matris, &sayac_1, oyuncu_degiskeni);
    return sayac_1;
}
