#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Structure to store a Huffman tree node
struct MinHNode
{
    char data;
    int freq;
    MinHNode *left;
    MinHNode *right;

    MinHNode(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Comparison function for the priority queue
struct Compare
{
    bool operator()(MinHNode *l, MinHNode *r)
    {
        return l->freq > r->freq;
    }
};

// Build the Huffman tree and return the root
MinHNode *buildHuffmanTree(map<char, int> freq)
{
    priority_queue<MinHNode *, vector<MinHNode *>, Compare> pq;

    for (auto it = freq.begin(); it != freq.end(); ++it)
    {
        char data = it->first;
        int frequency = it->second;
        pq.push(new MinHNode(data, frequency));
    }

    while (pq.size() > 1)
    {
        MinHNode *left = pq.top();
        pq.pop();
        MinHNode *right = pq.top();
        pq.pop();

        MinHNode *top = new MinHNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        pq.push(top);
    }

    return pq.top();
}

// Print Huffman codes
void printHuffmanCodes(MinHNode *root, string code)
{
    if (!root)
        return;

    if (root->data != '$')
    {
        cout << root->data << " : " << code << endl;
    }

    printHuffmanCodes(root->left, code + "0");
    printHuffmanCodes(root->right, code + "1");
}

// Wrapper function to encode
void huffmanEncoding(map<char, int> freq)
{
    MinHNode *root = buildHuffmanTree(freq);
    printHuffmanCodes(root, "");
}

int main()
{
    int n;
    cout << "Enter number of characters" << endl;
    cin >> n;
    map<char, int> freq;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter character and frequency" << endl;
        char x;
        int fre;
        cin >> x >> fre;
        freq.insert(make_pair(x, fre));
    }

    cout << "Huffman Codes:\n";
    huffmanEncoding(freq);

    return 0;
}