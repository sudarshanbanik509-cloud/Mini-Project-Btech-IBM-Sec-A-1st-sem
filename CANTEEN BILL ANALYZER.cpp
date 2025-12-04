#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter number of students: ";
    cin >> n;
    cout << "Enter number of days: ";
    cin >> m;

    int bill[100][100];     // Maximum limit (simple)
    int studentTotal[100];  // To store row sums
    int dayTotal[100];      // To store column sums

    // Initialize totals to 0
    for (int i = 0; i < n; i++)
        studentTotal[i] = 0;

    for (int j = 0; j < m; j++)
        dayTotal[j] = 0;

    // Input the bill table
    cout << "Enter the bill amounts:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> bill[i][j];
        }
    }

    // Calculate totals
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            studentTotal[i] += bill[i][j];
            dayTotal[j] += bill[i][j];
        }
    }

    // Print each student's total
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << " total: Rs " << studentTotal[i] << endl;
    }

    // Find highest day
    int maxDay = 0;
    for (int j = 1; j < m; j++) {
        if (dayTotal[j] > dayTotal[maxDay])
            maxDay = j;
    }

    cout << "\nHighest collection on Day " << maxDay + 1 << endl;

    // Find highest spender amount
    int maxSpend = studentTotal[0];
    for (int i = 1; i < n; i++) {
        if (studentTotal[i] > maxSpend)
            maxSpend = studentTotal[i];
    }

    // Print all highest spenders
    cout << "Highest spender(s): ";
    for (int i = 0; i < n; i++) {
        if (studentTotal[i] == maxSpend)
            cout << "Student " << i + 1 << " ";
    }

    cout << endl;

    return 0;
}

