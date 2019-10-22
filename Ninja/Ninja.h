#include <iostream>
#ifndef MAPS_H
#define MAPS_H
using namespace std;

int Shuriken;   //Number of Shuriken
bool Breaker;     //Breaker Mode Off or on
bool Mirror;      //Mirror mode status
char Direction; //Ninja Direction
char NextChar;
int Loop;

void PrintMap(char **Map, int NumRows, int NumCol)   //A Function to print the map
{
    for (int RowCount=0; RowCount < NumRows; RowCount++)
       {
        for(int ColCount=0; ColCount < NumCol; ColCount++)
           {
            cout<<Map[RowCount][ColCount];
           }
        cout<<endl;
       }
}

void GetStart(char **Map, int NumRows, int NumCol, int &NinjaRow,int &NinjaCol ) // GET @ dimentions
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

void MoveNinja(int &NinjaRow,int &NinjaCol, char Direction ) //Move Ninja according to direction ONE STEP
{
    switch (Direction)
    {
        case 'S': NinjaRow++; cout<<"SOUTH\n"; break;
        case 'E': NinjaCol++; cout<<"EAST\n";  break;
        case 'N': NinjaRow--; cout<<"NORTH\n"; break;
        case 'W': NinjaCol--; cout<<"WEST\n";  break;
        default: cout << "Wrong Direction, the game will be terminated"; exit(0);
    }
}

char GetNextChar(char **Map, int &NinjaRow,int &NinjaCol, char Direction) //Get the next char based on Direction
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

void ChangeDirection(char **Map,int NinjaRow,int NinjaCol, bool Mirror, char &Direction) //Change the direction
{
    char dir;
    if(Mirror == 0)     dir = 'S';
        else            dir = 'W';

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
            default:  cout << "Wrong Direction, the game will be terminated"; exit(0);
        }
    }
    Direction = dir;

}

#endif // NINJA_H
