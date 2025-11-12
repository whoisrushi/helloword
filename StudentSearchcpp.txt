#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    int id;
    string name;
    float cgpa;
};

void addStudent(vector<Student>& students) {
    Student s;
    cout << "Enter ID: ";
    cin >> s.id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter CGPA: ";
    cin >> s.cgpa;
    students.push_back(s);
}

void display(const vector<Student>& students) {
    cout << "\n--- Student List ---\n";
    for (auto& s : students)
        cout << "ID: " << s.id << ", Name: " << s.name << ", CGPA: " << s.cgpa << '\n';
}

int main() {
    vector<Student> students;
    int choice;
    do {
        cout << "\n1.Add  2.Display  3.Sort by Name  4.Sort by CGPA↑  5.Sort by CGPA↓  6.Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(students); break;
            case 2: display(students); break;
            case 3: sort(students.begin(), students.end(),
                         [](auto& a, auto& b){ return a.name < b.name; });
                    cout << "Sorted by Name.\n"; break;
            case 4: sort(students.begin(), students.end(),
                         [](auto& a, auto& b){ return a.cgpa < b.cgpa; });
                    cout << "Sorted Ascending.\n"; break;
            case 5: sort(students.begin(), students.end(),
                         [](auto& a, auto& b){ return a.cgpa > b.cgpa; });
                    cout << "Sorted Descending.\n"; break;
        }
    } while (choice != 6);
}