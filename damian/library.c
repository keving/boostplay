#include <stdio.h>
#include <Python.h>
#include "library.h"

bool CaddBook(Library *lib,  char *bookname, char * booktype, char *bookauthor, int numOfPages) {

//    static int result = 0;
//
//    if (result == 0) {
//        lib->booksStored = 0;
//        result = 1;
//    }

    static int count = 0;
    printf("Count = %d\n", count);
    printf("Book Name: '%s'\n", bookname);
    lib->Books[count].book_name = bookname;
    lib->Books[count].book_author = bookauthor;
    lib->Books[count].book_type = booktype;
    lib->Books[count].numOfPages = numOfPages;
    lib->booksStored++;
    printf("Adrs of book_name: %p\n", lib->Books[count].book_name);
    printf("Book_name: '%s'\n", lib->Books[count].book_name);
    printf("Book Count: '%d'\n", lib->booksStored);
    count++;

    return true;
}


char * CsearchForBookByName(Library *lib, char *bkname) {

    int storedBks = lib->booksStored;

    printf("Number of Books %d\n", storedBks);

    for (int i = 0; i < storedBks; i++) {
        if (!strcmp(lib->Books[i].book_name, bkname)) {
            return "Found";
        }
    }
    return "Not Found";
}


char * CsearchForBookByAuthor(Library *lib, char *bkauthor) {
    int storedBks = lib->booksStored;

    for (int i = 0; i < storedBks; i++) {
        if (!strcmp(lib->Books[i].book_author, bkauthor)) {
            return "Found";
        }
    }
    return "Not Found";
}

// in python creating a python class(Structure) with attributes which then could be happily passed
// to any of the functions above

// getting return values of SeaFoBook and SeaBookAuthor and printing them

static PyObject* addBook(PyObject* self, PyObject* args)
{
    Library *lib;  char *bookname; char * booktype; char *bookauthor; int numOfPages;

    if (!PyArg_ParseTuple(args, "lsssi", &lib, &bookname, &booktype, &bookauthor, &numOfPages)) {
        printf("Returning Null\n");
        return NULL;
    }

    return Py_BuildValue("i", CaddBook(lib, bookname, booktype, bookauthor, numOfPages));
}

static PyObject* searchForBookByName(PyObject* self, PyObject* args)
{
    Library *lib; char *bookname;

    if (!PyArg_ParseTuple(args, "O&s", &lib, &bookname))
        return NULL;

    return Py_BuildValue("s", CsearchForBookByName(lib, bookname));
}

static PyObject* searchForBookByAuthor(PyObject* self, PyObject* args)
{
    Library *lib; char *bookauthor;

    if (!PyArg_ParseTuple(args, "O&s", &lib, &bookauthor))
        return NULL;

    return Py_BuildValue("s", CsearchForBookByAuthor(lib, bookauthor));
}

static PyObject* version(PyObject* self)
{
    return Py_BuildValue("s", "Version 1.0");
}

static PyMethodDef myMethods[] = {
        {"addBook",               addBook,               METH_VARARGS, "This is adding a book to the library"},
        {"searchForBookByName",   searchForBookByName,   METH_VARARGS, "Returns whether book name is found or not."},
        {"searchForBookByAuthor", searchForBookByAuthor, METH_VARARGS, "Returns whether book is found or not based on author."},
        {"version", (PyCFunction)version, METH_NOARGS, "Returns the version."},
        { NULL, NULL, 0, NULL}
};

static struct PyModuleDef myModule = {
        PyModuleDef_HEAD_INIT,
        "library",
        "library Module",
        -1,
        myMethods
};

PyMODINIT_FUNC PyInit_library(void)
{
    Py_Initialize();
    return PyModule_Create(&myModule);
}
