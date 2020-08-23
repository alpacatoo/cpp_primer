#include <iostream>
#include <string>
class Screen{
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos w, pos h) :width(w), height(h), contents(w*h, ' '){}
    Screen(pos w, pos h, char c) :width(w), height(h), contents(w*h, c){}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r*width + c]; }

    Screen move(pos r, pos c)
    {
        cursor = r * width + c;
        return *this;
    }
    Screen set(char c)
    {
        contents[cursor] = c;
        return *this;
    }
    Screen display(std::ostream &output)
    {
        do_display(output);
        return *this;
    }
    const Screen display(std::ostream &output) const
    {
        do_display(output);
        return *this;
    }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

    void do_display(std::ostream &output) const { output << contents; }
};

int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << "\n";
    myScreen.display(std::cout);
    std::cout << "\n";
}