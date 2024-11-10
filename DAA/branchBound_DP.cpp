/*TC:O(2^N) SC: O(N)

    W:12
    P  30 28 20 24
    w   5  7  4  2
*/
/*
#include <bits/stdc++.h>
using namespace std;

// Structure for Item which store weight and corresponding
// value of Item
struct Item
{
    float weight;
    int value;
};

// Node structure to store information of decision tree
struct Node
{
    int level, profit, bound;
    float weight;
};

// Comparison function to sort Item according to
// val/weight ratio
bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Returns bound of profit in subtree rooted with u.
int bound(Node u, int n, int W, Item arr[])
{
    if (u.weight >= W)
        return 0;

    int profit_bound = u.profit;
    int j = u.level + 1;
    int totweight = u.weight;

    while ((j < n) && (totweight + arr[j].weight <= W))
    {
        totweight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }

    if (j < n)
        profit_bound += (W - totweight) * arr[j].value / arr[j].weight;

    return profit_bound;
}

// Returns maximum profit we can get with capacity W
int knapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, cmp);

    queue<Node> Q;
    Node u, v;

    u.level = -1;
    u.profit = u.weight = 0;
    Q.push(u);

    int maxProfit = 0;
    while (!Q.empty())
    {
        u = Q.front();
        Q.pop();

        if (u.level == -1)
            v.level = 0;

        if (u.level == n - 1)
            continue;

        v.level = u.level + 1;

        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;

        if (v.weight <= W && v.profit > maxProfit)
            maxProfit = v.profit;

        v.bound = bound(v, n, W, arr);

        if (v.bound > maxProfit)
            Q.push(v);

        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        if (v.bound > maxProfit)
            Q.push(v);
    }

    return maxProfit;
}

// Main function to take user input
int main()
{
    int n, W;

    cout << "Enter the maximum weight of the knapsack: ";
    cin >> W;

    cout << "Enter the number of items: ";
    cin >> n;

    Item *arr = new Item[n];
    cout << "Enter the weight and value of each item:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> arr[i].weight;
        cout << "Item " << i + 1 << " - Value: ";
        cin >> arr[i].value;
    }

    cout << "Maximum possible profit = " << knapsack(W, arr, n);

    delete[] arr; // Free dynamically allocated memory
    return 0;
}
*/
/* TC: O(N*W) SC: O(W)
int profit[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int W = 50;
*/
/*
****************LB*************************
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int index, int capacity)
{
    // base case
    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solve(weight, value, index - 1, capacity - weight[index]);
    }

    int exclude = solve(weight, value, index - 1, capacity);

    int ans = max(exclude, include);

    return ans;
}

int solveMem(vector<int> &weight, vector<int> &value, int index, int capacity, vector<vector<int>> &dp)
{
    // base case
    if (index == 0)
    {
        if (weight[0] <= capacity)
            return value[0];
        else
            return 0;
    }

    if (dp[index][capacity] != -1)
        return dp[index][capacity];
    int include = 0;
    if (weight[index] <= capacity)
    {
        include = value[index] + solveMem(weight, value, index - 1, capacity - weight[index], dp);
    }

    int exclude = solveMem(weight, value, index - 1, capacity, dp);

    dp[index][capacity] = max(exclude, include);

    return dp[index][capacity];
}

int solveTab(vector<int> &weight, vector<int> &value, int n, int capacity)
{
    // step 1:
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // step 2
    for (int w = weight[0]; w <= capacity; w++)
    {
        if (weight[0] <= capacity)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int include = 0;
            if (weight[index] <= w)
            {
                include = value[index] + dp[index - 1][w - weight[index]];
            }

            int exclude = 0 + dp[index - 1][w];

            dp[index][w] = max(exclude, include);
        }
    }
    return dp[n - 1][capacity];
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // return solve(weight, value, n - 1, maxWeight);
    // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // return solveMem(weight, value, n - 1, maxWeight, dp);
    return solveTab(weight, value, n, maxWeight);
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weight(n), value(n);

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    int maxWeight;
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> maxWeight;

    int maxProfit = knapsack(weight, value, n, maxWeight);
    cout << "The maximum profit is: " << maxProfit << endl;

    return 0;
}
*/

/*Classic DP*/
#include <iostream>
#include <vector>
using namespace std;

int knapsack(const vector<int> &weights, const vector<int> &values, int capacity)
{
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Filling the DP table
    for (int i = 1; i <= n; ++i)
    {
        for (int w = 1; w <= capacity; ++w)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main()
{
    int n, capacity;

    // Taking input from the user
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> weights[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> values[i];
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    // Finding the maximum value in the knapsack
    int result = knapsack(weights, values, capacity);

    cout << "Maximum value in Knapsack = " << result << endl;

    return 0;
}
