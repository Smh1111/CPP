#include<iostream>
#include<stdio.h>
#include <string>
using namespace std;

struct ISBN{
    int num1, num2, num3;
    char x;

};

class Book{
    private:
        string title, author;
        int copyright_year;
        ISBN i;

    public:
        Book() = default;
        Book(string t, string a, int y){
            
            title = t;
            author = a;
            copyright_year = y;
        }
        void set_ISBN(int n1, int n2, int n3, char ch)
        {
            i.num1 = n1;
            i.num2 = n2;
            i.num3 = n3;
            i.x = ch;
        }
        // accessors getters
        string get_title()
        {
            return title;
        }
        string get_author()
        {
            return author;
        }
        int get_copyright_year()
        {
            return copyright_year;
        }
        void get_ISBN()
        {
            cout << i.num1 << "-" << i.num2 << "-" << i.num3 << "-" << i.x << endl;
        }
        void print()
        {
            cout << "ISBN is: "; get_ISBN();
            cout << "Title is: " << get_title() << endl;
            cout << "Author is: " << get_author() << endl;
            cout << "Year is: " << get_copyright_year() << endl;
        }     
};
int main()
{
    Book b1("Accelerated c++", "Arthur", 2023);
    b1.set_ISBN(123, 456, 789, 'A');
    //b1.get_ISBN();
    b1.print();

    return 0;
}