#include <iostream>
using namespace std;

int main() {
    int stds = 5;
    int subs = 4;

    // DMA for students and subjects
    int** marks = new int*[stds];
    for (int i = 0; i < stds; i++) {
        marks[i] = new int[subs];
    }

    // Input marks for each student in each subject
    for (int i = 0; i < stds; i++) {
        cout << "Enter marks for std " << i + 1 << ":\n";
        for (int j = 0; j < subs; j++) {
            cout << "  Sub " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }

    // Calculate and display total marks of each student
    int* tmarks = new int[stds];
    for (int i = 0; i < stds; i++) {
        int sum = 0;
        for (int j = 0; j < subs; j++) {
            sum += marks[i][j];
        }
        tmarks[i] = sum;
        cout << "T.marks of student " << i + 1 << ": " << sum << endl;
    }

    // Calculate and display average marks of each subject
    cout << "\nAvg marks for each sub:\n";
    for (int j = 0; j < subs; j++) {
        int Sum = 0;
        for (int i = 0; i < stds; i++) {
            Sum += marks[i][j];
        }
        double average = static_cast<double>(Sum) / stds;
        cout << "Subj " << j + 1 << ": " << average << endl;
    }

    // Find the topper student (highest total marks)
    int index = 0;
    int highestm = tmarks[0];
    for (int i = 1; i < stds; i++) {
        if (tmarks[i] > highestm) {
            highestm = tmarks[i];
            index = i;
        }
    }
    cout << "\nTopper student is student " << index + 1 << " with total marks: " << highestm << endl;

    // Clear dynamically allocated memory
    for (int i = 0; i < stds; i++) {
        delete[] marks[i];
    }
    delete[] marks;
    delete[] tmarks;

    return 0;
}
