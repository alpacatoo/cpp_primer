#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<string> v{ "F", "D", "C", "B", "A", "A++" };
    for (int score; cin >> score;)
    {
        string grade;
        grade = (score < 60) ? v[0] : v[(score - 50) / 10];
        grade += (score < 60 || score == 100) ? "" : (score % 10)>6 ? "+" : (score % 10) < 3 ? "-" : "";
        cout << grade << endl;
    }
    return 0;
}