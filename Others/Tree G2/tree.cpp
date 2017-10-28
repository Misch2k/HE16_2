#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
public:
    Node *left;
    Node *right;
    int value;

    Node(int value);
};

Node::Node(int value) : value(value), left(0), right(0) {
}

class BinaryTree {
private:
    Node *root;

    void insert(int v, Node *n);

public:
    BinaryTree();
    void insert(int v);
    int height();
    int height(Node *last);
    void postOrder();
    void postOrder(Node *last);
};

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

int BinaryTree::height(Node *last) {
    int l = 1;
    int r = 1;
    if (last->left != 0) {
        l = height(last->left) + 1;
    }
    if (last->right != 0) {
        r = height(last->right) + 1;
    }
    if (l >= r) {
        return l;
    } else {
        return r;
    }
};

void BinaryTree::postOrder(){
    postOrder(root);
}

void BinaryTree::postOrder(Node * last){
    if (last != 0) {
        //Cout hier => PreOrder
        postOrder(last->left);
        //Cout hier => InOrder
        postOrder(last->right);
        cout << last->value << endl;
    }
}

int main(int argc, char **argv) {
    BinaryTree bt;
    int values[] = {50, 25, 75, 14, 7, 19, 63, 89, 99, 79};
    for (int i = 0; i < 10; i++) {
        bt.insert(values[i]);
    }

    //cout << bt.height() << endl;
    bt.postOrder();
    return 0;
}
