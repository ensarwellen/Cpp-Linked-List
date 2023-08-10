/**
* @file main.cpp
* @description Sayilar.txt dosyamızdaki elemanları tek tek okuyor, işlemler tamamlandıktan sonra dosyayı kapıyor ve
sayiListeleri listemizi siliyor.
* @course 2.ÖĞRETİM B GRUBU
* @assignment 1
* @date 24.11.2022
* @author Ensar Çelik-ensar.celik2@ogr.sakarya.edu.tr
*/
#include "SatirListesi.hpp"
#include <YoneticiListesi.hpp>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    ifstream oku("veriler.txt", ios::in);
    string boslugaKadar = "";
    string satir = "";
    YoneticiListesi *sayiListeleri = new YoneticiListesi();
    if (oku.is_open())
    {
        while (getline(oku, satir))
        {
            SatirListesi *liste = new SatirListesi();
            boslugaKadar = "";
            int *dizi = new int[satir.length()];
			for (int j = 0; j < satir.length(); j++) //satır sonunda boşluk varsa onları silmek için bu for döngüsünü kullandım.
			{
				int d = satir.length()-1;
				while(d>0)
				{
					if (satir[d] == ' ' || satir[d] == '\n' || satir[d] == '\t')
					d--;
					else break;
				}
				satir[d+1]='\0';
			}
            int gercekUzunluk = 0;
            for (int i = 0; i < satir.length(); i++)  //1 satır okur ve tekrar while döngüsüne döner
            {

                if (satir[i] == ' ' )
                {					
                    dizi[gercekUzunluk] = stoi(boslugaKadar);
                    gercekUzunluk++;
                    boslugaKadar = "";					
                }
                else
                {
                    boslugaKadar = boslugaKadar + satir[i];
                }
            }
            dizi[gercekUzunluk] = stoi(boslugaKadar);
            gercekUzunluk++; 
            liste->ekle(dizi, gercekUzunluk);
            sayiListeleri->listeEkle(liste);
			
        }
		sayiListeleri->ortalamaAl(0);
		sayiListeleri->icerikYazdir();

    }
    oku.close();
    

    delete sayiListeleri;
    system("pause");
}