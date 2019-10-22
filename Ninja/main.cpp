#include <iostream>
#include <Naming.h>
#include <fstream>
#include <Ninja.h>

using namespace std;

int main()
{

    //////////NAME THE NINJA//////////
    /*string Your_First_Name;
    string Your_Last_Name;
    string Ninja_Name;
    cout<<"Enter your first name:";
    cin>>Your_First_Name;                                         //Get first name
    cout<<endl<<"Enter your last name:";
    cin>>Your_Last_Name;                                         //Get Last name
    Ninja_Name = Ninja_Naming(Your_First_Name,Your_Last_Name);   //Assign Ninja name and call Ninja_Naming function
    cout <<endl<<"Ninja Name is: "<< Ninja_Name << endl;
*/

    //////////IMPORT MAPS LIST//////////
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


    string MapsList[MapsNumber];       //Create Maps array
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
    cout << "you selected: "<< MapsList[MapsNumber-1] <<endl;

    //////////INPUT MAP FILE//////////
    ifstream MapFile;
    MapFile.open("input/"+MapsList[MapsNumber-1]);

    //////////PRINT AND DEFINE MAP DIMENTIONS//////////
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

    //////////CREAT MAP MATRIX POINTER TO POINTER //////////  char Map [NumRows][NumCol];
    char** Map = new char*[NumRows];           //Main Map Matrix
    for(int a=0; a<NumRows; a++)
       {
          Map[a] = new char[NumCol];
       }

    ////////// ASSIGN VALUES TO MAP MATRIX//////////
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
    //////////GET START COORDINATES//////////
    int NinjaRow = 0;
    int NinjaCol = 0;
    GetStart(Map,NumRows,NumCol,NinjaRow, NinjaCol);   //Call function get @ location


    //////////INITILIZATIONS//////////

    Shuriken = 3;
    Breaker=0;
    Mirror=0;
    Direction='S';
    Loop = 0;

    //############################// START //############################//
    Start:   //---------------------//

    Loop++;
    if (Loop >1000) {cout <<"LOOP, the Holy Symbol can't be Distroyed \n"; exit (0);}  //Check for loop


    int row = NinjaRow;   //Temporary Coordinations
    int col = NinjaCol;   //Temporary Coordinations
    char dir;             //Temporary Direction

    //////////Distroy $ with Shuriken//////////
    if(Mirror==0) dir='S'; else dir='W';                       //reset temp direction
    for(int j=0; j<4;j++) {  cout << dir<<endl;                //Check for '$'
    if (Shuriken>0)
                {
                    switch (dir)
                    {
                    case 'S': row = NinjaRow; col=NinjaCol;
                              while(Map[row+1][col]!='$' && Map[row+1][col]!='X' && Map[row+1][col]!='#' && Map[row+1][col]!='M')
                                {row++;} //Check SOUTH
                              if (Map[row+1][col] == '$')
                              {
                                  cout << "THROW\n";
                                  cout << "\nGAME OVER, the Holy Symbol of the Red Claw tas been distroyed\n";
                                  PrintMap(Map, NumRows,NumCol);
                                  exit(0);
                              }
                              else {if(Mirror==0)dir='E';
                                   else          dir='W';}
                                break;

                    case 'E': row = NinjaRow; col=NinjaCol;
                              while(Map[row][col+1]!='$' && Map[row][col+1]!='X' && Map[row][col+1]!='#'&&Map[row][col+1]!='M')
                                {col++;} //Check EAST
                              if (Map[row][col+1] == '$')
                              {
                                  cout << "THROW\n";
                                  cout << "\nGAME OVER, the Holy Symbol of the Red Claw has been distroyed\n";
                                  PrintMap(Map, NumRows,NumCol);
                                  exit(0);
                              }
                              else {if(Mirror==0)dir='N';
                                   else         dir='S';}
                              break;

                    case 'N': row = NinjaRow; col=NinjaCol;
                              while(Map[row-1][col]!='$' && Map[row-1][col]!='X' && Map[row-1][col]!='#'&& Map[row-1][col]!='M')
                                {row--;} //Check NORTH
                              if (Map[row-1][col] == '$')
                              {
                                  cout << "THROW\n";
                                  cout << "\nGAME OVER, the Holy Symbol of the Red Claw has been distroyed\n";
                                  PrintMap(Map, NumRows,NumCol);
                                  exit(0);
                              }
                              else {if(Mirror==0)dir='W';
                                   else          dir='E';}
                              break;

                    case 'W': row = NinjaRow; col=NinjaCol;
                              while(Map[row][col-1]!='$' && Map[row][col-1]!='X' && Map[row][col-1]!='#'&& Map[row][col-1]!='M')
                                {col--;} //Check WEST
                              if (Map[row][col-1] == '$')
                              {
                                  cout << "THROW\n";
                                  cout << "\nGAME OVER, the Holy Symbol of the Red Claw has been distroyed\n";
                                  PrintMap(Map, NumRows,NumCol);
                                  exit(0);
                              }
                              else {if(Mirror==0)dir='S';
                                   else          dir='N';}
                              break;

                    }
                }
    else break;
    }

    //////////Distroy X with Shuriken//////////
    if(Mirror==0) dir='S'; else dir='W';                        //reset temp direction
    for(int j=0; j<4;) {  cout <<dir<<endl<<"Shuriken"<<Shuriken<<endl;                //Check for 'X'
                if(Shuriken>0)
                {
                    switch (dir)
                        {
                        case 'S': row = NinjaRow; col=NinjaCol;
                                  while(Map[row+1][col]!='X' && Map[row+1][col]!='#'&& Map[row+1][col]!='M')
                                    {row++;} //Check SOUTH
                                  if (Map[row+1][col] == 'X')
                                  {
                                      Shuriken--;
                                      cout<<"THROW\n";
                                      Map[row+1][col]='*';
                                      goto Start;
                                  }
                                  else
                                  {
                                      if(Mirror==0)
                                      {
                                          dir='E';
                                          j++;
                                      }
                                       else
                                      {
                                          dir='W';
                                          j++;
                                      }
                                  }
                                  break;

                        case 'E': row = NinjaRow; col=NinjaCol;
                                  while(Map[row][col+1]!='X' && Map[row][col+1]!='#'&& Map[row][col+1]!='M')
                                    {col++;} //Check EAST
                                  if (Map[row][col+1] == 'X')
                                  {
                                      Shuriken--;
                                      cout<<"THROW\n";
                                      Map[row][col+1]='*';
                                      goto Start;
                                  }
                                  else
                                  {
                                      if(Mirror==0)
                                      {
                                          dir='N';
                                          j++;
                                      }
                                       else
                                      {
                                          dir='S';
                                          j++;
                                      }
                                  }
                                  break;

                        case 'N': row = NinjaRow; col=NinjaCol;
                                  while(Map[row-1][col]!='X' && Map[row-1][col]!='#'&& Map[row-1][col]!='M')
                                    {row--;} //Check NORTH
                                  if (Map[row-1][col] == 'X')
                                  {
                                      Shuriken--;
                                      cout<<"THROW\n";
                                      Map[row-1][col]='*';
                                      goto Start;
                                  }
                                  else
                                  {
                                      if(Mirror==0)
                                      {
                                          dir='W';
                                          j++;
                                      }
                                       else
                                      {
                                          dir='E';
                                          j++;
                                      }
                                  }
                                  break;

                        case 'W': row = NinjaRow; col=NinjaCol;
                                  while(Map[row][col-1]!='X' && Map[row][col-1]!='#'&& Map[row][col-1]!='M')
                                    {col--;} //Check WEST
                                  if (Map[row][col-1] == 'X')
                                  {
                                      Shuriken--;
                                      cout<<"THROW\n";
                                      Map[row][col-1]='*';
                                      goto Start;
                                  }
                                  else
                                  {
                                      if(Mirror==0)
                                      {
                                          dir='S';
                                          j++;
                                      }
                                       else
                                      {dir='N';
                                          j++;
                                      }
                                  }
                                  break;

                        }
                }
                else break;
                }


    Move:   //---------------------//

    cout <<"Direction:"<<Direction<<endl;

    //////////Get Next Char//////////

    NextChar = GetNextChar(Map,NinjaRow,NinjaCol, Direction); //Next Char according to the direction
    cout<<"Next Char is :"<<NextChar<<endl;

    switch (NextChar)
    {
        case ' ': MoveNinja(NinjaRow,NinjaCol,Direction);                      goto Start;
        case '$': if(Breaker==1)
                    {
                        PrintMap(Map, NumRows,NumCol);
                        cout << "\nGAME OVER, the Holy Symbol of the Red Claw tas been distroyed\n";
                        exit(0);
                    }
                  else ChangeDirection(Map,NinjaRow,NinjaCol,Mirror,Direction); goto Move;

        case 'X': if(Breaker==1)
                    {
                        MoveNinja(NinjaRow,NinjaCol,Direction);
                        Map[NinjaRow][NinjaCol] = ' ';
                                                                               goto Start;
                    }
                  else ChangeDirection(Map,NinjaRow,NinjaCol,Mirror,Direction); goto Move;
        case '#': ChangeDirection(Map,NinjaRow,NinjaCol,Mirror,Direction)     ; goto Move;
        case '*': MoveNinja(NinjaRow,NinjaCol,Direction);
                  Map[NinjaRow][NinjaCol] = ' ';
                  Shuriken++                                                  ; goto Start;
        case 'S': MoveNinja(NinjaRow,NinjaCol,Direction); Direction='S'       ; goto Start;
        case 'E': MoveNinja(NinjaRow,NinjaCol,Direction); Direction='E'       ; goto Start;
        case 'N': MoveNinja(NinjaRow,NinjaCol,Direction); Direction='N'       ; goto Start;
        case 'W': MoveNinja(NinjaRow,NinjaCol,Direction); Direction='W'       ; goto Start;
        case 'M': MoveNinja(NinjaRow,NinjaCol,Direction); Mirror= !Mirror     ; goto Start;
        case 'B': MoveNinja(NinjaRow,NinjaCol,Direction); Breaker= !Breaker   ; goto Start;
        case 'F': goto Start;
        case 'G': goto Start;
        case 'H': goto Start;
        case 'I': goto Start;
        case 'J': goto Start;
        case 'K': goto Start;
        case 'L': goto Start;
        default: cout << "Wrong Direction, the game will be terminated\n"; exit(0);

    }





    cout << endl;
    return 0;

}
