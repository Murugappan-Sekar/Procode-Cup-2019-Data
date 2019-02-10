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

const int max_test_files = 10,maxn=1000;


//test_specific contents
mt19937_64 rng(time(NULL)); //random generator

void generate() {
	int val=rng()%maxn;
	int sign=rng()%2;
	if(sign==0) sign--; //make negative
	val*=sign;
	out <<val<<' ';
	
	val=rng()%maxn;
	sign=rng()%2;
	if(sign==0) sign--;
	val*=sign;
	out <<val<<' ';

	val=rng()%maxn;
	sign=rng()%2;
	if(sign==0) sign--;
	val*=sign;
	out <<val;
}

void strong0() {
	out<<0<<' '<<0<<' '<<0;
}

void strong1() {
	out<<0<<' '<<-3<<' '<<5;
}

void strong2() {
	out<<3<<' '<<-1<<' '<<0;
}

//end of test_specific contents


int main()
{
	srand(time(NULL));
	for (int i = 0; i < max_test_files; i++) {
		string file_name = "input/input" + to_string(i, 2) + ".txt";
		out.open(file_name.c_str(), std::ofstream::out | std::ofstream::trunc);
		assert(out.is_open());
		int t=1000;
		out<<t<<endl;
		while(t--)
		{
			if (t == 999)
				strong0();
			else if (t == 998)
				strong1();
			else if (t == 997)
				strong2();
			else
				generate();
			out<<endl;
		}
		
		out.close();
		assert(!out.is_open());
	}
	return 0;
}