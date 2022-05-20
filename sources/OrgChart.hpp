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

#pragma once
#ifndef CPP_EX5_B_ORGCHART_H
#define CPP_EX5_B_ORGCHART_H

#endif //CPP_EX5_B_ORGCHART_H
using namespace std;
namespace ariel {
    class OrgChart {
    public:
        typedef struct node {
            string value;
            node* brother;
            node* son;
        } node;

        node *root;

        OrgChart();

        ~OrgChart();

        OrgChart &add_root(string s);

        OrgChart &add_sub(string s1, string s2);

        friend std::ostream &operator<<(std::ostream &output, const OrgChart &o);

        class level_order_Iterator {
        public:
            queue<node*>brothers;
            queue<node*>sons;
            node *_ptr;

            level_order_Iterator(node *ptr) : _ptr(ptr) {
                this->brothers.push(ptr);
            }

            string &operator*() {
                return _ptr->value;
            }
            node* operator&(){
                return _ptr;
            }

            string& operator*() const {
                return _ptr->value;
            }

            string* operator->() const {
                return &(_ptr->value);
            }
            level_order_Iterator &operator++() {
                node* bro=this->brothers.front()->brother;
                node* son=this->sons.front()->son;
                if (bro!= nullptr){
                    brothers.push(bro);
                }
                if(son!= nullptr){
                    sons.push(son);
                }
                brothers.pop();
                if (brothers.empty()){
                    node* n=sons.front();
                    sons.pop();
                    brothers.push(n);
                }
                _ptr=brothers.front();
                return *this;
            }
            const level_order_Iterator operator++(int) {
                level_order_Iterator tmp= *this;
                node* bro=this->brothers.front()->brother;
                node* son=this->sons.front()->son;
                if (bro!= nullptr){
                    brothers.push(bro);
                }
                if(son!= nullptr){
                    sons.push(son);
                }
                brothers.pop();
                if (brothers.empty()){
                    node* n=sons.front();
                    sons.pop();
                    brothers.push(n);
                }
                _ptr=brothers.front();
                return tmp;
            }
            bool operator==(const level_order_Iterator& it) const {
                return _ptr == it._ptr;
            }

            bool operator!=(const level_order_Iterator& it) const {
                return _ptr != it._ptr;
            }
        };
        level_order_Iterator begin_level_order(){
            return level_order_Iterator{root};
        }
        level_order_Iterator end_level_order(){
            return nullptr;
        }
        class preorder_Iterator {
        public:
            node *_ptr;
            stack<node*>brothers;
            queue<node*>sons;

            preorder_Iterator(node *ptr) : _ptr(ptr) {
                this->sons.push(ptr);
            }

            string &operator*() {
                return _ptr->value;
            }

            node* operator&(){
                return _ptr;
            }

            string& operator*() const {
                return _ptr->value;
            }

            string* operator->() const {
                return &(_ptr->value);
            }
            preorder_Iterator &operator++() {
                node* bro=this->brothers.top()->brother;
                node* son=this->sons.front()->son;
                if (bro!= nullptr){
                    brothers.push(bro);
                }
                if(son!= nullptr){
                    sons.push(son);
                }
                sons.pop();
                if (sons.empty()){
                    node* n=brothers.top();
                    sons.pop();
                    brothers.push(n);
                }
                _ptr=sons.front();
                return *this;
            }
            const preorder_Iterator operator++(int) {
                preorder_Iterator tmp= *this;
                node* bro=this->brothers.top()->brother;
                node* son=this->sons.front()->son;
                if (bro!= nullptr){
                    brothers.push(bro);
                }
                if(son!= nullptr){
                    sons.push(son);
                }
                sons.pop();
                if (sons.empty()){
                    node* n=brothers.top();
                    sons.pop();
                    brothers.push(n);
                }
                _ptr=sons.front();
                return tmp;
            }
            bool operator==(const preorder_Iterator& it) const {
                return _ptr == it._ptr;
            }

            bool operator!=(const preorder_Iterator& it) const {
                return _ptr != it._ptr;
            }
        };
        preorder_Iterator begin_preorder(){
            return preorder_Iterator{root};
        }
        preorder_Iterator end_preorder(){
            return nullptr;
        }

        preorder_Iterator(node *ptr) : _ptr(ptr) {
                this->sons.push(ptr);
        }

        string &operator*() {
            return _ptr->value;
        }

        node* operator&(){
            return _ptr;
        }

        string& operator*() const {
            return _ptr->value;
        }

        string* operator->() const {
            return &(_ptr->value);
        }
        preorder_Iterator &operator++() {
            node* bro=this->brothers.top()->brother;
            node* son=this->sons.front()->son;
            if (bro!= nullptr){
                brothers.push(bro);
            }
            if(son!= nullptr){
                sons.push(son);
            }
            sons.pop();
            if (sons.empty()){
                node* n=brothers.top();
                sons.pop();
                brothers.push(n);
            }
            _ptr=sons.front();
            return *this;
        }
        const preorder_Iterator operator++(int) {
            preorder_Iterator tmp= *this;
            node* bro=this->brothers.top()->brother;
            node* son=this->sons.front()->son;
            if (bro!= nullptr){
                brothers.push(bro);
            }
            if(son!= nullptr){
                sons.push(son);
            }
            sons.pop();
            if (sons.empty()){
                node* n=brothers.top();
                sons.pop();
                brothers.push(n);
            }
            _ptr=sons.front();
            return tmp;
        }
        bool operator==(const preorder_Iterator& it) const {
            return _ptr == it._ptr;
        }

        bool operator!=(const preorder_Iterator& it) const {
            return _ptr != it._ptr;
        }
    };
    preorder_Iterator begin_preorder(){
        return preorder_Iterator{root};
    }
    preorder_Iterator end_preorder(){
        return nullptr;
    }

    };
}