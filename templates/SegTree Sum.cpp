vector<int> tree;
    int n;
    int merge(int l ,int r)
    {
        return l+r;
    }
    int query(int start,int end, int node, int left, int right)
    {
        if(left==start&&right==end) return tree[node];
        if(left>right) return 0;
        int mid=start+(end-start)/2;
        return query(start,mid,2*node,left,min(right,mid))+query(mid+1,end,2*node+1,max(left,mid+1),right);
    }
    void build(vector<int>&nums,int start,int end,int node)
    {
        if(start==end)
        {
            tree[node]=nums[start];
            return;
        }
        int mid=start+(end-start)/2;
        build(nums,start,mid,2*node);
        build(nums,mid+1,end,2*node+1);
        tree[node]=merge(tree[2*node],tree[2*node+1]);
    }
    void update(int start,int end,int node,int idx,int val)
    {
        if(start==idx&&end==idx)
        {
            tree[node]=val;
            return;
        }
        int mid=start+(end-start)/2;
        if(idx<=mid)
        {
            update(start,mid,2*node,idx,val);
        }
        else
        {
            update(mid+1,end,2*node+1,idx,val);
        }
        tree[node]=merge(tree[2*node],tree[2*node+1]);
    }