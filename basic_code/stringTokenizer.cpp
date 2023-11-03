vector<string> stringTokenizer(string value,vector<char> target) {
    int targetIndex = 0;
    string temp = "";
    vector<string> result;
    for(int i = 0 ; i < value.length() ; i++) {
        char cur = value.at(i);
        if(cur == target[ti]) {
            result.push_back(temp);
            targetIndex++;
            temp = "";
        } else {
            temp+=cur;
        }
    }
    return result;
}
