class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;

        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i <= n - m; i++)
        {
            int j = 0;
            // Check if the substring matches the needle
            while (j < m && haystack[i + j] == needle[j])
            {
                j++;
            }
            if (j == m)
                return i;
        }

        return -1;
    }
    // int strStr(const std::string& haystack, const std::string& needle) {
    //     if (needle.empty()) return 0;

    //     int n = haystack.size();
    //     int m = needle.size();

    //     for (int i = 0; i <= n - m; i++) {
    //         if (haystack.substr(i, m) == needle) {
    //             return i;
    //         }
    //     }

    //     return -1;
    // }
};
