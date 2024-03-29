#include <iostream>
#include <fstream>
#include <Naming.h>
#include <Ninja.h>

using namespace std;

int main()
{
    //////////BANNER//////////
    cout<<"############################(( NINJA LITE ))#################################\n\n";
    cout<<"BLACK LOTUS Clan is counting on you to destroy our rivals the RED CLAWS.\n"
          "Their actions are no longer accepted and its time to end it.\n"
          "It is your duty as the head of our clan to organize the attack to their HQ.\n"
          "We trust your judgment, please send our best warrior.\n\n"
          "WHO WOULD IT BE?\n";
          cout<<"#############################################################################\n\n";


    //////////NAME THE NINJA//////////
    string Ninja_Name;

    Ninja_Name = Ninja_Naming();
    cout <<endl<<"Ninja Name is: "<< Ninja_Name << endl;


    //////////BANNER//////////
    cout<<"\n\n############################(( SELECT MAP ))#################################\n";
    cout<<"To guarantee the success of our mission, we have the maps of their  terretory\n"
          "and here are they, this well give us a great advantage to plan the attack\n";
    cout<<"#############################################################################\n\n";


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
    MapsListFile.clear();              //clear
    MapsListFile.seekg(0, ios::beg);   //bring file pointer position to begining of the file


    string MapsList[MapsNumber];       //Create Maps array
    int i=0;

    while(i < MapsNumber)              //Read maps list file
       {
        MapsListFile >> MapsList[i];
        cout <<i+1<<"  "<< MapsList[i] <<endl;
        i++;
       }


    //////////SELECT A MAP//////////
    cout << "\nPlease select a map number:";
    cin >> MapsNumber; cout <<endl;


    //////////BANNER//////////
    cout<<"\n\n##############################(( RESULT ))###################################\n\n";
    cout<<Ninja_Name<<endl<<endl;


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
    while (MapFile)            //Print the map and define the number of rows and columns.
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


    //////////CREAT MAP MATRIX POINTER TO POINTER //////////
    char** Map = new char*[NumRows];           //Main Map Matrix
    for(int a=0; a<NumRows; a++)
       {
          Map[a] = new char[NumCol];
       }


    ////////// ASSIGN VALUES TO MAP MATRIX//////////
    MapFile.clear();              //clear
    MapFile.seekg(0, ios::beg);   //bring file pointer position to begining of the file

    for (int RowCount=0; RowCount < NumRows; RowCount++) //assign values to map matrix
        {
         for(int ColCount=0; ColCount < NumCol; ColCount++)
            {
             MapFile.get (c);       //to take into account spaces ' '.
             if (c!='\n' )
                {
                 Map[RowCount][ColCount]=c;
                 }
             else ColCount--;       //to ignore '\n' value
            }
        }


    //////////GET START COORDINATES//////////
    int NinjaRow = 0;
    int NinjaCol = 0;
    GetStart(Map,NumRows,NumCol,NinjaRow, NinjaCol);   //Call function get @ location, change NinjaRaw and NinjaCol values


    //////////INITIALIZATIONS//////////

    Shuriken  =   3;
    Breaker   =   0;
    Mirror    =   0;
    Direction = 'S';
    Loop      =   0;

    //############################// START //############################//
    Start:   //---------------------//

    Loop++;
    if (Loop >100)
        {
            cout <<"\n\nLOOP, the Holy Symbol can't be Distroyed \n\n";
            exit (0);
        }  //Check for loop


    int row = NinjaRow;   //Temporary coordinates
    int col = NinjaCol;   //Temporary coordinates
    char dir;             //Temporary Direction


    //////////Destroy $ with Shuriken//////////
    if(Mirror==0) dir='S'; else dir='W';                       //reset temp direction priorities.
    for(int j=0; j<4;j++) {                                    //Check for '$'
        if (Shuriken>0)
                {
                    switch (dir)
                    {
                    case 'S': row = NinjaRow; col=NinjaCol;
                              while(Map[row+1][col]!='$' && Map[row+1][col]!='X' && Map[row+1][col]!='#' && Map[row+1][col]!='M')
                                {
                                  row++;
                                } //Check SOUTH
                              if (Map[row+1][col] == '$')
                              {
                                  cout << "THROW\n";
                                  cout << "\nGAME OVER, the Holy Symbol of the Red Claw tas been distroyed\n";
                                  PrintMap(Map, NumRows,NumCol);
                                  exit(0);
                              }
                              else {if(Mirror==0) dir='E';
                                   else           dir='W';}
                              break;

                    case 'E': row = NinjaRow; col=NinjaCol;
                              while(Map[row][col+1]!='$' && Map[row][col+1]!='X' && Map[row][col+1]!='#'&&Map[row][col+1]!='M')
                                {
                                  col++;
                                } //Check EAST
                              if (Map[row][col+1] == '$')
                              {
                                  cout << "THROW\n";
                                  cout << "\nGAME OVER, the Holy Symbol of the Red Claw has been distroyed\n";
                                  PrintMap(Map, NumRows,NumCol);
                                  exit(0);
                              }
                              else {if(Mirror==0) dir='N';
                                   else           dir='S';}
                              break;

                    case 'N': row = NinjaRow; col=NinjaCol;
                              while(Map[row-1][col]!='$' && Map[row-1][col]!='X' && Map[row-1][col]!='#'&& Map[row-1][col]!='M')
                                {
                                  row--;
                                } //Check NORTH
                              if (Map[row-1][col] == '$')
                              {
                                  cout << "THROW\n";
                                  cout << "\nGAME OVER, the Holy Symbol of the Red Claw has been distroyed\n";
                                  PrintMap(Map, NumRows,NumCol);
                                  exit(0);
                              }
                              else {if(Mirror==0) dir='W';
                                   else           dir='E';}
                              break;

                    case 'W': row = NinjaRow; col=NinjaCol;
                              while(Map[row][col-1]!='$' && Map[row][col-1]!='X' && Map[row][col-1]!='#'&& Map[row][col-1]!='M')
                                {
                                  col--;
                                } //Check WEST
                              if (Map[row][col-1] == '$')
                              {
                                  cout << "THROW\n";
                                  cout << "\nGAME OVER, the Holy Symbol of the Red Claw has been distroyed\n";
                                  PrintMap(Map, NumRows,NumCol);
                                  exit(0);
                              }
                              else {if(Mirror==0) dir='S';
                                   else           dir='N';}
                              break;

                    }
                }
    else break;
    }


    //////////Destroy X with Shuriken//////////
    if(Mirror==0) dir='S'; else dir='W';                        //reset temp direction priorities.
    for(int j=0; j<4;) {                                        //Check for 'X'
        if(Shuriken>0)
                {
                    switch (dir)
                        {
                        case 'S': row = NinjaRow; col=NinjaCol;
                                  while(Map[row+1][col]!='X' && Map[row+1][col]!='#'&& Map[row+1][col]!='M')
                                    {
                                      row++;
                                    } //Check SOUTH
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
                                    {
                                      col++;
                                    } //Check EAST
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
                                    {
                                      row--;
                                    } //Check NORTH
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
                                    {
                                      col--;
                                    } //Check WEST
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


    //////////Get Next Char//////////
    NextChar = GetNextChar(Map,NinjaRow,NinjaCol, Direction); //Next Char according to the direction

    switch (NextChar)
    {
        case ' ': MoveNinja(NinjaRow,NinjaCol,Direction);                      goto Start;

        //////////THE HOLY SYMBOL//////////
        case '$': if(Breaker==1)
                    {
                        cout << "\nGAME OVER, the Holy Symbol of the Red Claw tas been distroyed\n";
                        PrintMap(Map, NumRows,NumCol);
                        exit(0);
                    }
                  else ChangeDirection(Map,NinjaRow,NinjaCol,Mirror,Direction); goto Move;

        //////////The Destructible Obstacle//////////
        case 'X': if(Breaker==1)
                    {
                        MoveNinja(NinjaRow,NinjaCol,Direction);
                        Map[NinjaRow][NinjaCol] = ' ';
                                                                               goto Start;
                    }
                  else ChangeDirection(Map,NinjaRow,NinjaCol,Mirror,Direction); goto Move;

        //////////The Wall//////////
        case '#': ChangeDirection(Map,NinjaRow,NinjaCol,Mirror,Direction)     ; goto Move;

        //////////The Shuriken//////////
        case '*': MoveNinja(NinjaRow,NinjaCol,Direction);
                  Map[NinjaRow][NinjaCol] = ' ';
                  Shuriken++                                                  ; goto Start;

        //////////The Path Modifiers//////////
        case 'S': MoveNinja(NinjaRow,NinjaCol,Direction);
                  Direction='S'                                               ; goto Start;

        case 'E': MoveNinja(NinjaRow,NinjaCol,Direction);
                  Direction='E'                                               ; goto Start;

        case 'N': MoveNinja(NinjaRow,NinjaCol,Direction);
                  Direction='N'                                               ; goto Start;

        case 'W': MoveNinja(NinjaRow,NinjaCol,Direction);
                  Direction='W'                                               ; goto Start;

        //////////The Mirror//////////
        case 'M': MoveNinja(NinjaRow,NinjaCol,Direction); Mirror= !Mirror     ; goto Start;

        //////////The Saké//////////
        case 'B': MoveNinja(NinjaRow,NinjaCol,Direction); Breaker= !Breaker   ; goto Start;

        //////////The Secret Pathways//////////
        case 'F': MoveNinja(NinjaRow,NinjaCol,Direction);
                  PathWay (Map, NumRows, NumCol,NinjaRow, NinjaCol, NextChar) ; goto Start;

        case 'G': MoveNinja(NinjaRow,NinjaCol,Direction);
                  PathWay (Map, NumRows, NumCol,NinjaRow, NinjaCol, NextChar) ; goto Start;

        case 'H': MoveNinja(NinjaRow,NinjaCol,Direction);
                  PathWay (Map, NumRows, NumCol,NinjaRow, NinjaCol, NextChar) ; goto Start;

        case 'I': MoveNinja(NinjaRow,NinjaCol,Direction);
                  PathWay (Map, NumRows, NumCol,NinjaRow, NinjaCol, NextChar) ; goto Start;

        case 'J': MoveNinja(NinjaRow,NinjaCol,Direction);
                  PathWay (Map, NumRows, NumCol,NinjaRow, NinjaCol, NextChar) ; goto Start;

        case 'K': MoveNinja(NinjaRow,NinjaCol,Direction);
                  PathWay (Map, NumRows, NumCol,NinjaRow, NinjaCol, NextChar) ; goto Start;

        case 'L': MoveNinja(NinjaRow,NinjaCol,Direction);
                  PathWay (Map, NumRows, NumCol,NinjaRow, NinjaCol, NextChar) ; goto Start;

        default: cout << "Wrong Direction, the game will be terminated\n"; break;

    }

    cout << endl;
    return 0;

}
