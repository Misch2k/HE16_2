#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Node {
public:
    Node *parent;
    Node *left;
    Node *right;
    int value;

    Node(int value);
    Node(int value, Node *parent);
    ~Node();
    static int counter;
};

int Node::counter = 0;

Node::Node(int value) : value(value), parent(0), left(0), right(0) {
    counter++;
}

Node::Node(int value, Node *parent) : value(value), parent(parent), left(0), right(0) {
    counter++;
};

Node::~Node(){
    delete left;
    delete right;
    counter--;
};

class BinaryTree {
private:
    Node *root;

    void insert(int v, Node *n);
    bool find(Node *last, int value);
    Node *findNode(Node *last, int value);
    Node *minRight(Node *last);
    Node *minLeft(Node *last);
    int height(Node *last);
    void postOrder(Node *last);
    void remove(Node *temp);

public:
    BinaryTree();
    void insert(int v);
    bool find(int value);
    Node *findNode(int value);
    int height();
    void remove(int value);
    void postOrder();
    bool hasRoot();
    int getRootVal() const;
};

bool BinaryTree::hasRoot() {
    return root != 0;
};

int BinaryTree::getRootVal() const {
    if(root != 0){
        return root->value;
    }
    return 0;
};
void BinaryTree::insert(int v, Node *n) {
    if (v < n->value) {
        // left
        if (n->left == 0) {
            n->left = new Node(v, n);
        } else {
            insert(v, n->left);
        }
    } else {
        // right
        if (n->right == 0) {
            n->right = new Node(v, n);
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

void BinaryTree::remove(int value) {
    Node *temp = findNode(value);
    if (temp == 0){
        cout << "Value: " << value << " : NOT FOUND" << endl;
        return;
    }
    Node *left = minLeft(temp->left);
    Node *right = minRight(temp->right);
    // Leave
    if (left == 0 && right == 0) {
        if (temp->parent == 0) {
            delete root;
            root = 0;
        }else {
            // Parent pointer reset
            temp->parent->left == temp ? temp->parent->left = 0 : temp->parent->right = 0;
            // Delete Node;
            delete temp;
        }
    } else if (right == 0) {
        temp->value = left->value;
        remove(left);
    } else if (left == 0){
        temp->value = right->value;
        remove(right);
    }else{
        if(temp->value - left->value <= right->value - temp->value){
            // Left
            temp->value = left->value;
            remove(left);
        }else{
            // right
            temp->value = right->value;
            remove(right);
        }
    }
}


void BinaryTree::remove(Node *temp) {
    if (temp == 0) {
        cout << "remove Error" << endl;
        return;
    }
    Node *left = minLeft(temp->left);
    Node *right = minRight(temp->right);
    // Leave
    if (left == 0 && right == 0) {
        if (temp->parent == 0) {
            delete root;
            root = 0;
        }
        // Parent pointer reset
        temp->parent->left == temp ? temp->parent->left = 0 : temp->parent->right = 0;
        // Delete Node;
        delete temp;
    } else if (right == 0) {
        temp->value = left->value;
        remove(left);
    } else if (left == 0){
        temp->value = right->value;
        remove(right);
    }else{
        if(temp->value - left->value <= right->value - temp->value){
            // Left
            temp->value = left->value;
            remove(left);
        }else{
            // right
            temp->value = right->value;
            remove(right);
        }
    }
}



Node *BinaryTree::minRight(Node *last) {
    if (last == 0) return 0;
    if (last->left == 0) {
        return last;
    } else {
        return minRight(last->left);
    }

}

Node *BinaryTree::minLeft(Node *last) {
    if (last == 0) return 0;
    if (last->right == 0) {
        return last;
    } else {
        return minLeft(last->right);
    }
}


bool BinaryTree::find(int value) {
    return find(root, value);
}

bool BinaryTree::find(Node *last, int value) {
    if (last == 0) return false;
    if (last->value == value) {
        return true;
    }
    if (last->value > value) {
        return find(last->left, value);
    } else {
        return find(last->right, value);
    }
}

Node *BinaryTree::findNode(int value) {
    return findNode(root, value);
}

Node *BinaryTree::findNode(Node *last, int value) {
    if (last == 0) return 0;
    if (last->value == value) {
        return last;
    }
    if (last->value > value) {
        return findNode(last->left, value);
    } else {
        return findNode(last->right, value);
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

void BinaryTree::postOrder() {
    postOrder(root);
}

void BinaryTree::postOrder(Node *last) {
    if (last != 0) {
        //Cout hier => PreOrder
        postOrder(last->left);
        //Cout hier => InOrder
        postOrder(last->right);
        cout << last->value << endl;
    }
}


int main(int argc, char **argv) {
    time_t start, stop;
    BinaryTree bt;
    /*int values[] = {50, 25, 75, 14, 7, 19, 63, 89, 99, 79};
    for (int i = 0; i < 10; i++) {
        bt.insert(values[i]);
    }*/

    //Aufgabe 1 - Wrong for this question. When remove 25 (root) it take 29 as a new root (value is 29 is near 25 and not 19)
    bt.insert(25);
    bt.insert(47);
    bt.insert(17);
    bt.insert(10);
    bt.insert(19);
    bt.insert(29);
    bt.insert(26);
    bt.insert(30);
    bt.remove(26);
    bt.insert(82);
    bt.remove(25);
    bt.remove(17);
    bt.postOrder();




    /*
    start = clock();
    while(Node::counter < 1000000){
        bt.insert(rand());
    }
    stop = clock();
    cout << "Time to fill: " << ((double)(stop-start)/CLOCKS_PER_SEC) << "ms" << endl;
    cout << "Tree hat " << Node::counter << " elemente" << endl;
    cout << "The hight of this tree is " << bt.height() << endl;

    start = clock();
    while(bt.hasRoot()){
        //cout << "delete: " << bt.getRootVal() << endl;
        bt.remove(bt.getRootVal());
    }
    stop = clock();
    cout << "Time to delete: " << ((double)(stop-start)/CLOCKS_PER_SEC) << "ms" << endl;
*/

    //cout << bt.height() << endl;
    //bt.postOrder();



    return 0;
}
