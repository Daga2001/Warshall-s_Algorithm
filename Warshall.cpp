/*
  File: Warshall.cpp
  Author: anonymous.
  creation date: 2021-04-15
  last update date: 2021-04-15
  Versión: 1.0
  Licencia: GNU-GPL
*/

#include "Warshall.h"
using namespace std;

Warshall::Warshall()
{
  
}

Warshall::~Warshall() 
{
  
} 

void Warshall::graphicMatrix(vector<vector<string>> matrix)
{
 
  for(int rows = 0; rows < matrix.size(); rows++)
  {
    
    cout<< "[" << "";

    for(int cols = 0; cols < matrix.at(rows).size(); cols++)
    {
      if(cols != matrix.at(rows).size() - 1 )
      {
        cout << matrix.at(rows).at(cols) << ",";
      }
      else
      {
        cout << matrix.at(rows).at(cols);
      }
    }

    cout<< "]" << endl;
    
  }

}

void Warshall::graphicMatrixAdjacency()
{
  graphicMatrix(adjacencyMatrix);
}

void Warshall::knowMatrix(vector<vector<string>> matrix)
{

  if(not isQuadratic(matrix))
  {
    throw string("You didn't insert a nxn matrix.");
  }

  for(int rows = 0; rows < matrix.size(); rows++ )
  {

    adjacencyMatrix.push_back(matrix.at(rows));

  }

}

bool Warshall::isNumber(string element)
{
  
  for(int nElement = 0; nElement < element.size(); nElement++ )
  {
    if(not isdigit(element[nElement]))
    {
      return false;
    }
  }
  return true;
}

void Warshall::locateCol(int col, vector<vector<string>> matrix)
{

  if(col > matrix.size())
  {
    throw string("The value of col is greater than the number of cols in matrix");
  }

  for(int nCol = 0; nCol < matrix.at(col-1).size(); nCol++)
  {

    colVector.push_back(matrix.at(col-1).at(nCol));

  }

}

void Warshall::graphicResizedMatrix(vector<vector<string>> matrix)
{
  
  string maximum = maximumLengthComponent(matrix);
  vector<string> component;
  int maximumLength = maximum.size();
  
  for(int rows = 0; rows < matrix.size(); rows++)
  {

    for(int cols = 0; cols < matrix.at(rows).size(); cols++)
    {

      if(matrix.at(rows).at(cols).size() < maximumLength)
      {

        component.push_back(matrix.at(rows).at(cols));
        matrix.at(rows).at(cols) = "";

        while(matrix.at(rows).at(cols).size() < maximumLength)
        {
          
          if(matrix.at(rows).at(cols).size() == maximumLength - 1)
          {
            matrix.at(rows).at(cols) += component.at(0);
          }
          else
          {
            matrix.at(rows).at(cols) += " ";
          }

        }
        
        component.clear();

      }

    }
    
  }

  graphicMatrix(matrix);

}

void Warshall::locateRow(int row, vector<vector<string>> matrix)
{
  if(row > matrix.size())
  {
    throw string("The value of row is greater than the number of rows in matrix");
  }
  
  for(int nRow = 0; nRow < matrix.size(); nRow++)
  {

    for(int nCol = 0; nCol < matrix.at(nRow).size(); nCol++)
    {

      if( (row-1) == nCol )
      {

        rowVector.push_back(matrix.at(nRow).at(nCol));

      }

    }
    
  }

}

