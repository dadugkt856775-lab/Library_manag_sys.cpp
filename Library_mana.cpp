#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool issued;

    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        issued = false;
    }
};

int main() {
    vector<Book> books;
    map<int, string> borrowers;

    books.emplace_back(101, "C++", "Bjarne");
    books.emplace_back(102, "DSA", "Mark");
    books.emplace_back(103, "Python", "Guido");

    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT =====\n";
        cout << "1. Display Books\n";
        cout << "2. Search Book\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Display Issued Books\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            for (const auto &b : books) {
                cout << b.id << " | " << b.title
                     << " | " << b.author << " | "
                     << (b.issued ? "Issued" : "Available")
                     << endl;
            }
        }
        else if (choice == 2) {
            int id;
            cout << "Enter book ID: ";
            cin >> id;

            auto it = find_if(books.begin(), books.end(),
                [id](const Book &b) {
                    return b.id == id;
                });

            if (it != books.end()) {
                cout << "Book: " << it->title << endl;
                cout << "Author: " << it->author << endl;
                cout << "Status: "
                     << (it->issued ? "Issued" : "Available")
                     << endl;
            } else {
                cout << "Book not found.\n";
            }
        }
        else if (choice == 3) {
            int id;
            string student;

            cout << "Enter book ID: ";
            cin >> id;
            cout << "Enter student name: ";
            cin >> student;

            auto it = find_if(books.begin(), books.end(),
                [id](const Book &b) {
                    return b.id == id;
                });

            if (it == books.end()) {
                cout << "Book not found.\n";
            }
            else if (it->issued) {
                cout << "Book is already issued.\n";
            }
            else {
                it->issued = true;
                borrowers[id] = student;
                cout << "Book issued successfully.\n";
            }
        }
        else if (choice == 4) {
            int id;
            cout << "Enter book ID: ";
            cin >> id;

            auto it = find_if(books.begin(), books.end(),
                [id](const Book &b) {
                    return b.id == id;
                });

            if (it == books.end()) {
                cout << "Book not found.\n";
            }
            else if (!it->issued) {
                cout << "Book is not currently issued.\n";
            }
            else {
                it->issued = false;
                borrowers.erase(id);
                cout << "Book returned successfully.\n";
            }
        }
        else if (choice == 5) {
            for (const auto &entry : borrowers) {
                cout << "Book ID: " << entry.first
                     << " | Student: " << entry.second << endl;
            }

            if (borrowers.empty())
                cout << "No books are currently issued.\n";
        }

    } while (choice != 6);

    return 0;
}
