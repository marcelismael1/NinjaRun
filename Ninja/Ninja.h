#include <iostream>
#ifndef MAPS_H
#define MAPS_H
using namespace std;

int Shuriken = 3;   //Number of Shuriken
bool Breaker=0;     //Breaker Mode Off or on
bool Mirror=0;      //Mirror mode status
char Direction='S'; //Ninja Direction


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

void MoveNinja(char **Map, int NumRows, int NumCol, int &NinjaRow,int &NinjaCol ) //Move Ninja the default way
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
                   while (Map[NinjaRow-1][NinjaCol]!= '#') {NinjaRow--; cout<<"NORTH\n";}        //Move NORTH Row--
                   }
               else
                   if(Map[NinjaRow][NinjaCol-1]!= '#')
                       {
                       while (Map[NinjaRow][NinjaCol-1]!= '#')  {NinjaCol--; cout<<"WEST\n";}   //Move WEST Col--
                       }
                   else
                       cout<<"LOOOOOOP"<<endl;


}



#endif // NINJA_H
