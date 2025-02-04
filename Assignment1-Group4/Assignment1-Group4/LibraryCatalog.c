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

}