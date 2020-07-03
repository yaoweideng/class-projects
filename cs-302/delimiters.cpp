//--------------------------------------------------------------------
//
//   delimiters.cpp
//
//--------------------------------------------------------------------

#include <iostream>
#include "config.h"

#if LAB6_TEST1
#   include "StackLinked.cpp"
#else
#   include "StackArray.cpp"
#endif

//--------------------------------------------------------------------

bool delimitersOk ( const string &expression );

//--------------------------------------------------------------------

int main()
{
    string inputLine;            // Input line
    char   ch;                   // Holding pen for input chars

    cout << "This program checks for properly matched delimiters."
         << endl;

    while( cin )
    {
        cout << "Enter delimited expression (<EOF> to quit) : "
             << endl;

        // Read in one line
        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }

        if( ! cin )              // Reached EOF: stop processing
            break;
    
        if ( delimitersOk (inputLine) )
            cout << "Valid" << endl;
        else
            cout << "Invalid" << endl;
    }

    return 0;
}

//--------------------------------------------------------------------
// delimitersOk: the function that students must implement for 
//    Programming Exercise 3.
// Note: we used the term "braces" to describe '[' and ']'. It would
//    have been better to use the term "brackets". The program can be
//    easily modified to process any set of matching delimiters.
//--------------------------------------------------------------------

// Insert your delimitersOk function below

bool delimitersOk ( const string &expression ){
    int length = expression.length();
    StackLinked<float> stack;
    int c, c2;
    for(int i = 0; i < length; i++){
        if(expression[i] == '('){
            char left = expression[i];
            stack.push(left);
            c++;
        }
        if(expression[i] == ')'){
            stack.pop();
            c2++;
        }
    }
    if(c == c2){
        return true;
    } else {
        return false;
    }
}



