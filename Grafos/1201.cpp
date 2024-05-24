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
    int data;
	struct Node* leftBranch;
	struct Node* rightBranch;
};

struct Node* createNewNode(int newData) {
    struct Node* newNode = new struct Node;
    newNode->data = newData;
    newNode->leftBranch = NULL;
    newNode->rightBranch = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int newData) {
     if(root == NULL) {
          root = createNewNode(newData);
     } else if(newData > root->data) {
          root->rightBranch = insertNode(root->rightBranch, newData);
     } else {
          root->leftBranch = insertNode(root->leftBranch, newData);
     }
     return root;
}

struct Node* searchData(struct Node* root, int targetData) {
     if(root == NULL || root->data == targetData) {
          return root;
     } else if(root->data < targetData) {
          return searchData(root->rightBranch, targetData);
     } else {
          return searchData(root->leftBranch, targetData);
     }
}

struct Node* findMaximum(struct Node* root) {
     if(root == NULL) {
          return NULL;
     } else if(root->rightBranch != NULL) {
          return findMaximum(root->rightBranch);
     }
     return root;
}

struct Node* deleteNode(struct Node* root, int data) {
     struct Node* delTemp;
     if(root == NULL) {
          return NULL;
     }
     if(data > root->data) {
          root->rightBranch = deleteNode(root->rightBranch, data);
     } else if(data < root->data) {
          root->leftBranch = deleteNode(root->leftBranch, data);
     } else {
          if(root->leftBranch == NULL && root->rightBranch == NULL) {
               free(root);
               return NULL;
          } else if(root->leftBranch == NULL || root->rightBranch == NULL) {
               if(root->leftBranch == NULL) {
                    delTemp = root->rightBranch;
               } else {
                    delTemp = root->leftBranch;
               }
               free(root);
               return delTemp;
          } else {
               delTemp = findMaximum(root->leftBranch);
               root->data = delTemp->data;
               root->leftBranch = deleteNode(root->leftBranch, delTemp->data);
          }
     }
     return root;
}

void inFixSearch(struct Node* root) {
    if(root == NULL) return;
    inFixSearch(root->leftBranch);
    printData += to_string(root->data);
    printData += " ";
    inFixSearch(root->rightBranch);
}

void preFixSearch(struct Node* root){
	if(root == NULL) return;
	printData += to_string(root->data);
    printData += " ";
	preFixSearch(root->leftBranch);
	preFixSearch(root->rightBranch);
}

void postFixSearch(struct Node* root){
	if(root == NULL) return;
	postFixSearch(root->leftBranch);
	postFixSearch(root->rightBranch);
    printData += to_string(root->data);
    printData += " ";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    struct Node* root;
    string op;
    int num;
    while(cin >> op) {
        if(op.size() == 1) {
            cin >> num;
            if(op[0] == 'I') {
                root = insertNode(root, num);
            } else if (op[0] == 'P') {
                struct Node* temp = searchData(root, num);
                if(temp != NULL) {
                    cout << num << " existe\n";
                } else {
                    cout << num << " nao existe\n";
                }
            } else if (op[0] == 'R') {
                root = deleteNode(root, num);
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
