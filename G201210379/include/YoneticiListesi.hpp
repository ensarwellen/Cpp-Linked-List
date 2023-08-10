/**
* @file YoneticiListesi.hpp
* @description YoneticiListesi sınıfının tanımını yapıyoruz.listeEkle, ortalamaAl, listeYazdir gibi metotlarımızı belirtiyoruz.
* @course 2.ÖĞRETİM B GRUBU
* @assignment 1
* @date 24.11.2022
* @author Ensar Çelik-ensar.celik2@ogr.sakarya.edu.tr
*/
#ifndef YoneticiListesi_hpp
#define YoneticiListesi_hpp

#include <iostream>
#include "SatirListesi.hpp"
using namespace std;

class YoneticiListesi
{
public:
	SatirListesi* bas;
	int listeSayaci;
	YoneticiListesi();
	void listeEkle(SatirListesi* _liste); //Sona eleman ekle
	void ortalamaAl(int say);
	void ListeYazdir(int say, int x);
	int SilmedenOnceSor(int say);
	void icerikYazdir();
	void ListeSil(int say);
	void DugumSil(int say, int say2);
	~YoneticiListesi();
};

#endif