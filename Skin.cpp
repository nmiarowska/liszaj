#include "Skin.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


Skin::Skin()
{
	sign = '+';
	for (int i = 0; i < 11; i++)	//domyœlnie ca³a tablica stanów ma wartoœæ 0 (komórki zdrowe), tak samo ca³a talica czasów (komórki mog¹ zmieniaæ stan)
	{
		for (int j = 0; j < 11; j++)
		{ 
			skin[i][j] = 0;
			times[i][j] = 0;
		}
	}
	skin[5][5] = 2;
	times[5][5] = 6;
	count++;
}

Skin::~Skin()
{
	cout << "Destruktor";
}

char Skin::display_cell(const int cond)
{
	if (cond == 0 || cond == 3)	//jeœli komórka jest w stanie zdrowym lub nara¿onym, jej znak to "+"
		sign = '+';
	else if (cond == 1)	//jeœli komórka jest w stanie odpornym, jej znak to "O"
		sign = 'O';
	else if (cond == 2) 	//jeœli komórka jest w stanie chorym, jej znak to "X"
		sign = 'X';
	return sign;	//zwracanie znaku 
}

const void Skin::display_skin()
{
	for (int i = 0; i < 11; i++)	//powierzchnia "skóry" zostaje wyœwietlona w rozmiarze 11x11 komórek
	{
		for(int j=0; j<11; j++)
			cout << " " << display_cell(skin[i][j]) << " "; //wyœwietlanie znaków dla wszystkich komórek
		cout << endl;
	}
}

void Skin::infect()
{
	int randomNumber;
	this->timing();
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (skin[i][j] == 3) //jeœli komórka jest nara¿ona, to z 50% szans stanie siê chora na 6 jednostek czasu
			{
				randomNumber = (rand() % 2) + 1;
				if (randomNumber == 1) 
				{
					skin[i][j] = 2;
					count++;
					times[i][j] = 6;
				}
			}
		}
	}
	this->expose();
}

void Skin::expose()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (skin[i][j] == 2)	//poni¿sze instrukcje sprawdzaj¹, czy taki s¹siad w ogóle istnieje.  
			{						//jeœli istnieje i jego czas wynosi 0 (czyli mo¿e zmieniæ swój stan) to stawia tego s¹siada w stanie nara¿enia
				if (i > 0)
				{
					if (times[i-1][j] == 0)
						skin[i - 1][j] = 3;
				}
				if (i < 10)
				{
					if (times[i+1][j] == 0)
						skin[i + 1][j] = 3;
				}
				if (j > 0)
				{
					if (times[i][j-1] == 0)
						skin[i][j - 1] = 3;
				}				
				if (j < 10)
				{
					if (times[i][j+1] == 0)
						skin[i][j + 1] = 3;
				}				
				if (i > 0 && j > 0)
				{
					if (times[i-1][j-1] == 0)
						skin[i - 1][j - 1] = 3;
				}			
				if (i > 0 && j < 10)
				{
					if (times[i-1][j+1] == 0)
						skin[i - 1][j + 1] = 3;
				}			
				if (i < 10 && j > 0)
				{
					if (times[i+1][j-1] == 0)
						skin[i + 1][j - 1] = 3;
				}				
				if (i <10 && j < 10)
				{
					if (times[i+1][j+1] == 0)
						skin[i + 1][j + 1] = 3;
				}			
			}
		}
	}
}

void Skin::timing()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (times[i][j] > 0)	//jeœli czas dla komórki jest wiêkszy od 0 to znaczy, ¿e jej stan zostanie zmieniony z up³ywem czasu (a nie przez szansê)
			{
				if (skin[i][j] == 2)	//jeœli komórka aktualnie jest chora, a po zmniejszeniu jej czasu bêdzie on równy 0,
				{						//to komórka przechodzi w stan odpornoœci i czas zostaje ustawiony na 4
					times[i][j]--;
					if (times[i][j] == 0)
					{
						skin[i][j] = 1;
						times[i][j] = 6; //czas odpornoœci
						count--;
					}
				}
				else if (skin[i][j] == 1)	//jeœli komórka jest w stanie odpornoœci, a po zmniejszeniu jej czasu bêdzie on równy 0,
				{							//to komórka zmieni swój stan na zdrowy
					times[i][j]--;
					if (times[i][j] == 0) {
						skin[i][j] = 0;
					}

				}
			}
		}
	}
}
