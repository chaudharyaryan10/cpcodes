
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:

    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        int mini= stalls[0];
        int maxi = stalls[n-1];
        int l=1;
        int h = (maxi-mini);
        int mid,ans=0;
        
        while(l<=h){
            mid=(l+h)/2;
            int c=1;
            int pr=0;
            for(int i=1;i<n;i++){
                if((stalls[i]-stalls[pr])>=mid){
                    c++;
                    pr=i;
                }
            }
            if(c>=k){
                ans=max(ans,mid);
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans;
    }
};

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
