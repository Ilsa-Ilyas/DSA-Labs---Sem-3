#include <iostream>
using namespace std;

int main() {
    // Declare and initialize a 2D array with 2 rows and 3 columns
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

    cout << "2D array: " << endl;

    // Outer loop iterates over rows (0 to 1)
    for (int i = 0; i < 2; i++) {
        // Inner loop iterates over columns (0 to 2)
        for (int j = 0; j < 3; j++) {
            // Print each element followed by a space
            cout << arr[i][j] << " ";
        }
        // After printing all columns in a row, print a newline
        cout << endl;  
    }

    return 0;
}
