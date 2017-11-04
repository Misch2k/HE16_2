#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>

using namespace std;

class Node {
public:
    Node *left;
    Node *right;
    int value;
    Node(int value);
    ~Node();
};

Node::Node(int value) : value(value), left(0), right(0) {
}

Node::~Node() {
    delete left;
    delete right;
};

class BinaryTree {
private:
    Node *root;
    void insert(int v, Node *n);
    int height(Node *n);
    void postOrder(Node *n);
    int sum(Node *n);
    void printLeaves(Node *n);
    deque<int> getFirstCommonAncestor(Node *n, int value, deque<int> cont);
    int getAnchestor(Node * n, int value);
public:
    BinaryTree();
    void insert(int v);
    int height();
    void postOrder();
    int sum();
    void printLeaves();
    int getAnchestor(int value);
    int getFirstCommonAncestor(int n1, int n2);
};

int BinaryTree::getAnchestor(int value){
    return getAnchestor(root, value);
};

int BinaryTree::getAnchestor(Node * n, int value){
    if(n == 0) return 0;
    if(n->left != 0 && n->left->value == value || n->right != 0 && n->right->value == value) return n->value;
    int result = 0;
    result = getAnchestor(n->left, value);
    if(result != 0) return result;
    result = getAnchestor(n->right, value);
    if(result != 0) return result;
    return result;
}

deque<int> BinaryTree::getFirstCommonAncestor(Node *n, int value, deque<int> cont) {
    if (n == 0) return cont;
    if (n->value == value) {
        cont.push_back(n->value);
        return cont;
    }
    cont = getFirstCommonAncestor(n->left, value, cont);
    if (cont.size() != 0) {
        cont.push_back(n->value);
        return cont;
    }
    cont = getFirstCommonAncestor(n->right, value, cont);
    if (cont.size() != 0) {
        cont.push_back(n->value);
        return cont;
    }

    return cont;
}

int BinaryTree::getFirstCommonAncestor(int n1, int n2) {
    deque<int> cont, cont2;
    cont = getFirstCommonAncestor(root, n1, cont);
    cont2 = getFirstCommonAncestor(root, n2, cont2);

    int last = 0;
    while (cont.size() != 0 && cont2.size() != 0 && cont.back() == cont2.back()) {
        last = cont.back();
        cont.pop_back();
        cont2.pop_back();
    }
    return last;
}

void BinaryTree::printLeaves() {
    printLeaves(root);
}

void BinaryTree::printLeaves(Node *n) {
    if (n == 0) return;
    if (n->left == 0 && n->right == 0) {
        cout << n->value << endl;
        return;
    }
    printLeaves(n->left);
    printLeaves(n->right);

}

int BinaryTree::sum() {
    return sum(root);
}

int BinaryTree::sum(Node *n) {
    if (n == 0) return 0;
    return n->value + sum(n->left) + sum(n->right);
}

void BinaryTree::insert(int v, Node *n) {
    if (v < n->value) {
        // left
        if (n->left == 0) {
            n->left = new Node(v);
        } else {
            insert(v, n->left);
        }
    } else {
        // right
        if (n->right == 0) {
            n->right = new Node(v);
        } else {
            insert(v, n->right);
        }
    }
}

void BinaryTree::insert(int v) {
    if (root == 0) {
        root = new Node(v);
    } else {
        insert(v, root);
    }
}

BinaryTree::BinaryTree() : root(0) {
}

int BinaryTree::height() {
    if (root != 0) {
        return height(root);
    } else {
        return 0;
    }

};

int BinaryTree::height(Node *n) {
    int l = 1;
    int r = 1;
    if (n->left != 0) {
        l = height(n->left) + 1;
    }
    if (n->right != 0) {
        r = height(n->right) + 1;
    }
    if (l >= r) {
        return l;
    } else {
        return r;
    }
};

void BinaryTree::postOrder() {
    postOrder(root);
}

void BinaryTree::postOrder(Node *n) {
    if (n != 0) {
        //Cout here => PreOrder
        postOrder(n->left);
        //Cout here => InOrder
        postOrder(n->right);
        //Cout here => PostOrder
        cout << n->value << endl;
    }
}

int main(int argc, char **argv) {
    time_t start, stop;
    BinaryTree bt;
    int sum = 0;
    int values[] = {30, 20, 50, 2, 29, 47, 55};
    for (int i = 0; i < 7; i++) {
        bt.insert(values[i]);
        sum += values[i];
    }

    //cout << sum << endl;
    //cout << bt.sum() << endl;
    //bt.printLeaves();

    cout << bt.getFirstCommonAncestor(2, 20) << endl;
    cout << bt.getAnchestor(2) << endl;
    return 0;
}