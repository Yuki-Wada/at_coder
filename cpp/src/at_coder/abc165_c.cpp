//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>

#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

#include <stdexcept>

using namespace std;

// type alias
using ll = long long;
using ull = unsigned long long;
using comp = complex<double>;

const ll MOD = 1000000007LL;
const double PI = 3.14159265358979323846;

//conversion
//------------------------------------------
inline int toint(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class t> inline string tostring(t x) { ostringstream sout; sout << x; return sout.str(); }

//debug
#define DUMP(x)  cerr << #x << " = " << (x) << endl
#define DEBUG(x) cerr << #x << " = " << (x) << " (l" << __line__ << ")" << " " << __file__ << endl


ll get_result(vector<ll>& As, vector<vector<ll>>& abcds) {
	ll res = 0;
	for (ll i = 0; i < abcds.size(); ++i) {
		if (As[abcds[i][1]] - As[abcds[i][0]] == abcds[i][2]) {
			res += abcds[i][3];
		}
	}
	return res;
}

ll solve(vector<ll>& As, ll idx, ll M, vector<vector<ll>>& abcds) {
	if (idx == As.size()) {
		return get_result(As, abcds);
	}

	ll A_begin = (idx > 0 ? As[idx - 1] : 1);
	ll res = 0;
	for (ll i = A_begin; i <= M; ++i) {
		As[idx] = i;
		res = max(res, solve(As, idx + 1, M, abcds));
	}
	return res;
}

//main function
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N, M, Q;
	cin >> N >> M >> Q;

	vector<vector<ll>> abcds(Q, vector<ll>(4));
	for (ll i = 0; i < Q; ++i) {
		cin >> abcds[i][0] >> abcds[i][1] >> abcds[i][2] >> abcds[i][3];
		--abcds[i][0], --abcds[i][1], abcds[i][2], abcds[i][3];
	}

	vector<ll> As(N);
	ll res = solve(As, 0, M, abcds);
	cout << res << endl;

	return 0;
}
