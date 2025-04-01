class Solution
{
public:
    string removeStars(string s)
    {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                if (!st.empty())
                    st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        string res(st.size(), NULL); // size accepts number and char(can be empty space' ' or NULL or any char)
        int index = st.size() - 1;
        while (!st.empty())
        {
            res[index--] = st.top();
            st.pop();
        }
        return res;
    }
};