#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <initializer_list>

using std::vector;
using std::string;

class StrBlob
{
public:
    using size_type = vector<string>::size_type;

    StrBlob() :data(std::make_shared<vector<string>>()){}
    StrBlob(std::initializer_list<string> il) : data(std::make_shared<vector<string>>(il)){}

    size_type size() const
    {
        return data->size();
    }
    bool empty() const
    {
        return data->empty();
    }
    //添加和删除元素
    void push_back(const string& s) const
    {
        data->push_back(s);
    }
    void pop_back() const
    {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }
    //元素访问
    string& front()
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    string& back()
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }
    const string& front() const
    {
        check(0, "front on empty StrBlob");
        return data->front();
    }
    const string& back() const
    {
        check(0, "back on empty StrBlob");
        return data->back();
    }

private:
    std::shared_ptr<vector<string>> data;
    //如果data[i]不合法，抛出一个异常
    void check(size_type i, const string &msg) const
    {
        if (i >= data->size())
            throw std::out_of_range(msg);
    }
};

int main()
{
    StrBlob p{"aa","bb"};
    const StrBlob q{ "ccc", "ddd", "eee" };

    std::cout << "p : " << p.front() << " " << p.back() << std::endl;
    std::cout << "q : " << q.front() << " " << q.back() << std::endl;

    return EXIT_SUCCESS;
}
