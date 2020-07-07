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
        if (score < 60)
            grade = v[0];
        else
        {
            grade = v[(score - 50) / 10];
            if (score != 100)
                grade += (score % 10)>6 ? "+" : (score % 10) < 3 ? "-" : "";
        }
        cout << grade << endl;
    }
    return 0;
}