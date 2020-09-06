#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    vector<int> vi;
    cout << "input: " << endl;
    istream_iterator<int> in_iter(cin), eof;
    copy(in_iter, eof, back_inserter(vi));
    sort(vi.begin(), vi.end());
    cout << "output:" << endl;
    copy(vi.cbegin(), vi.cend(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return EXIT_SUCCESS;
}