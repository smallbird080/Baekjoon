#include <iostream>
#include <algorithm>
#include <vector>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

typedef unsigned long long ull;
#define MATRIX vector<vector<ull>>

using namespace std;

const MATRIX A={{1, 1},
                {1, 0}};

const MATRIX I={{1, 0},
                {0, 1}};

MATRIX matMul(const MATRIX& m1, const MATRIX& m2){
    MATRIX result(2,vector<ull>(2,0));
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            for (int k=0; k<2; k++){
                result[i][j] += m1[i][k] * m2[k][j];
            }
            result[i][j] %= 1000000007;
        }
    }
    return result;
}

MATRIX matPow(ull n){
    if (n == 0)
        return I;
    if (n == 1)
        return A;

    MATRIX subMat = matPow(n/2);

    if (n&1)
        return matMul(matMul(subMat,subMat),A);
    return matMul(subMat,subMat);
}

int main()
{
    IO;
    ull n;
    cin >> n;
    n--;
    MATRIX ApowN = matPow(n);
    cout << ApowN[0][0];
}