//
// Created by shira on 19/05/2022.
//
#include "OrgChart.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>


namespace ariel {
    OrgChart::OrgChart() {
    }

    OrgChart::~OrgChart() {
        for(node* n: this->Nodes){
            delete n;
        }
    }


    OrgChart &OrgChart::add_root(string s) {
//        check empty string or other invalid string input
        if (s.empty() || s== " " || s== "\n" || s=="\t" || s=="\r"){
            throw invalid_argument("invalid string for root");
        }
        this->root.value = move(s);
        return *this;
    }

    OrgChart &OrgChart::add_sub(const string &s1, const string &s2) {
        if (s2.empty() || s2== " " || s2== "\n" || s2=="\t" || s2=="\r"){
            throw invalid_argument("invalid string for son");
        }
        if (s1.empty() || s1== " " || s1== "\n" || s1=="\t" || s1=="\r"){
            throw invalid_argument("invalid string for father");
        }
        bool b = false;
        b = add_sub_check(s1, s2, &root);
        if (b) {
            return *this;
        }
        throw std::invalid_argument("There is no such Node 'root' in the OrgChart");
//        return *this;
    }

    bool OrgChart::add_sub_check(const string &s1, const string &s2, node *root) {
//        recursive method to check if s1 is in the OrgChart
        bool x = false;
//        check if its the node itself
        if (root->value == s1) {
            node *new_node = new node();
            new_node->value = s2;
            root->sons.push_back(new_node);
            this->Nodes.push_back(new_node);
            return true;
        }
        //        check if its one of the children of node
        vector<node *> sons_of_root = root->sons;
        if (!sons_of_root.empty()) {
            for (node *s: sons_of_root) {
                x = add_sub_check(s1, s2, s);
                if (x) {
                    return true;
                }
            }
        }
//        else s1 its not in the OrgChart
        return x;
    }

    std::ostream &operator<<(std::ostream &output, const OrgChart &o){
        output<<"To see Your OrgChart You can go to one of the iterators!!!!";
        return output;
    }

}