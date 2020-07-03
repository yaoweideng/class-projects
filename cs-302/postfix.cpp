#include "StackLinked.h"
#include "StackLinked.cpp"
#include <math.h>
#include <string.h>
#include <iostream>

using namespace std;

float postfix(string input, StackLinked<float> &stack){
    int length = input.length();
    for(int i = 0; i < length; i++){
        if(input[i] == '0' || input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4' || input[i] == '5' 
        || input[i] == '6' || input[i] == '7' || input[i] == '8' || input[i] == '9'){
            char number = input[i] - '0';
            stack.push(number);
        } else if(input [i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^'){
            char op = input[i];
            float operand1 = stack.pop();
            float operand2 = stack.pop();
            float result;
            if(op == '+'){
                result = operand2 + operand1;
            } else if(op == '-'){
                result = operand2 - operand1;
            } else if(op == '*'){
                result = operand2 * operand1;
            } else if(op == '/'){
                result = operand2 / operand1;
            } else if(op == '^'){
                result = pow(operand2, operand1);
            }
            stack.push(result);
        }
    }
    return stack.pop();
}

int main(){
    StackLinked<float> s;
    string inputLine;
    char ch;
    while( cin )
    {
        cout << "Enter postfix expression"
             << endl;

        inputLine = "";
        cin.get(ch);
        while( cin && ch != '\n' )
        {
            inputLine = inputLine + ch;
            cin.get(ch);
        }

        if( ! cin )
            break;
        cout << "Result = " << postfix(inputLine, s) << endl;
    }
    return 0;
}

