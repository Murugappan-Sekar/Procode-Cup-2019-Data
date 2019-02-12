#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define x first
#define y second
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define PI (atan(1)*4)
#define mp make_pair
using namespace std;

string to_string(int num, int dig) {
	string s = "";
	for (int i = 0; i < dig; i++) {
		s += ((num % 10) + '0');
		num /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

ofstream out;
ifstream in;

const int max_test_files = 10;

//test_specific contents


ll bsrch(vector<ll>& v, int n, ll l, ll r) {
	if (l == r)
		return l;
	ll mid = (l + r + 1) / 2;
	int cnt = 0;
	ll sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
		sum = max(sum, 0LL);
		if (sum >= mid) {
			cnt++;
			sum = 0;
		}
	}
	if (cnt >= n)
		return bsrch(v, n, mid, r);
	else
		return bsrch(v, n, l, mid - 1);
}

void solve() {
	int n, m;
	in >> n >> m;
	vector<ll> v(m);
	for (int i = 0; i < m; i++)
		in >> v[i];
	if (n > m)
		out << 0;
	else
		out << bsrch(v, n, 0, 1e15);
}
//end of test_specific contents

int main()
{
	srand(time(NULL));
	for (int i = 0; i < max_test_files; i++) {
		string file_name_ip = "input/input" + to_string(i, 2) + ".txt";
		string file_name_op = "output/output" + to_string(i, 2) + ".txt";
		in.open(file_name_ip.c_str(), std::ifstream::in);
		out.open(file_name_op.c_str(), std::ofstream::out | std::ofstream::trunc);
		assert(out.is_open());
		assert(in.is_open());
		solve();
		out.close();
		in.close();
		assert(!in.is_open());
		assert(!out.is_open());
	}
	return 0;
}