#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

/* Bu fonksiyon, bir tek hamlede kazanma durumu olup olmadığını kontrol eder.

Örnek:

 _ _ x  sıra şuanda botta ve bot (0, 0) indexini seçmaz ise oyuncu bir sonraki hamlede kazanacakdır.
 _ o _
 _ _ o

 bu fonksiyon oyuncu_degiskeni paremetresine göre tek tek bğtğn boş olan inexlere
 yerine koyma ve win fonksiyonu ile kazananı kontrol etme mantığı ile çalışır.
 */
void kritik_pozisyon(int matris[3][3], int sonuc[3], int oyuncu_degiskeni)
{
    int kopya[3][3];
    int sayac_1 = 0;

    matrisi_kopyala(matris, kopya);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (kopya[i][j] == 0)
            {
                kopya[i][j] = oyuncu_degiskeni;
                if (kazanan_kontrolu(matris, oyuncu_degiskeni) > 0)
                {
                    sonuc[0]++;
                    sonuc[1] = i;
                    sonuc[2] = j;
                }
                sayac_1 = 0;
                kopya[i][j] = 0;
            }
        }
    }
}

/* stratejik_pozisyon_1 fonksiyonunun amacı, bir hamle ile bir sonraki hamle için aynı anda iki yada
daha fazla krıtik pozisyon var mı tespit etmekdir.

Örnek:

 _ _ x  Eğer bot (0, 0) indeksini işaretlerse, sonraki durum şu olacaktır:
 _ o _
 x _ o

 x _ x  şuan sıra oyuncuda ve oyuncu aynı anda hem sıfırıncı satır hem de sıfırıncı sutun
 _ o _  için botun kazanmasını engellemesi gerekmekte ancak bu mümkün değildir.
 x _ o

bu fonksiyon kritik_pozisyon fonksiyonu ile aynı şekilde yerine koyma ve kritik_pozisyon fonksiyonunu
çağırarak kritik pozisyon oluşuyor mu kontrol etme mantğı ile çalışır.

*/
void stratejik_pozisyon_1(int matris[3][3], int sonuc_1[3], int oyuncu_degiskeni)
{
    int kopya[3][3], sonuc[3] = {0, 0, 0};
    matrisi_kopyala(matris, kopya);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (kopya[i][j] == 0)
            {
                kopya[i][j] = oyuncu_degiskeni;
                kritik_pozisyon(kopya, sonuc, oyuncu_degiskeni);
                if (sonuc[0] > 1)
                {
                    sonuc_1[0]++;
                    sonuc_1[1] = i;
                    sonuc_1[2] = j;
                }
                sonuc[0] = 0;
                kopya[i][j] = 0;
            }
        }
    }
}

/* Bu fonksiyon, rakibin aynı anda birden çok stratejik pozisyonunu önleyebilecek bir hamle bulmayı amaçlar.
   bazı durumlarda sıra bizdeyeken rakibin bir sonraki hamleesi için birden fazla stratejik posizyon
   oluşturabileceği bir durum oluşmakta ve öyle bi yer seçilmeli ki rakip için bütün stratejik noktaları
   geçersiz kılmalıyız. bu fonksiyon yine yerine koyma ve rakip için stratejik poszisyon oluşyor mu kontrol
   etme mantığı ile çalışır.
*/
void rakip_stratejik_pozisyon(int matris[3][3], int sonuc[3], int oyuncu_degiskeni)
{
    int kopya[3][3], sonuc_1[3] = {0, 0, 0};

    sonuc[0] = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            matrisi_kopyala(matris, kopya);
            if (kopya[i][j] == 0)
            {
                kopya[i][j] = oyuncu_degiskeni;
                stratejik_pozisyon_1(kopya, sonuc_1, oyuncu_degiskeni);
                if (sonuc_1[0] == 0)
                {
                    sonuc[0] = 1;
                    sonuc[1] = i;
                    sonuc[2] = j;
                    return;
                }
                sonuc_1[0] = 0;
                kopya[i][j] = 0;
            }
        }
    }
}
