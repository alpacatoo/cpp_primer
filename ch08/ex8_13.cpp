#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;
struct PersonInfo{
    string name;
    vector<string> phones;
};
int main()
{
    std::ifstream fileInput("../ch08/PersonInfo.txt");
    if (!fileInput)
    {
        std::cout << "Open File Fail !!" << std::endl;
        return EXIT_FAILURE;
    }
    string line, word;
    vector<PersonInfo> people;
    std::istringstream record;
    while (std::getline(fileInput, line))
    {
        PersonInfo info;
        record.clear();     //必须要有这个clear函数
        record.str(line);
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
    }
    
    for (auto &p : people)
    {
        std::cout << p.name << " ";
        for (auto &phone : p.phones)
            std::cout << phone << " ";
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}