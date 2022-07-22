class Solution
{
    public:
    
    static bool comp(Item p1, Item p2){
        double c1 = (double)p1.value/p1.weight;
        double c2 = (double)p2.value/p2.weight;
        return c1>c2;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        double ans = 0;
        for(int i=0;i<n;i++){
            if(W==0) break;
            int take = min(arr[i].weight,W);
            double amount = (double)arr[i].value/arr[i].weight;
            ans += (amount*take);
            W -= take;
        }
        return ans;
    }
};
