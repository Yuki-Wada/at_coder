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

static const ll MOD = 1000000007LL;

ll getModValue(const ll& n, ll mod)
{
	return (n % mod + mod) % mod;
}

// computational complexity: o(log(max(a, b))) 
inline pair<ll, ll> getBezoutsIdentitySolution(ll a, ll b)
{
	if (b == 0)
	{
		return { 1, 0 };
	}
	auto sol = getBezoutsIdentitySolution(b, a % b);
	return { sol.second, sol.first - (a / b) * sol.second };
}

// computational complexity: o(log(max(n, mod))) 
inline ll getModInverse(const ll& n, ll mod)
{
	auto sol = getBezoutsIdentitySolution(n, mod);
	if (n * sol.first + mod * sol.second != 1)
	{
		return -1;
	}
	return getModValue(sol.first, mod);
}

template<unsigned int Mod> class ResidueInteger;
template<unsigned int Mod> ResidueInteger<Mod>& operator+=(ResidueInteger<Mod>& lhs, const ResidueInteger<Mod>& rhs);
template<unsigned int Mod> ResidueInteger<Mod>& operator+=(ResidueInteger<Mod>& lhs, const ll& rhs);
template<unsigned int Mod> ResidueInteger<Mod>& operator-=(ResidueInteger<Mod>& lhs, const ResidueInteger<Mod>& rhs);
template<unsigned int Mod> ResidueInteger<Mod>& operator-=(ResidueInteger<Mod>& lhs, const ll& rhs);
template<unsigned int Mod> ResidueInteger<Mod>& operator*=(ResidueInteger<Mod>& lhs, const ResidueInteger<Mod>& rhs);
template<unsigned int Mod> ResidueInteger<Mod>& operator*=(ResidueInteger<Mod>& lhs, const ll& rhs);
template<unsigned int Mod> ResidueInteger<Mod>& operator/=(ResidueInteger<Mod>& lhs, const ResidueInteger<Mod>& rhs);
template<unsigned int Mod> ResidueInteger<Mod>& operator/=(ResidueInteger<Mod>& lhs, const ll& rhs);
template<unsigned int Mod> std::istream& operator>>(std::istream& lhs, ResidueInteger<Mod>& rhs);

template<unsigned int Mod>
class ResidueInteger
{
private:
	ll n_;
public:
	ResidueInteger() : n_(getModValue(0, Mod)) {}
	ResidueInteger(ll n) : n_(getModValue(n, Mod)) {}

	ll mod() const { return Mod; }
	ll n() const { return n_; }

	friend ResidueInteger& operator+= <>(ResidueInteger& lhs, const ResidueInteger& rhs);
	friend ResidueInteger& operator+= <>(ResidueInteger& lhs, const ll& rhs);
	friend ResidueInteger& operator-= <>(ResidueInteger& lhs, const ResidueInteger& rhs);
	friend ResidueInteger& operator-= <>(ResidueInteger& lhs, const ll& rhs);
	friend ResidueInteger& operator*= <>(ResidueInteger& lhs, const ResidueInteger& rhs);
	friend ResidueInteger& operator*= <>(ResidueInteger& lhs, const ll& rhs);
	friend ResidueInteger& operator/= <>(ResidueInteger& lhs, const ResidueInteger& rhs);
	friend ResidueInteger& operator/= <>(ResidueInteger& lhs, const ll& rhs);
	friend std::istream& operator>> <>(std::istream& lhs, ResidueInteger& rhs);
};

