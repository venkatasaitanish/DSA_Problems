class Solution
{
    public:
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({end[i],start[i]});
        }
        sort(v.begin(),v.end());
        
        int cnt = 1;
        int prev = v[0].first;
        for(int i=1;i<n;i++){
            if(v[i].second>prev){
                cnt++;
                prev = v[i].first;
            }
        }
        return cnt;
    }
};
