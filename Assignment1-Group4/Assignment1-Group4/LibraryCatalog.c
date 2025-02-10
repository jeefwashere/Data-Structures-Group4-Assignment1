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
	Book* head = NULL; // head node is set to NULL **here for now**
 	Book* tail = NULL; // tail node is set to NULL **here for now**

	// variables for do-switch statement
	int userChoice;

	// do switch statement for the menu
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
	}

	return 0;
}

//
// FUNCTION : addBook()
// DESCRIPTION :
// just to list the menu options
// PARAMETERS : n/a
// RETURNS : n/a (void)
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
		else if (current->author == author) // if the current book author is equal to the author passed in (passed in = the value that is passed into the function)
		{
			printf("Book author of %s, exist arleady. \n", author); // print out that the book with the author already exists
			return;
		}
		else if (current->title == title) // if the current book title is equal to the title passed in (passed in = the value that is passed into the function)
		{
			printf("Book title of %s, exist arleady. \n", title); // print out that the book with the title already exists
			return;
		}
		else if (current->publication_year == publication_year) // if the current book publication year is equal to the publication year passed in (passed in = the value that is passed into the function)
		{
			printf("Book publication year of %d, exist arleady. \n", publication_year); // print out that the book with the publication year already exists
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