#include <bits/stdc++.h>

#include <functional>

#include "tree.h"

using namespace std;

int func(const int& a) { return a + 5; }

bool f(const int& a) { return (a > 30); }

int main() {

    cout << "Let's create a tree with 10 elements: 37 12 45 5 30 89 41 43 39 22" << endl;
    int *ptr = new int[10];
    for (int i = 0; i < 10; i++) {
        cin >> ptr[i];
    }
    Tree<int> *a = new Tree<int>(ptr, 10);

    cout << endl;
    cout << "Save to string: ";
    string str = a->save_to_string();
    cout << str << endl << endl;

    cout << "Let's remove some elements: 37(root), 45(have two children), 89(have no children), 12(have one left child)" << endl << endl;
    a->remove(37);
    a->remove(45);
    a->remove(89);
    a->remove(12);

    cout << "Let's take a look at our tree and save to string: " << endl << endl;;
    a->print();
    cout << endl;
    str = a->save_to_string();
    cout << str << endl << endl;

    cout << "Let's try to find 37: " << endl << '\t';
    cout << a->find(37) << " right. We have removed this element" << endl;
    cout << "Let's try to find 22: " << endl << '\t';
    cout << a->find(22) << " right. This element is ini place" << endl;
    cout << endl;

    delete[] ptr;


    cout << "Let's use map and add 5 to all elements: " << endl << '\t';
    auto newTree = a->map(func);
    cout << "result ";
    newTree->print();
    cout << endl;

    cout << "Let's use where with elements > 2: " << endl << '\t';
    auto nnewTree = a->where(f);
    if (!nnewTree) {
        cout << "AAAAAAAAAAAAAa" << endl;
    }
    cout << "result ";
    nnewTree->print();
    cout << endl;
    cout << nnewTree->find(5) << endl;

    a->delete_();
}