void Warshall::warshallN(string type, int number, vector<vector<string>> matrix)
{

  string x;
  string y;

  for(int rows = 0; rows < matrix.size(); rows++ )
  {

    wnMatrix.push_back(matrix.at(rows));

  }

  locateCol(number, matrix);
  locateRow(number, matrix);

  for(int nRow = 0; nRow < matrix.size(); nRow++)
  {

    for(int nCol = 0; nCol < matrix.at(nRow).size(); nCol++)
    {
      
      x = colVector.at(nCol);
      y = rowVector.at(nRow);
      string component = wnMatrix.at(nRow).at(nCol); 

      if(nCol != (number-1) and nRow != (number-1))
      {

        if(type == "boolean")
        {
          string finalComponent = multiplyBool(x, y);
          
          if(component != "1")
          {

            if(component != finalComponent)
            {
              cout << "The component: " << "'" << component << "'" << " has changed by: " << "'" << finalComponent << "'" << " in: (" + to_string(nRow+1) + "," + to_string(nCol+1) + ")" << endl;
            }

            wnMatrix.at(nRow).at(nCol) = finalComponent;
          }
            
        }

        if(type == "min")
        {
          string finalComponent = minimum( sum(x,y), component );

          if(component != finalComponent)
          {
            cout << "The component: " << "'" << component << "'" << " has changed by: " << "'" << finalComponent << "'" << " in: (" + to_string(nRow+1) + "," + to_string(nCol+1) + ")" << endl;
          }

          wnMatrix.at(nRow).at(nCol) = finalComponent;
        }

        if(type == "max")
        {
          string finalComponent = maximum( sum(x,y), component );

          if(component != finalComponent)
          {
            cout << "The component: " << "'" << component << "'" << " has changed by: " << "'" << finalComponent << "'" << " in: (" + to_string(nRow+1) + "," + to_string(nCol+1) + ")" << endl;
          }

          wnMatrix.at(nRow).at(nCol) = finalComponent;
        }

      }
    }
  }

}

void Warshall::optimizeAdjacencyMatrix()
{
  
  for(int rows = 0; rows < adjacencyMatrix.size(); rows++)
  {

    for(int cols = 0; cols < adjacencyMatrix.at(rows).size(); cols++)
    {

      if(adjacencyMatrix.at(rows).at(cols) == "I")
      {
        adjacencyMatrix.at(rows).at(cols) = "i";
      }

    }
    
  }

}

string Warshall::maximumLengthComponent(vector<vector<string>> matrix)
{

  vector<string> maximumComponent;
  maximumComponent.push_back(matrix.at(0).at(0));
  string maximum;

  for(int rows = 0; rows < matrix.size(); rows++)
  {

    for(int cols = 0; cols < matrix.at(rows).size(); cols++)
    {

      if(maximumComponent.at(0).size() < matrix.at(rows).at(cols).size())
      {
        maximumComponent.at(0) = matrix.at(rows).at(cols);
      }

    }
    
  }

  maximum = maximumComponent.at(0);
  
  return maximum;

}

bool Warshall::isBoolean(vector<vector<string>> matrix)
{

  for(int rows = 0; rows < matrix.size(); rows++)
  {

    for(int cols = 0; cols < matrix.at(rows).size(); cols++)
    {

      if(not isNumber(matrix[rows][cols]))
      {
        return false;
      }
      else
      {
        if(stoi(matrix[rows][cols]) != 0 and stoi(matrix[rows][cols]) != 1)
        {
          return false;
        }
      }

    }
    
  }

  return true;

}

bool Warshall::isQuadratic(vector<vector<string>> matrix)
{

  int numberOfRows = matrix.size();

  for(int rows = 0; rows < matrix.size(); rows++ )
  {

    int numberOfCols = matrix.at(rows).size();

    if(numberOfRows != numberOfCols)
    {
      return false;
    }

  }
  return true;
}

void Warshall::makeWarshallMatrices()
{

  thereAreWrongComponents(adjacencyMatrix);

  graphicMatrixAdjacency();

  cout << "-----------------------------" << endl;

  string *type = new string();

  if(not isBoolean(adjacencyMatrix))
  {
  cout << "What path do you want to calculate ?" << endl;
  cout << "write -> 'max' / for maximum path or 'min' / for minimum path" << endl;
  string answer;
  getline(cin, answer);

  cout << "-----------------------------" << endl;

  while(answer != "max" and answer!= "min")
  {
    cout << "Hey! you have to write -> 'max' / for maximum path or 'min' / for minimum path"<< endl;
    getline(cin, answer);
  }

  *type = answer;
  
  }

  if(isBoolean(adjacencyMatrix))
  {
    *type = "boolean";
  }

  for(int number = 1; number <= adjacencyMatrix.size(); number++)
  {
    
    previousWnMatrix.clear();
    
    for(int rows = 0; rows < wnMatrix.size(); rows++ )
    {

    previousWnMatrix.push_back(wnMatrix.at(rows));

    }

    wnMatrix.clear();
    rowVector.clear();
    colVector.clear();

    if(number == 1)
    {
      warshallN(*type, number, adjacencyMatrix);
    }
    else
    {
      warshallN(*type, number, previousWnMatrix);
    }
  
    cout << "-----------------------------" << endl;

    cout << "This is the W_" << to_string(number) << " matrix" << endl;

    graphicResizedMatrix(wnMatrix);

    cout << "-----------------------------" << endl;

  }

  delete type;

}

