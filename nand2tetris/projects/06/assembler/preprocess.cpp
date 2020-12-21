void cut_spaces(string &s) {
    string result = "";
    for (char c : s) 
        if (c != ' ') result += c;
    s.clear();
    s = result;
}

bool detect_cmt(string &s) {
    string result = "";
    if (s[0] == '/') return true;
    for (char c : s) {
        if (c=='/') break;
        result += c;
    }
    s.clear();
    s = result;
    return false;
}

vector<string> preprocess() {
    vector<string> result;
    string tmp;
    while(getline(cin, tmp)) {
        cut_spaces(tmp);
        if (!detect_cmt(tmp) && tmp != "") result.push_back(tmp);
    }
    return result;
}