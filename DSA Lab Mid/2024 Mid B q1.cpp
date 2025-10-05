#include <iostream>
using namespace std;

int main() {
    int n1, n2;

    cout << "Enter size of 1st Array: ";
    cin >> n1;
    int arr1[100];
    cout << "Enter elements of 1st Array: ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter size of 2nd Array: ";
    cin >> n2;
    int arr2[100];   
    cout << "Enter elements of 2nd Array: ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    int freq[1000] = {0};
    for (int i = 0; i < n1; i++) {
        freq[arr1[i]]++;
    }

    // Printing arr2 elements first
    for (int i = 0; i < n2; i++) {
        int element = arr2[i];
        int count = freq[element];
        for (int j = 0; j < n1 && count > 0; j++) {
            if (arr1[j] == element) {
                cout << arr1[j] << " ";
                count--;
            }
        }
        freq[element] = 0;
    }

    // Printing remaining arr1 elements
    for (int i = 0; i < n1; i++) {
        if (freq[arr1[i]] > 0) {
            cout << arr1[i] << " ";
            freq[arr1[i]]--;
        }
    }

    cout << endl;
    return 0;
}
