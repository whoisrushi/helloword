#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Student {
    int id;
    char name[50];
    float cgpa;
};

void addStudent(Student*& students, int& size) {
    students = (Student*)realloc(students, (size + 1) * sizeof(Student));
    if (students == NULL) {
        cout << "Memory allocation failed!" << endl;
        exit(1);
    }
    cout << "Enter Student ID: ";
    cin >> students[size].id;
    cout << "Enter Student Name: ";
    cin.ignore();
    cin.getline(students[size].name, 50);
    cout << "Enter Student CGPA: ";
    cin >> students[size].cgpa;
    size++;
}

void displayStudent(Student s) {
    cout << "ID: " << s.id << ", Name: " << s.name << ", CGPA: " << s.cgpa << endl;
}

void linearSearch(Student* students, int size, int searchID) {
    for (int i = 0; i < size; i++) {
        if (students[i].id == searchID) {
            cout << "Student Found (Linear Search): ";
            displayStudent(students[i]);
            return;
        }
    }
    cout << "Student not found (Linear Search)." << endl;
}

int compareByID(const void* a, const void* b) {
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;
    return s1->id - s2->id;
}

void binarySearch(Student* students, int size, int searchID) {
    qsort(students, size, sizeof(Student), compareByID);
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (students[mid].id == searchID) {
            cout << "Student Found (Binary Search): ";
            displayStudent(students[mid]);
            return;
        } else if (students[mid].id < searchID) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Student not found (Binary Search)." << endl;
}

int main() {
    Student* students = NULL;
    int size = 0;
    int choice, id;

    do {
        cout << "\n--- Student Database Menu ---\n";
        cout << "1. Add Student\n";
        cout << "2. Linear Search by ID\n";
        cout << "3. Binary Search by ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent(students, size);
            break;
        case 2:
            cout << "Enter ID to search (Linear): ";
            cin >> id;
            linearSearch(students, size, id);
            break;
        case 3:
            cout << "Enter ID to search (Binary): ";
            cin >> id;
            binarySearch(students, size, id);
            break;
        case 4:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 4);

    free(students);
    return 0;
}

