#include <string>
#include <iterator>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
    ifstream infile("../ch10/book.txt");
    istream_iterator<string> in_iter(infile), eof;
    vector<string> vs(in_iter, eof);
    for (auto s : vs)
        cout << s << endl;
    return EXIT_SUCCESS;
}