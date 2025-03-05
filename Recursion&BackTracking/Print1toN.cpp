#include<bits/stdc++.h> 
using namespace std; 

class Solution
{
private:
    void printNosHelper(int N, int current = 1){
        if(current > N) return;
        cout<<current++<<" ";
        printNosHelper(N, current);
    }
public:
    void printTillN(int N)
    {
        printNosHelper(N);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        ob.printTillN(N);
        cout<<endl;
    }
    return 0;
}
