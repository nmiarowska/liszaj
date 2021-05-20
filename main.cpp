#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <locale.h>
#include "Skin.h"
#include <iomanip> 
using namespace std;

int main()
{
	srand((unsigned)time(0));
	setlocale(LC_CTYPE, "Polish"); //kodowanie polskich znak�w
	int time = 1000; //czas w ms
	Skin s;
	int rounds = 0;
	while(1){
		if (s.count == 0)
			system("pause");
		float percentage = (s.count / 121 * 100);
		string header = "____________________\n\nSymulacja rozwoju liszaja\n____________________\n";
		string legend = "+ <- kom�rka zdrowa; X <- kom�rka chora; O <- kom�rka odporna\n";
		string result = "Aktualny stan: liczba chorych kom�rek to ";
		cout << header << legend << result << fixed << setprecision(0) << s.count << " (" << fixed << setprecision(2) << percentage << "%)\nMin�o ju� " << rounds << " jednostek czasu\n\n";
		s.display_skin();
		Sleep(time);
		system("CLS");
		s.infect();
		rounds++;
	}
	return 0;
}