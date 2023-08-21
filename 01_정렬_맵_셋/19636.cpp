#include <iostream>

using namespace std;

struct Desy {
    int weight; // 몸무게
    int i; // 다이어트 전 일일 에너지 섭취량
    int bmr; // 기초대사량
    int t; // 기초대사량 변화 역치
    int day; // 다이어트 기간
    int i_diet; // 다이어트 중 일일 에너지 섭취량
    int act_diet; // 다이어트 중 일일 활동 대사량
};

void bmrNotChange(Desy desy) {
    for (int j = 0; j < desy.day; j++) {
        desy.weight = desy.weight + (desy.i_diet - (desy.bmr + desy.act_diet));
        if (desy.weight <= 0) { //데시의 몸무게가 0 이하일 경우
                cout << "Danger Diet" << endl;
                return;
        }
    }
    cout << desy.weight << " " << desy.bmr << endl;
}

void bmrChange(Desy desy) {

    for (int j = 0; j < desy.day; j++) {
        desy.weight = desy.weight + (desy.i_diet - (desy.bmr + desy.act_diet));
        if (abs(desy.i_diet - (desy.bmr + desy.act_diet)) > desy.t) { // 기초 대사량 변화 역치 초과시 bmr 변화
            desy.bmr = desy.bmr + ((desy.i_diet - (desy.bmr + desy.act_diet)) / 2.0);
        }
        if (desy.weight <= 0 || desy.bmr <= 0) {
            cout << "Danger Diet";
            return;
        }
    }
    cout << desy.weight << " " << desy.bmr << " ";
    if (desy.i - (desy.bmr) > 0) { // 요요 여부
        cout << "YOYO";
    }
    else {
        cout << "NO";
    }    
}

int main(){
    Desy desy;
    cin >> desy.weight >> desy.i >> desy. t;
    cin >> desy.day >> desy.i_diet >> desy.act_diet;
    desy.bmr = desy.i;

    bmrNotChange(desy);
    bmrChange(desy);
}