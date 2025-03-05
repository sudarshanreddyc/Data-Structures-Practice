class Solution
{
public:
    bool isCharOfSameType(char fromString, char topOfTheStack)
    {
        if (fromString == ')' && topOfTheStack == '(')
            return true;
        else if (fromString == '}' && topOfTheStack == '{')
            return true;
        else if (fromString == ']' && topOfTheStack == '[')
            return true;
        return false;
    }
    bool isValid(string s)
    {
        stack<char> myStack;
        for (char &c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                myStack.push(c);
            }
            else if (!myStack.empty() && isCharOfSameType(c, myStack.top()))
            {
                myStack.pop();
            }
            else
                return false;
        }
        return myStack.empty() ? true : false;
    }
};