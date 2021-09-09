/*
  File: main.cpp
  Author: anonymous.
  creation date: 2021-04-15
  last update date: 2021-04-15
  Versión: 1.0
  Licencia: GNU-GPL
*/

#include <iostream>
#include "Warshall.h"
#define KnowMatrix(x)  warshall.knowMatrix(x);warshall.optimizeAdjacencyMatrix();cout << "This is the original matrix, called " #x << endl; 

using namespace std;

int main() {
  
  try
  {
    
    Warshall warshall;
    
    /*

    INSTRUCTIONS:
    
    PLEASE REMEMBER THAT YOU HAVE TO DEFINE A STRING QUADRATIC MATRIX, IN OTHER WORDS, A nxn MATRIX AND SET THE MATRIX IN KNOWMATRIX FUNCTION.

    INFINITY can be expressed like: "i" or "I"

    IF YOU WANT TO CALCULATE THE MAIN DIAGONAL, WRITE INSTEAD OF "-" A STRING "0"

    -WRITE "min" IF YOU WANT TO CALCULATE THE MINIMUM WEIGTH PATH
    
    -WRITE "max" IF YOU WANT TO CALCULATE THE MAXIMUM WEIGTH PATH
    
    */

    vector<vector<string>> adjacencyMatrix_7x7= 
    { {"-","1","2","i","i","i","i"},
      {"-","1","2","i","i","i","i"},
      {"i","-","i","2","3","i","i"},
      {"i","i","-","5","i","i","i"},
      {"i","i","i","-","i","2","9"},
      {"i","i","i","i","-","4","11"},
      {"4","5","i","i","i","11","i"} }; 

    vector<vector<string>> adjacencyMatrix_6x6= 
    { {"-","1","2","i","i","i"},
      {"i","-","i","2","3","i"},
      {"i","i","-","5","i","i"},
      {"i","i","i","-","i","2"},
      {"i","i","i","i","-","4"},
      {"4","5","i","i","i","-"} }; 

    vector<vector<string>> adjacencyMatrix_5x5= 
    { {"-","1","i","7","i"},
      {"i","-","4","2","i"},
      {"i","i","-","i","3"},
      {"i","i","1","-","5"},
      {"i","i","i","i","-"} };

    vector<vector<string>> connectivityMatrix_4x4= 
    { {"0","1","0","0"},
      {"1","0","1","0"},
      {"0","0","0","1"},
      {"0","0","0","0"} };

    vector<vector<string>> adjacencyMatrix_3x3= 
    { {"0","1","0"},
      {"1","0","1"},
      {"0","0","0"} };

    vector<vector<string>> adjacencyMatrix_2x2= 
    { {"0","1"},
      {"0","0"} };

    //you have to set here the matrix that you want to use for warshall's algorithm.
    KnowMatrix(connectivityMatrix_4x4);

    warshall.makeWarshallMatrices();
    
  }

  catch(const string &message)
  {
    cout << "ERROR! " << message << endl;
  }

}