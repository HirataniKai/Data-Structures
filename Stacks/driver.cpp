// Kai Hiratani

#include <iostream>
#include <string>
using namespace std;

#include "linkedStack.h"

string infixToPostfix(string);
int postfixToValue(string);
bool isOperator(char);
bool isGreaterPrecedence(char, char);
int doMath(char, int, int);

int main(){
    string infix, postfix;
    int result;
    
    cout << "Enter your arithmetic expression: ";
    getline(cin, infix);

    postfix = infixToPostfix(infix);
    cout << postfixToValue(postfix) << endl;

    return 0;
}

string infixToPostfix(string input){
    string output;
    LinkedStack<char> operators;

    for(int i = 0; i < input.length(); i++){
        char current = input[i];
        if(isOperator(current)){
            while(!operators.isEmpty() && isGreaterPrecedence(operators.peek(), current)){
                output += operators.peek();
                operators.pop();
            }
       
            operators.push(current);
        }
        else{
            output += current;
        }
    }

    while(!operators.isEmpty()){
        output += operators.peek();
        operators.pop();
    }

    return output;
}

int postfixToValue(string input){
    LinkedStack<int> operands;

    for(int i = 0; i < input.length(); i++){
        char current = input[i];
        if(isOperator(current)){
            int leftOperand = operands.peek();
            operands.pop();

            int rightOperand = operands.peek();
            operands.pop();            

            operands.push(doMath(current, rightOperand, leftOperand));
        }
        else{
            operands.push(current - '0');
        }
    }
    return operands.peek();
}

bool isOperator(char symbol){
    return symbol == '+'
        || symbol == '-'
        || symbol == '/'
        || symbol == '*'
        || symbol == '%';
}

bool isGreaterPrecedence(char first, char last){
    if(first == '*' || first == '/' || first == '%'){
        if(last == '+' || last == '-'){
            return true;
        }
    }
    return false;
}

int doMath(char operation, int operand1, int operand2){
    switch (operation){
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    case '%':
        return operand1 % operand2;
    }
}