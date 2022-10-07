/** A program that opens a text file, reads it line by line, and copies the contents to another file
*   The text file to read from name is passed on the command line as the first argument.
*   The text file to write to name is passed on the command line as the second arguments.
*   The text file should be placed in /home/debian for this to work.
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(int argc, char* argv[]){
  if(argc!=3){
    cout << endl;
    cout << "Usage is myCopier, name of read from file, and name of write to file: " << endl;
    cout << " e.g. ./myCopier readFile.txt writeFile.txt" << endl;
    return 2;
  }
  string readFile(argv[1]);
  string writeFile(argv[2]);

  string readFilePath = "/home/debian/" + readFile;
  string writeFilePath = "/home/debian/" + writeFile;

  cout << endl;
  cout << "Starting the reading-file program" << endl;
  cout << "The file to read from is located at: " << readFilePath << endl;
  cout << endl;

  fstream fsRead;
  fstream fsWrite;
  string line;

  fsRead.open((readFilePath).c_str(), fstream::in);
  fsWrite.open((writeFilePath).c_str(), fstream::out);

  while(getline(fsRead,line)) fsWrite << line << endl;

  fsRead.close();
  fsWrite.close();

  cout << "Writing file complete" << endl;
  cout << "The new file is: " << writeFilePath << endl;
  cout << endl;
}
