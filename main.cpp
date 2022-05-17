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
    Tree<int> *w = a->sub_tree(a->root->rb);
    bool e_b = a->equality_trees(w);
    cout << "Create new tree from root->rb and call function check for subtree this tree: " << e_b << endl;
    w->insert(76);
    e_b = a->equality_trees(w);
    cout << "insert 76 into the second tree and check for subtree: " << e_b << endl;

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
    cout << endl;

    cout << "Let's create two identical sets and check them for equality, elements: 5 1 13 8" << endl;
    auto set2 = new Set<int>;
    auto set3 = new Set<int>;
    set2->insert(5);
    set3->insert(5);
    set2->insert(1);
    set3->insert(1);
    set2->insert(13);
    set3->insert(13);
    set2->insert(8);
    set3->insert(8);

    cout << "first: " << endl << '\t';
    set2->print();
    cout << endl;
    cout << "second: " << endl << '\t';
    set3->print();
    cout << endl;
    cout << "Are they equal?  " << set2->Equality(set3) << "  Great!" << endl;
    cout << "Let's add element 99 at the second set and look at result again " << endl;
    set3->insert(99);
    cout << "second: " << endl << '\t';
    set3->print();
    cout << "Are they equal?  " << set2->Equality(set3) << "  OK. They aren't equal" << endl << endl;

    cout << "Now, let's check if the first without 99 is a subset of the second: " << set2->Subset(set3) << " Yes! We WON!!!" << endl;

    cout << "Let's save to string our set: " << endl << '\t';
    string str1 = set2->save_to_string();
    cout << str1 << endl;

    cout << "And now read from string our set: " << endl << '\t';
    auto set4 = set2->Read_from_string(str1);
    set4->print();
    cout << endl;
    cout << "insert element 6 and save to string again" << endl;
    set4->insert(6);
    string str2 = set4->save_to_string();
    cout << str2 << endl;

}
