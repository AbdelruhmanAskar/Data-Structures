#include <iostream>
#include <stack>
using namespace std;

// Helper function to check if the opening and closing characters match
bool arePaired(char open, char close)
{
    // Check if (parentheses, square brackets or curly braces) are matched
    if (open == '(' && close == ')') 
        return true;
    if (open == '[' && close == ']')
        return true;
    if (open == '{' && close == '}')
        return true;
    return false;
}

// Function to check if the expression has balanced parentheses, brackets, and braces
bool areBalanced(string exp)
{
    stack<int> s; // Stack to keep track of opening characters
    for (int i = 0; i < exp.length(); i++) // Iterate through each character in the expression
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') // If the character is an opening bracket
            s.push(exp[i]); // Push it onto the stack
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') // If the character is a closing bracket
        {
            if (s.empty() || !arePaired(s.top(), exp[i])) // Check if the stack is empty or the top doesn't match the closing bracket
                return false; // If not balanced, return false
            else
                s.pop(); // If matched, pop the opening character from the stack
        }
    }
    return s.empty();
}

int main()
{
    string expression;
    cin >> expression;
    if (areBalanced(expression)) // Call the areBalanced function to check the expression
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
}
