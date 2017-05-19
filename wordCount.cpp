/*
	Developer: Ian Johnson
	Program: Word Count
	Date: 4.11.17
	
	Sources:
		cppreference.com
		www.thecrazyprogrammer.com/2015/02/c-program-to-count-no-of-words-in-string.html
	
	OUTPUT:
		Lines words characters filename.txt
		
	NOTE:
		This could also be done by using getline to get a line from the file and then counting the number of times the line 		can be used in an output stream, and then counting the number of times that output stream can be used to output 			characters. But I didn't do it that way.
*/

#include <iostream>		// Does I/O stuff
#include <iomanip>		// Formats I/O stuff
#include <string>		// Necessary for string stuff
#include <fstream>		// Allows file stuff

using namespace std;
int main(int argCount, char* argVector[])
{
	// Checks for correct number of arguments
	if (argCount < 2)
	{
		cout << "Usage: ./my-word-count Filename.txt" << endl;
		return -1;
	}
	
	// Define some stuff
	int lineCount = 0;
	int wordCount = 1;
	int charCount = -1;
	string filename, lineFromFile;	// Creates string variables for filename and lineFromFile string
	ifstream fileStream;			// Input file stream
	char currentChar, previousChar = ' ';	// The current character to be evaluated from fileStream & the previousChar
	
	// get text file name from user
	filename = argVector[1];
	
	// open text file
	fileStream.open(filename);
	if (!fileStream)
	{
		cerr << "Error: 0923094\nCould not open file." << endl;
		return -1;
	}
	
	// Count words and chars in lineFromFile
	while (fileStream)
	{
		fileStream.get(currentChar);
		if ((currentChar == ' ' || currentChar == '\n') && previousChar != ' ' && previousChar != '\n')		// If currentChar is a space or a newline character...
			wordCount += 1;				// ... increment wordCount
		if (currentChar == '\n')							// If the currentChar is the newline character...
			lineCount += 1;				// ... increment lineCount
		charCount += 1;					// Increment character count
		previousChar = currentChar;		// Update previousChar
	}
	
	cout << std::setw(8) << lineCount << std::setw(8) << wordCount << std::setw(8) << charCount << " " << filename << endl;
	
	return 0;
}