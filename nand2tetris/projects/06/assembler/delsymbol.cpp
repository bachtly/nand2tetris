void simple_init(map<string,int> &result) {
    for (int i = 0; i < 16; ++i) {
        string tmp = "R";
        tmp += to_string(i);
        result[tmp] = i;
    }
    result["SCREEN"] = 16348;
    result["KBD"] = 24576;
    result["SP"] = 0;
    result["LCL"] = 1;
    result["ARG"] = 2;
    result["THIS"] = 3;
    result["THAT"] = 4;
}

string getFromParentheses(string s) {
    string result = "";
    for (char i : s) {
        if (i != '(' && i != ')') result += i;
    }
    return result;
}

string getAins(string s) {
    string res = "";
    for (int i = 1; i < s.size(); ++i) res += s[i];
    return res;
} 

bool isNum(string s) {
    for (char c : s) {
        if (c < '0' || c > '9') return false;
    }
    return true;
}

void process_Ains(string &s, int val) {
    s.clear();
    s = "@";
    s += to_string(val);
}

void phase1(map<string,int> &result, vector<string> &content) {
    vector<string> res;
    int num_labels = 0;
    for (int i = 0; i < content.size(); ++i) {
        if (content[i][0] == '(') {
            string label = getFromParentheses(content[i]);
            result[label] = i-num_labels;
            num_labels++;
        }
        else {
            res.push_back(content[i]);
        }
    }
    content.clear();
    content = move(res);
}

void phase2(map<string,int> &result, vector<string> &content, int &pos_in_mem) {
    vector<string> res;
    for (int i = 0; i < content.size(); ++i) {
        if (content[i][0] == '@') {
            string ins = getAins(content[i]);
            if (!isNum(ins)) {
                if (result.find(ins) == result.end()) {
                    result[ins] = pos_in_mem++;
                }
                process_Ains(content[i], result[ins]);
            }
        }
        res.push_back(content[i]);
    } 
}

map<string, int> delsymbol(vector<string> &content) {
    map<string, int> result;
    simple_init(result);
    int pos_in_mem = 16;
    phase1(result, content);
    phase2(result, content, pos_in_mem);
    return result;
}