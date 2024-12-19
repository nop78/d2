#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float sgpa;
};

void searchBySGPA(Student students[], int n, float searchSGPA) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (students[i].sgpa == searchSGPA) {
            cout << "Student found: Roll No: " << students[i].rollNo 
                 << ", Name: " << students[i].name 
                 << ", SGPA: " << students[i].sgpa << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No student found with SGPA " << searchSGPA << endl;
    }
}

void searchByName(Student students[], int n, string searchName) {
    int low = 0, high = n - 1;
    bool found = false;
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (students[mid].name == searchName) {
            cout << "Student found: Roll No: " << students[mid].rollNo
                 << ", Name: " << students[mid].name
                 << ", SGPA: " << students[mid].sgpa << endl;
            found = true;
            break;
        }
        else if (students[mid].name < searchName) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (!found) {
        cout << "No student found with the name " << searchName << endl;
    }
}

void sortByName(Student students[], int n) {
    sort(students, students + n, [](const Student &a, const Student &b) {
        return a.name < b.name;
    });
}

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;
    
    Student students[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter details for student " << i + 1 << endl;
        cout << "Roll No: ";
        cin >> students[i].rollNo;
        cout << "Name: ";
        cin.ignore(); 
        getline(cin, students[i].name);
        cout << "SGPA: ";
        cin >> students[i].sgpa;
    }

    int choice;
    cout << "\nChoose search option:\n";
    cout << "1. Search by SGPA\n";
    cout << "2. Search by Name\n";
    cout << "Enter choice (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        float searchSGPA;
        cout << "Enter SGPA to search: ";
        cin >> searchSGPA;
        searchBySGPA(students, n, searchSGPA);
    } 
    else if (choice == 2) {
        string searchName;
        cout << "Enter name to search: ";
        cin.ignore();  
        getline(cin, searchName);

        sortByName(students, n);
        
        searchByName(students, n, searchName);
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
