/*
* FILE : LibraryCatalog.c
* PROJECT : Singly Linked List Implementation
* PROGRAMMER : Jeff, Cy, Johnson, Ryan
* FIRST VERSION: 2/3/2025
* DESCRIPTION :
* DON'T FORGET...
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Book
{
	int id;
	char title[100];
	char author[100];
	int publication_year;
	struct Book* next;
} Book;

// List of prototypes
void menuList();
void addBook(Book** head, int id, const char* title, const char* author, int publication_year);
void viewBooks(Book* head);
void updateBook(Book* head, int id);
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
	Book* head = NULL; // Head node is set to NULL **here for now**
	Book* tail = NULL; // Tail node is set to NULL **here for now**

	// Variables for do-switch statement
	int userChoice;

	// Do switch statement for the menu
	while (true)
	{
		menuList();
		printf("Enter your choice: ");

		// check if the user input is valid
		if (scanf_s("%d", &userChoice) != 1)
		{
			printf("Invalid choice, please user numbers (1 - 6) \n");
			while (getchar() != '\n'); // clear buffer
			continue;
		}

		switch (userChoice)
    {
			case 1:
			{
				int id;
				char title[100];
				char author[100];
				int publication_year;

				// check if the id is valid
				bool validId = false;
				while (!validId) // while the value of id is not valid
				{
					printf("Enter the book ID: ");
					if (scanf_s("%d", &id) != 1)
					{
						printf("Invalid input, please enter a number. \n");
						while (getchar() != '\n');
					}
					else
					{
						validId = true;
					}
				}
				while (getchar != '\n');
				
				// check if the title is valid
				while (true)
				{
					printf("Enter the book title: ");
					if (fgets(title, sizeof(title), stdin) != NULL)
					{
						title[strcspn(title, "\n")] = 0;
						if (strlen(title) == 0)
						{
							printf("Invalid input, please enter a title. \n");
						}
						else
						{
							break;
						}
					}
				}

				// check if the author is valid
				while (true)
				{
					printf("Enter the book author: ");
					if (fgets(author, sizeof(author), stdin) != NULL)
					{
						author[strcspn(author, "\n")] = 0;
						if (strlen(author) == 0)
						{
							printf("Invalid input, please enter an author. \n");
						}
						else
						{
							break;
						}
					}
				}
				
				// check if the publication year is valid
				bool validYear = false;
				while (!validYear)
				{
					printf("Enter publication year (0 - 2025): ");
					if (scanf_s("%d", &publication_year) != 0 || publication_year < 0 || publication_year > 2025)
					{
						printf("Invalid input, please enter a number between 0 and 2025. \n");
						while (getchar() != '\n');
					}
					else
					{
						validYear = true;	
					}
					while (getchar() != '\n');
				}

				addBook(&head, id, title, author, publication_year);
				break;
			}
			case 2:
			{
				// viewBooks
			}
			case 3:
			{
				// updateBook
			}
			case 4:
			{
				// deleteBook
			}
			case 5:
			{
				// searchBooks
			}
			case 6:
			{
				// exit
				return 0;
			}
			default:
			{
				printf("Invalid choice, please use numbers (1 - 6) \n");
				break;
			}

		}
		return 0;
	}
}

//
// FUNCTION : addBook()
// 
// DESCRIPTION :
// This function is used to display the menu options available to the user.
// 
// PARAMETERS : n/a
//
void menuList()
{
	printf("1. Add a book \n");
	printf("2. View all books \n");
	printf("3. Update a book \n");
	printf("4. Delete a book \n");
	printf("5. Search for a book \n");
	printf("6. Exit \n");
}

//
// FUNCTION : addBook()
// 
// DESCRIPTION :
// This function will add a new book to the linked list. As well as to check if the book id already exists.
// 
// PARAMETERS : 
// Book** head			: pointer pointing to the head of the linked list
// int id				: the id of the book
// const char* title	: the title of the book
// const char* author	: the author of the book
// int publication_year : the publication year of the book
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

		current = current->next; // current is set to the next book
	}

	// Book pointer to newBook, malloc is used to allocate memory for the new book to the heap
	Book* newBook = (Book*)malloc(sizeof(Book));
	// check if the newBook is NULL (in other words, to see newBook exists or not in the heap)
	if (newBook == NULL) // if the newBook is NULL
	{
		printf("Failed to allocate memory. \n"); // print out that the memory allocation failed
		return;
	}

	// the book details
	newBook->id = id; // the newBook id is set to id which is passed in.
	strcpy_s(newBook->title, sizeof(newBook->title), title); // the newBook title is set to title which is passed in.
	strcpy_s(newBook->author, sizeof(newBook->author), author); // the newBook author is set to author which is passed in.
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
		Book* tail = *head; // tail is set to the head node
		{
			tail = tail->next; // tail is set to the next book
		}
		tail->next = newBook; // the tail next is set to the newBook
	}
}

//
// FUNCTION : viewBooks()
// 
// DESCRIPTION : 
// This function is used to view the book details present within the list
// 
// PARAMETERS :	
// Book* head	: Used as a pointer to the head node of the list
// int count	: Used as a counter for book number
//
void viewBooks(Book* head)
{
	int count = 0; // Counter declaration

	if (head == NULL) { // Checks if the list is empty

		printf("The list is empty!\n");
		return; // Exits function if so
	}

	Book* current = head; // Iterator declaration with initial value being the pointer to the head
	while (current != NULL) { // While loop for looping through the list. Checks if current is null by setting current to the next node's address after every iteration.

		count++; // Counter for book number
		printf("--------------------------------------------------------------------------------------\n"); // Print statements for book details
		printf("Book %d\n", count);
		printf("ID: %d\n", current->id);
		printf("Title: %s\n", current->title);
		printf("Author: %s\n", current->author);
		printf("Publication Year: %d\n", current->publication_year);

		if (current->next == NULL) { // Checks if the next node is null

			return; // Exits function if so
		}

		current = current->next; // Sets current to the address of the next node
	}
}

//
// FUNCTION :  updateBook()
// 
// DESCRIPTION :
// This function is used to update the details of a book. The chosen book to be updated is selected by the user providing the matching book ID.
// 
// PARAMETERS : 
// Book* head					: Used as a pointer to the head node of the list
// int id						: Struct variable for book ID
// int chosenId					: The user-selected book ID
// int updatedYear				: The user-selected book's new publication year
// char updatedBookTitle[100]	: New title for the user-selected book
// char updatedAuthor[100]		: New author for the user-selected author
//
void updateBook(Book* head, int id)
{

	if (head == NULL) { // Checks if list is empty

		printf("The list is empty!\n");
		return; // Exits function if so
	}

	// Local Parameters
	int chosenId = 0; // User-selected ID variable declaration
	int updatedYear = 0; // New book ID variable declaration
	char updatedBookTitle[100]; // New book title variable declaration
	char updatedAuthor[100]; // New book author variable declaration

	printf("\nPlease enter a book chosenID: ");
	while (scanf_s("%d", &chosenId) != 1 || chosenId < 0) { // User-selected book ID user input. Checks if input was valid.

		printf("\nEnter a valid number.\n"); // Error statement if input was invalid
	}

	while (getchar() != '\n'); // Clears newline character from input buffer

	Book* current = head; // Iterator declaration. Address of head is set as the initial value
	while (current != NULL) { // Loop for iterating through list

		if (current->id == chosenId) { // Checks if book ID in list matches to user-selected book ID

			printf("--------------------------------------------------------------------------------------\n"); // Print statements for book details
			printf("Current Book Details:\n");
			printf("Book ID: %d\n", current->id);
			printf("Book title: %s\n", current->title);
			printf("Book author: %s\n", current->author);
			printf("Book publication year: %d\n", current->publication_year);
			printf("--------------------------------------------------------------------------------------\n");
			printf("Updating Book ID: %d\n", current->id);

			printf("Enter new book title: ");
			if (fgets(updatedBookTitle, sizeof(updatedBookTitle), stdin) != NULL) { // User input for updating the book's title

				updatedBookTitle[strcspn(updatedBookTitle, "\n")] = '\0'; // Eliminates newline character from the new book title
			}

			printf("Enter new author: ");
			if (fgets(updatedAuthor, sizeof(updatedAuthor), stdin) != NULL) { // User-input for updating the book's author

				updatedAuthor[strcspn(updatedAuthor, "\n")] = '\0'; // Eliminates newline character from the new book title
			}

			printf("Enter new publication year: ");
			while (scanf_s("%d", &updatedYear) != 1 || updatedYear < 0 || updatedYear > 2025) { // User-input for updating book's publication year. Checks if book's new year is valid.

				printf("Invalid Year!\n"); // Error statement if inputted year was invalid
				while (getchar() != '\n'); // Eliminates newline character from input buffer
			}
			while (getchar() != '\n'); // Eliminates newline character from input buffer

			strcpy_s(current->title, sizeof(current->title), updatedBookTitle); // Replaces the matching book's title with the user-updated title
			strcpy_s(current->author, sizeof(current->author), updatedAuthor); // Replaces the matching book's author with the user-updated author
			current->publication_year = updatedYear; // Sets value of matching book's year to the user-updated year


			printf("\nBook ID: %d details updated successfully!\n", chosenId); // Confirmation statement
			return; // Exits function if successful
		}
		current = current->next; // Sets iterator's address to the address of the next node
	}
	printf("Book ID: %d does not exist.\n", chosenId); // Error statement if no matching ID was found in the list
}

//
// FUNCTION : deleteBook()
// DESCRIPTION :
// PARAMETERS : 
//
void deleteBook(Book** head, int id)
{

}

//
// FUNCTION : searchBooks()
// DESCRIPTION :
// PARAMETERS : 
//
void searchBooks(Book* head, const char* title)
{
	// Check if empty
	if (head == NULL) {
		printf("Empty! No books found!");
		return;
	}

	// prompt user for title or partial title to search
	char searchBookTitle[100];
	printf("Please enter a book title (or partial title) to search for: ");
	fgets(searchBookTitle, sizeof(searchBookTitle), stdin); // read user input
	searchBookTitle[strcspn(searchBookTitle, "\n")] = 0; // Remove new line character

	Book* current = head; // Traverse the linkedlist with pointer
	int found = 0; // Help check if a book is found

	// Copy title (will be used for case-insensitive)
	char searchTitleLow[100];
	if (strcpy_s(searchTitleLow, sizeof(searchTitleLow), searchBookTitle) != 0) {
		printf("Error copying title!"); // if copying fails
		return;
	}
	// Case-insensitive --> convert book title to lower case
	for (int i = 0; searchBookTitle[i]; i++) {
		searchBookTitle[i] = tolower(searchBookTitle[i]); // convert to lower case
	}

	// Traverse linked list of books
	while (current != NULL) {
		char currentBookTitle[100];
		// copy current book title for lower case
		if (strcpy_s(currentBookTitle, sizeof(currentBookTitle), current->title) != 0) {
			printf("Error copying title!"); // if copying fails
			return;
		}
		// Case-insensitive --> convert current book title to lower case
		for (int i = 0; currentBookTitle[i]; i++) {
			currentBookTitle[i] = tolower(currentBookTitle[i]); // convert to lower cse
		}
		// Check if book contains search strng
		if (strstr(currentBookTitle, searchBookTitle) != 0) {
			printf("Book ID: %d\n", current->id); // book id
			printf("Book Title: %s\n", current->title); // book title
			printf("Book Author: %s\n", current->author); // book author
			printf("Book Publicaiton Year: %d\n", current->publication_year); // published 
		}
		current = current->next; // next book
	}

	// if no book is found print message
	if (!found) {
		printf("No books found for title: '%s\n'", title);
	}
}