#include <iostream>

typedef <typename T>
class Tree {
    private:
        struct Element {
            T value;
            ELement *rb;
            Element *lb;
            //int length;
        };
        Element *root;
        int amount;
    public:
        Tree(T item) {
            Element *tmp = new Element;
            tmp->value = item;
            rb = new Element;
            rb->value = NULL;
            lb = new Element;
            lb->value = NULL;
            //length = 0;
            root = tmp;
            amount = 1;
        }
        Tree(T *items, int count) {
            Element *tmp = new Element;
            tmp->value = items[0];
            rb = new Element;
            rb->value = NULL;
            lb = new Element;
            lb->value = NULL;
            //length = 0;
            root = tmp;
            amount = 1;
            for (int i = 1; i < count; i++) {
                this->insert(items[i], root);
            }
        }
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
        //Element *tmp = new Element;
        ptr->value = item;
        ptr->rb = new Element;
        ptr->rb->value = NULL
        ptr->lb = new Element;
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
    Tree<int> *a = new Tree<int>(2);
}
