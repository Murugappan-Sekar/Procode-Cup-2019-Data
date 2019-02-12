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

ifstream in;

const int max_test_files = 10;



//test_specific contents

const int minn = 2, maxn = 1e6, minm = 2, maxm = 1e6;
const int minod = -1e9, maxod = 1e9;

void check() {
	vector<int> v;
	int tmp;
	while (in >> tmp)
		v.pb(tmp);
	assert(v.size() > 2);
	assert(v[0] >= minn);
	assert(v[0] <= maxn);
	assert(v[1] >= minm);
	assert(v[1] <= maxm);
	assert(v.size() == (v[1] + 2));
	for (int i = 2; i < v.size(); i++) {
		assert(v[i] >= minod);
		assert(v[i] <= maxod);
	}
}
//end of test_specific contents


int main()
{
	srand(time(NULL));
	for (int i = 0; i < max_test_files; i++) {
		string file_name = "input/input" + to_string(i, 2) + ".txt";
		in.open(file_name.c_str(), std::ifstream::in);
		assert(in.is_open());
		check();
		in.close();
		assert(!in.is_open());
	}
	return 0;
}