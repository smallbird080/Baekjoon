#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

ll a,b,c;

ll div_conq_power(ll n){
    if (n==0)
        return 1;
    if (n==1)
        return a % c;
    
    ll divd = div_conq_power(n/2)%c;

    if (n%2==0)
        return divd * divd % c;
    else
        return divd * divd % c * a % c;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);
    cin >> a >> b >> c;
    cout << div_conq_power(b);
}