#pragma once

class Skin 
{
	int skin[11][11]; //tablica reprezentuj�ca sk�r�, pojedyncza kom�rka tablicy przechowuje informacje o stanie kom�rki sk�ry
					  // 0 - zdrowa; 1 - odporna; 2 - chora; 3 - zagro�ona zaka�eniem [stan pomocniczy, niewidoczny]
	int times[11][11]; //tablica zawieraj�ca informacje o czasie choroby/odporno�ci pojedynczych kom�rek sk�ry
	char sign;
public:
	float count = 0; //zmienna zliczaj�ca ilo�� chorych kom�rek
	Skin(); //konstruktor
	~Skin(); //destruktor
	char display_cell(const int cond); //metoda wy�wietlaj�ca pojedynczy znak okre�laj�cy stan kom�rki sk�ry;
	const void display_skin(); //metoda wy�wietlaj�ca stan ca�ej sk�ry
	void infect();	//metoda "zaka�enia" - je�li nie ma jeszcze chorych kom�rek, zaka�enie rozpoczyna si� od �rodkowej. Je�li istniej� ju� chore, to z szans� 50%
					//wprowadza w stan choroby "nara�one" kom�rki
	void expose();  //wprowadza kom�rki na oko�o chorych w stan "nara�enia"
	void timing();	//metoda zarz�dzaj�ca czasem, przez kt�ry kom�rka sk�ry pozostaje chora/odporna, a w przypadku tego pierwszego zarz�dza r�wnie� przej�ciem w stan odporno�ci
};

