#include <iostream>
#include <fstream>
#include "stack.h"
#include <string>
string convertToPostfix(string expression);
void readFile(string inputFileName, string outputFileName);
bool IsOperator(char C);
bool IsOperand(char C);
int GetOperatorWeight(char op);               // https://gist.github.com/mycodeschool/7867739
int HasHigherPrecedence(char op1, char op2);  // converter adapted from mycodeschool youtube/github
bool isBalanced(string line);
bool match(char x, char y);
string math( string line);

int main() {


    string expression;
    cout<<"Enter Infix Expression \n";
    getline(cin,expression);
    cout<<"Equation is balanced: "<< boolalpha<<isBalanced(expression)<<endl;
    string postfix = convertToPostfix(expression);
    cout<<"Output = "<<postfix<<"\n";
    return 0;
}

void readFile(string inputFileName, string outputFileName) {
    ifstream myFile;
    myFile.open(inputFileName);
    string line;

    if(myFile.fail()){
        cout<<"File not found"<<endl;
        exit(1);
    }
    while(!myFile.eof()){
        if (isBalanced(line)) {
            getline(myFile, line);
            string postFix = convertToPostfix(line);// convert line to post fix
            //do math
            // write
        }
        else{

        }


    }
    myFile.close();


}

string convertToPostfix(string expression)
{
    // Declaring a Stack from Standard template library in C++.
    stack S;
    string postfix = ""; // Initialize postfix as empty string.
    for(int i = 0;i< expression.length();i++) {

        // Scanning each character from left.
        // If character is a delimitter, move on.
        if(expression[i] == ' ' || expression[i] == ',') continue;

            // If character is operator, pop two elements from stack, perform operation and push the result back.
        else if(IsOperator(expression[i]))
        {
            while(!S.isEmpty() && S.top() != '(' && HasHigherPrecedence(S.top(),expression[i]))
            {
                postfix+= S.top();
                S.pop();
            }
            S.push(expression[i]);
        }
            // Else if character is an operand
        else if(IsOperand(expression[i]))
        {
            postfix +=expression[i];
        }

        else if (expression[i] == '(')
        {
            S.push(expression[i]);
        }

        else if(expression[i] == ')')
        {
            while(!S.isEmpty() && S.top() !=  '(') {
                postfix += S.top();
                S.pop();
            }
            S.pop();
        }
    }

    while(!S.isEmpty()) {
        postfix += S.top();
        S.pop();
    }

    return postfix;
}

bool IsOperand(char C)
{
    if(C >= '0' && C <= '9') return true;
    if(C >= 'a' && C <= 'z') return true;
    if(C >= 'A' && C <= 'Z') return true;
    return false;
}

bool IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/' )
        return true;

    return false;
}

int GetOperatorWeight(char op)
{
    int weight = -1;
    switch(op)
    {
        case '+':
        case '-':
            weight = 1;
        case '*':
        case '/':
            weight = 2;
        case '$':
            weight = 3;
    }
    return weight;
}

int HasHigherPrecedence(char op1, char op2)
{
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);

    // If operators have equal precedence, return true if they are left associative.
    // return false, if right associative.
    // if operator is left-associative, left one should be given priority.
    if(op1Weight == op2Weight)
    {

        return true;
    }
    return op1Weight > op2Weight ?  true: false;
}


bool isBalanced(string line){
    stack S;
    for (int i = 0; i < line.length(); ++i) {
        if (line[i] == '('|| line[i] == '{'||line[i] == '['){
            S.push(line[i]);
        }
        if (line[i] == ')'|| line[i] == '}'||line[i] == ']'){
            if(!S.isEmpty()){
                if (match(S.top(),line[i])){
                    S.pop();
                }
            }
            else return false;
        }
    }
    if(S.isEmpty()) return true;
    else return false;
}
bool match(char x, char y){
    if (x == '(' && y == ')') return true;
    if (x == '{' && y == '}') return true;
    if (x == '[' && y == ']') return true;
    else return false;
}

string math(string line){
    stack numbers;
    stack operands;
    string number ="";
    long result;
    for (int i = 0; i < line.length(); ++i) {
      if(isdigit(line[i])){
          numbers.push(line[i]);
      }

      else{
          number = numbers.top();
          long opt2 = atol(number);
          numbers.pop();
          number = numbers.top();
          long opt1 = atol(number);
          numbers.pop();
          if(line[i]=='+') result = opt1+opt2;
          if(line[i]=='-') result = opt1-opt2;
          if(line[i]=='*') result = opt1*opt2;
          number = char(result);
          numbers.push(char(result)); // long can't go into char here
      }

    }
        /*if(isdigit(line[i])){
            number += line[i];
        }
        else{
            numbers.push(number);  // string and char conflict
        }   // This won't work yet. Revisit later when getitng larger numbers to work
    }*/
    
}