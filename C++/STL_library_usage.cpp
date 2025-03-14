#include<iostream>
#include<vector>
#include <list>
#include<map>


using namespace std;


int main()
{
    vector<int> vec = {1, 2, 3};
    vec.push_back(4);
    vec.push_back(5);

    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;

    //Doubly LL
    cout << "Dobuly Linked List" << endl;
    list<int> d_ll = {10, 20, 30};
    d_ll.push_front(5); // Insert at front
    d_ll.push_back(40); // Insert at back

    for (int num : d_ll) {
        cout << num << " ";
    }
    cout << endl;


    //Map
    cout << "Map" << endl;
    map<int, string > student;
    student[0] = "Bhakti";
    student[1] = "Kavya";
    
    for (const auto &p : student) {
        std::cout << "ID: " << p.first << " Name: " << p.second << "\n";
    }
    cout << endl;


}