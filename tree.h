#ifndef TREE
#define TREE

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Tree {
    private:
        class Element {
            public:
                T value;
                Element *rb;
                Element *lb;
        };

        //Element *root;
        //int amount;

    public:

        Element *root;
        int amount;

        Tree(T item) {
            Element *tmp = new Element;
            tmp->value = item;
            tmp->rb = nullptr;
            tmp->lb = nullptr;
            root = tmp;
            amount = 1;
        }
        Tree(T *items, int count) {
            Element *tmp = new Element;
            tmp->value = items[0];
            tmp->rb = nullptr;
            tmp->lb = nullptr;
            root = tmp;
            amount = 1;
            for (int i = 1; i < count; i++) {
                this->insert(items[i], root);
            }
        }
        bool find(T item) {
            return this->find(item, root);

        }
        bool find(T item, Element *ptr);

        Element *insert(T item, Element *ptr) {
            if (ptr == nullptr) {
                ptr = new Element;
                ptr->value = item;
                ptr->rb = nullptr;
                ptr->lb = nullptr;
                amount++;
            } else if(ptr->value == item) {
                cout << "this value is already in the tree" << endl;
            } else if (ptr->value < item) {
                ptr->rb = insert(item, ptr->rb);
            } else {
                ptr->lb = insert(item, ptr->lb);
            }
            return ptr;
        }

        Element *remove(T item, Element *ptr) {
            if (ptr == nullptr) {
                return nullptr;
            } else if (item < ptr->value) {
                ptr->lb = remove(item, ptr->lb);
                return ptr;
            } else if (item > ptr->value) {
                ptr->rb = remove(item, ptr->rb);
                return ptr;
            } else if (ptr->lb && ptr->rb) {
                Element *tmp = ptr->lb;
                Element *tmp_prev = ptr;
                int n = 0;
                while (tmp->rb != nullptr) {
                    n++;
                    tmp_prev = tmp;
                    tmp = tmp->rb;
                }
                T tmp_item = tmp->value;
                if (n) {
                    tmp_prev->rb = remove(tmp->value, tmp);
                } else {
                    tmp_prev->lb = remove(tmp->value, tmp);
                }
                ptr->value = tmp_item;
                return ptr;
            } else if (ptr->lb) {
                Element *tmp = ptr->lb;
                amount--;
                delete ptr;
                return tmp;
            } else if (ptr->rb) {
                Element *tmp = ptr->rb;
                delete ptr;
                amount--;
                return tmp;
            } else if (ptr->rb == nullptr && ptr->lb == nullptr) {
                delete ptr;
                return nullptr;
            }
            return ptr;
        }
        void remove(T item) {
            root = remove(item, root);
        }

        void print(Element *ptr);
        //void save_to_mas(T *item, int *n, Element *ptr);
        //string save_to_string();

        Element *delete_tree(Element *ptr) {
            if (ptr == nullptr) {
                return nullptr;
            }
            print(ptr->lb);
            delete ptr;
            print(ptr->rb);
        }

        void SaveToString(string &s, Element *ptr) {
            if (ptr == nullptr) {
                s += "null";
                return;
            }
            s += '(';
            SaveToString(s, ptr->lb);
            s += ',';
            s += to_string(ptr->value);
            s += ',';
            SaveToString(s, ptr->rb);
            s += ')';
        }

        string save_to_string() {
            string res = "";
            SaveToString(res, root);
            return res;
        }
};
/*
template <typename T>
string Tree<T>::save_to_string() {
    int n = 0;
    T *items = new T[amount];
    save_to_mas(items, &n, root);
    string new_string;
    for (int i = 0; i < amount; i++) {
        new_string.append(1, '0' + items[i]);
    }
    cout << "new_string: "  << new_string << endl;
    return new_string;
}

template <typename T>
void Tree<T>::save_to_mas(T *items, int *n, Element *ptr) {
    if (ptr == nullptr) {
        return;
    }
    save_to_mas(items, n, ptr->lb);
    items[(*n)] = ptr->value;
    (*n)++;
    save_to_mas(items, n, ptr->rb);
}*/

template <typename T>
void Tree<T>::print(Element *ptr) {
    if (ptr == nullptr) {
        return;
    }
    print(ptr->lb);
    cout << ptr->value << ' ';
    print(ptr->rb);
}

template <typename T>
bool Tree<T>::find(T item, Element *ptr) {
    if (ptr == nullptr) {
        return false;
    } else if (ptr->value == item) {
        return true;
    } else if (ptr->value < item) {
        return find(item, ptr->rb);
    } else {
        return find(item, ptr->lb);
    }
}

#endif
