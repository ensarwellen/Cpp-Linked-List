/**
* @file Dugum.cpp
* @description Dugum sınıfımızın metot gövdesi... Düğümleri oluşturuyor.
* @course 2.ÖĞRETİM B GRUBU
* @assignment 1
* @date 24.11.2022
* @author Ensar Çelik-ensar.celik2@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"
#include<iostream>
using namespace std;

Dugum::Dugum(int veri)
{
	this->veri = veri;
	sonraki=onceki=0;
}
Dugum::~Dugum()
{
}