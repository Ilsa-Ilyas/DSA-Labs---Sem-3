#include <iostream>
using namespace std;

int main() {

    int n;
    cout << "Enter size of 1D Array: ";
    cin >> n;
    int* arr = new int[n];
    cout << "Enter " << n << " "<< "elemetns:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Elements: " << endl;
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }


    return 0;

}