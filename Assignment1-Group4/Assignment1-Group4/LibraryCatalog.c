#include <stdio.h>

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
void searchBooks(Book* head, const char* title);

int main(void) {

	Book* head = NULL;

	return 0;
}

void addBook(Book** head, int id, const char* title, const char* author, int publication_year) {

}

void viewBooks(Book* head) {

}

void updateBook(Book* head, int id) {

	system("cls");

	int chosenId = 0;
	int newPublicationYear = 0;
	char newBookTitle[100];
	char newAuthor[100];
	bool done = true;

	do {

		printf("Please enter a book ID: ");
		scanf_s("%d", &chosenId, sizeof(int));

		if (chosenId < 0) {

			printf("Please enter a valid ID.\n");
			done = false;
			continue;
		}

		

		done = true;
	} while (!done);
}

void deleteBook(Book** head, int id) {

}

void searchBooks(Book* head, const char* title) {

}