#include <iostream>
#include <stack>

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value):
        value(value), left(nullptr), right(nullptr) {}
};

void preOrderRecur(Node* head) {
    if (head == nullptr) {
        return;
    }
    std::cout << head->value << ",";
    preOrderRecur(head->left);
    preOrderRecur(head->right);
}

void inOrderRecur(Node* head) {
    if (head == nullptr) {
        return;
    }
    inOrderRecur(head->left);
    std::cout << head->value << ",";
    inOrderRecur(head->right);
}

void posOrderRecur(Node* head) {
    if (head == nullptr) {
        return;
    }
    posOrderRecur(head->left);
    posOrderRecur(head->right);
    std::cout << head->value << ",";
}

void preOrderUnRecur(Node* head) {
    if (head == nullptr) {
        return;
    }
    std::stack<Node*> nstack;
    nstack.push(head);
    while(!nstack.empty()) {
        Node* head = nstack.top();  // get stack top
        std::cout << head->value << ",";
        nstack.pop();
        if (head->right != nullptr) {
            nstack.push(head->right);
        }
        if (head->left != nullptr) {
            nstack.push(head->left);
        }
    }
}

void inOrderUnRecur(Node* head) {
    if (head == nullptr) {
        return;
    }
    std::stack<Node*> nstack;
    while (!nstack.empty() || head != nullptr) {
        if (head != nullptr) {
            nstack.push(head);
            head = head->left;
        } else {
            head = nstack.top();
            std::cout << head->value << ",";
            nstack.pop();
            head = head->right;
        }
    }
}

void posOrderUnRecur(Node* head) {
    if (head == nullptr) {
        return;
    }
    std::stack<Node*> nstack1, nstack2;
    nstack1.push(head);
    while (!nstack1.empty()) {
        Node* head = nstack1.top();
        nstack2.push(head);
        nstack1.pop();
        if (head->left != nullptr) {
            nstack1.push(head->left);
        }
        if (head->right != nullptr) {
            nstack1.push(head->right);
        }
    }

    while (!nstack2.empty()) {
        std::cout << nstack2.top()->value << ",";
        nstack2.pop();
    }
}
int main() {
    Node* head = new Node(5);
    head->left = new Node(3);
    head->right = new Node(8);
    head->left->left = new Node(2);
    head->left->right = new Node(4);
    head->right->left = new Node(7);
    head->right->right = new Node(10);
    head->right->left->left = new Node(6);
    head->right->right->left = new Node(9);
    head->right->right->right = new Node(11);

    std::cout << "==============recursive==============";
    std::cout << "\npre-order: ";
    preOrderRecur(head);
    std::cout << "\nin-order: ";
    inOrderRecur(head);
    std::cout << "\npos-order: ";
    posOrderRecur(head);
    std::cout << "\n==============un-recursive==============";
    std::cout << "\npre-order: ";
    preOrderUnRecur(head);
    std::cout << "\nin-order: ";
    inOrderUnRecur(head);
    std::cout << "\npos-order: ";
    posOrderUnRecur(head);
    return 0;
}

