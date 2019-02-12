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

void solve() {
	ll fact[19];
	fact[0] = 1;
	for (int i = 1; i <= 18; i++)
		fact[i] = i * fact[i - 1];
	ll n, tot_len=0, denom=1;
	in >> n;
	for (int i = 2; i <= n; i++) {
		int f = 0;
		while (n % i == 0) {
			n /= i;
			f++;
		}
		tot_len += f;
		denom *= fact[f];
	}
	assert(tot_len <= 18);
	out << (fact[tot_len] / denom);

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