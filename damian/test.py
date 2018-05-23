from ctypes import *

import library

print(library.version())

class CBook(Structure):
    _fields_= [("book_name", c_wchar_p),
              ("book_type", c_wchar_p),
              ("book_author", c_wchar_p),
              ("num_of_pages", c_int)]

class CLibrary(Structure):
    _fields_= [("book_list", CBook * 100),
               ("books_stored", c_int)]

new_book = CBook("Harry Potter", "Children", "JK Rowling", 345)

print (new_book.book_name)

lib = CLibrary(books_stored=0)

print(lib)

print("Books stored in lib = %d" % lib.books_stored)



result = c_int()
result = library.addBook(addressof(lib), "Harry Aotter", "Ahildren", "JK Rowling", 345)
result = library.addBook(addressof(lib), "Harry Botter", "Bhildren", "JK Rowling", 345)
result = library.addBook(addressof(lib), "Harry Cotter", "Children", "JK Rowling", 345)
result = library.addBook(addressof(lib), "Harry Dotter", "Dhildren", "JK Rowling", 345)
result = library.addBook(addressof(lib), "Harry Eotter", "Ehildren", "JK Rowling", 345)
result = library.addBook(addressof(lib), "Harry Fotter", "Fhildren", "JK Rowling", 345)
result = library.addBook(addressof(lib), "Harry Gotter", "Ghildren", "JK Rowling", 345)
result = library.addBook(addressof(lib), "Harry Hotter", "Hhildren", "JK Rowling", 345)

print("I am here")
result = library.addBook(addressof(lib), "Lost", "Adult", "Damian ", 111)

print(result)
print("Done")

for i in range(lib.books_stored):
    print(
        lib.book_list[i].book_name,
        lib.book_list[i].book_type,
        lib.book_list[i].book_author,
        lib.book_list[i].num_of_pages
    )


