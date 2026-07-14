#ifndef LIBRARY_H
#define LIBRARY_H

struct Book
{
    int bookId;
    char title[50];
    char author[50];
    int quantity;
};

void libraryMenu();

void addBook(struct Book *book,int *count);
void viewBook(struct Book *book,int count);

#endif