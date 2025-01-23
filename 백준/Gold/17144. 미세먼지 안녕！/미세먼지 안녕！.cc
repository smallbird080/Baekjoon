#include <iostream>
#include <bitset>

using namespace std;

int r;
int c;

void spread(int** m, const int purifier){
    int** copy = new int*[r];
    for (int i=0; i<r; i++){
        copy[i] = new int[c];
        for (int j=0; j<c; j++){
            copy[i][j] = m[i][j];
        }
    }
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (copy[i][j] == -1 || copy[i][j] == 0)
                continue;
            int dust = copy[i][j]/5;
            if (i>0 && m[i-1][j] != -1){
                m[i][j] -= dust;
                m[i-1][j] += dust;
            }
            if (i<r-1 && m[i+1][j] != -1){
                m[i][j] -= dust;
                m[i+1][j] += dust;
            }
            if (j>0 && m[i][j-1] != -1){
                m[i][j] -= dust;
                m[i][j-1] += dust;
            }
            if (j<c-1 && m[i][j+1] != -1){
                m[i][j] -= dust;
                m[i][j+1] += dust;
            }
        }
    }
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            m[i][j] = m[i][j] < 0 ? 0 : m[i][j];
        }
    }
    m[purifier][0] = -1;
    m[purifier+1][0] = -1;

    for (int i=0; i<r; i++)
        delete[] copy[i];
    delete[] copy;
}

void cycle(int** m, const int up, const int down){
    int* upH = new int[c];
    int* upLo = new int[c];
    int* downH = new int[c];
    int* downLo = new int[c];
    int* R = new int[r];
    int* L = new int[r];

    for (int i=0; i<c; i++){
        upH[i] = m[0][i];
        upLo[i] = m[up][i];
        downH[i] = m[down][i];
        downLo[i] = m[r-1][i];
    }

    for (int i=0; i<r; i++){
        L[i] = m[i][0];
        R[i] = m[i][c-1];
    }

    m[up][1] = 0;
    m[down][1] = 0;

    for (int i=2; i<c; i++)
        m[up][i] = upLo[i-1];
    for (int i=0; i<up; i++)
        m[i][c-1] = R[i+1];
    if (up != 0){
        for (int i=0; i<c-1; i++)
            m[0][i] = upH[i+1];
        m[0][c-1] = R[1];
    }
    for (int i=1; i<up; i++)
        m[i][0] = L[i-1];
    
    for (int i=2; i<c; i++)
        m[down][i] = downH[i-1];
    for (int i=down+1; i<r; i++)
        m[i][c-1] = R[i-1];
    if (down != r-1){
        for (int i=0; i<c-1; i++)
            m[r-1][i] = downLo[i+1];
        m[r-1][c-1] = R[r-2];
    }
    for (int i=down+1; i<r-1; i++)
        m[i][0] = L[i+1];

    delete[] upH;
    delete[] upLo;
    delete[] downH;
    delete[] downLo;
    delete[] R;
    delete[] L;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t,up=-1,down=-1;
    cin >> r >> c >> t;
    int** room = new int*[r];
    for (int i=0; i<r; i++){
        room[i] = new int[c];
        for (int j=0; j<c; j++){
            cin >> room[i][j];
            if (room[i][j] == -1 && up==-1){
                up = i;
                down = i+1;
            }
        }
    }
    while (t--){
        spread(room,up);
        cycle(room,up,down);
    }

    long sum=0;
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            sum += room[i][j] > 0 ? room[i][j] : 0;
        }
    }
    cout << sum;

    for (int i=0; i<r; i++)
        delete[] room[i];
    delete[] room;
}