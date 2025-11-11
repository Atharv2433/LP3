#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

// Build Huffman codes recursively
void buildCodes(vector<vector<int>>& tree, int index, string code, unordered_map<char, string>& codes, vector<char>& chars) {
   
    if (tree[index][1] == -1 && tree[index][2] == -1) {
        codes[chars[index]] = (code == "") ? "0" : code;
        return;
    }

    if (tree[index][1] != -1)
        buildCodes(tree, tree[index][1], code + "0", codes, chars);
    if (tree[index][2] != -1)
        buildCodes(tree, tree[index][2], code + "1", codes, chars);
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);
    vector<int> freq(n);

    cout << "Enter each character followed by its frequency:\n";
    for (int i = 0; i < n; i++)
        cin >> chars[i] >> freq[i];

    // Priority queue (min-heap): (frequency, index)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) pq.push({freq[i], i});

    // Tree: each node -> [freq, left, right]
    vector<vector<int>> tree(2 * n, vector<int>(3, -1));
    for (int i = 0; i < n; i++) tree[i][0] = freq[i];

    int next = n;
    while (pq.size() > 1) {
        auto x = pq.top(); pq.pop();
        auto y = pq.top(); pq.pop();

        tree[next][0] = x.first + y.first; // combined frequency
        tree[next][1] = x.second;          // left child index
        tree[next][2] = y.second;          // right child index
        pq.push({tree[next][0], next});
        next++;
    }

    int root = pq.top().second;

    unordered_map<char, string> codes;
    buildCodes(tree, root, "", codes, chars);

    cout << "\nHuffman Codes:\n";
    for (int i = 0; i < n; i++) {
        cout << chars[i] << " : " << codes[chars[i]] << endl;
    }

    int totalBits = 0;
    for (int i = 0; i < n; i++)
        totalBits += freq[i] * codes[chars[i]].length();

    cout << "\nTotal bits required = " << totalBits << endl;
    return 0;
}
