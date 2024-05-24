#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
	struct Node* leftBranch;
	struct Node* rightBranch;
};

struct Node* createNewNode(int newData) {
    struct Node* newNode = new struct Node;
    newNode->data = newData;
    newNode->leftBranch = nullptr;
    newNode->rightBranch = nullptr;
    return newNode;
}

struct Node* insertNode(struct Node* root, int newData) {
     if(root == nullptr) {
          root = createNewNode(newData);
     } else if(newData > root->data) {
          root->rightBranch = insertNode(root->rightBranch, newData);
     } else {
          root->leftBranch = insertNode(root->leftBranch, newData);
     }
     return root;
}

void bfsSearch(queue<struct Node*> &nodes) {
    struct Node* currentNode = nodes.front();
    cout << currentNode->data;
    if(currentNode->leftBranch != nullptr) nodes.emplace(currentNode->leftBranch);
    if(currentNode->rightBranch != nullptr) nodes.emplace(currentNode->rightBranch);
    nodes.pop();
    if(!nodes.empty()) {
        cout << " ";
        bfsSearch(nodes);
    } else {
        cout << "\n\n";
    }
    return;
}

void clearBst(struct Node* root) {
    if(root->leftBranch != nullptr) clearBst(root->leftBranch);
    if(root->rightBranch != nullptr) clearBst(root->rightBranch);
    delete root;
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    struct Node* root = nullptr;
    int n, temp, cases;
    int counter = 1;
    cin >> n;
    queue<struct Node*> nodes;
    for(int i = 0; i < n; i++) {
        cin >> cases;
        for(int j = 0; j < cases; j++) {
            cin >> temp;
            root = insertNode(root, temp);
        }
        nodes.emplace(root);
        cout << "Case " << counter << ":\n";
        bfsSearch(nodes);
        clearBst(root);
        root = nullptr;
        counter++;
    }
    return 0;
}
