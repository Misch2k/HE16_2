#include <iostream>
#include "linkedList.h"
#include <ctime>

using namespace std;

class A {
public:
    int a;

    A(int a) : a(a) {};

    ~A() {
        cout << "~A" << endl;
    }
};

class B : public A {
public:
    int a;

    B(int a) : A(a - 1), a(a) {
        cout << "A" << endl;
    };

    ~B() {
        cout << "~B" << endl;
    }
};


int crosssum(unsigned int n) {
    int result = 0;
    if (n == 0) return 0;
    result += n % 10 + crosssum(n / 10);
    return result;
}

template<class T>
int LinkedList<T>::deleteEvenNumbers() {
    int deleteCounter = 0;
    Node<T> *toDelete;

    while (head != 0 && head->value % 2 == 0) {
        toDelete = head;
        head = head->next;
        if (head == 0) {
            tail = 0;
        }
        delete toDelete;
        deleteCounter++;
        count--;

    }

    if (head != 0) {
        Node<T> *temp = head;
        while (temp->next != 0) {
            if (temp->next->value % 2 == 0) {
                toDelete = temp->next;
                temp->next = toDelete->next;
                if (temp->next == 0) {
                    tail = temp;
                }
                deleteCounter++;
                delete toDelete;
            } else {
                temp = temp->next;
            }

        }
    }

    return deleteCounter;
};


int main() {
    clock_t start, stop;
    bool ok = true;
    A *obj = new B(5);
    obj->a++;
    cout << obj->a << endl;
    delete obj;

    Collection<int> *linkedlist = new LinkedList<int>;

    start = clock();
    for (long long i = 0; i < 10000; i++) {
        linkedlist->add(2);
    }
    linkedlist->add(2);
    linkedlist->add(2);
    linkedlist->add(2);
    linkedlist->add(2);
    linkedlist->add(2);
    cout << "Erstellen der Linked List: " << (double) (clock() - start) / CLOCKS_PER_SEC << "ms" << endl;

    start = clock();
    cout << linkedlist->deleteEvenNumbers() << " Elemente wurden geloescht" << endl;
    cout << "Löschen der geraden Elemente: " << (double) (clock() - start) / CLOCKS_PER_SEC << "ms" << endl;

    cout << *linkedlist << endl;


    cout << crosssum(123456) << endl;
}