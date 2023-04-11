#ifndef BOOK_H_
#define BOOK_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Book
{
	friend ostream& operator<<(ostream& os, Book& b);
	
public:
	Book();
	Book(string n, string a, string d);
	string getAutor();
	string getTitle();
	friend bool operator==(const Book& lhs, const Book& rhs)
	{
		return lhs.Name == rhs.Name && lhs.Autor == rhs.Autor && lhs.Date == rhs.Date;
	}
	~Book();
private:
	string Name;
	string Autor;
	string Date;
};


class Library
{
public:
	Library();
	Library(string fname);
	void addBook(Book book);
	void removeBook(Book book);
	void sort_by_author(string name);
	void ShowAll();
	void fing_by_title(string name);
private:
	vector<Book> books;
	string file_name;
};



#endif 
