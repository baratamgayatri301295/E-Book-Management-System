# E-Book-Management-System
Creating an eBook management system in C++ can be a comprehensive project where users can manage their eBooks. This can include functionalities like adding new books, viewing book details, searching for a book by title or author, and removing books from the collection. Below is a simple structure for such a system.

Key Features:
Add Book: Add a new eBook to the system.
View All Books: Display all the books in the system.
Search Book: Search for a book by title or author.
Remove Book: Remove a book from the system.
Edit Book Information: Update the details of a book.
Save and Load from File: Persist the collection by saving/loading to/from a file.
Structure:
Classes:
Book: Holds book information like title, author, ISBN, etc.
EbookManagementSystem: Manages the collection of books and provides functionalities like adding, viewing, searching, etc.
Explanation:
Book Class:
It holds the details of each book like title, author, ISBN, and year.
It provides methods to access these properties and display book details.
EbookManagementSystem Class:
Manages a collection of Book objects using a vector.
Provides methods for adding, viewing, searching, removing books, and also for saving/loading from a file.
File Operations:
The saveToFile() method saves all books to a file in CSV format.
The loadFromFile() method reads books from a file and adds them to the collection.
