#include <iostream>

using std::logic_error;
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

auto main(int argc, const char* argv[]) -> int
{
	try
	{
		/* Losujemy numer */
		srand(time(NULL));
		int CorrectNumber = (rand() % 100) + 1;
		int Number = 0;

		cout << "Wylosowano liczbe! Zgadnij!" << endl;

		do {
			cout << "Podaj liczbe: ";
			cin >> Number;
			if (cin.fail())
			{
				throw logic_error{ "Podany ciag znakow nie mogl zostac zrzutowany na typ int" };
			}

			if (Number > CorrectNumber)
			{
				cout << "Liczba za duza!" << endl;
			}
			else if (Number < CorrectNumber)
			{
				cout << "Liczba za mala!" << endl;
			}
		} while (Number != CorrectNumber);

		cout << "Brawo!" << endl;

		return 0;
	}
	catch (logic_error ex)
	{
		cerr << ex.what() << endl;
		return 1;
	}
}