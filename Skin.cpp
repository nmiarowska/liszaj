#include "Skin.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


Skin::Skin()
{
	sign = '+';
	for (int i = 0; i < 11; i++)	//domy�lnie ca�a tablica stan�w ma warto�� 0 (kom�rki zdrowe), tak samo ca�a talica czas�w (kom�rki mog� zmienia� stan)
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
	if (cond == 0 || cond == 3)	//je�li kom�rka jest w stanie zdrowym lub nara�onym, jej znak to "+"
		sign = '+';
	else if (cond == 1)	//je�li kom�rka jest w stanie odpornym, jej znak to "O"
		sign = 'O';
	else if (cond == 2) 	//je�li kom�rka jest w stanie chorym, jej znak to "X"
		sign = 'X';
	return sign;	//zwracanie znaku 
}

const void Skin::display_skin()
{
	for (int i = 0; i < 11; i++)	//powierzchnia "sk�ry" zostaje wy�wietlona w rozmiarze 11x11 kom�rek
	{
		for(int j=0; j<11; j++)
			cout << " " << display_cell(skin[i][j]) << " "; //wy�wietlanie znak�w dla wszystkich kom�rek
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
			if (skin[i][j] == 3) //je�li kom�rka jest nara�ona, to z 50% szans stanie si� chora na 6 jednostek czasu
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
			if (skin[i][j] == 2)	//poni�sze instrukcje sprawdzaj�, czy taki s�siad w og�le istnieje.  
			{						//je�li istnieje i jego czas wynosi 0 (czyli mo�e zmieni� sw�j stan) to stawia tego s�siada w stanie nara�enia
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
			if (times[i][j] > 0)	//je�li czas dla kom�rki jest wi�kszy od 0 to znaczy, �e jej stan zostanie zmieniony z up�ywem czasu (a nie przez szans�)
			{
				if (skin[i][j] == 2)	//je�li kom�rka aktualnie jest chora, a po zmniejszeniu jej czasu b�dzie on r�wny 0,
				{						//to kom�rka przechodzi w stan odporno�ci i czas zostaje ustawiony na 4
					times[i][j]--;
					if (times[i][j] == 0)
					{
						skin[i][j] = 1;
						times[i][j] = 6; //czas odporno�ci
						count--;
					}
				}
				else if (skin[i][j] == 1)	//je�li kom�rka jest w stanie odporno�ci, a po zmniejszeniu jej czasu b�dzie on r�wny 0,
				{							//to kom�rka zmieni sw�j stan na zdrowy
					times[i][j]--;
					if (times[i][j] == 0) {
						skin[i][j] = 0;
					}

				}
			}
		}
	}
}
