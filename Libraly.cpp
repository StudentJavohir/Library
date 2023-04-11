#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Book.h"
using namespace std;

int main() {
	string fname;
	Book pnt;
	cout << "Enter name for Library : "  ;
	cin >> fname;
	Library Lib(fname);
	int a = 10;
	while (a != 0) {
		cout << " 0: Quit" << endl;
		cout << " 1: Add book" << endl;
		cout << " 2: Choose by autor" << endl;
		cout << " 3: Choose by title" << endl;
		cout << " 4: Show all" << endl;
		cout << " 5: Remove book" << endl;
		cin >> a;
		switch (a)
		{
		case 0: {
			continue; }
		case 1: {
			string x, y, z;
			cout << "Input : Title,Autor,Date" << endl;
			cin >> x >> y >> z;
			Book  b(x, y, z);
			Lib.addBook(b);
			break;
		}

		case 2: {
			string x;
			cout << "What autor : ";
			cin >> x;
			Lib.sort_by_author(x);
			break;

		}case 3: {
			string x;
			cout << "What title : ";
			cin >> x;
			Lib.fing_by_title(x);
			break;

		}
		case 4: {
			Lib.ShowAll();
			break;

		}
		case 5: {
			string x, y, z;
			cout << "Input : Title,Autor,Date" << endl;
			cin >> x >> y >> z;
			Book  b(x, y, z);
			Lib.removeBook(b);
			break;
		}

		}
	}


}