#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

// matrisi_initialize_et fonksiyonu oyun matrisini başlatır
void matrisi_initialize_et(int *matris, int boyut1, int boyut2)
{
    for (int i = 0; i < boyut1; i++)
    {
        for (int j = 0; j < boyut2; j++)
        {
            *(matris + i * boyut2 + j) = 0;
        }
    }
}

void oyun_tahtasini_yazdir(int matris[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matris[i][j] == 1)
            {
                printf("X ");
            }
            if (matris[i][j] == 2)
            {
                printf("O ");
            }
            if (matris[i][j] == 0)
            {
                printf("_ ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void matrisi_kopyala(int kaynak[3][3], int hedef[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            hedef[i][j] = kaynak[i][j];
        }
    }
}

void rastgele_hareket_uret(int matris[3][3], int sonuc[3])
{
    int kontrol = 0;

    srand(time(NULL));
    while (kontrol != 1)
    {
        int i = rand() % 3;
        int j = rand() % 3;
        if (matris[i][j] == 0)
        {
            sonuc[0] = 1;
            sonuc[1] = i;
            sonuc[2] = j;
            kontrol = 1;
        }
    }
}

// kontrol_et fonksiyonu oyun matrisinin dolu olup olmadığını kontrol eder.
int kontrol_et(int matris[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matris[i][j] == 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

void oyuncu(int matris[3][3], int oyuncu_degiskeni)
{
    int c, r;
    printf("\nsatır ve sütun: ");
    scanf("%d %d", &r, &c);
    if (matris[r][c] == 2 || matris[r][c] == 1)
    {
        printf("\nbu yer zaten kullanılmış. Lütfen başka bir yer seçin.\n");
        oyuncu(matris, oyuncu_degiskeni);
    }
    else
    {
        matris[r][c] = oyuncu_degiskeni;
    }
}
