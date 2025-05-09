#include <iostream>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <iomanip>
#include <algorithm>
#define juba std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll ;
using namespace std ;

const int MaxBooks = 100 ;
const int MaxUsers = 20 ;

struct book
{
    int id , quantity ;
    string name ;
    string borrow[MaxUsers] ;

    book() {id = -1 , quantity = 0;}

   void addBook()
    {
        cout << "Please Enter The ID , Name and Quantity Respectively of Your Book : ";
        int i ; string n ; int q ;
        cin >> i >> n >> q ;
        id = i , quantity = q , name = n ;
    }

    bool searchByPre(string s)
    {
        if( (name.size() < s.size()) || name == "") return 0 ;
        else
        {
            for(int i = 0 ; i < s.size() ; ++i)
            {
                if(name[i] != s[i]) return 0 ;
            }
            return 1 ;
        }
    }

    bool Available()
    {
        if(quantity == 0)
        {
            cout << "Not Available right Now\n\n";
            return 0 ;
        }
        return 1 ;
    }
    void addBorrow(string s)
    {
            for(int i = 0 ; i < MaxUsers ; ++i)
            {
                if(borrow[i]=="")
                {
                    borrow[i]=s ;
                    quantity--;
                    return ;
                }
            }
    }

    void removeBorrow(string s)
    {
        for(int i = 0 ; i < MaxUsers ; ++i)
        {
            if(borrow[i]==s)
            {
                borrow[i]= "" ;
                quantity++;
                return ;

            }
        }
    }

    void printBorrow()
    {
        bool flag = 0 ;
        for(int i = 0 ; i < MaxUsers ; ++i)
        {
            if(borrow[i] != "")
            {
                cout << borrow[i] << '\n' ;
                flag = 1 ;
            }
        }
        if(flag == 0) cout << "No one has borrow this book" ;
        cout << "\n\n" ;
    }
};
bool compareById(book &b1 , book &b2)
{
    return (b1.id < b2.id) ;
}
bool compareByName(book &b1 , book &b2)
{
    return (b1.name < b2.name) ;
}

struct user
{
    int id , age ;
    string name ;
    string Borrow[MaxBooks];
    int bo = 0 ;

    user(){id = -1 , age = -1 ;}
    void addUser()
    {
        cout << "Please Enter Your ID , Name and Age : " ;
        int i ; string n ; int a ; cin >> i >> n >> a ;
        id = i , age = a , name = n ;
    }
    bool canBorrow()
    {
        if(bo == MaxBooks)
        {
            cout << "You Borrow your limit books\n\n";
            return 0 ;
        }
        return 1 ;
    }
    void borrowBook(string b)
    {
        for(int i = 0 ; i < MaxBooks; ++i)
        {
            if(Borrow[i]=="")
            {
                Borrow[i]=b;
                return ;
            }
        }
    }

    int IsBorrowBook(string b)
    {
        for(int i = 0 ; i < MaxBooks ; ++i)
        {
            if(Borrow[i]==b)
            {
                Borrow[i]="";
                return i ;
            }
        }
        return -1;
    }

    void printUser()
    {
        cout << "ID : " << id << ", Name : " << name  << " , Age : " << age << '\n' ;
    }

};

struct library
{

    book Books[MaxBooks];
    user Users[MaxUsers];
    int bookLen = 0 ;
    int userLen = 0 ;

    void AddBook()
    {
        if(bookLen == MaxBooks) cout << "Library is Full of Books\n";
        else Books[bookLen++].addBook() ;
    }

    void searchByPrefix()
    {
        cout << "Enter a prefix of the book : ";
        bool flag = 0 ;
        string s ; cin >> s ;

        for(int i = 0 ; i < MaxBooks ; ++i)
        {
            if(Books[i].searchByPre(s))
            {
                flag = 1 ;
                cout << Books[i].name << '\n' ;
            }
        }
        if(flag==0) cout << "There is no book by this prefix here" ;
        cout << '\n' ;
    }

