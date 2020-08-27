#include <iostream>
#include <string>
#include <vector>
using namespace std;
class myData
{
private:
    unsigned day = 1, month = 1, year = 1970;
public:
    myData(const string &s)
    {
        if (s.find("/") != string::npos)
        {
            // 1/1/1900
            auto first = s.find_first_of("/");
            auto second = s.find_last_of("/");
            month = stoi(s.substr(0, first));
            day = stoi(s.substr(first + 1, second - first - 1));
            year = stoi(s.substr(second + 1));
        }
        else
        {
            // January 1, 1900 or Jan 1, 1900 or Jan 1 1900
            vector<string> months{"Jan","Feb", "Mar", "Apr", "May","June", 
                "July","Aug", "Sep", "Oct", "Nov", "Dec"};
            auto curr = months.begin();
            while (curr != months.end())
            {
                if (string::npos != s.find(*curr))    
                    break;  
                ++curr;
            }
            if (curr != months.end())
            {
                month = curr - months.begin() + 1;
                auto first = s.find_first_of(" ,");
                auto second = s.find_last_of(" ,");
                day = stoi(s.substr(first + 1, second - first - 1));
                year = stoi(s.substr(second + 1));
            }
        }
    }
    void print_data(const char * s)
    {
        cout << s
            << "Year: " << year << ", "
            << "Month: " << month << ", "
            << "Day: " << day << endl;
    }
};

int main()
{
    myData format1("4/30/1982: ");
    format1.print_data("4/12/1982 : ");
    myData format2("February 27,2001");
    format2.print_data("February 27,2001: ");
    myData format3("Sep 22 2010");
    format3.print_data("Sep 22 2010: ");
    myData format4("July 7, 2014");
    format4.print_data("July 15, 2014 : ");
    return EXIT_SUCCESS;
}