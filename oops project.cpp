#include <iostream>
using namespace std;

class User {
protected:
    string username = "student";
    string password = "1234";

public:
    bool login(string u, string p) {
        return (u == username && p == password);
    }
};


class Student {
public:
    string name;
    int age;
    string department;
    string email;
    string phone;

    void fillForm() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();

        cout << "Enter Department: ";
        getline(cin, department);

        cout << "Enter Email: ";
        getline(cin, email);

        cout << "Enter Phone: ";
        getline(cin, phone);

        cout << "\nForm Submitted Successfully!\n";
    }

    void display() {
        cout << "\nName: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Department: " << department << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
    }
};

class Admin {
private:
    string adminCode = "admin123";

public:
    bool checkCode(string code) {
        return (code == adminCode);
    }

    void showAll(Student students[], int count) {
        cout << "\n--- All Applications ---\n";
        if (count == 0) {
            cout << "No applications submitted.\n";
            return;
        }

        for (int i = 0; i < count; i++) {
            students[i].display();
            cout << "-------------------------\n";
        }
    }

    void searchStudent(Student students[], int count, string searchName) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (students[i].name == searchName) {
                cout << "\n--- Student Found ---\n";
                students[i].display();
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Student not found.\n";
        }
    }
};

int main() {
    User user;
    Admin admin;
    Student students[10];
    int studentCount = 0;

    int choice;
    string u, p;

    cout << "=== Student Admission System ===\n";
    cout << "1. Login\n2. Exit\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        cout << "\nEnter Username: ";
        cin >> u;
        cout << "Enter Password: ";
        cin >> p;

        if (user.login(u, p)) {
            cout << "\nLogin Successful!\n";

            students[studentCount].fillForm();
            studentCount++;

            char adminAsk;
            cout << "\nGo to Admin Panel? (Y/N): ";
            cin >> adminAsk;

            if (adminAsk == 'Y' || adminAsk == 'y') {
                string code;
                cout << "Enter Admin Code: ";
                cin >> code;

                if (admin.checkCode(code)) {
                    int adminChoice;

                    do {
                        cout << "\n--- Admin Panel ---\n";
                        cout << "1. View All Applications\n";
                        cout << "2. Search Student\n";
                        cout << "3. Exit\n";
                        cout << "Enter choice: ";
                        cin >> adminChoice;

                        if (adminChoice == 1) {
                            admin.showAll(students, studentCount);
                        } else if (adminChoice == 2) {
                            string searchName;
                            cout << "Enter name to search: ";
                            cin.ignore();
                            getline(cin, searchName);
                            admin.searchStudent(students, studentCount, searchName);
                        }

                    } while (adminChoice != 3);
                } else {
                    cout << "Wrong admin code!\n";
                }
            }

        } else {
            cout << "Invalid username or password.\n";
        }

    } else {
        cout << "Goodbye!\n";
    }

    return 0;
}