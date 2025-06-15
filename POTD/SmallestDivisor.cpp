class Solution {
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int n=arr.size();
        int l=1;
        int max_=*max_element(arr.begin(),arr.end());
    
        int ans=max_;
        while(l<=max_){
            int mid=(l+max_)/2;
            int cnt=0;
            for(auto &e:arr){
                cnt+=ceil((double)e/mid);
            }
            if(cnt<=k){
                ans=mid;
                max_=mid-1;
            }else
                l=mid+1;
        }
        return ans;
    }
};
