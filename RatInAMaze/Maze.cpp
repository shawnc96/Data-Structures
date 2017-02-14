#include "Maze.h"
#include <queue>
#include <iostream>
#include <cstdlib>
#include <cassert>

using namespace std;


void Maze::print_dfsExitPath()
{
   cout << "Begin search!!\n";
   stack<Position> path;
   Position current, nbr;
   // FILL IN MISSING CODE
   

    bool esc=false;
    path.push(start);
    current=path.top();
    //setState(current, VISITED);
    
    while(!path.empty())
    {
       if(getState(current.Neighbor(DOWN))==OPEN)
       {
           path.push(current.Neighbor(DOWN));
           setState(current.Neighbor(DOWN), VISITED);
       }
       
       else if(getState(current.Neighbor(LEFT))==OPEN)
       {
           path.push(current.Neighbor(LEFT));
           setState(current.Neighbor(LEFT), VISITED);
       }
       
       else if(getState(current.Neighbor(UP))==OPEN)
       {
           path.push(current.Neighbor(UP));
           setState(current.Neighbor(UP), VISITED);
       }
       else if(getState(current.Neighbor(RIGHT))==OPEN)
       {
           path.push(current.Neighbor(RIGHT));
           setState(current.Neighbor(RIGHT), VISITED);
       }      
       
      
       else
       {
         path.pop();
       }
       
       current=path.top();
       if(current == start)
       break;     


       if(path.top()==exitpos)
       {
         esc=true;
         break;
       }
    }//end while
       
       
      if(esc==true)
      {
      
        cout <<"Remy, here is a sequence of positions to escape the maze:\n ";
        printBottomToTop(path);
       }       
      else
      {
          {
             cout << "Oh no, Poor Remy! There is now way to escape from the maze.\n\nOh no, Poor Remy! There is now way to escape from the maze.";
            exit(1);
          
          }//
      }//end else
      
    

}// end func.
             
                
           


void Maze::printShortestPath()
{
   queue<Position> Q;
   Position current, nbr;
   // Allocate the two dimensional predecessor array
   // The predecessor of Position P is given by
   // predecessor[P.row][P.col]
   Position** predecessor = new Position *[size];
   for(int i = 0; i < size; ++i) {
      predecessor[i] = new Position[size];
      for(int j = 0; j < size; ++j)
	       predecessor[i][j] = NULLPOS;
   }
   // FILL IN MISSING CODE
   
   Q.push(start);
   setState(Q.front(), VISITED);
   //current=Q.front();
   bool esc=false;
   current=Q.front();
   
   while(!Q.empty()&&esc==false)
   {   
        nbr=current.Neighbor(DOWN);
        if(getState(nbr)==OPEN)
       {
           predecessor[nbr.getRow()][nbr.getCol()]=current;
           setState(nbr, VISITED);
           if((nbr)==exitpos)
            {
               esc = true;
               break;
            }
           else
              Q.push(nbr);                 
       }
       
      
     
       nbr=current.Neighbor(LEFT);
        if(getState(current.Neighbor(LEFT))==OPEN)
       {
           
           predecessor[nbr.getRow()][nbr.getCol()]=current;
           setState(nbr, VISITED);
           if((nbr)==exitpos)
            {
               esc = true;
               break;
            }
           else
              Q.push(nbr);        
       }
      
         nbr=current.Neighbor(UP);
         if(getState(current.Neighbor(UP))==OPEN)
       {
           
           predecessor[nbr.getRow()][nbr.getCol()]=current;
           setState(nbr, VISITED);
           if((nbr)==exitpos)
            {
               esc = true;
               break;
            }
           else
           Q.push(nbr);  
          
       }
    
         nbr=current.Neighbor(RIGHT);
         if(getState(current.Neighbor(RIGHT))==OPEN)
       {
           
           predecessor[nbr.getRow()][nbr.getCol()]=current;
           setState(nbr, VISITED);
           if(nbr==exitpos)
            {
               esc = true;
               break;
            }
           else
           Q.push(nbr);  
   
       }
   

         
        Q.pop();
        current=Q.front();      
       
         
     }//end while   
     
     if(esc==true)
      {
        cout <<"Remy, here is a shortest sequence of positions to escape the maze:\n ";
        printPredecessorPath(predecessor, exitpos);
       }       
      else
      {
          {
            cout << "Oh no, Poor Remy! There is now way to escape from the maze.\n";
          
          }//
      }//end else
      
       


}

