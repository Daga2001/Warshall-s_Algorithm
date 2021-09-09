/*
  File: Warshall.h
  Author: anonymous.
  creation date: 2021-04-15
  last update date: 2021-04-15
  Versión: 1.0
  Licencia: GNU-GPL
*/

/*
  Class: Warshall

  Atributtes:
  -adjacencyMatrix
  -rowVector
  -colVector
  -previousWnMatrix
  -wnMatrix

  Functions:
  -graphicMatrix 
  -graphicMatrixAdjacency
  -makeWarshallMatrices
  -isNumber
  -locateRow
  -locateCol
  -knowMatrix
  -warshallN
  -optimizeAdjacencyMatrix
  -graphicResizedMatrix
  -sum
  -minimum
  -maximum
  -existInMatrix
  -maximumLengthComponent
  -graphicProof
    
*/

#ifndef WARSHALL_H
#define WARSHALL_H

#include<vector>
#include <iostream>
#include<algorithm>
#include<limits>
using namespace std;

class Warshall
{
  protected:
    vector<vector<string>> adjacencyMatrix;
    vector<string> rowVector;
    vector<string> colVector;
    vector<vector<string>> previousWnMatrix;
    vector<vector<string>> wnMatrix;

  public:
    //Constructor
    Warshall();

    //Destructor
    virtual ~Warshall();

    //Functions

    //Generates the graphic of a matrix.
    virtual void graphicMatrix(vector<vector<string>> matrix);

    virtual void graphicMatrixAdjacency();

    //generates warshall matrix depending of the number of nodes.
    virtual void makeWarshallMatrices();

    //check if an element is an integer.
    virtual bool isNumber(string element);

    //locates a row from the WnMatrix or adjacencyMatrix.
    virtual void locateRow(int row, vector<vector<string>> matrix);

    //locates a col from the WnMatrix or adjacencyMatrix.
    virtual void locateCol(int col, vector<vector<string>> matrix);

    //Allows to know a matrix.
    virtual void knowMatrix(vector<vector<string>> matrix);

    //Calculates the Wn matrix.
    virtual void warshallN(string type, int number, vector<vector<string>> matrix);
    
    //makes the adjacencyMatrix more legible, if there are components "I", they change by "i". 
    virtual void optimizeAdjacencyMatrix();

    //resizes the matrix.
    virtual void graphicResizedMatrix(vector<vector<string>> matrix);

    //sum 2 components from a matrix.
    virtual string sum(string value1, string value2);

    //finds the minimum value between two in a coordinate.
    virtual string minimum(string value1, string value2);

    //finds the maximum value between two in a coordinate.
    virtual string maximum(string value1, string value2);

    //multiplies 2 components from a boolean matrix.
    virtual string multiplyBool(string value1, string value2);

    //checks if there are wrong element in a matrix.
    virtual void thereAreWrongComponents( vector<vector<string>> matrix);

    //finds the component with the maximum length.
    virtual string maximumLengthComponent(vector<vector<string>> matrix);

    //checks if a matrix is boolean.
    virtual bool isBoolean(vector<vector<string>> matrix);

    //checks if a matrix is a quadratic matrix.
    virtual bool isQuadratic(vector<vector<string>> matrix);

    //function for debuggin (please use it only if is necessary).
    virtual void graphicProof();

};

#else
class Warshall;
#endif