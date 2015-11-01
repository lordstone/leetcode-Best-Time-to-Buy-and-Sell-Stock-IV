class Solution {
public:

    bool operator() (const int& lhs, const int&rhs) const
    {
        return (lhs<rhs);
    }
    
    int solveIt(vector<int> arr){
        int sum = 0;
        int lowest = arr[0];
        for(int i = 1; i < arr.size() ; i ++){
            if(arr[i] < lowest){
                lowest = arr[i];
                continue;
            }
            if(arr[i] > arr[i-1]){
                sum += arr[i] - arr[i-1];
            }else{
                lowest = arr[i];
            }
        }
        return sum;
    }


    int maxProfit(int k, vector<int>& prices) {
        if(k == 0 || prices.size() <= 1) return 0;
        if (prices.empty()) return 0;
        if (k >= prices.size()) return solveIt(prices);
        int g[k + 1] = {0};
        int l[k + 1] = {0};
        for (int i = 0; i < prices.size() - 1; ++i) {
            int diff = prices[i + 1] - prices[i];
            for (int j = k; j >= 1; --j) {
                l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
                g[j] = max(g[j], l[j]);
            }
        }
        return g[k];
    }
};
