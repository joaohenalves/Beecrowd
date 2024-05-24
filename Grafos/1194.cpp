#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> k;
string prfx, infx;
int idx;

typedef struct Node {
    char c;
    struct Node *left;
    struct Node *right;
} Node;

Node* newNode(char c) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->c = c;
    node->left = node->right = nullptr;
    return node;
}

Node* buildTree(int l, int r) {
    if(l > r) return nullptr;
    Node *node = newNode(prfx[idx++]);
    node->left = buildTree(l, k[node->c] - 1);
    node->right = buildTree(k[node->c] + 1, r);
    return node;
}

void postFix(Node *node) {
    if(node->left != nullptr) postFix(node->left);
    if(node->right != nullptr) postFix(node->right);
    cout << node->c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n >> prfx >> infx;
        idx = 0;
        for(int i = 0; i < n; i++) {
            k[infx[i]] = i;
        }
        Node *node = buildTree(0, n - 1);
        postFix(node);
        cout << "\n";
    }
    return 0;
}
