#include <iostream>
#include <string>
#include <map>
#include <vector>

std::string MBTIs[] = {"INTP","INTJ","INFP","INFJ","ISTP","ISFP","ISTJ","ISFJ","ENTP","ENTJ","ENFP","ENFJ","ESTP","ESFP","ESTJ","ESFJ"};

std::map<std::string, int> getMBTIcnt(int numStudent){
    std::map<std::string, int> MBTIcnt;
    std::string temp;
    for (int i=0;i<numStudent; i++){
        std::cin>>temp;
        MBTIcnt[temp]++;
    }
    return MBTIcnt;
}

int getDistance(const std::string& lhs, const std::string& rhs){
    int d = 0;
    for(int i=0; i<4; i++){
        if(lhs[i] != rhs[i]) d++;
    }
    return d;
}

std::map<std::string, std::map<std::string, int> > setRelation(){
    std::map<std::string, std::map<std::string, int> > result;
    for(int i=0; i<16; i++){
        for(int j=0; j<16; j++){
            result[MBTIs[i]][MBTIs[j]] = getDistance(MBTIs[i], MBTIs[j]);
        }
    }
    return result;
}

std::map<std::string, std::map<std::string, int> > DISTANCE_TABLE;

int nogada(std::vector<std::string>& mbtis){
    int distance = 100000000;
    for (int i=0; i<mbtis.size();i++){
        for (int j=i+1; j<mbtis.size();j++){
            for (int k=j+1; k<mbtis.size();k++)
                distance = std::min(distance, DISTANCE_TABLE[mbtis[i]][mbtis[j]]+DISTANCE_TABLE[mbtis[i]][mbtis[k]]+DISTANCE_TABLE[mbtis[j]][mbtis[k]]);  
    }
    }
    return distance;
    }


int main(){
    DISTANCE_TABLE = setRelation();
    int numCase, numStudent;
    std::string students;
    std::cin>>numCase;
    for (int i=0; i<numCase; i++){
        int result = -1;
        std::cin>>numStudent;
        std::map<std::string, int> mbtiCnt;
        mbtiCnt = getMBTIcnt(numStudent);
        for(const auto& element : mbtiCnt){
            if (element.second >=3) {
                result = 0;
                break;
            }
        }
        if (result == 0) {
            std::cout<<result<<std::endl;
            continue;
        }
        std::vector<std::string> vecMBTIs;
        for(const auto& element : mbtiCnt){
            for(int i=0; i<element.second; i++)
                vecMBTIs.push_back(element.first);
        }
        result = nogada(vecMBTIs);
        std::cout<<result<<std::endl;
    }
}