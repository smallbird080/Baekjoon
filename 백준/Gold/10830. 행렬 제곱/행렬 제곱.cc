#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

typedef unsigned long long ULL;

using namespace std;

struct Matrix{
    int dim;
    vector<vector<ULL>> mat;
    Matrix(int d):dim(d){
        mat = vector<vector<ULL>>(dim,vector<ULL>(dim,0));
    }
    Matrix(){}

    Matrix operator*(const Matrix& other){
        Matrix res(dim);
        for (int i=0; i<dim; i++){
            for (int j=0; j<dim; j++){
                for (int k=0; k<dim; k++){
                    res.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
                res.mat[i][j] %= 1000;
            }
        }
        return res;
    }

    void printMat(){
        for (int i=0; i<dim; i++){
            for (int j=0; j<dim; j++){
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

Matrix I;

Matrix DnQpow(Matrix& a, ULL b){
    if (b==0)
        return I;
    if (b==1)
        return a*I;
    Matrix half = DnQpow(a,b/2);
    if (b&1)
        return half*half*a;
    else
        return half*half;
}

int main() {
    IO;
    int n;
    ULL b;
    cin >> n >> b;
    I = Matrix(n);
    for (int i=0; i<n; i++){
        I.mat[i][i]=1;
    }
    Matrix A(n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> A.mat[i][j];
        }
    }
    Matrix result = DnQpow(A,b);
    result.printMat();
}