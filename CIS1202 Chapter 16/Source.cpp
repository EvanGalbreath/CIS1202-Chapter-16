//Evan Galbreath
//CIS 1202
// April 30th, 2023

#include <iostream>
#include "Exception.h"
using namespace std;

char character(char, int);

int main()
{
    cout << character('A', 1) << endl;
    cout << character('a', -32) << endl;
    cout << character('Z', -1) << endl;
    cout << character('?', 5) << endl;

    return 0;
}

char character(char start, int offset)
{
    try
    {
        if (!isalpha(start)) //if the input char is not a character, it will give a character exception
        {
            throw invalidCharacterException();
        }

        char result = start + offset; //creating a variable for what the char will be after the change is made

        if (!isalpha(result)) // if the result is not an alphanum char, but the input was, the range is a problem
        {
            throw invalidRangeException();
        }

        if (isupper(start) && islower(result)) // if the start and result are different capitilization, the ASCII value changed out of the range
        {
            throw invalidRangeException();
        }

        if (islower(start) && isupper(result)) //same as last but other way around
        {
            throw invalidRangeException();
        }

        return result; //if it got this far without running into an error, it will just display the result
    }
    catch (invalidCharacterException& e) //output if the exceptions are caught
    {
        cout << "Invalid character" << endl;
    }
    catch (invalidRangeException& e)
    {
        cout << "Invalid range" << endl;
    }

    return 0;
}