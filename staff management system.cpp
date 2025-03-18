#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struct for Staff
struct Staff {
    string name;
    string department;
    string designation;
    double salary;
};

// Global staff list
vector<Staff> staffList;

// Function to add a staff member
void addStaff() {
    Staff newStaff;
    cout << "Enter Name: ";
    cin.ignore();  // Ignore leftover newline character from previous input
    getline(cin, newStaff.name);  // Get name with spaces
    cout << "Enter Department: "; cin >> newStaff.department;
    cout << "Enter Designation: "; cin >> newStaff.designation;
    cout << "Enter Salary: "; cin >> newStaff.salary;

    // Add the new staff to the list
    staffList.push_back(newStaff);
    cout << "Staff added successfully!\n";
}

// Function to update staff information
void updateStaff() {
    string name;
    cout << "Enter Staff Name to Update: ";
    cin.ignore();  // Ignore leftover newline
    getline(cin, name);  // Get name to search

    bool found = false;
    for (auto &staff : staffList) {
        if (staff.name == name) {
            found = true;
            cout << "Enter New Department: "; cin >> staff.department;
            cout << "Enter New Designation: "; cin >> staff.designation;
            cout << "Enter New Salary: "; cin >> staff.salary;
            cout << "Staff updated successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Staff not found.\n";
    }
}

// Function to search for a staff member
void searchStaff() {
    string name;
    cout << "Enter Staff Name to Search: ";
    cin.ignore();  // Ignore leftover newline
    getline(cin, name);  // Get name to search

    bool found = false;
    for (const auto &staff : staffList) {
        if (staff.name == name) {
            found = true;
            cout << "Name: " << staff.name << "\nDepartment: " << staff.department
                 << "\nDesignation: " << staff.designation << "\nSalary: " << staff.salary << "\n";
            break;
        }
    }

    if (!found) {
        cout << "Staff not found.\n";
    }
}

// Function to view all staff members
void viewAllStaff() {
    if (staffList.empty()) {
        cout << "No staff records found.\n";
    } else {
        cout << "All Staff Members:\n";
        for (const auto &staff : staffList) {
            cout << "Name: " << staff.name << ", Department: " << staff.department
                 << ", Designation: " << staff.designation << ", Salary: " << staff.salary << "\n";
        }
    }
}

// Function to delete a staff member
void deleteStaff() {
    string name;
    cout << "Enter Staff Name to Delete: ";
    cin.ignore();  // Ignore leftover newline
    getline(cin, name);  // Get name to search

    bool found = false;
    for (auto it = staffList.begin(); it != staffList.end(); ++it) {
        if (it->name == name) {
            found = true;
            staffList.erase(it);
            cout << "Staff deleted successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Staff not found.\n";
    }
}

// Main function
int main() {
    int choice;
    
    // Menu-driven loop for user interaction
    do {
        cout << "\n--- Staff Management System ---\n";
        cout << "1. Add Staff\n";
        cout << "2. Update Staff\n";
        cout << "3. Search Staff\n";
        cout << "4. View All Staff\n";
        cout << "5. Delete Staff\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStaff(); 
                break;
            case 2:
                updateStaff(); 
                break;
            case 3:
                searchStaff(); 
                break;
            case 4:
                viewAllStaff(); 
                break;
            case 5:
                deleteStaff(); 
                break;
            case 6:
                cout << "Exiting program...\n"; 
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
