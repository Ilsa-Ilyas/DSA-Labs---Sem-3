#include <iostream>
using namespace std;

int main() {
    int r = 3;                    // Number of rows
    int** arr = new int*[r];      // Array of pointers (rows)
    int size[3];                  // Stores sizes of each row

    // Input sizes and allocate each row
    for (int i = 0; i < r; i++) {
        cout << "Enter size of row " << i << ": ";
        cin >> size[i];
        arr[i] = new int[size[i]];  // Allocate row i with size[i] columns
    }

    // Input elements for each row
    for (int i = 0; i < r; i++) {
        cout << "Enter elements for row " << i << ": ";
        for (int j = 0; j < size[i]; j++) {
            cin >> arr[i][j];
        }
    }

    // Print the elements of the jagged array
    cout << "Jagged Array elements:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < size[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Deallocate memory to avoid memory leaks
    for (int i = 0; i < r; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}



