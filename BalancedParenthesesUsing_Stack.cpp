#include <iostream>
#include <stack>
using namespace std;
bool arePaired(char open, char close)
{
	if (open == '(' && close == ')')
		return true;
	if (open == '[' && close == ']')
		return true;
	if (open == '{' && close == '}')
		return true;
	return false;
}
bool areBalanced(string exp)
{
	stack<int>s;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
			s.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
		{
			if (s.empty() || !arePaired(s.top(), exp[i]))
				return false;
			else
				s.pop();
		}
	}
	return s.empty();
}
int main()
{
	string expression;
	cin >> expression;
	if (areBalanced(expression))
		cout << "Balanced\n";
	else
		cout << "Not Balanced\n";
}