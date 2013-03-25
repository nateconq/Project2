#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
	double len; //total length of string
	int lines;
	int lastSpace; // last space in the current line
	int remainder; // remaining words from first line after wordwrap
	int currLine = 1; // current line in operation
	int currLen; // allowable length of current line
	string userInput;
	cout << "This will create word wrap." << endl;
	cout << "Enter a string, preferably longer than the console (80 characters)" << endl;
	getline(cin, userInput);
	cout << "Your string is this long: ";
	len = userInput.length();
	cout << len;
	cout  <<  " characters."  <<  endl;
	cout << "Number of lines text needs in console: ";
	lines = ceil(len / 80);
	cout << lines << endl;

	_getch();
	


	if (len <= 80) // string will only need 1 line
	{
		cout << "Program has detected that string is less than or equal to 80 chars." << endl;
		cout << userInput;
	}



	else if (len > 80) // string will take mult lines
	{
		
		cout << "Program has detected that string is over 80 chars." << endl;
		for (int i = 79; i > 0; i--)  // establish last space
		{
			if (userInput[i] == ' ')
			{
				lastSpace = i;
				cout << "Detected space at: " << lastSpace << endl;
				break;
			}

		} // end establish last space

		for (int i = 0; i < lastSpace; i++) // output the first sentence with wordwrap
		{
			cout << userInput[i];
		}

		currLine ++;

		cout << endl;
	
		remainder = 79 - lastSpace;
		cout << "The remainder is " << remainder << endl;
		
		currLen = 80 - remainder;
		cout << "The current line allowable length is " << currLen << endl;
		
		if (remainder + (len - 79 * currLine) > 80)
		{
			cout << "Needed to add 1 to max lines needed" << endl;
			lines = lines++;
		}
		
		for (int i = (79 * currLine - remainder); i > 0; i--)  // establish last space for 2nd line
		{
			if (userInput[i] == ' ')
			{
				lastSpace = i;
				cout << "Detected space at: " << lastSpace << endl;
				break;
			}

		} // end establish last space for 2nd line


		for (int i = lastSpace + 1; i < currLen + 80; i++) // output second row of text
		{
			cout << userInput[i];
		}

		
	
	} // end if needs mult lines

	_getch();
	return 0;
}