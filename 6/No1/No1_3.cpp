#include<iostream>
#include<stdio.h>
#include <string>
using namespace std;

struct ISBN{
    int num1, num2, num3;
    char x;

};

enum class Genre 
{
    fiction, 
    nonfiction, 
    periodical, 
    biography, 
    children,
};

class Book{
    private:
        string title, author;
        int copyright_year;
        ISBN i;
        bool check_out = true;
        Genre genre;
        
    public:
        Book() = default;
        
        Book(string t, string a, int y){
            
            title = t;
            author = a;
            copyright_year = y;
        }
        void set_enum(Genre g)
        {
            genre = g;
        }
        void set_ISBN(int n1, int n2, int n3, char ch)
        {
            i.num1 = n1;
            i.num2 = n2;
            i.num3 = n3;
            i.x = ch;
        }
        string get_genre()
        {
            
            if (genre == Genre::biography)
            {
                return "biography"; 
            }
            else if (genre == Genre::children)
            {
                return "children"; 
            }
            else if (genre == Genre::fiction)
            {
                return "fiction"; 
            }
            else if (genre == Genre::nonfiction)
            {
                return "nonfiction"; 
            }
            else if (genre == Genre::periodical)
            {
                return "periodical"; 
            }
            else{
                return "Wrong";
            }
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
        

        // No1.2
        void compare_ISBN(Book b)
        {
            if (b.i.num1 == i.num1 && 
                b.i.num2 == i.num2 && 
                b.i.num3 == i.num3 &&
                b.i.x == i.x)
            {
                cout << "Same" << endl;
            }
            else
            {
                cout << "Not Same" << endl;
            }
        }
        void print()
        {
            cout << "ISBN is: "; get_ISBN();
            cout << "Title is: " << get_title() << endl;
            cout << "Author is: " << get_author() << endl;
            cout << "Year is: " << get_copyright_year() << endl;
            //cout << "Genre is: " << genre << endl;
        }  
};
int main()
{
    Book b1("Accelerated c++", "Arthur", 2023);
    b1.set_ISBN(123, 456, 789, 'A');
    
    Book b2("Accelerated c++", "Arthur", 2023);
    b2.set_ISBN(123, 456, 789, 'A');

    
    b2.set_enum(Genre::children);
    cout<< b2.get_genre() << endl;
    b2.compare_ISBN(b1);

    return 0;
}