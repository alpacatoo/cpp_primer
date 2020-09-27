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
        if (!result.second)         //second�ǲ����Ƿ�ɹ�������key����ɹ�
            ++result.first->second; //first��ָ��Ԫ�صĵ������ģ���Ԫ�ص�second�ۼ�
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