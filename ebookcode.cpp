#include<bits/stdc++.h>
#include <iostream>

#include <vector>
#include <fstream>
#include <string>

using namespace std;

// Book class to represent an eBook
class Book {
private:
    string title;
    string author;
    string isbn;
    int year;

public:
    // Constructor
    Book(string t, string a, string i, int y) : title(t), author(a), isbn(i), year(y) {}

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }
    int getYear() const { return year; }

    // Display book details
    void displayBook() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Year: " << year << endl;
    }
};

// Ebook Management System class to manage the eBooks
class EbookManagementSystem {
private:
    vector<Book> books;

    // Helper method to find a book by title
    int findBookByTitle(const string& title) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].getTitle() == title) {
                return i;
            }
        }
        return -1;
    }

public:
    // Add a new book to the collection
    void addBook(const Book& book) {
        books.push_back(book);
        cout << "Book added successfully!\n";
    }

    // View all books in the system
    void viewBooks() const {
        if (books.empty()) {
            cout << "No books in the system.\n";
            return;
        }
        for (const auto& book : books) {
            book.displayBook();
            cout << "---------------------------\n";
        }
    }

    // Search for a book by title
    void searchBook(const string& title) {
        int index = findBookByTitle(title);
        if (index != -1) {
            books[index].displayBook();
        } else {
            cout << "Book not found.\n";
        }
    }

    // Remove a book by title
    void removeBook(const string& title) {
        int index = findBookByTitle(title);
        if (index != -1) {
            books.erase(books.begin() + index);
            cout << "Book removed successfully!\n";
        } else {
            cout << "Book not found.\n";
        }
    }

    // Save books to a file
    void saveToFile(const string& filename) const {
        ofstream outFile(filename);
        for (const auto& book : books) {
            outFile << book.getTitle() << "," << book.getAuthor() << "," 
                    << book.getISBN() << "," << book.getYear() << "\n";
        }
        outFile.close();
        cout << "Books saved to " << filename << "\n";
    }

    // Load books from a file
    void loadFromFile(const string& filename) {
        ifstream inFile(filename);
        if (!inFile) {
            cout << "File not found.\n";
            return;
        }

        string title, author, isbn;
        int year;
        while (getline(inFile, title, ',') && getline(inFile, author, ',') 
               && getline(inFile, isbn, ',') && (inFile >> year)) {
            inFile.ignore();  // Ignore the newline after the year
            books.push_back(Book(title, author, isbn, year));
        }
        inFile.close();
        cout << "Books loaded from " << filename << "\n";
    }
};

// Main function
int main() {
    EbookManagementSystem system;
    int choice;
    string title, author, isbn;
    int year;

    do {
        cout << "\n1. Add Book\n2. View Books\n3. Search Book\n4. Remove Book\n5. Save Books\n6. Load Books\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter ISBN: ";
                getline(cin, isbn);
                cout << "Enter year: ";
                cin >> year;
                system.addBook(Book(title, author, isbn, year));
                break;

            case 2:
                system.viewBooks();
                break;

            case 3:
                cout << "Enter title to search: ";
                getline(cin, title);
                system.searchBook(title);
                break;

            case 4:
                cout << "Enter title to remove: ";
                getline(cin, title);
                system.removeBook(title);
                break;

            case 5:
                system.saveToFile("books.txt");
                break;

            case 6:
                system.loadFromFile("books.txt");
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 0);

    return 0;
}