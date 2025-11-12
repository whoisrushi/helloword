#include <iostream>
#include <cstring>
#include <cstdlib>   // for realloc
using namespace std;

struct Student {
    int id;
    char name[50];
    float cgpa;
};

int main() {
    Student *s = NULL;
    int n = 0, ch;

    do {
        cout << "\n1.Add  2.Display  3.Sort(Name)  4.Sort(CGPA)  5.Exit\nChoice: ";
        cin >> ch;

        if (ch == 1) {  // Add Student
            s = (Student*)realloc(s, (n + 1) * sizeof(Student));
            cout << "Enter ID Name CGPA: ";
            cin >> s[n].id >> s[n].name >> s[n].cgpa;
            n++;
            cout << "Added!\n";
        }

        else if (ch == 2) {  // Display
            if (n == 0) cout << "No records!\n";
            else {
                cout << "\nID\tName\tCGPA\n";
                for (int i = 0; i < n; i++)
                    cout << s[i].id << "\t" << s[i].name << "\t" << s[i].cgpa << endl;
            }
        }

        else if (ch == 3) {  // Sort by Name (Bubble Sort)
            for (int i = 0; i < n - 1; i++)
                for (int j = i + 1; j < n; j++)
                    if (strcmp(s[i].name, s[j].name) > 0)
                        swap(s[i], s[j]);
            cout << "Sorted by Name!\n";
        }

        else if (ch == 4) {  // Sort by CGPA (Selection Sort - Descending)
            for (int i = 0; i < n - 1; i++) {
                int maxIndex = i;
                for (int j = i + 1; j < n; j++)
                    if (s[j].cgpa > s[maxIndex].cgpa)
                        maxIndex = j;
                if (maxIndex != i)
                    swap(s[i], s[maxIndex]);
            }
            cout << "Sorted by CGPA (Selection Sort)!\n";
        }

        else if (ch == 5)
            cout << "Exit!\n";

        else
            cout << "Invalid!\n";

    } while (ch != 5);

    free(s);
    return 0;
}
