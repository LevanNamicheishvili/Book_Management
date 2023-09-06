#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char title[100];
    char author[100];
    int isbn;
    int available;
};
struct Book library[MAX_BOOKS];
int numBooks = 0;

void addBook() {
    if (numBooks >= MAX_BOOKS) {
        printf("The library is full. Cannot add more books.\n");
        return;
    }
    struct Book newBook;
    printf("Enter the title of the book: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    printf("Enter the author of the book: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    printf("Enter the ISBN of the book: ");
    scanf("%d", &newBook.isbn);
    newBook.available = 1;

    library[numBooks++] = newBook;
    printf("Book added successfully!\n");
}
void displayBooks() {
    if (numBooks == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("Books in the library:\n");
    printf("-------------------------------\n");
    for (int i = 0; i < numBooks; i++) {
        printf("Title: %s", library[i].title);
        printf("Author: %s", library[i].author);
        printf("ISBN: %d\n", library[i].isbn);
        printf("Availability: %s\n", library[i].available ? "Available" : "Not Available");
        printf("-------------------------------\n");
    }
}
int searchBookByTitle(const char* title) {
    for (int i = 0; i < numBooks; i++) {
        if (strcmp(library[i].title, title) == 0) {
            return i;
        }
    }
    return -1;
}
void deleteBook() {
    char searchTitle[100];
    printf("Enter the title of the book to delete: ");
    fgets(searchTitle, sizeof(searchTitle), stdin);

    int bookIndex = searchBookByTitle(searchTitle);
    if (bookIndex == -1) {
        printf("Book not found.\n");
        return;
    }
    // Shift books to the left to cover the deleted book
    for (int i = bookIndex; i < numBooks - 1; i++) {
        library[i] = library[i + 1];
    }
    numBooks--;
    printf("Book deleted successfully!\n");
}
int main() {
    int choice;
    do {
        printf("===== Book Management =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Delete Book\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from the input buffer
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                deleteBook();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    } while (choice != 0);

    return 0;
}
