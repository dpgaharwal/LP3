/* TC: NlogN +N SC:O(1)*/
/*int n = 3, weight = 50;
   Item arr[n] = { {100,20},{60,10},{120,30} };
*/
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    bool static comp(Item a, Item b)
    {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }
    // function to return fractional weights
    double fractionalKnapsack(int W, Item arr[], int n)
    {

        sort(arr, arr + n, comp);

        int curWeight = 0;
        double finalvalue = 0.0;

        for (int i = 0; i < n; i++)
        {
            if (curWeight + arr[i].weight <= W)
            {
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;
            }
            else
            {
                int remain = W - curWeight;
                finalvalue += (arr[i].value / (double)arr[i].weight) * (double)remain;
                break;
            }
        }
        return finalvalue;
    }
};

int main()
{
    int n, weight;
    cout << "Enter the number of items: ";
    cin >> n;

    Item *arr = new Item[n];
    cout << "Enter the value and weight of each item:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Item " << i + 1 << " - Value: ";
        cin >> arr[i].value;
        cout << "Item " << i + 1 << " - Weight: ";
        cin >> arr[i].weight;
    }

    cout << "Enter the maximum weight of the knapsack: ";
    cin >> weight;

    Solution obj;
    double ans = obj.fractionalKnapsack(weight, arr, n);
    cout << "The maximum value is " << setprecision(2) << fixed << ans;

    delete[] arr; // Free dynamically allocated memory
    return 0;
}
