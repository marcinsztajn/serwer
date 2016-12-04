# Description 
Jezeli pod eclipse:
	Dla clienta, normalny projekt (zmienic IP)
	Dla serwera, kompilacja biblioteki:
	a) gcc -c -Wall -fpic moja_biblioteka.c (pic - dodanie wskazania posredniego. ladowanie adresu i skok do niego )
	b) gcc -shared -o -libmoja_biblioteka.so moja_biblioteka.o (tworzenie biblioteki dynamicznej z pliku obiektowego)
	Dalej w opcjach dla serwera w eclipse nalezy ustawic sciezke do biblioteki, dodac nazwe biblioteki (jedna zakladaka) oraz zmienna 
	srodowiskowa LD_LIBRARY_PATH
Jezeli z poziomu powloki:
	Kompilacja biblioteki standardowo.
	Komendy do uruchomienia serwera z wlaczeniem biblioteki dynamicznej do kompilacji:
	gcc -L/home/marcin/eclipse/nowy/serwer/src/ -Wall -o test serwer.c -lmoja_biblioteka

Dodatkowe komendy:
	a) ar rcs libmoja_biblioteka.a libmoja_biblioteka.o - kompilowanie z pliku obiektowego do biblioteki statycznej
	b) gcc -static main.c -L. -lmoja_biblioteka -o static - kompilowanie z dolaczeniem biblioteki statycznej
