#include <sstream>

vector<string> stringSplit(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
    return answer;
}


// vector<string> time = stringSplit("20:21:54",':');
// time[0] = "20"
// time[1] = "21"
// time[2] = "54"
