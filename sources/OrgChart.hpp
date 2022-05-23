//
// Created by shira on 19/05/2022.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>

#pragma once
#ifndef CPP_EX5_B_VER_2_ORGCHART_H
#define CPP_EX5_B_VER_2_ORGCHART_H

#endif //CPP_EX5_B_VER_2_ORGCHART_H
using namespace std;
namespace ariel {
    class OrgChart {
    public:
        typedef struct node {
            string value;
            vector<node *> sons;
        } node;

        node root;
        vector<node*>Nodes;

        OrgChart();

        ~OrgChart();

        OrgChart &add_root(string s);

        OrgChart &add_sub(const string &s1, const string &s2);

        bool add_sub_check(const string &s1,  const string &s2, node *root);

        friend std::ostream &operator<<(std::ostream &output, const OrgChart &o);

        class level_order_Iterator {
        public:
            queue<node *> sons;
            node *_ptr;


            level_order_Iterator(node *ptr) : _ptr(ptr) {
                this->sons.push(ptr);
            }

            string &operator*() {
                return _ptr->value;
            }

            node *operator&() {
                return _ptr;
            }

            string &operator*() const {
                return _ptr->value;
            }

            string *operator->() const {
                return &(_ptr->value);
            }

            level_order_Iterator &operator++() {
                node *curr = this->sons.front();
                for (size_t i = 0; i < curr->sons.size(); ++i) {
                    this->sons.push(curr->sons.at(i));
                }
                if (this->sons.size() == 1 && sons.front()->sons.empty()) {
                    this->_ptr = nullptr;
                } else {
                    this->sons.pop();
                    this->_ptr = sons.front();
                }
                return *this;
            }


            const level_order_Iterator operator++(int) {
                level_order_Iterator tmp = *this;
                node *curr = this->sons.front();
                for (size_t i = 0; i < curr->sons.size(); ++i) {
                    this->sons.push(curr->sons.at(i));
                }
                if (this->sons.size() == 1 && sons.front()->sons.empty()) {
                    this->_ptr = nullptr;
                } else {
                    this->sons.pop();
                    this->_ptr = sons.front();
                }
                return tmp;
            }

            bool operator==(const level_order_Iterator &it) const {
                return _ptr == it._ptr;
            }

            bool operator!=(const level_order_Iterator &it) const {
                return _ptr != it._ptr;
            }
        };

        level_order_Iterator begin_level_order() {
            if (root.value != "") {
                return level_order_Iterator{&root};
            }
            throw logic_error("root is null");
        }

        level_order_Iterator end_level_order() {
            if (root.value != "") {
                return nullptr;
            }
            throw logic_error("root is null");
        }

        class preorder_Iterator {
        public:
            stack<node *> sons;
            node *_ptr;


            preorder_Iterator(node *ptr) : _ptr(ptr) {
                this->sons.push(ptr);
            }

            string &operator*() {
                return _ptr->value;
            }

            node *operator&() {
                return _ptr;
            }

            string &operator*() const {
                return _ptr->value;
            }

            string *operator->() const {
                return &(_ptr->value);
            }

            preorder_Iterator &operator++() {
                node *curr = this->sons.top();
                this->sons.pop();
                for (int i = (int) curr->sons.size() - 1; i >= 0; --i) {
                    this->sons.push(curr->sons.at((unsigned int) i));
                }
                if (this->sons.empty()) {
                    this->_ptr = nullptr;
                } else {
                    this->_ptr = sons.top();
                }
                return *this;
            }


            const preorder_Iterator operator++(int) {
                preorder_Iterator tmp = *this;
                node *curr = this->sons.top();
                this->sons.pop();
                for (int i = (int) curr->sons.size() - 1; i >= 0; --i) {
                    this->sons.push(curr->sons.at((unsigned int) i));
                }
                if (this->sons.empty()) {
                    this->_ptr = nullptr;
                } else {
                    this->_ptr = sons.top();
                }
                return tmp;
            }

            bool operator==(const preorder_Iterator &it) const {
                return _ptr == it._ptr;
            }

            bool operator!=(const preorder_Iterator &it) const {
                return _ptr != it._ptr;
            }
        };

        preorder_Iterator begin_preorder() {
            if (root.value != "") {
                return preorder_Iterator{&root};
            }
            throw logic_error("root is null");
        }

        preorder_Iterator end_preorder() {
            if (root.value != "") {
                return nullptr;
            }
            throw logic_error("root is null");
        }

        class reverse_order_Iterator {
        public:
            vector<node *> sons;
            queue<node *> my_queue;
            node *_ptr;
            int index;


            reverse_order_Iterator(node *ptr) : _ptr(ptr) {
                if (ptr == nullptr) {
                    return;
                }
                node *curr = ptr;
                my_queue.push(curr);
                while (!my_queue.empty()) {
                    for (int i = (int) my_queue.front()->sons.size() - 1; i >= 0; --i) {
                        this->my_queue.push(my_queue.front()->sons.at((unsigned int) i));
                    }
                    node *f = my_queue.front();
                    my_queue.pop();
                    sons.push_back(f);
                }
                index = sons.size() - 1;
                _ptr = this->sons.at((unsigned int) index);
            }

            string &operator*() {
                return _ptr->value;
            }

            node *operator&() {
                return _ptr;
            }

            string &operator*() const {
                return _ptr->value;
            }

            string *operator->() const {
                return &(_ptr->value);
            }

            reverse_order_Iterator &operator++() {
                index--;
                try {
                    _ptr = this->sons.at((unsigned int) index);
                }
                catch (const std::exception &e) {
                    _ptr = nullptr;
                }
                return *this;
            }


            const reverse_order_Iterator operator++(int) {
                reverse_order_Iterator tmp = *this;
                index--;
                try {
                    _ptr = this->sons.at((unsigned int) index);
                }
                catch (const std::exception &e) {
                    _ptr = nullptr;
                }
                return tmp;
            }

            bool operator==(const reverse_order_Iterator &it) const {
                return _ptr == it._ptr;
            }

            bool operator!=(const reverse_order_Iterator &it) const {
                return _ptr != it._ptr;
            }
        };

        reverse_order_Iterator begin_reverse_order() {
            if (root.value != "") {
                return reverse_order_Iterator{&root};
            }
            throw logic_error("root is null");
        }

        reverse_order_Iterator reverse_order() {
            if (root.value != "") {
                return reverse_order_Iterator{nullptr};
            }
            throw logic_error("root is null");
        }

        level_order_Iterator begin() {
            return level_order_Iterator{&root};
        }

        level_order_Iterator end() {
            return nullptr;
        }
    };
}