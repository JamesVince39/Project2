#include <iostream>
#include <fstream>
#include <string>
#include <new>

using namespace std;

string delete_whitespace(string str);
bool   isBuffer(string str);
int    index(int size, int x, int y);

int main() {
  
  ifstream inFile("identities.txt");
  string * bufferArray;
  string * identityArray;
  string   line, noSpaceLine;
  int      n, bufferIndex, identityIndex;

  bufferIndex   = 0;
  identityIndex = 0;
  n = 12;
  bufferArray   = new string[n]();
  identityArray = new string[n*5](); //This is secretly a 2D array.
  
  while(getline(inFile, line)) {
    
    noSpaceLine = delete_whitespace(line);
    
    if(isBuffer(noSpaceLine)) {
      bufferArray[bufferIndex] = noSpaceLine;
      cout << bufferArray[bufferIndex] << endl;
      bufferIndex++;
    } else {
      identityArray[index(n, identityIndex, 0)] = noSpaceLine;
      cout << identityArray[index(n, identityIndex, 0)] << endl;
      identityIndex++;
    }
  }

  //This nightmarish block of code separates the identities by the '=' and stores them in the proper place in the 2D array.
  cout << endl;
  int j = 0;
  string tempString;
  for(int count = 0; count < identityIndex; count++) {
    j = 0;
    tempString = identityArray[index(n, count, 0)];
    identityArray[index(n, count, 0)] = "";
    for(int i = 0; i < tempString.length(); i++) {
      if(tempString.at(i) != '=') {
        identityArray[index(n, count, j)] += tempString.at(i);
      } else {
        j++;
      }
    }
  }

  //This for loop prints out each entry in the identityArray along with its index.
  for(int foo = 0; foo < n; foo++) {
    cout << "\n";
    for(int bar = 0; bar < 5; bar++) {
      cout << foo << " " << bar << " is: " << identityArray[index(n, foo, bar)] << endl ;
    }
  }
      
  delete[] bufferArray;
  delete[] identityArray;
}

string delete_whitespace(string str) {
  
  string newString = "";

  for(int i = 0; i < str.length(); i++) {
    if(str.at(i) != ' ') {newString += str.at(i);}
  }
  return newString;
}

bool isBuffer(string str) {
  if(str.at(0) == '<') {return true;}
  else                 {return false;}
}

//This function allows simple-minded access to the 2D array.
//First parameter: the total number of rows.
//Second parameter: the x index.
//Third parameter: the y index.
int index(int size, int x, int y) {
  return y*size + x;
}
