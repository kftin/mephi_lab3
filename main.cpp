#include <iostream>

typedef <typename T>
class Tree {
    private:
        struct Element {
            T value;
            ELement *rb;
            Element *lb;
            int length;
        };
        Element *root;
    public:
        bool find(T item, Element *ptr);
        void insert(T item, Element *ptr);
};

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
void Tree<T>::insert(T item, Element *ptr) {
    if (!ptr->value) {
        Element *tmp = new Element;
        tmp->value = item;
        length = 1;
    }
}

