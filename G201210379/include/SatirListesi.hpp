/**
* @file SatirListesi.hpp
* @description SatirListesi sınıfının tanımını yapıyoruz.ekle ve yazdir gibi metotlarımızı belirtiyoruz.
* @course 2.ÖĞRETİM B GRUBU
* @assignment 1
* @date 24.11.2022
* @author Ensar Çelik-ensar.celik2@ogr.sakarya.edu.tr
*/
#ifndef SatirListesi_hpp
#define SatirListesi_hpp
#include "Dugum.hpp"
class SatirListesi
{
public:
	SatirListesi();
	~SatirListesi();
	int elemanSayisi;
	SatirListesi* sonrakiListe;
	SatirListesi* oncekiListe;
	void ekle(int* dizi, int uzunluk);
	Dugum* dugumGetir(int sira);
	void listeyiSil();
	void DugumSil();
	void cikarIndex(int sira);
	void yazdir(int sayi, int say2);
	float ortalamaGetir();
private:
	Dugum* ilk;
};

#endif