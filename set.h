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

        bool Equality(Set<T> *ns) {
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

        string save_to_string() {
            T *values = tree->get_values();
            string res;
            int size = tree->getSize();
            for (int i = 0; i < size; i++) {
                res += to_string(values[i]);
                res += ',';
                res += ' ';
            }
            res.pop_back();
            res.pop_back();
            return res;
        }

        Set<T> *Read_from_string(string s) {
            int ind = 0;
            Set<T> *res = new Set<T>;
            int size = s.length();
            for (int i = 0; i < size; i++) {
                //cout << '\t' << s[i] << endl;
                if (s[i] == ',') {
                    string str = s.substr(ind, i - 1);
                    if (ind != i - 1 ) {
                        cout << str << endl;
                        const char *c_str = str.c_str();
                        int a = atoi(c_str);
                        res->insert(a);
                    } else {
                        string str1;
                        str1.append(1, s[ind]);
                        const char *c_str1 = str1.c_str();
                        int d = atoi(c_str1);
                        res->insert(d);
                    }
                    ind = i + 2;
                }
            }
            string str = s.substr(ind, size - 1);
            const char *c_str = str.c_str();
            int b = atoi(c_str);
            res->insert(b);
            return res;
        }
};

#endif
