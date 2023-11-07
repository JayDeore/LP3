#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    double weight;
    double value;
    double valuePerWeight; // Profit by Weight ratio

    Item(double w, double v)
    {
        this->weight = w;
        this->value = v;
        this->valuePerWeight = v / w;
    }
};

bool compareItems(const Item &a, const Item &b)
{
    return a.valuePerWeight > b.valuePerWeight;
}

double fractionalKnapsack(vector<Item> &items, int capacity)
{

    // sorting according to p/w ratio in decreasing order
    sort(items.begin(), items.end(), compareItems);

    double totalValue = 0.0;

    for (int i = 0; i < items.size(); i++)
    {
        if (capacity >= items[i].weight)
        {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            totalValue += (capacity / items[i].weight) * items[i].value;
            break;
        }
    }

    return totalValue;
}

int main()
{
    int n;        // Number of items
    int capacity; // Knapsack capacity
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    vector<Item> items;

    for (int i = 0; i < n; ++i)
    {
        int weight, value;
        cout << "Enter the weight and value of item " << (i + 1) << ": ";
        cin >> weight >> value;
        items.push_back(Item(weight, value));
    }

    double maxTotalValue = fractionalKnapsack(items, capacity);

    cout << "Maximum Profit: " << maxTotalValue << endl;

    return 0;
}