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

const int max_test_files = 10,maxn=1000,minn=-1000;



//test_specific contents


void check() {
	ll i,h,c;
	in>>i>>h>>c;
	assert(i >= minn);
	assert(i <= maxn);

	assert(h >= minn);
	assert(h <= maxn);
	
	assert(c >= minn);
	assert(c <= maxn);
	

}
//end of test_specific contents


int main()
{
	srand(time(NULL));
	for (int i = 0; i < max_test_files; i++) {
		string file_name = "input/input" + to_string(i, 2) + ".txt";
		in.open(file_name.c_str(), std::ifstream::in);
		assert(in.is_open());
		int t=1000;
		while(t--)
			check();
		in.close();
		assert(!in.is_open());
	}
	return 0;
}