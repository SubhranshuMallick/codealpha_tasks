#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int numSemesters;
    double totalCredits = 0, totalPoints = 0;
    
    cout << "Enter number of semesters completed: ";
    cin >> numSemesters;
    
    for(int sem = 1; sem <= numSemesters; sem++) {
        cout << "\nSemester " << sem << endl;
        cout << "----------------" << endl;
        
        int numSubjects;
        cout << "Enter number of subjects in semester " << sem << ": ";
        cin >> numSubjects;
        cin.ignore();
        
        for(int i = 0; i < numSubjects; i++) {
            string subjectName;
            double credits;
            char grade;
            
            cout << "\nSubject " << i+1 << " name: ";
            getline(cin, subjectName);
            
            cout << "Credits for " << subjectName << ": ";
            cin >> credits;
            
            cout << "Grade obtained (O/E/A/B/C/D/F/S/M): ";
            cin >> grade;
            cin.ignore();
            
            // Convert grade to points
            double points = 0;
            switch(toupper(grade)) {
                case 'O': points = 10; break;
                case 'E': points = 9; break;
                case 'A': points = 8; break;
                case 'B': points = 7; break;
                case 'C': points = 6; break;
                case 'D': points = 5; break;
                case 'F': points = 2; break;
                case 'S': points = 0; break;
                case 'M': points = 0; break;  // For MP
            }

            // ... rest of the code remains same ...
            totalPoints += credits * points;
            totalCredits += credits;
        }
    }
    
    // Calculate CGPA
    double cgpa = totalPoints / totalCredits;
    
    cout << "\n----------------------------------------" << endl;
    cout << "Total Credits Completed: " << totalCredits << endl;
    cout << "CGPA: " << fixed << setprecision(2) << cgpa << endl;
    cout << "----------------------------------------" << endl;
    
    return 0;
}
