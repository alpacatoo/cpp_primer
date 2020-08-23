#include <fstream>
#include <string>
#include <vector>
using std::string;
using std::vector;
void ReadFileToVec(const string &fileName, vector<string> v)
{
    std::ifstream f(fileName, std::fstream::in);
    if (f)
    {
        string str;
        while (std::getline(f, str))
        {
            v.push_back(str);
        }
    }
    
}
int main()
{
    return 0;
}