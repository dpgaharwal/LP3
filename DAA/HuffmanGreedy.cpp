#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node structure for Huffman Tree
struct Node
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char character, int frequency)
    {
        ch = character;
        freq = frequency;
        left = right = nullptr;
    }
};

// Comparator for priority queue to sort nodes based on frequency
struct Compare
{
    bool operator()(Node *left, Node *right)
    {
        return left->freq > right->freq;
    }
};

// Recursive function to generate Huffman codes for each character
void generateHuffmanCodes(Node *root, string code, unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
        return;

    // Leaf node: contains a character
    if (!root->left && !root->right)
    {
        huffmanCode[root->ch] = code;
    }

    // Traverse left and right subtrees
    generateHuffmanCodes(root->left, code + "0", huffmanCode);
    generateHuffmanCodes(root->right, code + "1", huffmanCode);
}

// Function to build Huffman Tree and generate codes
unordered_map<char, string> buildHuffmanTree(const string &text)
{
    // Count frequency of each character
    unordered_map<char, int> frequency;
    for (char ch : text)
    {
        frequency[ch]++;
    }

    // Priority queue to store nodes of the Huffman tree
    priority_queue<Node *, vector<Node *>, Compare> pq;

    // Create a leaf node for each character and push it to the priority queue
    for (auto pair : frequency)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    // Iterate while there are more than one nodes in the queue
    while (pq.size() > 1)
    {
        // Remove the two nodes with the highest priority (lowest frequency)
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        // Create a new internal node with a frequency equal to the sum of the two nodes' frequencies
        Node *sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;

        // Add the new node to the priority queue
        pq.push(sum);
    }

    // Root of the Huffman Tree
    Node *root = pq.top();

    // Traverse the Huffman Tree and generate codes
    unordered_map<char, string> huffmanCode;
    generateHuffmanCodes(root, "", huffmanCode);

    return huffmanCode;
}

// Function to print the generated Huffman codes
void printHuffmanCodes(const unordered_map<char, string> &huffmanCode)
{
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode)
    {
        cout << pair.first << " : " << pair.second << endl;
    }
}

int main()
{
    string text;
    cout << "Enter the text to encode: ";
    getline(cin, text);

    // Build Huffman Tree and get codes
    unordered_map<char, string> huffmanCode = buildHuffmanTree(text);

    // Print the Huffman codes
    printHuffmanCodes(huffmanCode);

    // Print encoded string
    cout << "\nEncoded string: ";
    for (char ch : text)
    {
        cout << huffmanCode[ch];
    }
    cout << endl;

    return 0;
}
