#include <iostream>
#include <string>
using namespace std;

// Define the structure to store student data
struct Student {
    int rollNo;
    string name;
    float SGPA;
};

// Function to implement Bubble Sort
void bubbleSort(Student students[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (students[j].rollNo > students[j+1].rollNo) {
                // Swap the students
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

// Function to display the student list
void displayStudents(const Student students[], int n) {
    cout << "Roll No\tName\t\tSGPA" << endl;
    cout << "-----------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << students[i].rollNo << "\t" << students[i].name << "\t" << students[i].SGPA << endl;
    }
}

int main() {
    int n;

    // Get the number of students
    cout << "Enter the number of students: ";
    cin >> n;

    // Array to store student data
    Student students[n];

    // Input student data
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for student " << i+1 << ":" << endl;
        cout << "Enter Roll No: ";
        cin >> students[i].rollNo;
        cin.ignore();  // to clear the newline character from input buffer
        cout << "Enter Name: ";
        getline(cin, students[i].name);
        cout << "Enter SGPA: ";
        cin >> students[i].SGPA;
    }

    // Sorting the student list by Roll No using Bubble Sort
    bubbleSort(students, n);

    // Display sorted student list
    cout << "\nSorted Roll Call List:" << endl;
    displayStudents(students, n);

    return 0;
}
