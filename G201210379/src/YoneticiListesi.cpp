/**
* @file YoneticiListesi.cpp
* @description YoneticiListesi sınıfımızın metot gövdesi... Bu kod bloğunda SatirListesinden aldığımız satırların ortalamaları tutuluyor. Ortalama yazırma da bu kod bloğu içerisinde 
yer almaktadır.
* @course 2.ÖĞRETİM B GRUBU
* @assignment 1
* @date 24.11.2022
* @author Ensar Çelik-ensar.celik2@ogr.sakarya.edu.tr
*/
#include "YoneticiListesi.hpp"
#include<iomanip>
#include<random>

YoneticiListesi::YoneticiListesi()
{
    bas = NULL;
	listeSayaci=0;
}

void YoneticiListesi::listeEkle(SatirListesi *_liste)
{
    //Eger liste bossa
    if (bas == NULL)
    {
        bas = _liste;
		listeSayaci++;
		return;
    }
	SatirListesi *pBas = bas;
	double x = 0;
	float y = 0;
	x = pBas->ortalamaGetir();
	cout<<"";
	y = _liste->ortalamaGetir();
	if(pBas->sonrakiListe==NULL)  //listede 1 eleman varken
	{
		if(x<y){                 //ilk elemanın sağına ekler
		listeSayaci++;
		_liste->oncekiListe=pBas;
        _liste->sonrakiListe=NULL;
		pBas->sonrakiListe=_liste;
		return;
		}
		if(x>=y){                 //ilk elemanın soluna ekler
			_liste->sonrakiListe=pBas;
			pBas->oncekiListe=_liste;
			bas=_liste;
		}
	}
    if(x>y)  //ilk elemanın öncesine eleman koyma
    {
			listeSayaci++;
			_liste->sonrakiListe=pBas;	
			pBas->oncekiListe=_liste;
			bas=_liste;
			
	}else{		
        //Sona git
        while (pBas->sonrakiListe != NULL && pBas->sonrakiListe->ortalamaGetir()<y)
        {		
            pBas = pBas->sonrakiListe;
			x=pBas->ortalamaGetir();
			
        }
		if(pBas->sonrakiListe==NULL)
		{
		listeSayaci++;
		_liste->oncekiListe=pBas;
        _liste->sonrakiListe=NULL;
		pBas->sonrakiListe=_liste;
		return;
		}
		listeSayaci++;
		_liste->oncekiListe=pBas;
        _liste->sonrakiListe=pBas->sonrakiListe;
		pBas->sonrakiListe->oncekiListe=_liste;	
		pBas->sonrakiListe=_liste;
			
	}
}

