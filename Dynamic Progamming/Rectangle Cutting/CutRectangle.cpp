// https://cses.fi/problemset/task/1744/
#include <bits/stdc++.h>

using namespace std;

int f[505][505];
int a, b;
const int inf = INT_MAX;

int main() {
	cin >> a >> b;
	for(int i=0; i<=a; i++){
		for(int j=0; j<=b; j++){
			if(i == j){
				f[i][j] = 0;
			}else{
				f[i][j] = inf;
			}
		}
	}
	
	for(int i=0; i<=a; i++){
		for(int j=0; j<=b; j++){
			for(int u=1; u<i; u++){
				f[i][j] = min(f[i][j], f[u][j] + f[i-u][j] + 1);
			}
			for(int v=1; v<j; v++){
				f[i][j] = min(f[i][j], f[i][v] + f[i][j-v] + 1);
			}
		}
	}
	
	cout << f[a][b] << endl;
	return 0;
}
