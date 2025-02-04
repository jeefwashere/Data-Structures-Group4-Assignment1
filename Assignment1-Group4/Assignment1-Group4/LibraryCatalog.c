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
//void viewBooks(Book* head);
//void updateBook(Book* head, int id);
//void deleteBook(Book** head, int id);
//void searchBooks(Book* head, const char* title);

// List of pointers:
// Book* head --> head node (beginning)
// Book* current --> current node
// Book* next --> next node
// Book* tail --> tail node (end)
// Book* newBook --> new book node

int main(void) 
{
	Book* head = NULL; // head node is set to NULL (must)
	Book* tail = NULL; // tail node is set to NULL (must)

	return 0;
}

//
// FUNCTION : addBook()
// DESCRIPTION :
// This function will add a new book to the linked list. As well as to check if the book id already exists.
// PARAMETERS : 
// Book** head - pointer pointing to the head of the linked list
// int id - the id of the book
// const char* title - the title of the book
// const char* author - the author of the book
// int publication_year - the publication year of the book
// RETURNS : n/a (void)
//
void addBook(Book** head, int id, const char* title, const char* author, int publication_year) 
{
	// this will be to identify the current book in the linked list making sure it has a value
	Book* current = *head; // current points to the head of the linked list (the first book in the list)

	// iterate through the linked list to check if the book id already exists
	while (current != NULL)
	{
		if (current->id == id) // if the current book id is equal to the id passed in (passed in = the value that is passed into the function)
		{
			printf("Book ID of %d, exist arleady. \n", id); // print out that the book with the id already exists
			return; 
		}
	}

	// Book pointer to newBook, malloc is used to allocate memory for the new book to the heap
	Book* newBook = (Book*)malloc(sizeof(Book));

	// the book details
	newBook->id = id; // the newBook id is set to id which is passed in.
	strcpy(newBook->title, title); // the newBook title is set to title which is passed in.
	strcpy(newBook->author, author); // the newBook author is set to author which is passed in.
	newBook->publication_year = publication_year; // the newBook publication_year is set to publication_year which is passed in.
	newBook->next = NULL; // the newBook next is set to NULL

	// this sends the new book to the end of the linked list*
	// checks if next book HEAD NODE is NULL
	if (*head == NULL)
	{
		*head = newBook; // then the head node is set to the newBook
	}
	else // if the next book HEAD NODE is not NULL
	{
		while (current->next != NULL)
		{
			current = current->next; // then the current (data) is set to the next book
		}
		current->next = newBook; // the current next is set to the newBook
	}
}

//
// FUNCTION : viewBooks()
// DESCRIPTION :
// PARAMETERS : 
// RETURNS :
//
void viewBooks(Book* head) 
{

}

//
// FUNCTION :  updateBook()
// DESCRIPTION :
// PARAMETERS : 
// RETURNS :
//
void updateBook(Book* head, int id) 
{

}

//
// FUNCTION : deleteBook()
// DESCRIPTION :
// PARAMETERS : 
// RETURNS :
//
void deleteBook(Book** head, int id) 
{

}

//
// FUNCTION : searchBooks()
// DESCRIPTION :
// PARAMETERS : 
// RETURNS :
//
void searchBooks(Book* head, const char* title) 
{

}