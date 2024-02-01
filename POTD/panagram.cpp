#include<iostream>
#include<vector>
using namespace std;

class Solution
{
  public:
    //Function to check if a string is Pangram or not.
    bool checkPangram (string s) {
        // your code here
        vector<int> arr(26, 0);
        int count = 0;
        
        for(char &ch : s){
            if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z'){
                ch = tolower(ch);
                
                if(arr[ch - 'a'] == 0){
                    arr[ch - 'a']++;
                    count++;
                }
            }
        }
        return count == 26;
    }

};

//{ Driver Code Starts.

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        if (obj.checkPangram(s) == true)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return(0);
}