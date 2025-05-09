#include <iostream>
using namespace std;
int main()
{
    bool first = 1 ;
    int index = 0 ;
    const int Employee_Numbers = 1000 ;

       string name[Employee_Numbers]{"\0"} ;
       int age[Employee_Numbers]{0} ;
       double salary[Employee_Numbers]{0} ;
       char gender[Employee_Numbers]{'\0'} ;

   while(true)
   {
       if(!first) cout << "\n\n" ;
       cout << "1) Add New Employee"
       << "\n2) Print All Employees"
       << "\n3) Delete by Age"
       << "\n4) Update Salary by Name" ;

       int choice = -1 ; cout << "\n\nEnter Your Choice : " ;
       cin >> choice ;
       if(choice < 1 || choice > 4)
       {
           cout << "\nPlease Enter a Right Choice\n" ;
          break ;
       }


       if(choice==1)
       {
           cout << "Enter Name : " ; cin >> name[index] ;
           cout << "Enter Age : " ; cin >> age[index] ;
           cout << "Enter Salary : " ; cin >> salary[index] ;
           cout << "Enter Gender : " ; cin >> gender[index] ;
           if(gender[index] != 'M' && gender[index] != 'F')
           {
               while(true)
               {
                   cout << "Please Enter The Right Gender (M) is for Male and (F) is for Female : " ;
                   cin >> gender[index] ;
                   if(gender[index] == 'M' || gender[index] == 'F')
                    break ;
               }
           }

           index++ ;
       }
       else if(choice==2)
       {
           for(int i = 0 ; i < index ; ++i)
           {
               if(age[i] == 0 ) continue ;
            cout << endl ;
               cout << name[i]
               << " " << age[i]
               << " " << salary[i]
               << " " << gender[i];
           }
       }
       else if(choice==3)
       {
           int st_age , end_age ;
           cout << "Enter Start and End Age : " ; cin >> st_age >> end_age ;
           for(int i = 0 ; i < index ; ++i)
           {
               if(age[i] >= st_age && age[i] <= end_age)
                name[i] = "\0" , age[i] = 0 , salary[i] = 0 , gender[i] = '\0' ;
           }

       }
       else if(choice == 4)
       {
           cout << "Enter The Name and The New Salary : " ;
           string find_str ; double newsala ;
           cin >> find_str >> newsala ;
           int i = 0  ;
           for(; i < index ; ++i)
           {
               if(find_str == name[i])
               {
                salary[i] = newsala ;
                break ;
               }
           }
           if(i == index) cout << "There is no a Person called " << find_str ;

       }

first = 0 ;
   }
  return 0 ;
}
