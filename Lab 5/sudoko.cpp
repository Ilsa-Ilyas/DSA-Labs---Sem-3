#include <iostream>
using namespace std;

bool isSafe(int x, int y, int arr[9][9], int dig){
    for(int i = 0; i < 9; i++){
        if(arr[x][i] == dig) return false;
    }
    for(int i = 0; i < 9; i++){
        if(arr[i][y] == dig) return false;
    }

    int xC = 3 * (x / 3);
    int yC = 3 * (y / 3);
    for (int i = xC; i < 3 + xC; i++)
    {
        for (int j = yC; j < 3 + yC; j++)
        {
            if(arr[i][j] == dig){
                return false;
            }
        }
    }
}

void sudoko(int arr[9][9], int x = 0, int y = 0){
    if(x > 8 || y > 8){
        return;
    }

    // cheaking a full row
    for (int i = 1; i <= 9; i++)
    {
        if(isSafe(x, y, arr, i), arr[x][y] != 0) sudoko(arr, x + 1, y);
    }
    
    // cheaking a full col
    for (int i = 1; i <= 9; i++)
    {
        if(isSafe(x, y, arr, i), arr[x][y] != 0) sudoko(arr, x, y + 1);
    }
}

int main(){
    int arr[9][9] = {
        {0,0,0,0,4,0,0,0,0},
        {0,0,0,0,8,0,0,0,0},
        {0,0,5,7,0,3,4,0,0},
        {0,0,4,0,2,0,5,0,0},
        {9,2,0,1,0,4,0,8,7},
        {0,0,1,0,3,0,2,0,0},
        {0,0,8,4,0,6,9,0,0},
        {0,0,0,0,1,0,0,0,0},
        {0,0,0,0,9,0,0,0,0}
    };

    sudoko(arr);

    cout << "Array: " << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}