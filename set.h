#ifndef SET
#define SET

#include "tree.h"

template <typename T>
class Set {
    //private:
        //Tree<T> *tree;

    public:
        Tree<T> *tree;

        Set() { tree = new Tree<T>; }

        void insert(T item) {
            tree->insert(item);
        }

        void remove(T item) {
            tree->remove(item);
        }

        bool find(T item) {
            return tree->find(item);
        }

        void print() {
            tree->print();
        }

        string save_to_string() {
            return tree->save_to_string();
        }

        Set<T> *map(function<T(const T&)> f) {
            auto newTree = tree->map(f);
            auto newSet = new Set<T>;
            newSet->tree = newTree;
        }

        Set<T> *where(function<T(const T&)> f) {
            auto newTree = tree->where(f);
            auto newSet = new Set<T>;
            newSet->tree = newTree;
        }

        void unionSets(Set<T> *ns) {
            T *values = ns->tree->get_values();
            int size = ns->tree->getSize();
            for (int i = 0; i < size; i++) {
                if(!tree->find(values[i])) {
                    tree->insert(values[i]);
                }
            }
        }

        void intersect(Set<T> *ns) {
            T *values = tree->get_values();
            int size = tree->getSize();
            for (int i = 0; i < size; i++) {
                if(!ns->find(values[i])) {
                    tree->remove(values[i]);
                }
            }
        }

        void subtract(Set<T> * ns) {
            T *values = tree->get_values();
            int size = tree->getSize();
            for (int i = 0; i < size; i++) {
                if (ns->find(values[i])) {
                    tree->remove(values[i]);
                }
            }
        }

        bool Subset(Set<T> *ns) {
            T *values = tree->get_values();
            int size = tree->getSize();
            for (int i = 0; i < size; i++) {
                if (!ns->find(values[i])) {
                    return false;
                }
            }
            return true;
        }

        bool Equal(Set<T> *ns) {
            T *values1 = tree->get_values();
            int size1 = tree->getSize();
            T *values2 = ns->tree->get_values();
            int size2 = ns->tree->getSize();
            if (size1 != size2) {
                return false;
            }
            for (int i = 0; i < size1; i++) {
                if (values1[i] != values2[i]) {
                    return false;
                }
            }
            return true;
        }


};

#endif
