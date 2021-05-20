#pragma once

class Skin 
{
	int skin[11][11]; //tablica reprezentuj¹ca skórê, pojedyncza komórka tablicy przechowuje informacje o stanie komórki skóry
					  // 0 - zdrowa; 1 - odporna; 2 - chora; 3 - zagro¿ona zaka¿eniem [stan pomocniczy, niewidoczny]
	int times[11][11]; //tablica zawieraj¹ca informacje o czasie choroby/odpornoœci pojedynczych komórek skóry
	char sign;
public:
	float count = 0; //zmienna zliczaj¹ca iloœæ chorych komórek
	Skin(); //konstruktor
	~Skin(); //destruktor
	char display_cell(const int cond); //metoda wyœwietlaj¹ca pojedynczy znak okreœlaj¹cy stan komórki skóry;
	const void display_skin(); //metoda wyœwietlaj¹ca stan ca³ej skóry
	void infect();	//metoda "zaka¿enia" - jeœli nie ma jeszcze chorych komórek, zaka¿enie rozpoczyna siê od œrodkowej. Jeœli istniej¹ ju¿ chore, to z szans¹ 50%
					//wprowadza w stan choroby "nara¿one" komórki
	void expose();  //wprowadza komórki na oko³o chorych w stan "nara¿enia"
	void timing();	//metoda zarz¹dzaj¹ca czasem, przez który komórka skóry pozostaje chora/odporna, a w przypadku tego pierwszego zarz¹dza równie¿ przejœciem w stan odpornoœci
};

