#include <iostream>
#include <Naming.h>

using namespace std;

int main()
{
    string Your_First_Name;
    string Your_Last_Name;
    string Ninja_Name;

    cout << "Start \n"; //delete when finished

    cout<<"Enter your first name:";
    cin>>Your_First_Name; //Get first name

    cout<<endl<<"Enter your last name:";
    cin>>Your_Last_Name; //Get Last name

    Ninja_Name = Ninja_Naming(Your_First_Name,Your_Last_Name); //Assign Ninja name
    cout <<endl<<"Ninja Name is: "<< Ninja_Name << endl;


    cout << "End \n"; //delete when finished
    return 0;
}
