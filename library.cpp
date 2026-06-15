#include <iostream>
#include <string>
using namespace std;


class LibraryItem {
protected:
    string title, author, dueDate;

public:
    LibraryItem(string t, string a, string d) {
        title = t;
        author = a;
        dueDate = d;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;


};


class Book : public LibraryItem {
public:
    Book(string t, string a, string d) : LibraryItem(t, a, d) {}

    void checkOut() {
        cout << "Book checked out successfully."<< endl;
    }

    void returnItem() {
        cout << "Book returned successfully."<< endl;
    }

    void displayDetails() {
        cout << endl<< "--- Book Details ---"<< endl;
        cout << "Title     : " << title << endl;
        cout << "Author    : " << author << endl;
        cout << "Due Date  : " << dueDate << endl;
    }
};


class DVD : public LibraryItem {
public:
    DVD(string t, string a, string d) : LibraryItem(t, a, d) {}

    void checkOut() {
        cout << "DVD checked out successfully."<< endl;
    }

    void returnItem() {
        cout << "DVD returned successfully."<< endl;
    }

    void displayDetails() {
        cout << endl << "--- DVD Details ---"<< endl;
        cout << "Title     : " << title << endl;
        cout << "Author    : " << author << endl;
        cout << "Due Date  : " << dueDate << endl;
    }
};

int main() {
    int choice;
    LibraryItem* item = NULL;
    string title, author, dueDate;

    do {
        cout << "--- Library Menu ---"<< endl;
        cout << "1. Add Book"<< endl;
        cout << "2. Add DVD"<< endl;
        cout << "3. Display Item"<< endl;
        cout << "4. Check Out"<< endl;
        cout << "5. Return Item"<< endl;
        cout << "0. Exit"<< endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cin.ignore();
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Author Name: ";
            getline(cin, author);
            cout << "Enter Due Date: ";
            getline(cin, dueDate);

            item = new Book(title, author, dueDate);
            cout << "Book Added Successfully"<< endl;
            break;

        case 2:
            cin.ignore();
            cout << "Enter DVD Title: ";
            getline(cin, title);
            cout << "Enter Author Name: ";
            getline(cin, author);
            cout << "Enter Due Date: ";
            getline(cin, dueDate);

            item = new DVD(title, author, dueDate);
            cout << "DVD Added Successfully"<< endl;
            break;

        case 3:
            if (item)
                item->displayDetails();
            else
                cout << "No item available"<< endl;
            break;

        case 4:
            if (item)
                item->checkOut();
            else
                cout << "No item available"<< endl;
            break;

        case 5:
            if (item)
                item->returnItem();
            else
                cout << "No item available"<< endl;
            break;

        case 0:
            cout << "Thank you!"<< endl;
            break;

        default:
            cout << "Invalid Choice!"<< endl;
        }

    } while (choice != 0);


}