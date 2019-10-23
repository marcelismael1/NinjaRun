#include <iostream>
#ifndef MAPS_H
#define MAPS_H
using namespace std;

int  Shuriken;      //Number of Shurikens
bool Breaker;       //Breaker Mode status
bool Mirror;        //Mirror mode status
char Direction;     //Ninja Direction
char NextChar;      //The character that is in front of the Ninja
int  Loop;

//Print the map in any certain point
void PrintMap(char **Map, int NumRows, int NumCol)
{   cout<<endl;
    for (int RowCount=0; RowCount < NumRows; RowCount++)
       {
        for(int ColCount=0; ColCount < NumCol; ColCount++)
           {
            cout<<Map[RowCount][ColCount];
           }
        cout<<endl;
       }
}

// GET @ coordinates
void GetStart(char **Map, int NumRows, int NumCol, int &NinjaRow,int &NinjaCol )
{
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
    //cout <<endl<< "NinjaRow = " << NinjaRow<<endl<< "NinjaCol = "<<NinjaCol<<endl;

}

//Move Ninja according to direction ONE STEP
void MoveNinja(int &NinjaRow,int &NinjaCol, char Direction )
{
    switch (Direction)
    {
        case 'S': NinjaRow++; cout<<"SOUTH\n"; break;
        case 'E': NinjaCol++; cout<<"EAST\n";  break;
        case 'N': NinjaRow--; cout<<"NORTH\n"; break;
        case 'W': NinjaCol--; cout<<"WEST\n";  break;
        default: cout << "Wrong Direction, the game will be terminated\n"; exit(0);
    }
}

//Get the next char based on direction
char GetNextChar(char **Map, int &NinjaRow,int &NinjaCol, char Direction)
{

    switch (Direction)
    {
        case 'S': NextChar = Map[NinjaRow+1][NinjaCol]; break;
        case 'E': NextChar = Map[NinjaRow][NinjaCol+1]; break;
        case 'N': NextChar = Map[NinjaRow-1][NinjaCol]; break;
        case 'W': NextChar = Map[NinjaRow][NinjaCol-1]; break;
        default: cout << "Wrong Direction, the game will be terminated"; exit(0);
    }
    return NextChar;
}

//Change the direction
void ChangeDirection(char **Map,int NinjaRow,int NinjaCol, bool Mirror, char &Direction)
{
    char dir;

    if(Mirror == 0)     dir = 'S';  //Mirror Mode off
        else            dir = 'W';  //Mirror Mode off

    for(int i=0;i<4;i++)
    {
        switch (dir)
        {

            case 'S': if (Map[NinjaRow+1][NinjaCol] == '$' || Map[NinjaRow+1][NinjaCol] == 'X' ||Map[NinjaRow+1][NinjaCol] == '#')
                      {
                        if(Mirror==0)  dir='E';
                        else           dir='W';
                      }
                      break;

            case 'E': if (Map[NinjaRow][NinjaCol+1] == '$' || Map[NinjaRow][NinjaCol+1] == 'X' || Map[NinjaRow][NinjaCol+1] == '#')
                      {
                        if(Mirror==0)  dir='N';
                        else           dir='S';
                      }
                      break;

            case 'N': if (Map[NinjaRow-1][NinjaCol] == '$' || Map[NinjaRow-1][NinjaCol] == 'X' || Map[NinjaRow-1][NinjaCol] == '#')
                      {
                        if(Mirror==0)  dir='W';
                        else           dir='E';
                      }
                      break;

            case 'W': if (Map[NinjaRow][NinjaCol-1] == '$' || Map[NinjaRow][NinjaCol-1] == 'X' || Map[NinjaRow][NinjaCol-1] == '#')
                      {
                        if(Mirror==0)  dir='S';
                        else           dir='N';
                      }
                      break;
            default:  cout << "Wrong Direction, the game will be terminated\n"; exit(0);
        }
    }
    Direction = dir;  //Set new direction

}

//To move across the map through pathways
void PathWay (char **Map,int NumRows, int NumCol, int &NinjaRow,int &NinjaCol, char NextChar)
{
    for (int RowCount=0; RowCount < NumRows; RowCount++)
       {
        for(int ColCount=0; ColCount < NumCol; ColCount++)
           {

            if (Map[RowCount][ColCount]==NextChar ) //get path way coordinates
               if ( RowCount != NinjaRow || ColCount != NinjaCol) //if the coordinates are different from the current location, then change
                    {
                       NinjaRow = RowCount;
                       NinjaCol = ColCount;
                    }

           }

       }
    //cout << "NinjaRow : "<< NinjaRow<<endl;
    //cout<<"NinjaCol :"<<NinjaCol<<endl;
}

#endif // NINJA_H