string Warshall::multiplyBool(string value1, string value2)
{

  if(value1 == "1" and value2 == "1")
  {
    return "1";
  }
  else
  {
    return "0";
  }

}

string Warshall::sum(string value1, string value2)
{

  if( value2 == "i" and isNumber(value1) )
  {
    return value2;
  }

  if( value1 == "i" and isNumber(value2) )
  {
    return value1;
  }

  if( value1 == "-" or value2 == "-" )
  {
    return "-";
  }

  else
  {
    if(value1 == "-" and value2 == "i")
    {
      return value1;
    }
    if(value1 == "i" and value2 == "-")
    {
      return value2;
    }
    if(value1 == "i" and value2 == "i")
    {
      return value1;
    }
    if(value1 == "-" and value2 == "-")
    {
      return value1;
    }
    else
    {
      return to_string( stoi(value1) + stoi(value2) );
    }
  }

}

string Warshall::minimum(string value1, string value2)
{

  if( value2 == "i" and isNumber(value1) )
  {
    return value1;
  }
  if( value1 == "i" and isNumber(value2) )
  {
    return value2;
  }

  if( value1 == "-" or value2 == "-" )
  {
    return "-";
  }

  else
  {
    if(value1 == "-" and value2 == "i")
    {
      return value1;
    }
    if(value1 == "i" and value2 == "-")
    {
      return value2;
    }
    if(value1 == "i" and value2 == "i")
    {
      return value1;
    }
    if(value1 == "-" and value2 == "-")
    {
      return value1;
    }
    else
    {
      return to_string( min ( stoi(value1), stoi(value2) ) );
    }

  }

}

string Warshall::maximum(string value1, string value2)
{

  if( value2 == "i" and isNumber(value1) )
  {
    return value2;
  }
  if( value1 == "i" and isNumber(value2) )
  {
    return value1;
  }

  if( value1 == "-" or value2 == "-" )
  {
    return "-";
  }

  else
  {
    if(value1 == "-" and value2 == "i")
    {
      return value1;
    }
    if(value1 == "i" and value2 == "-")
    {
      return value2;
    }
    if(value1 == "i" and value2 == "i")
    {
      return value1;
    }
    if(value1 == "-" and value2 == "-")
    {
      return value1;
    }
    else
    {
      return to_string( max ( stoi(value1), stoi(value2) ) );
    }

  }

}

void Warshall::thereAreWrongComponents( vector<vector<string>> matrix)
{
  for(int rows = 0; rows < matrix.size(); rows++)
  {

    for(int cols = 0; cols < matrix.at(rows).size(); cols++)
    {
      string component = matrix[rows][cols];
      if(component != "i" and component != "-" and not isNumber(component))
      {
        throw string("You've written a wrong value for the matrix in (" + to_string(rows+1) + "," + to_string(cols+1) + ")" + ", check again!");
      }
    }
    
  }
}

void Warshall::graphicProof()
{
  cout << "-----------------------------" << endl; 
  
  cout<< "[" << "";
  for(int i = 0; i < colVector.size(); i++)
  {
    if(i != colVector.size()-1)
    {
      cout << colVector.at(i) << ",";
    }
    else
    {
      cout << colVector.at(i);
    }
  }
  cout<< "]" << endl;
  
  cout << "-----------------------------" << endl; 

  cout<< "[" << "";
  for(int i = 0; i < rowVector.size(); i++)
  {
    if(i != rowVector.size()-1)
    {
      cout << rowVector.at(i) << ",";
    }
    else
    {
      cout << rowVector.at(i);
    }
  }
  cout<< "]" << endl;

  cout << "-----------------------------" << endl;

  graphicMatrix(wnMatrix);

}
