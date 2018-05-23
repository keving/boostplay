//
// Created by damian on 14/05/18.
//

#ifndef LIBRARY_LIBRARY_H
#define LIBRARY_LIBRARY_H
#include <stdbool.h>

typedef struct Book {
    char *book_name;
    char *book_type;
    char *book_author;
    int numOfPages;
} Book;

typedef struct Library {
    struct Book Books[100];
    int booksStored;
} Library;


bool CaddBook(Library *lib,  char *bookname, char * booktype, char *bookauthor, int numOfPages);
char * CsearchForBookByName(Library *lib, char *bkname);
char * CsearchForBookByAuthor(Library *lib, char *bkauthor);


#endif //LIBRARY_LIBRARY_H
