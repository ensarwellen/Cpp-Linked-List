/**
* @file Dugum.hpp
* @description Dugum sınıfının tanımını yapıyoruz.
* @course 2.ÖĞRETİM B GRUBU
* @assignment 1
* @date 24.11.2022
* @author Ensar Çelik-ensar.celik2@ogr.sakarya.edu.tr
*/
#ifndef Dugum_hpp
#define Dugum_hpp

class Dugum
{
public:
	Dugum(int veri);
	~Dugum();
	int veri;
	Dugum* onceki;
	Dugum* sonraki;
};

#endif