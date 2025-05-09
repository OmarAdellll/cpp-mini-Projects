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

const int MaxSizeQue = 5 ;
const int MaxSizeSpe = 20 ;
string Patients[MaxSizeSpe][MaxSizeQue+1];
bool PatientStatus[MaxSizeSpe][MaxSizeQue+1]{0};
int queue_len[MaxSizeSpe]{0};


void shift_right(string p[] ,bool ps[] ,int len)
{
    for(int i = len-1 ; i >= 0 ; --i)
    {
        p[i+1] = p[i] ;
        ps[i+1] = ps[i];
    }
}

void shift_left(string p[] ,bool ps[] ,int len)
{
    for(int i = 0 ; i < len ; ++i)
    {
        p[i] = p[i+1] ;
        ps[i] = ps[i+1];
    }
}

void AddNewPat()
{
    int sp ; string name ; bool st ;
    cout << "Enter Your Specialization , Name , Status : ";
    cin >> sp >> name >> st ;

    int pos = queue_len[sp-1] ;
    if(pos == MaxSizeQue) cout << "Sorry , We can't add more patients for this specialization\n\n";
    else
    {
    if(st==1){
       shift_right(Patients[sp-1] , PatientStatus[sp-1] , MaxSizeQue) ;
       Patients[sp-1][0] = name ;
       PatientStatus[sp-1][0] = st;
    }

    else
    {
        Patients[sp-1][pos] = name ;
        PatientStatus[sp-1][pos] = st;
    }
    queue_len[sp-1]++;
    }

}

void PrintAll()
{
    for(int  i = 0 ; i < 19 ; ++i)
    {
        if(queue_len[i]==0) continue;
        else
        {
            cout << "There are " << queue_len[i] << " patients in specialization " << i+1 << '\n';
            for(int j = 0 ; j < queue_len[i] ; ++j)
            {
                cout << Patients[i][j] ;
                if(PatientStatus[i][j]) cout << " : Urgent\n";
                else cout << " : Regular\n" ;
            }
        }
        cout << '\n';
    }
}

void GetNext()
{
    cout << "Enter Specialization: ";
    int sp ; cin >> sp ;
    if(queue_len[sp-1]==0) cout << "No patients at the moment. Have rest ,Dr\n\n";
    else
    {
        cout << Patients[sp-1][0] << " go with the Dr\n\n";
        queue_len[sp-1]-- ;
        shift_left(Patients[sp-1] , PatientStatus[sp-1] , MaxSizeQue ) ;
    }
}

int intf()
{
    cout << "Enter Your Choice:\n"
    << "1) Add New Patient\n"
    << "2) Print All Patients\n"
    << "3) Get Next Patient\n"
    << "4) Exit\n------------------\n" ;
     int n ; cin >> n ;
     return n ;
}

void System()
{
    while(true)
    {
        int q = intf() ;
        if(q == 1) AddNewPat() ;
        else if(q == 2) PrintAll() ;
        else if(q == 3) GetNext() ;
        else break ;
    }
}

int main()
{
    System() ;
	return 0 ;
}
