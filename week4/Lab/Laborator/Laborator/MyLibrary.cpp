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
MyLibrary::MyLibrary(ostream& output_stream) : output_stream(output_stream)
{
    this->books_number = -1;
    books= nullptr;
}
MyLibrary::MyLibrary(ostream& output_stream, int books_number, int* books) : output_stream(output_stream)
{
    this->books_number = books_number;
    this->books        = new int[books_number];
    for (int i=0;i<books_number;i++)
    {
        this->books[i] = books[i];
    }
}
MyLibrary::MyLibrary(ostream& output_stream, int books_number, int min, int max): output_stream(output_stream)
{
    this->books_number = books_number;
    srand(time(NULL));
    books = new int[books_number];
    for (int i=0;i<books_number;i++)
    {
        books[i] = rand() % (max - min) + min;
    }
}
MyLibrary::MyLibrary(ostream& output_stream, const char* books_values) : output_stream(output_stream) 
{

}
MyLibrary::MyLibrary(ostream& output_stream, int books_count, ...) : output_stream(output_stream)
{
    this->books_number = books_count;
    books = new int[books_number];

    va_list arg;
    va_start(arg, books_count);
    for (int i = 0; i < books_number; i++)
    {
        this->books[i] = va_arg(arg, int);
    }

    va_end(arg);
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