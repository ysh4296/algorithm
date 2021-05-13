#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for(double i = left ; i <= right ; i++){
        double pi = sqrt(i);
        if(fmod(i,pi) == 0)
            answer -= i;
        else
            answer += i;
    }
    return answer;
}
