#include <iostream>
#include <vector>
#include <algorithm>

#define IO ios::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

struct Student{
    int country;
    int num;
    int score;

    Student(int c, int n, int s):country(c),num(n),score(s){}

    bool operator<(const Student& other) const{
        return score > other.score;
    }
};

int main() {
    IO;
    int n;
    cin >> n;
    vector<int> countryCnt(n);
    vector<Student> students;
    while(n--){
        int c,m,s;
        cin >> c >> m >> s;
        students.emplace_back(c,m,s);
    }
    sort(students.begin(),students.end());
    int prize = 0;
    for (Student st : students){
        if (countryCnt[st.country] < 2){
            countryCnt[st.country]++;
            cout << st.country << " " << st.num << '\n';
            prize++;
        }
        if (prize==3)
            break;
    }
}