#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

bitset<1> isR;

void getArr(string arr, int* nums){
    int i=1, len = arr.length();
    int index = 0;
    vector<int> numbers;
    if (len == 2){
        return;
    }
    while(i<len){
        int digits = 0;
        while(arr[i] != ',' && arr[i] != ']'){
            digits++;
            i++;
        }
        nums[index] = (stoi(arr.substr(i-digits,digits)));
        index++;
        i ++;
    }
    return;
}

void printArr(int* arr, int len){
    if(len == 0){
        cout<<"[]"<<endl;
        return;
    }
    cout<<"[";
    if(isR.none()){
        for (int i=0; i<len-1; i++){
            cout<<arr[i]<<',';
        }
        cout<<arr[len-1]<<']'<<endl;
    }
    else{
        for (int i= len-1; i>0; i--){
            cout<<arr[i]<<',';
        }
        cout<<arr[0]<<']'<<endl;
    }
    return;
}


int main(){
    int t,n;
    string p,nums;
    cin>>t;
    while(t>0){
        isR.reset();
        bool isE = false;
        cin>>p>>n>>nums;
        int index = 0;
        int totalFunc = p.length();
        int* originArr = new int[n];
        int len = n;
        getArr(nums, originArr);
        int* arr = originArr;
        while(index<totalFunc){
            int Rcount = 0, Dcount = 0;
            while (p[index] == 'R'){
                Rcount++;
                index++;
            }
            if (Rcount%2 == 1){
                isR.flip();
            }
            while (p[index] == 'D'){
                Dcount++;
                index++;
            }
            if (Dcount<=len){
                if (!isR.any()){
                    arr = arr + Dcount;
                }
                len -= Dcount;
            }
            else{
                cout<<"error"<<endl;
                isE = true;
                break;
            }
        }
        if(!isE){
            printArr(arr, len);
        }
        delete[] originArr;
        t--;
    }
}