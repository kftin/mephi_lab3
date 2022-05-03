#include <iostream>

using namespace std;

template <typename T>
class Tree {
    private:
        class Element {
            public:
                T value;
                Element *rb;
                Element *lb;
                Element *parent;
                //int length;
        };

        //Element *root;
        //int amount;

    public:

        Element *root;
        int amount;

        Tree(T item) {
            Element *tmp = new Element;
            tmp->parent = NULL;
            tmp->value = item;

            tmp->rb = new Element;
            tmp->rb->parent = tmp;
            tmp->rb->value = NULL;

            tmp->lb = new Element;
            tmp->lb->parent = tmp;
            tmp->lb->value = NULL;

            //length = 0;
            root = tmp;
            amount = 1;
        }
        Tree(T *items, int count) {
            Element *tmp = new Element;
            tmp->parent = NULL;
            tmp->value = items[0];
            //cout << items[0] << endl;

            tmp->rb = new Element;
            tmp->rb->parent = tmp;
            tmp->rb->value = NULL;

            tmp->lb = new Element;
            tmp->lb->parent = tmp;
            tmp->lb->value = NULL;

            //length = 0;
            root = tmp;
            amount = 1;
            for (int i = 1; i < count; i++) {
                this->insert(items[i], root);
                //cout << items[i] << endl;
            }
        }
        bool find(T item, Element *ptr);
        void *find_pointer(T item, Element *ptr);
        void insert(T item, Element *ptr);
        void remove(T item, Element *ptr);
        void print(Element *ptr);
};

template <typename T>
void Tree<T>::print(Element *ptr) {
    if (!ptr->value) {
        return;
    }
    print(ptr->lb);
    cout << ptr->value << ' ';
    print(ptr->rb);
}

template <typename T>
bool Tree<T>::find(T item, Element *ptr) {
    if (!ptr->value) {
        return false;
    } else if (ptr->value == item) {
        return true;
    } else if (ptr->value < item) {
        return find(item, ptr->rb);
    } else {
        return find(item, ptr->lb);
    }
}

template <typename T>
void *Tree<T>::find_pointer(T item, Element *ptr) {
    if (!ptr->value) {
        cout << "no element to remove" << endl;
        return NULL;
    } else if (ptr->value == item) {
        return ptr;
    } else if (ptr->value < item) {
        return find_pointer(item, ptr->rb);
    } else {
        return find_pointer(item, ptr->lb);
    }
}

template <typename T>
void Tree<T>::remove(T item, Element *ptr) {
    Element *tmp = (Element *)this->find_pointer(item, ptr);
    if (tmp) {
        if (!tmp->lb->value) {
            if (!tmp->rb->value) {
                delete tmp->rb;
                delete tmp->lb;
                if (tmp != this->root) {
                    if (tmp->parent) {
                        if (item < tmp->parent->value) {
                            tmp->parent->lb = new Element;
                            tmp->parent->lb->parent = tmp->parent;
                            tmp->parent->lb->value = NULL;
                        } else if (item > tmp->parent->value) {
                            tmp->parent->rb = new Element;
                            tmp->parent->rb->parent = tmp->parent;
                            tmp->parent->rb->value = NULL;
                        }
                    }
                }
                delete tmp;
                this->amount--;
            } else {
                delete tmp->lb;
                tmp->rb->parent = tmp->parent;
                if (this->root == tmp) {
                    this->root = tmp->rb;
                } else {
                    if (tmp->value < tmp->parent->value) {
                        tmp->parent->lb = tmp->rb;
                    } else if (tmp->value > tmp->parent->value) {
                        tmp->parent->rb = tmp->rb;
                    }
                }
                delete tmp;
                this->amount--;
            }
        } else if (!tmp->rb->value) {
            delete tmp->rb;
            tmp->lb->parent = tmp->parent;
            if (this->root != tmp) {
                if (tmp->value < tmp->parent->value) {
                    tmp->parent->lb = tmp->lb;
                } else if (tmp->value > tmp->parent->value) {
                    tmp->parent->rb = tmp->lb;
                }
            } else {
                this->root = tmp->lb;
            }
            delete tmp;
            this->amount--;
        } else {
            Element *new_tmp = tmp->lb;
            while (new_tmp->rb->value) {
                new_tmp = new_tmp->rb;
            }
            T v = new_tmp->value;
            //tmp->value = new_tmp->value;
            this->remove(new_tmp->value, new_tmp);
            tmp->value = v;
        }
    }
}

template <typename T>
void Tree<T>::insert(T item, Element *ptr) {
    if (!ptr->value) {
        //Element *tmp = new Element;
        ptr->value = item;

        ptr->rb = new Element;
        ptr->rb->parent = ptr;
        ptr->rb->value = NULL;

        ptr->lb = new Element;
        ptr->lb->parent = ptr;
        ptr->lb->value = NULL;

        this->amount++;
        // length = 1;
    } else if(ptr->value == item) {
      cout << "this value is already in the tree" << endl;  
    } else if (ptr->value < item) {
        insert(item, ptr->rb);
    } else {
        insert(item, ptr->lb);
    }
}

int main() {
    
    int *ptr = new int[6];
    for (int i = 0; i < 6; i++) {
        cin >> ptr[i];
    }
    Tree<int> *a = new Tree<int>(ptr, 6);

    cout << "tree: " << endl << '\t';
    a->print(a->root);
    cout << endl;

    delete[] ptr;

    cout << "find before remove: " <<  a->find(1, a->root) << a->find(2, a->root) << a->find(3, a->root) << a->find(4, a->root) << a->find(5, a->root) << a->find(6, a->root) << endl;
    
    a->remove(1, a->root);
    cout << "find after remove '1' : " <<  a->find(1, a->root) << a->find(2, a->root) << a->find(3, a->root) << a->find(4, a->root) << a->find(5, a->root) << a->find(6, a->root) << endl;
    cout << "tree after remove '1' : " << endl << '\t';
    a->print(a->root);
    cout << endl;

    a->insert(1, a->root);
    a->insert(7, a->root);
    cout << "find after insert '1' '7'  : " <<  a->find(1, a->root) << a->find(2, a->root) << a->find(3, a->root) << a->find(4, a->root) << a->find(5, a->root) << a->find(6, a->root) << a->find(7, a->root) << endl;
    cout << "tree after insert '1' '7' : " << endl << '\t';
    a->print(a->root);
    cout << endl;

    a->remove(6, a->root);
    cout << "find after remove '6' : " <<  a->find(1, a->root) << a->find(2, a->root) << a->find(3, a->root) << a->find(4, a->root) << a->find(5, a->root) << a->find(6, a->root) << a->find(7, a->root) << endl;
    cout << "tree after remove '6' : " << endl << '\t';
    a->print(a->root);
    cout << endl;


    delete a;


/*
    Tree<int> *b = new Tree<int>(2);
    cout << "tree: " << endl << '\t';
    b->print(b->root);
    cout << endl;
    cout << "find before remove: " << b->find(2, b->root) << endl;  ////проверка удаления дерева из одного элемента
    b->remove(2, b->root);
    delete b;
*/
}
