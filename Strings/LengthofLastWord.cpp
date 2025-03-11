class Solution
{
public:
    // int lengthOfLastWord(string s)
    // {
    //     bool wordStarted = false;
    //     int i = s.length() - 1;
    //     int len = 0;
    //     while (i >= 0)
    //     {
    //         if (s[i] != ' ')
    //         {
    //             len++;
    //             wordStarted = true;
    //         }
    //         else if (s[i] == ' ' && wordStarted)
    //         {
    //             return len;
    //         }
    //         i--;
    //     }
    //     return len;
    // }
    int lengthOfLastWord(string s)
    {
        bool wordStarted = false;
        int i = s.length() - 1;
        int len = 0;
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }
        while (i >= 0 && s[i] != ' ')
        {
            len++;
            i--;
        }
        return len;
    }
};
