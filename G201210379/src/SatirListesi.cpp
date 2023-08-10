/**
* @file SatirListesi.cpp
* @description SatirListesi sınıfımızın metot gövdesi... 
Listenin her elemanına dosyadaki her satırdan
okuduğumuz verileri atamak için bir döngü oluşturup atama işlemini bu döngü içerisinde
yapıyor.
* @course 2.ÖĞRETİM B GRUBU
* @assignment 1
* @date 24.11.2022
* @author Ensar Çelik-ensar.celik2@ogr.sakarya.edu.tr
*/
#include "SatirListesi.hpp"
#include <iostream>
#include<iomanip>
using namespace std;
SatirListesi::SatirListesi()
{
	//ortalama=0;
	ilk=0;
	elemanSayisi= 0;
	sonrakiListe = NULL;
	oncekiListe = NULL;
}
SatirListesi::~SatirListesi()
{
	Dugum* gec= ilk;
		
	while(gec!=0)
	{
		Dugum* sil = gec;
		gec=gec->sonraki;
		delete sil;
	}
}
void SatirListesi::ekle(int* dizi, int uzunluk)
{
	Dugum* yeni;
	//elemanSayisi = uzunluk;
	for (int i = 0; i < uzunluk; i++)
    {
		//Liste bossa
		if(ilk==0)
		{
		ilk= new Dugum(dizi[i]);
		elemanSayisi++;
		}
		else{  //listede eleman varsa
			yeni = new Dugum(dizi[i]);
			Dugum* gec= ilk;
			while(gec->sonraki!=0)
				gec=gec->sonraki;
			
			gec->sonraki = yeni;
			yeni->onceki = gec;
			elemanSayisi++;
	}
	}
	//diziyi sil
	delete dizi;
}

float SatirListesi::ortalamaGetir()
{
	int elemanSayaci=0;
	float ortalama=0;
	float toplam=0;
	Dugum* gec=ilk;
	while(gec!=0)
	{
		toplam= toplam + gec->veri;
		gec=gec->sonraki;
		elemanSayaci++;
	}	
	ortalama= toplam/elemanSayaci;
	toplam=0;
	return ortalama;	
}
void SatirListesi::listeyiSil()
{
	if(ilk==0) return;		//düğüm yok mu?
	if(ilk->sonraki==0){    //tek düğüm mü var?
		delete ilk;
		ilk=0;
	}else{
	while(ilk->sonraki!=0){
	Dugum* gec=ilk;
	while(gec->sonraki->sonraki!=0)
	{
		gec=gec->sonraki;
	}
	delete gec->sonraki;
	gec->sonraki = 0;
	}
	listeyiSil();
	}
}
void SatirListesi::cikarIndex(int sira)
{
	Dugum* sil= dugumGetir(sira);
	if(sil==0) return;
	Dugum* onceki = sil->onceki;
	Dugum* sonraki = sil->sonraki;
	delete sil;
	elemanSayisi--;
	
	if(sonraki)
		sonraki->onceki=onceki;
	if(onceki){
		onceki->sonraki=sonraki;
	}else{
		ilk=sonraki;
	}
}

Dugum* SatirListesi::dugumGetir(int sira)
{
	int sayac = 0;
	Dugum* gec= ilk;
	while(gec!=0)
	{
		if(sayac==sira)
			return gec;
			
		gec=gec->sonraki;
		sayac++;
	}
	return 0;
}
void SatirListesi::yazdir(int say,int say2)
{
	int aaa=0;
	Dugum* gec= ilk;
		if(say>7){
			say=say%8;
		}
			
		cout<<setw(say*15)<<" "<<"^^^^^^^^"<<endl;
		while(gec!=0){
			if(aaa!=say2){
			cout<<setw(say*15)<<" "<<gec<<endl;
			cout<<setw(say*15)<<" "<<"----------"<<endl;
			cout<<setw(say*15)<<" "<<"|   "<<gec->veri<<"   |"<<endl;			
			cout<<setw(say*15)<<" "<<"----------"<<endl;
			if(gec->sonraki==NULL){
				cout<<setw(say*15)<<" "<<"|00000000|"<<endl;
			}else{
				cout<<setw(say*15)<<" "<<"|"<<gec->sonraki<<"|"<<endl;
			}
			cout<<setw(say*15)<<" "<<"----------"<<endl<<endl;
			}else{
				cout<<setw(say*15)<<" "<<gec<<endl;
				cout<<setw(say*15)<<" "<<"----------"<<endl;
				cout<<setw(say*15)<<" "<<"|   "<<gec->veri<<"   |"<<endl;			
				cout<<setw(say*15)<<" "<<"----------"<<"   <---Silinecek"<<endl;
				if(gec->sonraki==NULL){
					cout<<setw(say*15)<<" "<<"|00000000|"<<endl;
				}else{
					cout<<setw(say*15)<<" "<<"|"<<gec->sonraki<<"|"<<endl;
				}
				cout<<setw(say*15)<<" "<<"----------"<<endl<<endl;
			}
			aaa++;
			gec=gec->sonraki;
		}
		cout<<endl;	

			
}