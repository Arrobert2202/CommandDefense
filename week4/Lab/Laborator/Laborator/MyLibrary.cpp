#include "MyLibrary.h"
#include <cstdio>
#include <cstdlib> /* srand, rand */
#include <ctime>   /* time */
#include <fstream>
#include <cstdarg>

int MyLibrary::get_books_count()
{
    return books_number;
}
int MyLibrary::get_book_index_by_id(int id)
{
    if (books_number <= id)
            return -1;
    return books[id];
}

void MyLibrary::print_books()
{
    output_stream << "Found " << books_number << " books" << endl;
    for (int i = 0; i < books_number; i++)
        output_stream << "Book: " << i << " " << books[i] << endl;
}

MyLibrary::~MyLibrary()
{
    delete[] books;
}

void MyLibrary::update_books_id_by_index(int book_index, int book_id)
{
    if (book_index < books_number)
        this->books[book_index] = book_id;
}