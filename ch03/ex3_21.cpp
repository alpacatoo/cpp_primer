#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;

void my_print(const vector<int> &v)
{
    cout << "Size: " << v.size() << " Context: [";
    for (auto begin = v.begin(); begin != v.end(); begin++)
        cout << *begin << (begin != v.end() - 1 ? "," : "");
    cout << "]" << endl;
}

void my_print(const vector<string> &v)
{
    cout << "Size: " << v.size() << " Context: [";
    for (auto begin = v.begin(); begin != v.end(); begin++)
        cout << *begin << (begin != v.end() - 1 ? "," : "");
    cout << "]" << endl;
}

int main()
{
    vector<int> v1;         // size:0,  no values.
    vector<int> v2(10);     // size:10, value:0
    vector<int> v3(10, 42); // size:10, value:42
    vector<int> v4{ 10 };     // size:1,  value:10
    vector<int> v5{ 10, 42 }; // size:2,  value:10, 42
    vector<string> v6{ 10 };  // size:10, value:""
    vector<string> v7{ 10, "hi" };  // size:10, value:"hi"

    my_print(v1);
    my_print(v2);
    my_print(v3);
    my_print(v4);
    my_print(v5);
    my_print(v6);
    my_print(v7);

    return 0;
}