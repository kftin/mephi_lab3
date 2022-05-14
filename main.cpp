#include <bits/stdc++.h>

#include <functional>

#include "tree.h"
#include "set.h"

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

    cout << "Let's try to extract subtree from our tree from element 43 (we have to get tree 43 41 39): " << endl << '\t';
    auto nnnewTree = a->sub_tree(a->root->rb);
    cout << "result ";
    nnnewTree->print();
    cout << endl;
    nnnewTree->delete_();

    delete[] ptr;


    cout << "Let's use map and add 5 to all elements: " << endl << '\t';
    auto newTree = a->map(func);
    cout << "result ";
    newTree->print();
    cout << endl;
    newTree->delete_();

    cout << "Let's use where with elements > 30: " << endl << '\t';
    auto nnewTree = a->where(f);
    cout << "result ";
    nnewTree->print();
    cout << endl;
    cout << nnewTree->find(5) << endl;
    nnewTree->delete_();

    auto set = new Set<int>;
    set->insert(37);
    set->insert(12);
    set->insert(45);
    set->insert(5);
    set->insert(30);
    set->insert(41);
    set->insert(89);

    auto set1 = new Set<int>;
    set->insert(31);
    set->insert(20);
    set->insert(72);
    set->insert(1);

    set->unionSets(set1);
    set->print();

    a->delete_();
}
