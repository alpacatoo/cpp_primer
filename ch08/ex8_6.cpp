#include <iostream>
#include <fstream>
#include <string>
struct Sales_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
int main(int argc, char *argv[])
{
    std::ifstream input(argv[1]);

    struct Sales_data total;//������һ�����׼�¼�ı���
    double price = 0.0;
    if (input >> total.bookNo >> total.units_sold >> price)
    {
        total.revenue = total.units_sold * price;
        struct Sales_data trans;
        while (input >> trans.bookNo >> trans.units_sold >> price)
        {
            if (total.bookNo == trans.bookNo)
            {
                total.revenue += trans.units_sold * price;
                total.units_sold += trans.units_sold;
            }
            else
            {   //��ӡǰһ����Ľ��
                std::cout << total.bookNo << " " << total.units_sold << " "
                    << total.revenue << " " << total.revenue / total.units_sold
                    << std::endl;
            }
        }
        //��ӡ���һ������
        std::cout << total.bookNo << " " << total.units_sold << " "
            << total.revenue << " " << total.revenue / total.units_sold << std::endl;
    }
    else
    {
        std::cout << "No data!!" << std::endl;
    }
    return 0;
}