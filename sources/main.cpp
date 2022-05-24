#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
/**
 * main file for the exercise on iterators
 *
 * @author Ohad Shirazi
 * @since 2022-05
 */
using namespace std;

#include "OrgChart.hpp"

using namespace ariel;
//int main() {
//    OrgChart organization;
//    cout<<"enter your root"<<endl;
//    string x;
//    cin>>x;
//    organization.add_root(x);
//    cout<<"enter subs till you have a error"<<endl;
//    while (1){
//        string s1;
//        cout<<"enter father"<<endl;
//        cin>>s1;
//        string s2;
//        cout<<"enter his son"<<endl;
//        cin>>s2;
//        try{
//            organization.add_sub(s1,s2);
//        }
//        catch (const std::exception &e){
//            break;
//        }
//    }
//
//    while (1){
//        string str;
//        cout<<"enter your choice for iterator:\n1- for level order\n2- for preordr\n3-for reverse order\nany other key to exit"<<endl;
//        cin>>str;
//        if (str=="1"){
//            for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it) {
//
//                cout << (*it) << " ";
//
//            }
//        }
//        else if (str=="2"){
//            for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it) {
//                cout << (*it) << " ";
//            }
//        }
//        else if (str=="3"){
//            for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it) {
//                cout << (*it) << " ";
//            }
//        }
//        else{
//            exit(1);
//        }
//    }
//    return 0;
//}




