#include <iostream>
#include <cstring>
#include <utility>
using namespace std;

struct Student {
    int id;
    char name[50];
    float cgpa;
};

void addStudent(Student*& students, int& count) {
    Student* temp = new Student[count + 1];
    for (int i = 0; i < count; i++) {
        temp[i] = students[i];
    }
    cout << "Enter Student ID: ";
    cin >> temp[count].id;
    cout << "Enter Student Name: ";
    cin.ignore();
    cin.getline(temp[count].name, 50);
    cout << "Enter CGPA: ";
    cin >> temp[count].cgpa;
    delete[] students;
    students = temp;
    count++;
    cout << "Student added successfully!\n";
}

void displayStudents(Student* students, int count) {
    if (count == 0) {
        cout << "No student records found.\n";
        return;
    }
    cout << "\n--- Student List ---\n";
    for (int i = 0; i < count; i++) {
        cout << "ID: " << students[i].id
             << ", Name: " << students[i].name
             << ", CGPA: " << students[i].cgpa << endl;
    }
}

void bubbleSortByName(Student* students, int count) {
    if (count == 0) {
        cout << "No students to sort!\n";
        return;
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                swap(students[j], students[j + 1]);
            }
        }
    }
    cout << "Sorted by Name (A-Z).\n";
}

void selectionSortByCGPA(Student* students, int count, bool ascending) {
    if (count == 0) {
        cout << "No students to sort!\n";
        return;
    }
    for (int i = 0; i < count - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < count; j++) {
            if (ascending) {
                if (students[j].cgpa < students[idx].cgpa)
                    idx = j;
            } else {
                if (students[j].cgpa > students[idx].cgpa)
                    idx = j;
            }
        }
        swap(students[i], students[idx]);
    }
    if (ascending)
        cout << "Sorted by CGPA (Ascending).\n";
    else
        cout << "Sorted by CGPA (Descending).\n";
}

int main() {
    Student* students = NULL;
    int count = 0;
    int choice;
    do {
        cout << "\n=== Student Database Menu ===\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Sort by Name (Bubble Sort)\n";
        cout << "4. Sort by CGPA Ascending (Selection Sort)\n";
        cout << "5. Sort by CGPA Descending (Selection Sort)\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent(students, count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                bubbleSortByName(students, count);
                break;
            case 4:
                selectionSortByCGPA(students, count, true);
                break;
            case 5:
                selectionSortByCGPA(students, count, false);
                break;
            case 6:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);
    delete[] students;
    return 0;
}

