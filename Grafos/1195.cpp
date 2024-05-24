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

void inFixSearch(struct Node* root, int &counter, int &n) {
    if(root == NULL) return;
    inFixSearch(root->leftBranch, counter, n);
    cout << root->data;
    counter++;
    if(counter < n) cout << " ";
    inFixSearch(root->rightBranch, counter, n);
}

void preFixSearch(struct Node* root, int &counter, int &n){
	if(root == NULL) return;
	cout << root->data;
    counter++;
    if(counter < n) cout << " ";
	preFixSearch(root->leftBranch, counter, n);
	preFixSearch(root->rightBranch, counter, n);
}

void postFixSearch(struct Node* root, int &counter, int &n){
	if(root == NULL) return;
	postFixSearch(root->leftBranch, counter, n);
	postFixSearch(root->rightBranch, counter, n);
    cout << root->data;
    counter++;
    if(counter < n) cout << " ";
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
    int n, counter, temp, cases;
    cin >> cases;
    for(int i = 1; i <= cases; i++) {
        cin >> n;
        for(int j = 0; j < n; j++) {
            cin >> temp;
            root = insertNode(root, temp);
        }
        cout << "Case " << i << ":\n";
        cout << "Pre.: ";
        counter = 0;
        preFixSearch(root, counter, n);
        cout << "\n";
        cout << "In..: ";
        counter = 0;
        inFixSearch(root, counter, n);
        cout << "\n";
        cout << "Post: ";
        counter = 0;
        postFixSearch(root, counter, n);
        cout << "\n\n";
        clearBst(root);
        root = nullptr;
    }
    return 0;
}
