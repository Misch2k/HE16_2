#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>

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

Node::~Node() {
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

    int printTree(Node *root, int height, int &index, int level, int &index2, int offset, int distance, int **ray);

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

    void printTree();

};

void BinaryTree::printTree() {
    if (root == 0) {
        cout << "TREE IS EMPTY!" << endl;
        return;
    }
    int tree_height = height();
    int index = 0;
    int index2 = 1;
    int offset = 0;
    int distance = 0;

    int x = (int) pow(2, (double) tree_height);
    int y = tree_height;
    int **ray = new int *[x];
    for (int i = 0; i < x; i++) {
        ray[i] = new int[y]{0};
    }

    do {
        offset = (int) pow(2, (double) index2 - 1) - 1;
        distance = (int) pow(2, (double) index2);
        tree_height = printTree(root, tree_height, index, 0, index2, offset, distance, ray);
        index2++;
        index = 0;
    } while (tree_height > 0);

    bool isZero = true;
    int x_offset = 0;

    for (int i = 0; i < x && isZero; i++) {
        for (int j = 0; j < y; j++) {
            int va = ray[i][j];
            if (va != 0) {
                isZero = false;
                x_offset = i;
                break;
            }
        };
    };


    for (int i = x_offset; i < x; i++) {
        cout << "==";
    }
    cout << endl;

    for (int i = 0; i < y; i++) {
        for (int j = x_offset; j < x; j++) {
            if (ray[j][i] != 0) {
                cout << setw(2) << ray[j][i];
            } else {
                cout << setw(2) << "";
            }
        };
        cout << endl;
    };

    for (int i = 0; i < x; i++) {
        delete ray[i];
    }
    delete ray;

    for (int i = x_offset; i < x; i++) {
        cout << "==";
    }
    cout << endl;
}

int BinaryTree::printTree(Node *node, int height, int &index, int level, int &index2, int offset, int distance,
                          int **ray) {
    if (level == height) return 0;
    printTree(node != 0 ? node->left : 0, height, index, level + 1, index2, offset, distance, ray);
    printTree(node != 0 ? node->right : 0, height, index, level + 1, index2, offset, distance, ray);
    offset = distance * index + offset; // x achse
    // level = y achse;
    if (level == height - 1) {
        if (node != 0) {
            ray[offset][level] = node->value;
        }
        index++;
    }
    return height - 1;
}

bool BinaryTree::hasRoot() {
    return root != 0;
};

int BinaryTree::getRootVal() const {
    if (root != 0) {
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
    if (temp == 0) {
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
        } else {
            // Parent pointer reset
            temp->parent->left == temp ? temp->parent->left = 0 : temp->parent->right = 0;
            // Delete Node;
            delete temp;
        }
    } else if (right == 0) {
        temp->value = left->value;
        remove(left);
    } else if (left == 0) {
        temp->value = right->value;
        remove(right);
    } else {
        // Next value
        /*
        if (temp->value - left->value <= right->value - temp->value) {
            // Left
            temp->value = left->value;
            remove(left);
        } else {
            // right
            temp->value = right->value;
            remove(right);
        }
         */
        // Left
        temp->value = left->value;
        remove(left);
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
    } else if (left == 0) {
        temp->value = right->value;
        remove(right);
    } else {
        if (temp->value - left->value <= right->value - temp->value) {
            // Left
            temp->value = left->value;
            remove(left);
        } else {
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

BinaryTree::BinaryTree() : root(0) {}

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
    cout << "Post Order: ";
    postOrder(root);
    cout << endl;
}

void BinaryTree::postOrder(Node *last) {
    if (last != 0) {
        //Cout hier => PreOrder
        postOrder(last->left);
        //Cout hier => InOrder
        postOrder(last->right);
        cout << last->value << (last == root ? "" : ", ");
    }
}

int main(int argc, char **argv) {

    //Aufgabe 1 - Wrong for this question. When remove 25 (root) it take 29 as a new root (value is 29 is near 25 and not 19)

    BinaryTree bt;
    vector<int> values = {25, 47, 17, 10, 19, 29, 26, 30};
    for (int i = 0; i < values.size(); i++) {
        bt.insert(values[i]);
    }
    cout << "Initial Tree" << endl;
    bt.printTree();
    cout << "Remove: 26" << endl;
    bt.remove(26);
    bt.printTree();
    cout << "Insert: 82" << endl;
    bt.insert(82);
    bt.printTree();
    cout << "Remove: 25" << endl;
    bt.remove(25);
    bt.printTree();
    cout << "Remove: 17" << endl;
    bt.remove(17);
    bt.printTree();
    bt.postOrder();

    /*
    while(bt.hasRoot()){
        bt.remove(bt.getRootVal());
        bt.printTree();
    }
*/
    return 0;
}
