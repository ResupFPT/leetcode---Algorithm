// https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/description/
#include<bits/stdc++.h>
using namespace std;

int const inf = 100005;
int dp[100005];

class Solution {
	public:
		int minimumPartition(string s, int k) {
        	int n = (int) s.length();
        	for(int i=0; i<n; i++){
        		dp[i] = inf;
			}
			dp[0] = 1;
			int curVal = s[0] - '0';
			for(int i=0; i<n; i++){
				curVal = curVal * 10 + s[i+1] - '0';
				if(curVal > k){
					if(s[i+1] - '0' > k){
						break;
					}
					dp[i+1] = min(dp[i+1], dp[i] + 1);
					curVal = s[i+1] - '0';
				}else{
					dp[i+1] = min(dp[i+1], dp[i]);
				}
			}
			
			int res = dp[n-1];
			int ans = (res == inf) ? -1 : res;
			
			return ans;
    	}
};

int main() {
	int k;
	string s;
	cin >> s >> k;
	Solution sol;
	int ans = sol.minimumPartition(s, k);
	cout << ans << endl;
	
	return 0;
}
