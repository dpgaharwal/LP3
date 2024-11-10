/*
TC:O(2^N) SC: O(N)

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
#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum profit
int knapSack(int W, int wt[], int val[], int n)
{
    // Making and initializing dp array
    int dp[W + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n + 1; i++)
    {
        for (int w = W; w >= 0; w--)
        {
            if (wt[i - 1] <= w)
                // Finding the maximum value
                dp[w] = max(dp[w], dp[w - wt[i - 1]] + val[i - 1]);
        }
    }
    // Returning the maximum value of knapsack
    return dp[W];
}

// Driver code
int main()
{
    int n, W;

    cout << "Enter the number of items: ";
    cin >> n;

    int *profit = new int[n];
    int *weight = new int[n];

    cout << "Enter the profit of each item:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Profit of item " << i + 1 << ": ";
        cin >> profit[i];
    }

    cout << "Enter the weight of each item:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Weight of item " << i + 1 << ": ";
        cin >> weight[i];
    }

    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> W;

    cout << "Maximum possible profit = " << knapSack(W, weight, profit, n);

    delete[] profit; // Free dynamically allocated memory
    delete[] weight;

    return 0;
}
