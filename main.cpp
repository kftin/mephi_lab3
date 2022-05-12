#include <iostream>

#include "tree.h"

using namespace std;

int main() {
    
    int *ptr = new int[6];
    for (int i = 0; i < 6; i++) {
        cin >> ptr[i];
    }
    Tree<int> *a = new Tree<int>(ptr, 6);
    //cout << a->root->rb->value << "  root->rb " << endl;

    cout << "tree: " << endl << '\t';
    a->print(a->root);
    cout << endl;

    delete[] ptr;

    cout << "find before remove: " <<  a->find(1, a->root) << a->find(2, a->root) << a->find(3, a->root) << a->find(4, a->root) << a->find(5, a->root) << a->find(6, a->root) << endl;
   
    a->remove(4);

    cout << "find after remove '4' - root: " <<  a->find(1, a->root) << a->find(2, a->root) << a->find(3, a->root) << a->find(4, a->root) << a->find(5, a->root) << a->find(6, a->root) << endl;
    cout << "tree after remove '4' - root: " << endl << '\t';
    a->print(a->root);
    cout << endl;

    a->remove(6);
    cout << "find after remove '6': " <<  a->find(1, a->root) << a->find(2, a->root) << a->find(3, a->root) << a->find(4, a->root) << a->find(5, a->root) << a->find(6, a->root) << endl;
    cout << "tree after remove '6': " << endl << '\t';
    a->print(a->root);
    cout << endl;
    
    a->insert(7, a->root);
    a->insert(6, a->root);
    cout << "find after insert '7' '6'  : " <<  a->find(1, a->root) << a->find(2, a->root) << a->find(3, a->root) << a->find(4, a->root) << a->find(5, a->root) << a->find(6, a->root) << a->find(7, a->root) << endl;
    cout << "tree after insert '7' '6' : " << endl << '\t';
    a->print(a->root);
    cout << endl;

    a->remove(5);
    cout << "find after remove '5' : " <<  a->find(1, a->root) << a->find(2, a->root) << a->find(3, a->root) << a->find(4, a->root) << a->find(5, a->root) << a->find(6, a->root) << a->find(7, a->root) << endl;
    cout << "tree after remove '5' : " << endl << '\t';
    a->print(a->root);
    cout << endl;

    delete a;
}
