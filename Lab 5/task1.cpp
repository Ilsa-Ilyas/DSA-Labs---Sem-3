#include <iostream>

using namespace std;

bool isSubsetSum(int* nums, int n, int target) {
    // dp[i][j] -> using (n+1) x (target+1) dynamic 2D array
    bool** dp = new bool*[n+1];
    for (int i = 0; i <= n; ++i) {
        dp[i] = new bool[target+1];
        for (int j = 0; j <= target; ++j) dp[i][j] = false;
    }

    for (int i = 0; i <= n; ++i) dp[i][0] = true;
    for (int i = 1; i <= n; ++i) {
        for (int sum = 1; sum <= target; ++sum) {
            if (nums[i-1] > sum)
                dp[i][sum] = dp[i-1][sum];
            else
                dp[i][sum] = dp[i-1][sum] || dp[i-1][sum-nums[i-1]];
        }
    }

    bool result = dp[n][target];

    for (int i = 0; i <= n; ++i) delete [] dp[i];
    delete [] dp;
    return result;
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    if (!(cin >> n)) return 0;
    int* nums = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) cin >> nums[i];
    cout << "Enter target sum: ";
    cin >> target;

    if (isSubsetSum(nums, n, target))
        cout << "Yes, there exists a subset with the given sum." << endl;
    else
        cout << "No, there does not exist such a subset." << endl;

    delete [] nums;
    return 0;
}