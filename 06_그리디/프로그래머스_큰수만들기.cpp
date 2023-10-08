#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    int len = number.length() - k; // 자릿수
    int max = -1, index = 0, lim = k, temp;
    string answer = "";
    
    while(lim > 0) { //뺄 수 있는 숫자가 0개 이상일 때까지
        for (int i = 0; i <= lim; i++) { // 앞자리부터 세었을 때 lim번째 수까지 맨 앞에 올 수 있음.
            temp = (number[i] - '0'); // i번째 자리의 숫자
            if (temp > max) {
                max = temp;
                index = i;
            }
        }
        number = number.substr(index + 1); //index 다음부터 substring을 리턴하여 새로운 number 정의
        answer += (max + '0');
        lim -= index; // index번째 수까지 없어졌으므로 앞자리부터 세었을 때 lim - index 수까지 맨 앞에 올 수 있음.
        max = -1; //초기화
        index = 0;
        if (answer.length() == len) { //요구 길이에 도달했을 경우
            return answer;
        }
    }
    answer += number; //마지막으로 남은 숫자를 붙임

    return answer;
}