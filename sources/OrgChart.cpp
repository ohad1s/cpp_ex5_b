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

    OrgChart::~OrgChart() {}


    OrgChart &OrgChart::add_root(string s) {
        this->root.value = move(s);
        return *this;
    }

    OrgChart &OrgChart::add_sub(const string &s1, const string &s2) {
        bool b = false;
        b = add_sub_check(s1, s2, &root);
        if (b) {
            return *this;
        }
        throw std::invalid_argument("There is no such Node 'root' in the OrgChart");
//        return *this;
    }

    bool OrgChart::add_sub_check(const string &s1, const string &s2, node *root) {
        bool x = false;
        if (root->value == s1) {
            node *new_node = new node();
            new_node->value = s2;
            root->sons.push_back(new_node);
            return true;
        }
        vector<node *> sons_of_root = root->sons;
        if (!sons_of_root.empty()) {
            for (node *s: sons_of_root) {
                x = add_sub_check(s1, s2, s);
                if (x) {
                    return true;
                }
            }
        }
        return x;
    }

    std::ostream &operator<<(std::ostream &output, const OrgChart &o) {
        return output;
    }

}