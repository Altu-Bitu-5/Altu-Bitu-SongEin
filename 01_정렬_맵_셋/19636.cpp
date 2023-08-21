#include <iostream>

using namespace std;

struct Desy {
    int weight; // ������
    int i; // ���̾�Ʈ �� ���� ������ ���뷮
    int bmr; // ���ʴ�緮
    int t; // ���ʴ�緮 ��ȭ ��ġ
    int day; // ���̾�Ʈ �Ⱓ
    int i_diet; // ���̾�Ʈ �� ���� ������ ���뷮
    int act_diet; // ���̾�Ʈ �� ���� Ȱ�� ��緮
};

void bmrNotChange(Desy desy) {
    for (int j = 0; j < desy.day; j++) {
        desy.weight = desy.weight + (desy.i_diet - (desy.bmr + desy.act_diet));
        if (desy.weight <= 0) { //������ �����԰� 0 ������ ���
                cout << "Danger Diet" << endl;
                return;
        }
    }
    cout << desy.weight << " " << desy.bmr << endl;
}

void bmrChange(Desy desy) {

    for (int j = 0; j < desy.day; j++) {
        desy.weight = desy.weight + (desy.i_diet - (desy.bmr + desy.act_diet));
        if (abs(desy.i_diet - (desy.bmr + desy.act_diet)) > desy.t) { // ���� ��緮 ��ȭ ��ġ �ʰ��� bmr ��ȭ
            desy.bmr = desy.bmr + ((desy.i_diet - (desy.bmr + desy.act_diet)) / 2.0);
        }
        if (desy.weight <= 0 || desy.bmr <= 0) {
            cout << "Danger Diet";
            return;
        }
    }
    cout << desy.weight << " " << desy.bmr << " ";
    if (desy.i - (desy.bmr) > 0) { // ��� ����
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