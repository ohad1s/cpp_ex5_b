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
        this->root=NULL;
    }

    OrgChart::~OrgChart() {}


    OrgChart &OrgChart::add_root(string s) {
        this->root.value=s;
        return *this;
    }

    OrgChart &OrgChart::add_sub(string s1, string s2) {

        return *this;
    }

    std::ostream &operator<<(std::ostream &output, const OrgChart &o) {
        return output;
    }

}
