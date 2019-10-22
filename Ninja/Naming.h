#include <iostream>
#ifndef NAMING_H
#define NAMING_H

using namespace std;

//Ninja Naming function
string Ninja_Naming ()
{
    Naming:

    string Ninja_FirstName;
    string Ninja_LastName;
    cout<<"First Name: ";
    cin>>Ninja_FirstName;
    cout<<"Last Name: ";
    cin>>Ninja_LastName;
    for( int j = 3; j < 5; j++ ) //To select between first and last name
    {
        string Name; //For letter assinment process
        string N;

        switch (j)
                {
                    case 3: N = Ninja_FirstName;  break;
                    case 4: N = Ninja_LastName;  break;
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
                        case 'A': Name = Name + "Ka";  break;
                        case 'B': Name = Name + "Zu";  break;
                        case 'C': Name = Name + "Mi";  break;
                        case 'D': Name = Name + "Te";  break;
                        case 'E': Name = Name + "Ku";  break;
                        case 'F': Name = Name + "Lu";  break;
                        case 'G': Name = Name + "Ji";  break;
                        case 'H': Name = Name + "Ri";  break;
                        case 'I': Name = Name + "Ki";  break;
                        case 'J': Name = Name + "Zu";  break;
                        case 'K': Name = Name + "Me";  break;
                        case 'L': Name = Name + "Ta";  break;
                        case 'M': Name = Name + "Rin"; break;
                        case 'N': Name = Name + "To";  break;
                        case 'O': Name = Name + "Mo";  break;
                        case 'P': Name = Name + "No";  break;
                        case 'Q': Name = Name + "Ke";  break;
                        case 'R': Name = Name + "Shi"; break;
                        case 'S': Name = Name + "Ari"; break;
                        case 'T': Name = Name + "Chi"; break;
                        case 'U': Name = Name + "Do";  break;
                        case 'V': Name = Name + "Ru";  break;
                        case 'W': Name = Name + "Mei"; break;
                        case 'X': Name = Name + "Na";  break;
                        case 'Y': Name = Name + "Fu";  break;
                        case 'Z': Name = Name + "Zi";  break;
                        // If a differnt character entered, exit with error message
                        default: cerr << "Wrong Character, Please use only letters for the name\n"; goto Naming;

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
