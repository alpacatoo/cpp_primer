#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
int main()
{
    std::ifstream inputFile("../ch08/data.txt");
    if (!inputFile)
    {
        std::cout << "Open file Fail!!" << std::endl;
        return EXIT_FAILURE;
    }

    string bufString;
    vector<string> v;
    while (getline(inputFile, bufString))
    {
        v.push_back(bufString);
    }

    for (auto & s : v)
    {
        std::istringstream iss(s);
        string word;
        while (iss >> word)
        {
            std::cout << word << std::endl;
        }
    }

    return 0;
}