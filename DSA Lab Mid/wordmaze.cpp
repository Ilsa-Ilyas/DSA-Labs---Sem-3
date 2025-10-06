#include <iostream>
using namespace std;

#define R 4
#define C 4

bool isBound(int x, int y){
    return x >= 0 && y >= 0 && x < R && y < C;
}

bool isLetter(int x, int y, char L, char arr[R][C]){
    return arr[x][y] == L;
}

bool wordSearch(int x, int y, string word, int w,int wSize, char arr[R][C]){
    //Base Case
    if(arr[x][y] == word[wSize - 1]){
        return true;
    }

    // No match
    if(!isLetter(x, y, word[w], arr)){
        return false;
    }

    // Right
    else if(arr[x][y + 1] == word[wSize - 1]){
        return wordSearch(x, y + 1, word, w + 1, wSize, arr);
    }
    
    // Down
    else if(arr[x + 1][y] == word[wSize - 1]){
        return wordSearch(x + 1, y, word, w + 1, wSize, arr);
    }

    // Left
    else if(arr[x][y - 1] == word[wSize - 1]){
        return wordSearch(x, y - 1, word, w + 1, wSize, arr);
    }
    
    // Up
    else if(arr[x - 1][y] == word[wSize - 1]){
        return wordSearch(x - 1, y, word, w + 1, wSize, arr);
    }

    return false;
}

int main(){
    char board[4][4] = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
    string word = "eat";

    cout << wordSearch(0,0,word,0,3,board);
}