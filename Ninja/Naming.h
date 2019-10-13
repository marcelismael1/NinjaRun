#include <iostream>
#ifndef NAMING_H
#define NAMING_H

using namespace std;

//Ninja Naming function
string Ninja_Naming (string First_Name, string Last_Name )
{
    string Ninja_FirstName;
    string Ninja_LastName;

    for( int j = 3; j < 5; j++ ) //To select between first and last name
    {
        string Name; //For letter assinment process
        string N;

        switch (j)
                {
                    case 3: N = First_Name;  break;
                    case 4: N = Last_Name;  break;
                    default:   break;
                }
        for( int i = 0; i < j; i++ )  //Assign japanese letters
            {
            switch (N[i])
                    {
                        case 'a': Name = Name + "ka";  break;
                        case 'b': Name = Name + "zu";  break;
                        case 'c': Name = Name + "mi";  break;
                        case 'd': Name = Name + "te";  break;
                        case 'e': Name = Name + "ku";  break;
                        case 'f': Name = Name + "lu";  break;
                        case 'g': Name = Name + "ji";  break;
                        case 'h': Name = Name + "ri";  break;
                        case 'i': Name = Name + "ki";  break;
                        case 'j': Name = Name + "zu";  break;
                        case 'k': Name = Name + "me";  break;
                        case 'l': Name = Name + "ta";  break;
                        case 'm': Name = Name + "rin"; break;
                        case 'n': Name = Name + "to";  break;
                        case 'o': Name = Name + "mo";  break;
                        case 'p': Name = Name + "no";  break;
                        case 'q': Name = Name + "ke";  break;
                        case 'r': Name = Name + "shi"; break;
                        case 's': Name = Name + "ari"; break;
                        case 't': Name = Name + "chi"; break;
                        case 'u': Name = Name + "do";  break;
                        case 'v': Name = Name + "ru";  break;
                        case 'w': Name = Name + "mei"; break;
                        case 'x': Name = Name + "na";  break;
                        case 'y': Name = Name + "fu";  break;
                        case 'z': Name = Name + "zi";  break;
                        default: cout << "Error! operator is not correct";   break;
                    }

        }
    switch (j)
            {
                case 3: Ninja_FirstName = Name;  break;
                case 4: Ninja_LastName  = Name;  break;
                default:   break;
            }
    }

    string Ninja_Name = Ninja_FirstName + " " + Ninja_LastName;
    return Ninja_Name;
}
#endif // NAMING_H
