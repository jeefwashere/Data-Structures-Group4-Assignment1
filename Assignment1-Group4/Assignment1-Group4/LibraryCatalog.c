/*
* FILE : LibraryCatalog.c
* PROJECT : Singly Linked List Implementation
* PROGRAMMER : Jeff, Cy, Johnson, Ryan
* FIRST VERSION: 2/3/2025
* DESCRIPTION :
* DON'T FORGET...
*/

#include <stdio.h>

typedef struct Book 
{
	int id;
	char title[100];
	char author[100];
	int publication_year;
	struct Book* next;
} Book;

// List of prototypes
void addBook(Book** head, int id, const char* title, const char* author, int publication_year);
void viewBooks(Book* head);
void updateBook(Book* head, int id);
void deleteBook(Book** head, int id);
void searchBooks(Book* head, const char* title);

int main(void) 
{
	return 0;
}

//
// FUNCTION :
// DESCRIPTION :
// PARAMETERS : 
// RETURNS :
//
void addBook(Book** head, int id, const char* title, const char* author, int publication_year) 
{

}

//
// FUNCTION : 
// DESCRIPTION :
// PARAMETERS : 
// RETURNS :
//
void viewBooks(Book* head) 
{

}

//
// FUNCTION : 
// DESCRIPTION :
// PARAMETERS : 
// RETURNS :
//
void updateBook(Book* head, int id) 
{

}

//
// FUNCTION : 
// DESCRIPTION :
// PARAMETERS : 
// RETURNS :
//
void deleteBook(Book** head, int id) 
{

}

//
// FUNCTION : 
// DESCRIPTION :
// PARAMETERS : 
// RETURNS :
//
void searchBooks(Book* head, const char* title) 
{

}