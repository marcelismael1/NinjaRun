#include <iostream>
#include <Naming.h>
#include <fstream>
#include <Maps.h>

using namespace std;

int main()
{
    //////////NAME THE NINJA//////////
    string Your_First_Name;
    string Your_Last_Name;
    string Ninja_Name;
    cout<<"Enter your first name:";
    cin>>Your_First_Name;                                         //Get first name
    cout<<endl<<"Enter your last name:";
    cin>>Your_Last_Name;                                         //Get Last name
    Ninja_Name = Ninja_Naming(Your_First_Name,Your_Last_Name);   //Assign Ninja name and call Ninja_Naming function
    cout <<endl<<"Ninja Name is: "<< Ninja_Name << endl;


    //////////IMPORT MAP LIST//////////
    ifstream MapsListFile;
    MapsListFile.open("input/input-all.list");

    if(MapsListFile.fail())  //test if the file loaded correctly
        {
            cerr<< "No file detected\n";
            exit(1);
        }

    //////////COUNTING THE MAPS//////////
    int MapsNumber=0;
    string MapsListFileLine;
    while (getline(MapsListFile, MapsListFileLine))
         MapsNumber++;
    MapsListFile.clear();              //return to the first of the file
    MapsListFile.seekg(0, ios::beg);   //bring file pointer position to begining of file

    string MapsList[MapsNumber];       //Create Maps list array
    int i=0;
    while(i < MapsNumber)              //Read maps list file
       {
        MapsListFile >>MapsList[i];
        cout <<i+1<<"  "<< MapsList[i] <<endl;
        i++;
       }

    //////////SELECT A MAP//////////
    cout << "Please select a map number:";
    cin >> MapsNumber; cout <<endl;
    cout << "You selected: "<< MapsList[MapsNumber-1] <<endl;

    //////////INPUT MAP FILE//////////
    ifstream MapFile;
    MapFile.open("input/"+MapsList[MapsNumber-1]);

   //////////PRINT AND DEFINE DIMENTIONS//////////
    char c;
    int Numchars, NumRows, NumCol; //Map Dimentions
    NumCol=0;
    Numchars = 0;
    NumRows = 0;
    MapFile.get(c);            //Get a character from MapFile
    cout<<c;
    while (MapFile)            //Print the map and define the Mumber of rows and columns.
       {
       while (MapFile && c != '\n')
           {
           Numchars = Numchars + 1;
           MapFile.get(c);
           cout<<c;
           }
         if (Numchars > NumCol )  NumCol=Numchars;  //the maximum number of columns
         Numchars = 0;
         NumRows++;                                //the maximum number of rows
         MapFile.get(c);
         cout<<c;
       }

    //////////CREAT MAP MATRIX//////////
     char Map [NumRows][NumCol];   //Main Map Matrix

     MapFile.clear();              //return to the first of the file
     MapFile.seekg(0, ios::beg);   //bring file pointer position to begining of file

     for (int RowCount=0; RowCount < NumRows; RowCount++) //assign values to map matrix
        {
         for(int ColCount=0; ColCount < NumCol; ColCount++)
            {
             MapFile.get (c);
             if (c!='\n' )
                {
                 Map[RowCount][ColCount]=c;
                 cout <<Map[RowCount][ColCount];
                 }
             else ColCount--;
            }
         cout <<endl;
        }


     //////////SELECT START COORDINATES//////////

     int NinjaRow = 0;
     int NinjaCol = 0;
     for (int RowCount=0; RowCount < NumRows; RowCount++)
        {
         for(int ColCount=0; ColCount < NumCol; ColCount++)
            {

             if (Map[RowCount][ColCount]=='@' ) //get start point @
                {
                    NinjaRow = RowCount;
                    NinjaCol = ColCount;
                 }
            }

        }

     cout <<endl<< "NinjaRow = " << NinjaRow<<endl<< "NinjaCol = "<<NinjaCol<<endl;

    //////////MOVE NINJA//////////
     for (i=0; i<5;i++)
     {
         if (Map[NinjaRow+1][NinjaCol]!= '#')
            {
             while (Map[NinjaRow+1][NinjaCol]!= '#') {NinjaRow++; cout<<"SOUTH\n";}              //Move South Row++
            }
         else
             if(Map[NinjaRow][NinjaCol+1]!= '#')
                {
                 while (Map[NinjaRow][NinjaCol+1]!= '#') {NinjaCol++; cout<<"EAST\n";}           //Move EAST Col++
                }
             else
                if(Map[NinjaRow-1][NinjaCol]!= '#')
                    {
                    while (Map[NinjaRow-1][NinjaCol]!= '#') {NinjaRow--; cout<<"NORTH\n";}      //Move NORTH Row--
                    }
                else
                    if(Map[NinjaRow][NinjaCol-1]!= '#')
                        {
                        while (Map[NinjaRow][NinjaCol-1]!= '#')  {NinjaCol--; cout<<"WEST\n";}   //Move WEST Col--
                        }
                    else
                        cout<<"LOOOOOOP"<<endl;


     }


    cout << endl;
    return 0;
}
