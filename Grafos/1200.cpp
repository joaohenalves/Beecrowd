#include <bits/stdc++.h>
using namespace std;

string printData = "";

void printString() {
    if (!printData.empty()) {
        printData.erase(printData.size() - 1);
    }
    cout << printData << "\n";
}

struct Node {
    char data;
	struct Node* leftBranch;
	struct Node* rightBranch;
};

struct Node* createNewNode(char newData) {
    struct Node* newNode = new struct Node;
    newNode->data = newData;
    newNode->leftBranch = NULL;
    newNode->rightBranch = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, char newData) {
     if(root == NULL) {
          root = createNewNode(newData);
     } else if(newData > root->data) {
          root->rightBranch = insertNode(root->rightBranch, newData);
     } else {
          root->leftBranch = insertNode(root->leftBranch, newData);
     }
     return root;
}

struct Node* searchData(struct Node* root, char targetData) {
     if(root == NULL || root->data == targetData) {
          return root;
     } else if(root->data < targetData) {
          return searchData(root->rightBranch, targetData);
     } else {
          return searchData(root->leftBranch, targetData);
     }
}


void inFixSearch(struct Node* root) {
    if(root == NULL) return;
    inFixSearch(root->leftBranch);
    printData += root->data;
    printData += " ";
    inFixSearch(root->rightBranch);
}

void preFixSearch(struct Node* root){
	if(root == NULL) return;
	printData += root->data;
    printData += " ";
	preFixSearch(root->leftBranch);
	preFixSearch(root->rightBranch);
}

void postFixSearch(struct Node* root){
	if(root == NULL) return;
	postFixSearch(root->leftBranch);
	postFixSearch(root->rightBranch);
    printData += root->data;
    printData += " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    struct Node* root;
    string op;
    while(getline(cin, op)) {
        if(op.size() == 3) {
            if(op[0] == 'I') {
                root = insertNode(root, op[2]);
            } else if (op[0] == 'P') {
                struct Node* temp = searchData(root, op[2]);
                if(temp != NULL) {
                    cout << op[2] << " existe\n";
                } else {
                    cout << op[2] << " nao existe\n";
                }
            }
        } else {
            if(op == "INFIXA") {
                inFixSearch(root);
                printString();
                printData = "";
            } else if (op == "POSFIXA") {
                postFixSearch(root);
                printString();
                printData = "";
            } else if (op == "PREFIXA") {
                preFixSearch(root);
                printString();
                printData = "";
            }
        }
    }
    return 0;
}