void YoneticiListesi::ortalamaAl(int say)  //sayiListelerinin ortalamalarını ortalamaGetir ile getirir.
{
	double ort=0;
	int sayac=0;
	int j=0;
	cout<<"";
	//int ls= ListeSayisi();
	if(listeSayaci==0) return;
	
	SatirListesi* pBas = bas;	
	if(listeSayaci-say>8){
		if(say==0){
			cout<<"ilk";
		}else{
			cout<<"<---";
		}
		cout<<setw(114)<<right<<"--->"<<endl;
		while(j!=say){
			pBas = pBas->sonrakiListe;
			j++;
		}
		while(sayac<8){
			cout<<setw(9)<<right<<pBas<<setw(6)<<" ";
			pBas = pBas->sonrakiListe;
			sayac++;
		}
		cout<<endl;
		sayac=0;
		j=0;
		pBas=bas;
		while(j!=say){
			pBas = pBas->sonrakiListe;
			j++;
		}
		while(sayac<8){
			cout<<setw(15)<<left<<"-----------";
			pBas = pBas->sonrakiListe;
			sayac++;
		}
		cout<<endl;
		sayac=0;
		j=0;
		pBas=bas;
		while(j!=say){
			pBas = pBas->sonrakiListe;
			j++;
		}
		while(sayac<8){
			if(pBas->oncekiListe==NULL){
				cout<<"|"<<setw(9)<<right<<"000000000"<<"|"<<setw(4)<<" ";
				pBas=pBas->sonrakiListe;
				sayac++;
			}
			cout<<"|"<<setw(9)<<right<<pBas->oncekiListe<<"|"<<setw(4)<<" ";
			pBas = pBas->sonrakiListe;
			sayac++;
		}
		cout<<endl;
		sayac=0;
		j=0;
		pBas=bas;
		while(j!=say){
			pBas = pBas->sonrakiListe;
			j++;
		}
		while(sayac<8){
			cout<<setw(15)<<left<<"-----------";
			pBas = pBas->sonrakiListe;
			sayac++;
		}
		cout<<endl;
		sayac=0;
		j=0;
		pBas=bas;
		while(j!=say){
			pBas = pBas->sonrakiListe;
			j++;
		}
		while(sayac<8){
			ort = pBas->ortalamaGetir();
			cout<<"|"<<setw(9)<<right<<fixed<<setprecision(2)<<ort<<"|"<<setw(4)<<" ";
			pBas = pBas->sonrakiListe;
			sayac++;
		}
		cout<<endl;
		sayac=0;
		j=0;
		pBas=bas;
		while(j!=say){
			pBas = pBas->sonrakiListe;
			j++;
		}
		while(sayac<8){
			cout<<setw(15)<<left<<"-----------";
			pBas = pBas->sonrakiListe;
			sayac++;
		}
		cout<<endl;
		sayac=0;
		j=0;
		pBas=bas;
		while(j!=say){
			pBas = pBas->sonrakiListe;
			j++;
		}
		while(sayac<8){
			cout<<"|"<<setw(9)<<right<<pBas->sonrakiListe<<"|"<<setw(4)<<" ";
			pBas = pBas->sonrakiListe;
			sayac++;
		}
		cout<<endl;
		sayac=0;
		j=0;
		pBas=bas;
		while(j!=say){
			pBas = pBas->sonrakiListe;
			j++;
		}
		while(sayac<8){
			cout<<setw(15)<<left<<"-----------";
			pBas = pBas->sonrakiListe;
			sayac++;
		}
		cout<<endl;
	}
	if(listeSayaci-say<=8){
		if(say==0){
			cout<<"ilk";
		}else{
			cout<<"<---";
		}
		if(listeSayaci%8==0){
			cout<<setw(114)<<right<<"son"<<endl;
		}else{
			cout<<setw((listeSayaci%8)*13)<<right<<"son"<<endl;
		}
		
		
		while(j!=say){
			pBas = pBas->sonrakiListe;
			j++;
		}
		while(sayac<listeSayaci-say){
			cout<<setw(9)<<right<<pBas<<setw(6)<<" ";
			pBas = pBas->sonrakiListe;
			sayac++;
		}
		cout<<endl;
		sayac=0;
		j=0;
		pBas=bas;
		while(j!=say){
			pBas = pBas->sonrakiListe;
			j++;
		}
		while(sayac<listeSayaci-say){
			cout<<setw(15)<<left<<"----------";
			pBas = pBas->sonrakiListe;
			sayac++;
		}
		cout<<endl;
		sayac=0;
		j=0;
		pBas=bas;
		while(j!=say){
			pBas = pBas->sonrakiListe;
			j++;
		}
		while(sayac<listeSayaci-say){
			cout<<"|"<<setw(9)<<right<<pBas->oncekiListe<<"|"<<setw(4)<<" ";
			pBas = pBas->sonrakiListe;
			sayac++;
		}
		cout<<endl;
		sayac=0;
		j=0;
		pBas=bas;
		while(j!=say){
			pBas = pBas->sonrakiListe;
			j++;
		}
		while(sayac<listeSayaci-say){
			cout<<setw(15)<<left<<"----------";
			pBas = pBas->sonrakiListe;
			sayac++;
		}
		cout<<endl;
		sayac=0;
		j=0;
		pBas=bas;
		while(j!=say){
			pBas = pBas->sonrakiListe;
			j++;
		}
		while(sayac<listeSayaci-say){
			ort = pBas->ortalamaGetir();
			cout<<"|"<<setw(9)<<right<<fixed<<setprecision(2)<<ort<<"|"<<setw(4)<<" ";
			pBas = pBas->sonrakiListe;
			sayac++;
		}
		cout<<endl;
		sayac=0;
		j=0;
		pBas=bas;
		while(j!=say){
			pBas = pBas->sonrakiListe;
			j++;
		}
		while(sayac<listeSayaci-say){
			cout<<setw(15)<<left<<"----------";
			pBas = pBas->sonrakiListe;
			sayac++;
		}
		cout<<endl;
		sayac=0;
		j=0;
		pBas=bas;
		while(j!=say){
			pBas = pBas->sonrakiListe;
			j++;
		}
		while(sayac<listeSayaci-say){
			if(pBas->sonrakiListe==NULL){
				cout<<"|"<<setw(9)<<right<<"000000000"<<"|"<<setw(4)<<" ";
				pBas=pBas->sonrakiListe;
				sayac++;
			}else{
			cout<<"|"<<setw(9)<<right<<pBas->sonrakiListe<<"|"<<setw(4)<<" ";
			pBas = pBas->sonrakiListe;
			sayac++;
			}
		}			
		cout<<endl;
		sayac=0;
		j=0;
		pBas=bas;
		while(j!=say){
			pBas = pBas->sonrakiListe;
			j++;
		}
		while(sayac<listeSayaci-say){
			cout<<setw(15)<<left<<"----------";
			pBas = pBas->sonrakiListe;
			sayac++;
		}
		cout<<endl;
	}
		
}
void YoneticiListesi::icerikYazdir()
{
		char ch;
		int i=0;
		int t = 0;
		//int bolum = listeSayaci/8;
		ListeYazdir(i,-1);
		//i++;
		while(true){
		cin>>ch;
		if(ch=='c' && (i<=t+7 && i<listeSayaci-1))
		{
			if(i==t+7){
				system("cls");
				ortalamaAl(t);
				ListeYazdir(i,-1);
			}else{
				system("cls");
				ortalamaAl(t);
				i++;
				ListeYazdir(i,-1);
			}
			
		}else if(ch=='c' && i>=t && i==listeSayaci-1){
			system("cls");
			ortalamaAl(t);
			ListeYazdir(i,-1);
		}else if(ch=='z' && i>t){
			i--;
			system("cls");
			ortalamaAl(t);
			ListeYazdir(i,-1);
		}else if(ch=='z' && i==t){
			system("cls");
			ortalamaAl(t);
			ListeYazdir(i,-1);
		}else if(ch=='p'){
			ListeSil(i);
			if(i==listeSayaci)  //son listeyi silince i yi bir azaltıp sondan bir önceki listeyi gösteriyoruz.
			{
				i--;
				if(listeSayaci%8==0){     //son liste silinirse ekranı bir önceki listeye atıyor. Mesela 4 sayfa var 4. sayfayı komple silersen seni 3e atar ve 4e ulaşamazsın.
				t-=8;
				i=t;
				system("cls");
				cout<<i<<endl;
				ortalamaAl(t);
				ListeYazdir(i,-1);
				}else{
				system("cls");
				ortalamaAl(t);
				ListeYazdir(i,-1);}
			}else{				//son listeden farklı bir liste silince i yi değiştirmemize gerek yok.
				system("cls");
				cout<<i<<endl;
				ortalamaAl(t);
				ListeYazdir(i,-1);
			}
		}else if(ch=='k'){
			int x = SilmedenOnceSor(i);
			system("cls");
			ortalamaAl(t);
			ListeYazdir(i,x);
			cin>>ch;
			if(ch=='k'){
			DugumSil(i, x);
			if(listeSayaci<8){
				system("cls");
				ortalamaAl(t);
				ListeYazdir(i,-1);
			}
			else if(i==listeSayaci)  //son listeyi silince i yi bir azaltıp sondan bir önceki listeyi gösteriyoruz.
			{
				if(listeSayaci%8==0){     //son liste silinirse ekranı bir önceki listeye atıyor. Mesela 4 sayfa var 4. sayfayı komple silersen seni 3e atar ve 4e ulaşamazsın.
				t-=8;
				i=t;
				system("cls");
				ortalamaAl(t);
				ListeYazdir(i,-1);
				}else{
				system("cls");
				ortalamaAl(t);
				ListeYazdir(i,-1);}
			}else{				//son listeden farklı bir liste silince i yi değiştirmemize gerek yok.
				system("cls");
				ortalamaAl(t);
				ListeYazdir(i,-1);
			}
			}
		}else if(ch=='d'){
			if(listeSayaci>=8)
			{
				if(listeSayaci%8!=0){
					if(t==(listeSayaci/8)*8)
					{
						system("cls");
						ortalamaAl(t);
						ListeYazdir(i,-1);
					}else{
						t+=8;
						i = t;
						system("cls");
						ortalamaAl(t);
						ListeYazdir(i,-1);
					}
					
				}else{
					if(t==((listeSayaci/8)*8) - 8){
						system("cls");
						ortalamaAl(t);
						ListeYazdir(i,-1);
					}else{
						t+=8;
						i = t;
						system("cls");
						ortalamaAl(t);
						ListeYazdir(i,-1);
					}
				
				}				
			}else{                     //liste 8den küçükse
				system("cls");
				ortalamaAl(t);
				ListeYazdir(i,-1);
			}
		}
		else if(ch=='a'){
			if(t!=0){
				t-=8;
				i=t;
				system("cls");
				ortalamaAl(t);
				ListeYazdir(i,-1);				
			}else{
				system("cls");
				ortalamaAl(t);
				ListeYazdir(i,-1);				
			}
		}
	}
		
}
int YoneticiListesi::SilmedenOnceSor(int say)
{
	int i=0;
	int sira;
	SatirListesi* pBas=bas;
	while(i!=say){
		pBas=pBas->sonrakiListe;
		i++;
	}
	if(pBas->elemanSayisi==1)
	{
		sira=0;
		return sira;
	}
	srand (time(0));
	sira = rand()% (pBas->elemanSayisi-1);
	
	return sira;
}
void YoneticiListesi::DugumSil(int say, int say2)
{
	int i=0;
	SatirListesi* pBas=bas;
	while(i!=say){
		pBas=pBas->sonrakiListe;
		i++;
	}
	if(pBas->elemanSayisi==1)
	{
		pBas->cikarIndex(0);
		ListeSil(i);
		return;
	}
	pBas->cikarIndex(say2);     //Burdan asagiyi yapmak tam bir ölümdü.
	if(listeSayaci==1){
		return;
	}
	SatirListesi* itr=pBas;
	while(pBas->oncekiListe!=NULL){
		pBas=pBas->oncekiListe;
	}
	if(itr->oncekiListe==NULL)
	{
		if(itr->ortalamaGetir()<pBas->sonrakiListe->ortalamaGetir()){   //ilk eleman silindiği halde en küçükse
			return;
		}
		while(pBas->ortalamaGetir()>itr->ortalamaGetir() && pBas->sonrakiListe!=NULL){  //sağa eleman ekleme
			pBas=pBas->sonrakiListe;
		}
			if(pBas->sonrakiListe==NULL && pBas->ortalamaGetir()<itr->ortalamaGetir()){  //son elemanın sağına ekleme
			itr->sonrakiListe->oncekiListe=NULL;
			bas=itr->sonrakiListe;
			pBas->sonrakiListe=itr;
			itr->oncekiListe=pBas;
			itr->sonrakiListe=NULL;
			}else
			itr->sonrakiListe->oncekiListe=NULL;                //sola eleman ekleme 
			bas=itr->sonrakiListe;
			itr->sonrakiListe=pBas;
			itr->oncekiListe=pBas->oncekiListe;
			pBas->oncekiListe->sonrakiListe=itr;
			pBas->oncekiListe=itr;
			}
	else if(itr->sonrakiListe==NULL){
		if(itr->ortalamaGetir()>itr->oncekiListe->ortalamaGetir()){
			return;
		}
		while(pBas->ortalamaGetir()<itr->ortalamaGetir() && pBas->sonrakiListe!=NULL){
			pBas=pBas->sonrakiListe;
		}
		itr->oncekiListe->sonrakiListe=NULL;
		itr->oncekiListe=pBas->oncekiListe;
		itr->sonrakiListe=pBas;
		pBas->oncekiListe->sonrakiListe=itr;
		pBas->oncekiListe=itr;
		
	}
		else{
		itr->sonrakiListe->oncekiListe=itr->oncekiListe;
		itr->oncekiListe->sonrakiListe=itr->sonrakiListe;
		while(pBas->ortalamaGetir()<itr->ortalamaGetir()&&pBas->sonrakiListe!=NULL){
			pBas=pBas->sonrakiListe;
		}if(pBas->oncekiListe==NULL){   //itr sağdayken ilk elemanın soluna eleman ekleme
			itr->sonrakiListe=pBas;
			pBas->oncekiListe=itr;
			bas=itr;
			itr->oncekiListe=NULL;
		}else if(pBas->sonrakiListe==NULL && pBas->ortalamaGetir()<itr->ortalamaGetir()){  //
			pBas->sonrakiListe=itr;
			itr->oncekiListe=pBas;
			itr->sonrakiListe=NULL;
		}
		else{                         //itr sağdayken araya eleman ekleme
			itr->sonrakiListe=pBas;
			itr->oncekiListe=pBas->oncekiListe;
			pBas->oncekiListe->sonrakiListe=itr;
			pBas->oncekiListe=itr;
		}
	}
		
}

