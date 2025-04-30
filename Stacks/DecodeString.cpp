class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> numbers;
        stack<string> strStack;
        string currStr = "";
        int num = 0;
        for (auto &c : s)
        {
            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            else if (c == '[')
            {
                numbers.push(num); // We can't just push in the above if as there may be multi digit number. So, first calculate the number and then push.
                num = 0;
                strStack.push("[");
            }
            else if (isalpha(c))
            {
                strStack.push(string(1, c));
            }
            else if (c == ']')
            {
                while (!strStack.empty() && strStack.top() != "[")
                {
                    currStr = strStack.top() + currStr;
                    strStack.pop();
                }
                strStack.pop(); // Remove [ from stack
                int repeat = numbers.top();
                numbers.pop();
                string repeated = "";
                while (repeat-- > 0)
                {
                    repeated += currStr;
                }
                strStack.push(repeated);
                currStr = "";
            }
        }

        string result = "";
        while (!strStack.empty())
        {
            result = strStack.top() + result;
            strStack.pop();
        }
        return result;
    }
};