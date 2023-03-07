#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; //계단의 수
	cin >> n;
	int s[301]; //입력받은 계단의 점수 저장
	int dp[301]; //총 점수 누적
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	dp[0] = 0; //쓰이지않는인덱스와값
	dp[1] = s[1];
	dp[2] = s[1] + s[2];
	dp[3] = max(s[1] + s[3], s[2] + s[3]);
	for (int i = 4; i <= n; i++) {
		dp[i] = max(dp[i - 2] + s[i], dp[i - 3] + s[i - 1] + s[i]);
	}
	cout << dp[n] << "\n";
	return 0;
}