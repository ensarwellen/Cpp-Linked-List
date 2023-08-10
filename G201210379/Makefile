all:derle bagla calistir
derle:
	g++ -c -I "./include" ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -c -I "./include" ./src/YoneticiListesi.cpp -o ./lib/YoneticiListesi.o
	g++ -c -I "./include" ./src/SatirListesi.cpp -o ./lib/SatirListesi.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
bagla:
	g++ ./lib/SatirListesi.o ./lib/YoneticiListesi.o ./lib/Dugum.o ./lib/main.o -o ./bin/program
calistir:
	./bin/program