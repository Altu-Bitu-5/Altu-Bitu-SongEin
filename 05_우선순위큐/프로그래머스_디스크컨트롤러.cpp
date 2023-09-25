#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare {
    bool operator()(vector<int> a, vector<int> b) {
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int t = 0, sum = 0, count = 0;
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;

    //jobs를 오름차순으로 정렬
    sort(jobs.begin(), jobs.end());

    while (count < jobs.size() || !pq.empty()) {
        while (count < jobs.size() && jobs[count][0] <= t) { // 작업이 요청된 시간이 현재 시간 이전이거나 같을 경우
            // 작업 요청을 우선순위 큐에 삽입
            pq.push(jobs[count]);
            count++;
        }
        if (pq.empty()) { //요청된 작업이 없을 경우
            t = jobs[count][0]; // 시간 증가
        }
        else { //요청된 작업이 있을 경우 작업 수행
            // 작업 수행이 끝날 때 까지의 시간 업데이트
            t += pq.top()[1];
            // 요청부터 수행까지 시간을 sum에 더함
            sum += (t - pq.top()[0]);
            // pop
            pq.pop();
        }
    }
    answer = sum / jobs.size();
    return answer;
}