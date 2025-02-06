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
	int newPublicationYear = 0;
	char newBookTitle[100];
	char newAuthor[100];
	char yearInput[100];
	char idInput[100];
	bool done = false;
	bool yearCheck = false;

	while (!done) {

		printf("\nPlease enter a book ID: ");
		fgets(idInput, sizeof(idInput), stdin);

		if (!sscanf_s(idInput, "%d", &chosenId)) {

			printf("\nEnter a valid number.\n");
			continue;
		}

		if (chosenId < 0) {

			printf("Please enter a valid ID.\n");
			while (getchar() != '\n'); // clear buffer
			continue;
		}

		Book* current = head;
		while (current != NULL) {

			if (current->id == chosenId) {

				printf("Enter new book title: ");
				fgets(newBookTitle, sizeof(newBookTitle), stdin);
				printf("\nEnter new author: ");

				fgets(newAuthor, sizeof(newAuthor), stdin);
				printf("\nEnter new publication year: ");

				while (!yearCheck) {
					fgets(yearInput, sizeof(yearInput), stdin);

					if (!sscanf_s(yearInput, "%d", &newPublicationYear)) {

						if (newPublicationYear < 0 || newPublicationYear > 2025) {

							printf("Enter a valid year (0-2025): ");
							while (getchar() != '\n'); // clear buffer
							continue;
						}
					}

					yearCheck = true;
				}

				strcpy_s(current->title, sizeof(current->title), newBookTitle);
				strcpy_s(current->author, sizeof(current->author), newAuthor);
				current->publication_year = newPublicationYear;
				break;
			}


			current = current->next;
		}

		printf("ID does not exist.\n");
		done = true;
	}
}

void deleteBook(Book** head, int id) {

}

void searchBooks(Book* head, const char* title) {

}