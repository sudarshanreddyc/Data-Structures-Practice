class Solution
{
public:
    int performOperation(int operand1, int operand2, string op)
    {
        if (op == "+")
            return operand1 + operand2;
        else if (op == "-")
            return operand1 - operand2;
        else if (op == "*")
            return operand1 * operand2;
        else if (op == "/")
            return operand1 / operand2;
        return -1;
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<int> myStack;
        for (string &s : tokens)
        {
            if (s == "/" || s == "*" || s == "+" || s == "-")
            {
                int operand2 = myStack.top();
                myStack.pop();
                int operand1 = myStack.top();
                myStack.pop();
                int result = performOperation(operand1, operand2, s);
                myStack.push(result);
            }
            else
                myStack.push(stoi(s));
        }
        return myStack.top();
    }
};