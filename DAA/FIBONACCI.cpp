#include <iostream>
using namespace std;

int Recursion(int n)
{
    if (n <= 1)
        return n;

    return Recursion(n - 1) + Recursion(n - 2);
}

int withoutRecursion(int n)
{
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

int main()
{
    int n;
    cout << "Enter number: " << endl;
    cin >> n;

    int recursiveResult = Recursion(n);
    int nonRecursiveResult = withoutRecursion(n);
    cout << "Output with Recursion: " << recursiveResult << endl;
    cout << "Output without Recursion: " << nonRecursiveResult << endl;

    return 0;
}