#include <string>
class Screen{
public:
    typedef std::string::size_type pos;
    char get() const { return contents[cursor]; }
    char get(pos r, pos c) const { return contents[r*width + c]; }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};