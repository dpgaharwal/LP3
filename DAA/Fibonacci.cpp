#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

// Iterative (Non-Recursive) Fibonacci Calculation
int fibonacciIterative(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int prev1 = 0, prev2 = 1, fib = 0;
    for (int i = 2; i <= n; ++i)
    {
        fib = prev1 + prev2;
        prev1 = prev2;
        prev2 = fib;
    }
    return fib;
}

// Recursive Fibonacci Calculation
int fibonacciRecursive(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main()
{
    int n;
    cout << "Enter a number (0-based index): ";
    cin >> n;

    // Measure time for iterative approach
    auto startIterative = high_resolution_clock::now();
    int fibIterative = fibonacciIterative(n);
    auto endIterative = high_resolution_clock::now();
    auto durationIterative = duration_cast<nanoseconds>(endIterative - startIterative);

    cout << "Fibonacci (Iterative) of " << n << " is: " << fibIterative;
    cout << " | Time taken (Iterative): " << durationIterative.count() << " nanoseconds" << endl;

    // Measure time for recursive approach
    auto startRecursive = high_resolution_clock::now();
    int fibRecursive = fibonacciRecursive(n);
    auto endRecursive = high_resolution_clock::now();
    auto durationRecursive = duration_cast<nanoseconds>(endRecursive - startRecursive);

    cout << "Fibonacci (Recursive) of " << n << " is: " << fibRecursive;
    cout << " | Time taken (Recursive): " << durationRecursive.count() << " nanoseconds" << endl;

    return 0;
}
