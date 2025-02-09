#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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
	int id = 0;

	addBook(&head, 3, "Book 1", "Jeff Tieng", 2004);
	addBook(&head, 001, "Book 2", "MJ", 2005);
	updateBook(head, id);

	return 0;
}

void addBook(Book** head, int id, const char* title, const char* author, int publication_year) {

}

void viewBooks(Book* head) {

}

void updateBook(Book* head, int id) {

	if (head == NULL) {

		printf("The list is empty!\n");
		return;
	}

	int chosenId = 0;
	int menuChoice = 0;
	int updatedYear = 0;
	char updatedBookTitle[100];
	char updatedAuthor[100];

	printf("\nPlease enter a book ID: ");
	while (scanf_s("%d", &chosenId) != 1 || chosenId < 0) {

		printf("\nEnter a valid number.\n");
	}

	while (getchar() != '\n');

	Book* current = head;
	while (current != NULL) {

		if (current->id == chosenId) {

			printf("--------------------------------------------------------------------------------------\n");
			printf("Current Book Details:\n");
			printf("Book title: %s\n", current->title);
			printf("Book author: %s\n", current->author);
			printf("Book publication year: %d\n", current->publication_year);
			printf("--------------------------------------------------------------------------------------\n");
			printf("Updating Book ID: %d\n", chosenId);

			printf("Enter new book title: ");
			if (fgets(updatedBookTitle, sizeof(updatedBookTitle), stdin) != NULL) {

				updatedBookTitle[strcspn(updatedBookTitle, "\n")] = '\0';
			}

			printf("Enter new author: ");
			if (fgets(updatedAuthor, sizeof(updatedAuthor), stdin) != NULL) {

				updatedAuthor[strcspn(updatedAuthor, "\n")] = '\0';
			}

			printf("Enter new publication year: ");
			while (scanf_s("%d", &updatedYear) != 1 || updatedYear < 0 || updatedYear > 2025) {

				printf("Invalid Year!\n");
				while (getchar() != '\n');
			}
			while (getchar() != '\n');

			strcpy_s(current->title, sizeof(current->title), updatedBookTitle);
			strcpy_s(current->author, sizeof(current->author), updatedAuthor);
			current->publication_year = updatedYear;
			

			printf("\nBook ID: %d details updated successfully!\n", chosenId);
			return;
		}
		current = current->next;
	}
	printf("Book ID: %d does not exist.\n", chosenId);
}

void deleteBook(Book** head, int id) {

}

void searchBooks(Book* head, const char* title) {

}