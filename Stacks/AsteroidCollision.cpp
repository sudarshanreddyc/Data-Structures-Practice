class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;
        for (auto &num : asteroids)
        {
            bool isRetained = true;
            while (!st.empty() && st.top() > 0 && num < 0)
            {
                if (st.top() > abs(num))
                { // If top > num, then don't do anything
                    isRetained = false;
                    break;
                }
                // If top < then top will be exploded
                else if (st.top() < abs(num))
                {
                    st.pop();
                }
                else
                { // If both are same, both will explode
                    st.pop();
                    isRetained = false;
                    break;
                }
            }
            if (isRetained)
                st.push(num);
        }

        vector<int> res(st.size());
        int index = st.size() - 1;
        while (!st.empty())
        {
            res[index--] = st.top();
            st.pop();
        }
        return res;
    }
};