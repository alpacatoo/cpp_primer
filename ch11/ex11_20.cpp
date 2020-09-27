#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;
void word_count(map<string, int> m)
{
    string s;
    while (cin >> s){
        auto result = m.insert({ s, 1 });
        if (!result.second)         //second是插入是否成功，已有key不会成功
            ++result.first->second; //first是指向元素的迭代器的，将元素的second累加
    }
    for (const auto& elem : m)
        std::cout << elem.first << " : " << elem.second << endl;
}
int main()
{
    map<string, int> m;
    word_count(m);
    return EXIT_SUCCESS;
}