template<unsigned int Mod> inline ResidueInteger<Mod> operator+(const ResidueInteger<Mod>& lhs, const ResidueInteger<Mod>& rhs){ return lhs.n() + rhs.n(); }
template<unsigned int Mod> inline ResidueInteger<Mod> operator+(const ResidueInteger<Mod>& lhs, const ll& rhs){ return lhs.n() + getModValue(rhs, Mod); }
template<unsigned int Mod> inline ResidueInteger<Mod> operator+(const ll& lhs, const ResidueInteger<Mod>& rhs) { return getModValue(lhs, Mod) + rhs.n(); }
template<unsigned int Mod> inline ResidueInteger<Mod>& operator+=(ResidueInteger<Mod>& lhs, const ResidueInteger<Mod>& rhs) { lhs.n_ = getModValue(lhs.n() + rhs.n(), Mod); return lhs; }
template<unsigned int Mod> inline ResidueInteger<Mod>& operator+=(ResidueInteger<Mod>& lhs, const ll& rhs){ lhs.n_ = getModValue(lhs.n() + getModValue(rhs, Mod), Mod); return lhs; }
template<unsigned int Mod> inline ResidueInteger<Mod> operator-(const ResidueInteger<Mod>& lhs, const ResidueInteger<Mod>& rhs) { return lhs.n() - rhs.n(); }
template<unsigned int Mod> inline ResidueInteger<Mod> operator-(const ResidueInteger<Mod>& lhs, const ll& rhs) { return lhs.n() - getModValue(rhs, Mod), Mod; }
template<unsigned int Mod> inline ResidueInteger<Mod> operator-(const ll& lhs, const ResidueInteger<Mod>& rhs) { return getModValue(lhs, Mod) - rhs.n(); }
template<unsigned int Mod> inline ResidueInteger<Mod>& operator-=(ResidueInteger<Mod>& lhs, const ResidueInteger<Mod>& rhs) { lhs.n_ = getModValue(lhs.n() - rhs.n(), Mod); return lhs; }
template<unsigned int Mod> inline ResidueInteger<Mod>& operator-=(ResidueInteger<Mod>& lhs, const ll& rhs) { lhs.n_ = getModValue(lhs.n() - getModValue(rhs, Mod), Mod); return lhs; }
template<unsigned int Mod> inline ResidueInteger<Mod> operator*(const ResidueInteger<Mod>& lhs, const ResidueInteger<Mod>& rhs) { return lhs.n() * rhs.n(); }
template<unsigned int Mod> inline ResidueInteger<Mod> operator*(const ResidueInteger<Mod>& lhs, const ll& rhs) { return lhs.n() * getModValue(rhs, Mod); }
template<unsigned int Mod> inline ResidueInteger<Mod> operator*(const ll& lhs, const ResidueInteger<Mod>& rhs) { return getModValue(lhs, Mod) * rhs.n(); }
template<unsigned int Mod> inline ResidueInteger<Mod>& operator*=(ResidueInteger<Mod>& lhs, const ResidueInteger<Mod>& rhs) { lhs.n_ = getModValue(lhs.n() * rhs.n(), Mod); return lhs; }
template<unsigned int Mod> inline ResidueInteger<Mod>& operator*=(ResidueInteger<Mod>& lhs, const ll& rhs) { lhs.n_ = getModValue(lhs.n() * getModValue(rhs, Mod), Mod); return lhs; }
template<unsigned int Mod> inline ResidueInteger<Mod> operator/(const ResidueInteger<Mod>& lhs, const ResidueInteger<Mod>& rhs) { return lhs.n() * getModInverse(rhs.n(), Mod); }
template<unsigned int Mod> inline ResidueInteger<Mod> operator/(const ResidueInteger<Mod>& lhs, const ll& rhs) { return lhs.n() * getModInverse(getModValue(rhs, Mod), Mod); }
template<unsigned int Mod> inline ResidueInteger<Mod> operator/(const ll& lhs, const ResidueInteger<Mod>& rhs) { return getModValue(lhs, Mod) * getModInverse(rhs.n(), Mod); }
template<unsigned int Mod> inline ResidueInteger<Mod>& operator/=(ResidueInteger<Mod>& lhs, const ResidueInteger<Mod>& rhs) { lhs.n_ = getModValue(lhs.n() * getModInverse(rhs.n(), Mod), Mod); return lhs; }
template<unsigned int Mod> inline ResidueInteger<Mod>& operator/=(ResidueInteger<Mod>& lhs, const ll& rhs) { lhs.n_ = getModValue(lhs.n() * getModInverse(getModValue(rhs, Mod), Mod), Mod); return lhs; }
template<unsigned int Mod> inline bool operator==(const ResidueInteger<Mod>& lhs, const ResidueInteger<Mod>& rhs) { return lhs.n() == rhs.n(); }
template<unsigned int Mod> inline bool operator==(const ResidueInteger<Mod>& lhs, const ll& rhs) { return lhs.n() == getModValue(rhs, Mod); }
template<unsigned int Mod> inline bool operator==(const ll& lhs, const ResidueInteger<Mod>& rhs) { return getModValue(lhs, Mod) == rhs.n(); }

template<unsigned int Mod>
std::ostream& operator<<(std::ostream& lhs, const ResidueInteger<Mod>& rhs)
{
	return lhs << rhs.n();
}

template<unsigned int Mod>
std::istream& operator>>(std::istream& lhs, ResidueInteger<Mod>& rhs)
{
	lhs >> rhs.n_;
	return lhs;
}

using rll = ResidueInteger<MOD>;

vector<rll> get_exclamations(ull n) {
	vector<rll> exclamations(n + 1ULL);
	exclamations[0] = 1LL;
	for (ll i = 1; i <= n; ++i) exclamations[i] = exclamations[i - 1] * i;

	return exclamations;
}
