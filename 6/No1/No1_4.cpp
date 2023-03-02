#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
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
        string copyright_year;
        ISBN i;
        bool check_out = true;
        Genre genre;
        
    public:
        Book() = default;
        
        Book(string t, string a, string y){
            
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
        string get_copyright_year()
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
            cout << "Genre is: " << get_genre() << endl;
        }  
};

void splitString(const string& str, string& first, string& second, string& third, string& fourth) 
{
    istringstream iss(str);
    getline(iss, first, '-');
    getline(iss, second, '-');
    getline(iss, third, '-');
    getline(iss, fourth);
}

Genre get_genre_from_input(string s)
        {
            
            if (s == "biography")
            {
                return Genre::biography; 
            }
            else if (s == "children")
            {
                return Genre::children; 
            }
            else if (s =="fiction" )
            {
                return Genre::fiction; 
            }
            else if (s == "nonfiction")
            {
                return Genre::nonfiction; 
            }
            else if (s =="periodical" )
            {
                return Genre::periodical; 
            }
            else{
                return Genre::periodical; 
            }
        }

//void find_book_byISBN(vector<Book> b, string ISB)
//{
//    if (b.)    
//}
int main()
{
    vector<Book> v;

    Book b1("Accelerated c++", "Arthur", "2023");
    b1.set_ISBN(123, 456, 789, 'A');
    
    Book b2("Accelerated c++", "Arthur", "2023");
    b2.set_ISBN(123, 456, 789, 'A');

    
    b2.set_enum(Genre::children);
    //cout<< b2.get_genre() << endl;
    b2.compare_ISBN(b1);
    
    
    ifstream file("D:/KMITL University/1st year 2nd sem/OOP/6/No1/book/names.txt");

    // No 1.4
    int a,b,c;
    char d;
    string title, author;
    string copyright_year;
    ISBN i;

    cout << endl << "Reading a book data from a file" << endl << endl;
    if (file.is_open())
    {
    	string line;
        string first, second, third, fourth;
        
        getline(file, line); // first line

        splitString(line, first, second, third, fourth);
        a = stoi(first);b = stoi(second);c = stoi(third); d = fourth[0];

        
        i.num1 = a; i.num2 = b; i.num3 = c; i.x = d;

        getline(file, line);    // second line
        title = line;

        getline(file, line);
        author = line;

        getline(file, line);
        copyright_year = line;

        getline(file, line);

        Book b4(title, author, copyright_year);
        b4.set_ISBN(i.num1, i.num2, i.num3, i.x);
        b4.set_enum(get_genre_from_input(line));
        	// note that the newline character is not included
            // in the getline() function	
            //cout << line << endl;
        
        b4.print();
        v.push_back(b4);
    }
    
    
    v.push_back(b1);

    v.push_back(b2);
        
    return 0;
}