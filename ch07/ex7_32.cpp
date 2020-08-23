#include <string>
#include <vector>
class Screen;
class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    inline void clear(ScreenIndex);
private:
    std::vector<Screen> screens;
};
class Screen{
    friend void Window_mgr::clear(ScreenIndex);
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos w, pos h) :width(w), height(h), contents(w*h, ' '){}
    Screen(pos w, pos h, char c) :width(w), height(h), contents(w*h, c){}

    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r*width + c]; }

    Screen& move(pos r, pos c)
    {
        cursor = r * width + c;
        return *this;
    }
    Screen& set(char c)
    {
        contents[cursor] = c;
        return *this;
    }
    Screen& display(std::ostream &output)
    {
        do_display(output);
        return *this;
    }
    const Screen& display(std::ostream &output) const
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
inline void Window_mgr::clear(ScreenIndex index)
{
    Screen &s = screens[index];
    s.contents = std::string(s.height * s.width, ' ');
}

int main()
{
    return 0;
}