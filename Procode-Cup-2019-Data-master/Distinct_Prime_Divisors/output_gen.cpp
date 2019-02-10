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
//compute primes between 1 and 10^3
vector<int>primes;
void compute_primes()
{
	primes.pb(2);
	for(int i=3;i<=1000;++i)
	{
		int f=0;
		for(int j=2;j<i;++j)
		{
			if(i%j==0)
			{
				f=1;
				break;
			}
		}
		if(!f)
		{
			//cout<<i<<endl;
			primes.pb(i);
		}
	}
}

void solve() {
	ll n;
	in>>n;
	if(n==1)
	{
		out<<1<<endl<<1;
	}
	else
	{
		//cout<<n<<endl;
		set<ll>s;
		ll max_sq_number=sqrt(n);
		//cout<<max_sq_number<<endl;
		for(int i=1;i<=max_sq_number;++i)
		{
			for(int j=0;j<primes.size();++j)
			{
				if(i%primes[j]==0)
				{
					s.insert(primes[j]);
				}
			}
			//find all distinct prime divisors
		}
		out<<s.size()<<endl;
		set<ll>::iterator it;
		for(it=s.begin();it!=s.end();++it)
		{
			out<<*it<<' ';
		}

	}
}
//end of test_specific contents

int main()
{
	srand(time(NULL));
	compute_primes();
	// cout<<primes.size()<<endl;
	// for(int i=0;i<primes.size();++i)
	// {
	// 	cout<<primes[i]<<endl;;
	// }
	// cout<<"check"<<endl;
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