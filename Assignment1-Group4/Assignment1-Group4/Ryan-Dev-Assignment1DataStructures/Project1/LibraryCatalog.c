#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct Book {

	int id;
	char title[100];
	char author[100];
	int publication_year;
	struct Book* next;
} Book;

void addBook(Book** head, int id, const char* title, const char* author, int publication_year);
void viewBooks(Book* head);
void updateBook(Book* head, int id);
void deleteBook(Book** head, int id);
void searchBooks(Book* head, const char* title); // Ryan

int main(void) {

	return 0;
}

void addBook(Book** head, int id, const char* title, const char* author, int publication_year) {

}

void viewBooks(Book* head) {

}

void updateBook(Book* head, int id) {

}

void deleteBook(Book** head, int id) {

}

void searchBooks(Book* head, const char* title) {
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