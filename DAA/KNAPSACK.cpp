#include <bits/stdc++.h>

using namespace std;

// Top down recursion method
int fun(int ind, int W, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (wt[0] <= W)
            return val[0];
        return 0;
    }
    if (dp[ind][W] != -1)
    {
        return dp[ind][W];
    }
    int notTake = 0 + fun(ind - 1, W, wt, val, dp);
    int take = INT_MIN;
    if (wt[ind] <= W)
    {
        take = val[ind] + fun(ind - 1, W - wt[ind], wt, val, dp);
    }

    return dp[ind][W] = max(take, notTake);
}

// bottom up tabulation method
int funBottomUp(int n, int maxWt, vector<int> &wt, vector<int> &val)
{
    vector<vector<int>> dp(n + 1, vector<int>(maxWt + 1, 0));
    for (int j = wt[0]; j <= maxWt; j++)
        dp[0][j] = val[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= maxWt; j++)
        {
            int notTake = 0 + dp[i - 1][j];
            int take = INT_MIN;
            if (wt[i] <= j)
            {
                take = val[i] + dp[i - 1][j - wt[i]];
            }
            dp[i][j] = max(take, notTake);
        }
    }
    /** tabulation table for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxWt; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    **/
    return dp[n - 1][maxWt];
}

int main()
{
    int n; // Number of items
    int W; // Knapsack capacity
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the knapsack capacity: ";
    cin >> W;

    vector<int> wt(n);
    vector<int> val(n);

    cout << "Enter the weights of items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    cout << "Enter the values of items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    int maxTotalValue = funBottomUp(n, W, wt, val);

    cout << "Maximum total value in the knapsack: " << maxTotalValue << endl;

    return 0;
}