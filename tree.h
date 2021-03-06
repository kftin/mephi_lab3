#ifndef TREE
#define TREE

#include <bits/stdc++.h>

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

        bool find(T item, Element *ptr) {
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

        Element *find_pointer(T item, Element *ptr) {
            if (ptr == nullptr) {
                return nullptr;
            } else if (ptr->value == item) {
                return ptr;
            } else if (ptr->value < item) {
                return find_pointer(item, ptr->rb);
            } else {
                return find_pointer(item, ptr->lb);
            }
        }



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

        void print(Element *ptr) {
            if (ptr == nullptr) {
                return;
            }
            print(ptr->lb);
            cout << ptr->value << ' ';
            print(ptr->rb);
        }

        void delete_tree(Element *ptr) {
            if (ptr == nullptr) {
                return;
            }
            delete_tree(ptr->lb);
            Element *tmp = ptr->rb;
            delete ptr;
            delete_tree(tmp);
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

        Element *Map(Element *ptr, function<T(const T&)> f) const {
            if (ptr == nullptr) {
                return nullptr;
            }
            auto np = new Element;
            np->value = f(ptr->value);
            np->lb = Map(ptr->lb, f);
            np->rb = Map(ptr->rb, f);
            return np;
        }

        void SubTree(Tree<T> *tree, Element *ptr) const {
            if (ptr == nullptr) {
                return;
            }
            tree->insert(ptr->value);
            if (ptr->lb) {
                SubTree(tree, ptr->lb);
            }
            if (ptr->rb) {
                SubTree(tree, ptr->rb);
            }
        }

        void Where(Tree<T> *tree, Element *ptr, function<bool(const T&)> f) const {
            if (ptr == nullptr) {
                return;
            }
            if (f(ptr->value)) {
                tree->insert(ptr->value);
            }
            if (ptr->lb) {
                Where(tree, ptr->lb, f);
            }
            if (ptr->rb) {
                Where(tree, ptr->rb, f);
            }
        }

        void GetValues(Element *ptr, T *res, int &ind) {
            if (ptr == nullptr) {
                return;
            }
            GetValues(ptr->lb, res, ind);
            res[ind] = ptr->value;
            ind++;
            GetValues(ptr->rb, res, ind);

        }

        void countNodes(Element *ptr, int &cnt) {
            if (ptr == nullptr) {
                return;
            }
            cnt++;
            countNodes(ptr->lb, cnt);
            countNodes(ptr->rb, cnt);
        }

        void Equality_trees(Element *t1, Element *t2, bool &E_B) {
            if (t1 == nullptr && t2 == nullptr) {
                return;
            } else if (t1 == nullptr && t2 != nullptr) {
                E_B = false;
                return;
            } else if (t1 != nullptr && t2 == nullptr) {
                E_B = false;
                return;
            } else if (t1->value != t2->value) {
                E_B = false;
                return;
            } else {
                Equality_trees(t1->lb, t2->lb, E_B);
                Equality_trees(t1->rb, t2->rb, E_B);
                return;
            }
        }

    public:
        
        Element *root;
        int amount;

        Tree() {
            root = nullptr;
        }
        
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

        void insert(T item) {
            root = insert(item, root);
        }

        string save_to_string() {
            string res = "";
            SaveToString(res, root);
            return res;
        }

        void delete_() {
            delete_tree(root);
        }

        void remove(T item) {
            root = remove(item, root);
        }

        void print() {
            cout << "tree: " << '\t';
            print(root);
            cout << endl;
        }

        Tree<T> *map(function<T(const T&)> f) const {
            auto newTree = new Tree<T>;
            newTree->root = Map(root, f);
            return newTree;
        }

        Tree<T> *where(function<bool(const T&)> f) const {
            auto newTree = new Tree<T>;
            Where(newTree, root, f);
            return newTree;
        }

        Tree<T> *sub_tree(Element *ptr) const {
            auto newTree = new Tree<T>;
            SubTree(newTree, ptr);
            return newTree;
        }

        T *get_values() {
            T *res = new T[this->getSize()];
            int ind = 0;
            GetValues(root, res, ind);
            return res;
        }

        int getSize() {
            int ans = 0;
            countNodes(root, ans);
            return ans;
        }

        bool equality_trees(Tree<T> *t) {
            bool e_b = true;
            Element *tmp = find_pointer(t->root->value, root);
            Equality_trees(tmp, t->root, e_b);
            return e_b;
        }
};

#endif
