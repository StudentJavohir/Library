#include "Book.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

Book::Book() {
	Name = "XXX";
	Autor = "XXX";
	Date = "XXX";
}

Book::Book(string n, string a, string d):Name(n),Autor(a),Date(d){}
Book::~Book(){}
string Book::getAutor() {
	return Autor;
}
string Book::getTitle() {
	return Name;
}

ostream& operator<<(ostream& os, Book& b) {
	cout << "\n//////////////////////////////////////\n";
	cout << "Author " << " Title " << " Date " << endl;
	os << b.Autor << " " << b.Name << " " << b.Date << endl;
	return os;
}


Library::Library() {

}
Library::Library(string fname):file_name(fname) {}

void Library::addBook(Book book) {
	books.push_back(book);
	ofstream LibraryV2;
	LibraryV2.open(file_name, ios::app);
	LibraryV2.write((char*)&book, sizeof(Book));
	LibraryV2.close();
}

void Library::removeBook(Book book) {
	std::vector<Book>::iterator it;
	it = std::find(books.begin(), books.end(), book);
	if (it != books.end()) {
		books.erase(it);
	}
	
	
	ofstream LibraryV2;
	LibraryV2.open(file_name);
	for (const auto b : books) {
		LibraryV2.write((char*)&b, sizeof(Book));
	}
	
	LibraryV2.close();
}

void Library::sort_by_author(string name) {
	
	ifstream LibraryV2;
	LibraryV2.open(file_name);
	Book pnt;

	while (LibraryV2.read((char*)&pnt, sizeof(Book))) {
		if (name == pnt.getAutor()) {
			cout << pnt;
		}

	}

	LibraryV2.close();
	
}

void Library::ShowAll()
{
	for (Book b : books) {
		cout << b;
	}
}

void Library::fing_by_title(string name) {
	ifstream LibraryV2;
	LibraryV2.open(file_name);
	Book pnt;

	while (LibraryV2.read((char*)&pnt, sizeof(Book))) {
		if (name == pnt.getTitle()) {
			cout << pnt;
		}

	}

	LibraryV2.close();
}