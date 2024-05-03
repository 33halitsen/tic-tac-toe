#ifndef FONKSIYONLAR
#define FONKSIYONLAR

void matrisi_initialize_et(int *matris, int boyut1, int boyut2);
void oyun_tahtasini_yazdir(int matris[3][3]);
void matrisi_kopyala(int kaynak[3][3], int hedef[3][3]);
void rastgele_hareket_uret(int matris[3][3], int sonuc[3]);
int kontrol_et(int matris[3][3]);
void oyuncu(int matris[3][3], int oyuncu_degiskeni);
int kazanan_kontrolu(int matris[3][3], int oyuncu_degiskeni);
void kritik_pozisyon(int matris[3][3], int sonuc[3], int oyuncu_degiskeni);
void stratejik_pozisyon_1(int matris[3][3], int sonuc_1[3], int oyuncu_degiskeni);
void stratejik_pozisyon_2(int matris[3][3], int sonuc_2[3], int oyuncu_degiskeni);
void rakip_stratejik_pozisyon(int matris[3][3], int sonuc_1[3], int oyuncu_degiskeni);
void gelecek_durumu_hesapla(int matris[3][3], int sonuc[3], int oyuncu_degiskeni);
void bot(int matris[3][3], int oyuncu_degiskeni);
void bot_vs_bot();
int oyuncu_vs_bot();
int oyuncu_vs_oyuncu();
void olasılık(int matris[3][3], int sonuc[3], int oyuncu_degiskeni);
#endif