void YoneticiListesi::ListeSil(int say)
{
	int i=0;
	if(bas==NULL) return;
	if(bas->sonrakiListe==NULL) //Listede 1 liste varsa
	{
		bas->listeyiSil();
		delete bas;
		bas=0;
		listeSayaci--;
	}else{
		SatirListesi* pBas=bas;
		while(i!=say){
			pBas=pBas->sonrakiListe;
			i++;
		}
		pBas->listeyiSil();
		if(pBas->sonrakiListe!=NULL)
		{
			if(say==0) //çoklu listede ilk listeyi silme
			{
				pBas->sonrakiListe->oncekiListe=NULL;
				bas=pBas->sonrakiListe;
				listeSayaci--;
				return;
			}
			//çoklu listede aradan liste silme
			pBas->oncekiListe->sonrakiListe=pBas->sonrakiListe;
			pBas->sonrakiListe->oncekiListe=pBas->oncekiListe;
			listeSayaci--;
			delete pBas;
		}else{
			pBas->oncekiListe->sonrakiListe=NULL;
			delete pBas;
			listeSayaci--;
		}
	}
		
		
}
void YoneticiListesi::ListeYazdir(int say, int x)
{
	int i=0;
	SatirListesi* pBas=bas;	
	if(listeSayaci==0){
		cout<<"Listede liste yok!"<<endl;
		return;
	}
			
		while(i!=say){
			pBas=pBas->sonrakiListe;
			i++;
		}
		pBas->yazdir(say, x);
}
YoneticiListesi::~YoneticiListesi(){
    SatirListesi *pBas = bas;
    while (pBas != NULL)
    {
        SatirListesi* silinecek  = pBas;
        pBas = pBas->sonrakiListe;
        delete silinecek;
    }
}
