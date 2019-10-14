#include <iostream>
#include <Naming.h>

using namespace std;

int main()
{
    string Your_First_Name;
    string Your_Last_Name;
    cout << "Start \n";

    cout<<"Enter your first name:";
    cin>>Your_First_Name;


    cout<<endl<<"Enter your last name:";
    cin>>Your_Last_Name;


    cout <<endl<<"Ninja Name is: "<< Ninja_Naming(Your_First_Name,Your_Last_Name) << endl;


    cout << "End \n";
    return 0;
}
