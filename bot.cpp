#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

void bot(int matris[3][3], int oyuncu_degiskeni)
{
    if (kontrol_et(matris) == 0)
    {
        return;
    }

    int oyuncu_degiskeni_tersi = 3 - oyuncu_degiskeni;

    if (matris[1][1] == 0)
    {
        matris[1][1] = oyuncu_degiskeni;
        return;
    }

    int sonuc[3] = {0, 0, 0};
    // Oyuncunun kazanma şansı var mı kontrol et.
    kritik_pozisyon(matris, sonuc, oyuncu_degiskeni);

    if (sonuc[0] > 0)
    {
        matris[sonuc[1]][sonuc[2]] = oyuncu_degiskeni;
        return;
    }

    // Rakibin kazanma şansı var mı kontrol et.
    kritik_pozisyon(matris, sonuc, oyuncu_degiskeni_tersi);

    if (sonuc[0] > 0)
    {
        matris[sonuc[1]][sonuc[2]] = oyuncu_degiskeni;
        return;
    }

    sonuc[0] = 0;
    // Oyuncu için stratejik bir pozisyon var mı kontrol et.
    stratejik_pozisyon_1(matris, sonuc, oyuncu_degiskeni);

    if (sonuc[0] > 0)
    {
        matris[sonuc[1]][sonuc[2]] = oyuncu_degiskeni;
        return;
    }

    // Rakip için stratejik bir pozisyon var mı kontrol et.
    stratejik_pozisyon_1(matris, sonuc, oyuncu_degiskeni_tersi);

    // Eğer rakip için birden fazla stratejik pozisyon varsa, bunların tümünü geçersiz kılacak bir pozisyon bul.
    if (sonuc[0] > 1)
    {
        rakip_stratejik_pozisyon(matris, sonuc, oyuncu_degiskeni_tersi);
        if (sonuc[0] == 1)
        {
            matris[sonuc[1]][sonuc[2]] = oyuncu_degiskeni;
            return;
        }
    }

    if (sonuc[0] == 1)
    {
        matris[sonuc[1]][sonuc[2]] = oyuncu_degiskeni;
        return;
    }

    olasılık(matris, sonuc, oyuncu_degiskeni);

    if (sonuc[0] == 1)
    {
        matris[sonuc[1]][sonuc[2]] = oyuncu_degiskeni;
        return;
    }

    // Hiçbir özel durum karşılanmazsa rastgele bir hamle üret.
    rastgele_hareket_uret(matris, sonuc);
    matris[sonuc[1]][sonuc[2]] = oyuncu_degiskeni;
}
