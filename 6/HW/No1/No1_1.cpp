#include<iostream>
#include<stdio.h>
#include <string>
#include <vector>
#include <algorithm>
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
        // mutators setters
        void set_title(string t)
        {
            title = t;
        }
        void set_author(string a)
        {
            author = a;
        }
        void set_copyright_year(int y)
        {
            copyright_year = y;
        }
        void set_genre(string g)
        {
            if (g == "fiction")
            {
                genre = Genre::fiction;
            }
            else if (g == "nonfiction")
            {
                genre = Genre::nonfiction;
            }
            else if (g == "periodical")
            {
                genre = Genre::periodical;
            }
            else if (g == "biography")
            {
                genre = Genre::biography;
            }
            else if (g == "children")
            {
                genre = Genre::children;
            }
            else
            {
                cout << "Wrong" << endl;
            }
        }
        // set the ISBN
        void set_ISBN(int n1, int n2, int n3, char ch)
        {
            i.num1 = n1;
            i.num2 = n2;
            i.num3 = n3;
            i.x = ch;
        }
        // divide the string into 4 parts and set the ISBN
        void set_ISBN(string isbn)
        {
            int pos1 = isbn.find('-');
            int pos2 = isbn.find('-', pos1 + 1);
            int pos3 = isbn.find('-', pos2 + 1);
            i.num1 = stoi(isbn.substr(0, pos1));
            i.num2 = stoi(isbn.substr(pos1 + 1, pos2 - pos1 - 1));
            i.num3 = stoi(isbn.substr(pos2 + 1, pos3 - pos2 - 1));
            i.x = isbn[pos3 + 1];
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
        void check_out_book()
        {
            check_out = false;
        }
        // - check in a book
        void check_in_book()
        {
            check_out = true;
        }
        // - check if a book is checked out
        bool is_checked_out()
        {
            return check_out;
        }
        // Read a book data from the input stream
        // The data format will be "<ISBN>\n<title>\n<author>\n<copyright>\n<genre>\n" , 
        // each consumes the whole line of text
        void read()
        {
            string isbn, title, author, year, genre;
            getline(cin, isbn);
            getline(cin, title);
            getline(cin, author);
            getline(cin, year);
            getline(cin, genre);
            set_ISBN(isbn);
            set_title(title);
            set_author(author);
            set_copyright_year(stoi(year));
            set_genre(genre);
        }
        
        // Find a book that match the title from a collection of books
        // Return the index of the book in the collection
        
        int find_book_byTitle(vector<Book> books, string title)
        {
            for (int i = 0; i < books.size(); i++)
            {
                if (books[i].get_title() == title)
                {
                    return i;
                }
            }
            return -1;
        }

        // Find a book that match the ISBN from a collection of books
        // Return the index of the book in the collection
        
        int find_book_byISBN(vector<Book> books, ISBN isbn)
        {
            for (int i = 0; i < books.size(); i++)
            {
                if (books[i].i.num1 == isbn.num1 && 
                    books[i].i.num2 == isbn.num2 && 
                    books[i].i.num3 == isbn.num3 &&
                    books[i].i.x == isbn.x)
                {
                    return i;
                }
            }
            return -1;
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

    
    Book b3;
    b3.read();
    /*
    999-888-333
    Hello World
    John
    2050
    fiction

    */

    b3.print();

    return 0;
}