    void printWhoBorrowed()
    {
        cout << "Enter the book name :" ;
        string s ; cin >> s ;
        bool flag = 0 ;
        for(int i = 0 ; i < MaxBooks ; ++i)
        {
            if(Books[i].name == s)
            {
                flag = 1 ;
                Books[i].printBorrow() ;
               break;
            }
        }
        if(flag == 0) cout << "There is no book by this name here\n\n" ;
    }

    void printLibById()
    {
        sort(Books , Books+bookLen , compareById) ;
        for(int i = 0 ; i < bookLen ; ++i)
        {
            cout << Books[i].name << '\n';
        }
        cout << '\n';
    }

    void printLibByName()
    {
        sort(Books , Books+bookLen , compareByName) ;
        for(int i = 0 ; i < bookLen ; ++i)
        {
            cout << Books[i].name << '\n';
        }
        cout << '\n';
    }

    void AddUser()
    {
        if(userLen == MaxUsers) cout << "Library is Full of Users\n\n";
        else Users[userLen++].addUser() ;
    }

    void userBorrow()
    {
        cout << "Enter The User Name and Book Name : " ;
        string u , b ; cin >> u >> b ;

        bool flag = 0 ;
        int i = 0 , j = 0 ;
        while(i < MaxBooks)
        {
           if(Books[i].name == b)
           {
               flag = 1 ;
               break ;
           }
           i++;
        }
        if(flag == 0) {cout << "No Book here has this name\n\n" ; return ;}
        flag = 0 ;

        while(j < MaxUsers)
        {
            if(Users[j].name == u)
            {
                flag = 1 ;
                break ;
            }
            j++;
        }
        if(flag == 0) {cout << "No User here has this name\n\n" ; return ;}
        if(Books[i].Available() && Users[j].canBorrow())
        {
            Books[i].addBorrow(u);
            Users[j].borrowBook(b);
        }
    }

    void userReturn()
    {
         cout << "Enter The User Name and Book Name : " ;
        string u , b ; cin >> u >> b ;

        bool flag = 0 ;
        int i = 0 , j = 0 ;
        while(i < MaxBooks)
        {
           if(Books[i].name == b)
           {
               flag = 1 ;
               break ;
           }
           i++;
        }
        if(flag == 0) {cout << "No Book here has this name\n\n" ; return ;}
        flag = 0 ;

        while(j < MaxUsers)
        {
            if(Users[j].name == u)
            {
                flag = 1 ;
                break ;
            }
            j++;
        }
        if(flag == 0) {cout << "No User here has this name\n\n" ; return ;}

        if(Users[j].IsBorrowBook(b) != -1)
        {
            Books[i].removeBorrow(u);
        }
        else
        {
            cout << "User does not borrow this book\n\n";
        }
    }

    void printUser()
    {
        if(userLen == 0) cout << "No users yet\n\n";
        else
        {
            for(int i = 0 ; i < userLen ; ++i)
            {
                Users[i].printUser();
            }
            cout << '\n' ;
        }
    }

    int Background()
    {
        cout << "Library Menu : \n--------------\n"
        <<"1) Add book\n"
        <<"2) Search books by prefix\n"
        <<"3) Print who borrowed book by name\n"
        <<"4) Print library by ID\n"
        <<"5) Print library by Name\n"
        <<"6) Add user\n"
        <<"7) User borrow book\n"
        <<"8) User return book\n"
        <<"9) Print users\n"
        << "10) Exit\n\n\n"

        << "Enter your menu choice [1 : 10] : " ;
        int n ; cin >> n ; return n ;
    }

    void System()
    {
        while(true)
        {
        int q = Background();
            if(q == 1) AddBook();
        else if(q == 2) searchByPrefix();
        else if(q == 3) printWhoBorrowed() ;
        else if(q == 4) printLibById();
        else if(q == 5) printLibByName();
        else if(q == 6) AddUser();
        else if(q == 7) userBorrow();
        else if(q == 8) userReturn();
        else if(q == 9) printUser();
        else break ;
        }
    }
};

int main()
{
   library l1 ;
   l1.System() ;
	return 0 ;
}
