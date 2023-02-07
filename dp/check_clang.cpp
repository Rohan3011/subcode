#include <iostream>
#include <fstream>
using namespace std ;

int main(int argc, char const *argv[])
{
	fstream myFile ;
	myFile.open("FileHandlingInCPP.txt" , ios::out) ;
	if (myFile.is_open()) {
		myFile << "Hello, World!\n";
		myFile << "This is a second line" << endl;
		myFile.close();
	}
	return 0;
}