long long cost=0;
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<arr.size();i++){
            q.push(arr[i]);
        }
        while(q.size()>1){
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            cost+=a+b;
            q.push(a+b);
        }
        return cost;