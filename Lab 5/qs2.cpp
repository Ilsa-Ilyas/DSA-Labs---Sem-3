#include <iostream>
using namespace std;

// Generate all well-formed parentheses combinations for `n` pairs.
void gen(string current, int start, int end, int n) {
    // When the partial string reaches length 2*n, it is a complete sequence
    if (current.length() == 2 * n) {
        cout << current << endl;
        return;
    }

    // Add '(' if there is capacity
    if (start < n)
        gen(current + "(", start + 1, end, n);

    // Add ')' only if it will not produce an invalid prefix
    if (end < start)
        gen(current + ")", start, end + 1, n);
}

int main() {
    int n = 3; // Number of pairs 

    // Start recursion with empty string and 0 start/end brackets
    gen("", 0, 0, n);

    return 0;
}