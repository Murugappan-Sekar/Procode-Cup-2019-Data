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

const int max_test_files = 10;


//test_specific contents

const int maxn = 1e6, maxod = 1e9, maxm = 1e6;
void generate() {
	int n = rand() % maxn + 1;
	int m = rand() % maxm + 1;
	n=max(n,2);
	m=max(m,2);
	if (n > m)
		swap(n, m);
	out << n << " " << m << endl;
	for (int i = 1; i <= m; i++) {
		int sign = -1 * (rand() % 2);
		if (sign == 0)
			sign = 1;
		int od = rand() % maxod;
		out << sign*od << " ";
	}
}

void strong0() {
	int n = 3, m = 2;
	out << n << " " << m << endl;
	for (int i = 1; i <= m; i++)
		out << maxod << " ";
}

void strong1() {
	int n = 2, m = 3;
	out << n << " " << m << endl;
	for (int i = 1; i <= m; i++)
		out << -1 << " ";
}

void strong2() {
	int n = maxn, m = maxm;
	out << n << " " << m << endl;
	for (int i = 1; i <= m; i++) {
		int sign = -1 * (rand() % 2);
		if (sign == 0)
			sign = 1;
		int od = rand() % maxod;
		out << sign*od << " ";
	}
}

//end of test_specific contents


int main()
{
	srand(time(NULL));
	for (int i = 0; i < max_test_files; i++) {
		string file_name = "input/input" + to_string(i, 2) + ".txt";
		out.open(file_name.c_str(), std::ofstream::out | std::ofstream::trunc);
		assert(out.is_open());
		if (i == 0)
			strong0();
		else if (i == 1)
			strong1();
		else if (i == 2)
			strong2();
		else
			generate();
		out.close();
		assert(!out.is_open());
	}
	return 0;
}