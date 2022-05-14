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

    auto set1 = new Set<int>;

    cout << "Let's create two sets on trees from elements:" << endl << '\t';
    cout << "first set: 37 12 45 5 30 41 89" << endl << '\t';
    set->insert(37);
    set->insert(12);
    set->insert(45);
    set->insert(5);
    set->insert(30);
    set->insert(41);
    set->insert(89);
    set->print();
    cout << endl << '\t';

    cout << "second set: 30 31 20 72 1 5" << endl << '\t';
    set1->insert(30);
    set1->insert(31);
    set1->insert(20);
    set1->insert(72);
    set1->insert(1);
    set1->insert(5);
    set1->print();
    cout<< endl;

    cout << "Let's connect these sets" << endl << '\t';
    set->unionSets(set1);
    set->print();

    set->remove(31);
    set->remove(20);
    set->remove(72);
    set->remove(1);

    cout << "Let's intersection of these sets" << endl << '\t';
    set->intersect(set1);
    set->print();

    set->insert(37);
    set->insert(12);
    set->insert(45);
    set->insert(41);
    set->insert(89);

    cout << "Let's subtract the second from the first" << endl << '\t';
    set->subtract(set1);
    set->print();
}
