#include <string>
class Book
{
public:
    Book(unsigned isbn, std::string const& name, std::string const& author, std::string const& pubdate)
        :m_isbn(isbn), m_name(name), m_author(author), m_pubdate(pubdate)
    { }

    explicit Book(std::istream &in)
    {
        in >> m_isbn >> m_name >> m_author >> m_pubdate;
    }

private:
    unsigned m_isbn;
    std::string m_name;
    std::string m_author;
    std::string m_pubdate;
};

int main()
{
    return 0;
}