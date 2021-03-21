#include "slr.h"
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

//构造函数
//切分，得到first,follow,LR(0)和SLR(1)
slr::slr(string inputString) {
    //先用字符串分割的方式，找到每一个产生式子串
    //再采用字符串流的方法，因为可以读取时可以按照空格、换行等等来分割
    //分割出每一个产生式并存于可变数组中
    vector<string> v;
    int from = 0;
    int len = 0;
    int i;

    //分行
    for (i = 0; i < inputString.length(); ++i) {
        if (inputString[i] == '\n') {
            len = i - from;
            v.push_back(inputString.substr(from, len));
            from = i + 1;
        }
    }
    v.push_back(inputString.substr(from));

    //文法检查扩充
    isExtend = false;
    stringstream ss(v[0]);
    string s;
    ss >> s;
    if (v[0].find('|') != string::npos) {
        v.insert(v.begin(), string(s + "'" + " -> " + s));
        s += "'";
        isExtend = true;
    }
    this->start = s;

    //处理每一个产生式变成键值对
    for (auto &x : v) {
        string key;
        vector<vector<string>> values;
        string a;
        vector<string> value;
        if (x == "")break;
        stringstream ss(x + " $");
        ss >> key;
        ss >> a;
        while (1) {
            ss >> a;
            if (a == "$") {
                break;
            }
            if (a == "|") {
                values.push_back(value);
                value.clear();
                continue;
            }
            int from = 0;
            int len = 0;
            for (int i = 0; i < a.length(); ++i) {
                if (a[i] == '(' || a[i] == ')') {
                    len = i - from;
                    if (len != 0) {
                        value.push_back(a.substr(from, len));
                    }
                    from = i + 1;
                    value.push_back(string(1, a[i]));
                }
            }
            if (from != i) {
                value.push_back(a.substr(from));
            }
        }
        values.push_back(value);
        this->m[key] = values;
    }

    //求非终结符集
    for (auto it = m.begin(); it != m.end(); ++it) {
        this->ntSet.insert(it->first);
    }

    //求所有终结符的follow集合和follow集合
    this->first_follow_all();

    //求LR(0)DFA、判断是否为SLR(1)文法、SLR(1)表格
    this->node_relationship();
}

//是否要扩充
bool slr::get_isExtend() {
    return isExtend;
}

//是否符合SLR(1)
bool slr::get_isSLR1() {
    return isSLR1;
}

//不符合SLR(1)原因
string slr::get_reason()
{
    return reason;
}

//得到first集合
map<string,set<string>> slr::getfirst() {
    return m_first;
}

//得到follow集合
map<string,set<string>> slr::getfollow() {
    return m_follow;
}

//得到LR(0)的DFA内容和编号
map<int,string> slr::getContent_num(){
    string s;
    for (int i = 0; i<this->DFA_nodes.size(); i++) {
        for (auto &p : this->DFA_nodes[i]) {
            s = s+p.key+"->";
            for (int j=0; j<this->m[p.key][p.value_num].size(); j++) {
                if (j == p.index) {s=s+".";}
                s = s+this->m[p.key][p.value_num][j]+" ";
            }
            if (p.index == this->m[p.key][p.value_num].size()) {
                s = s+".";
            }
            s = s+"\n";
        }
        Content_num[i]=s; s.clear();
    }
    return Content_num;
}

string** slr::get_DFA() {
    int Gsize = DFA_nodes.size();
    string** DFA;
    DFA=new string*[Gsize];
    for(int i=0; i<Gsize; i++){
        DFA[i]=new string[Gsize];
    }

    for (auto &x : this->forwards) {
        int from = x.first;
        for (auto &y : x.second) {
            string t = y.first;
            int to = y.second;
            DFA[from][to]=t;

        }
    }
    return DFA;
}

//获得配对
map<string,int> slr::getSLRContent_num(){
    set<string> sSet;
    //得到移进和规约
    for (auto &x : this->forwards) {
        for (auto &y : x.second) {
            sSet.insert(y.first);
        }
    }
    for (auto &x : this->backs) {
        for (auto &y : x.second) {
            sSet.insert(y.first);
        }
    }
    //配起来
    int num=0;
    for(set<string>::iterator it=sSet.begin(); it!=sSet.end(); it++){
        SLRContent_num[*it]=num;
        num++;
    }
    return SLRContent_num;
}

//过的SLR分析表
string** slr::get_SLR(){
    stringstream ss;
    set<string> sSet;
    string** SLR;
    getSLRContent_num();
    getContent_num();
    //得到移进和规约
    for (auto &x : this->forwards) {
        for (auto &y : x.second) {
            sSet.insert(y.first);
        }
    }
    for (auto &x : this->backs) {
        for (auto &y : x.second) {
            sSet.insert(y.first);
        }
    }

    //开辟空间
    SLR = new string*[DFA_nodes.size()];
    for(int i=0; i<DFA_nodes.size(); i++){
        SLR[i]=new string[sSet.size()];
    }

    //建表
    for (int i = 0; i<this->DFA_nodes.size(); i++) {
        for (auto &s : sSet) {
            if (this->forwards[i].find(s) != this->forwards[i].end()) { //有无移进项
                if (this->ntSet.find(s) != this->ntSet.end()) {
                    SLR[i][SLRContent_num[s]] = to_string(this->forwards[i][s]);
                }
                else {
                    SLR[i][SLRContent_num[s]] = "S" + to_string(this->forwards[i][s]);
                }
            }
            else if (this->backs[i].find(s) != this->backs[i].end()) { //有无归约项
                Item & p = this->DFA_nodes[i][this->backs[i][s]];
                if (p.key == this->start) {
                    SLR[i][SLRContent_num[s]] = "AC";
                }
                else {
                    string a = "r(";
                    a += p.key;
                    a += " -> ";
                    vector<string> & value = this->m[p.key][p.value_num];
                    for (auto &b : value) {
                        a += b;
                        a += " ";
                    }
                    a[a.length() - 1] = ')';
                    SLR[i][SLRContent_num[s]]= a;
                }
            }
            else {
                 SLR[i][SLRContent_num[s]]= "  ";
           }
        }
    }
    return SLR;
}

//得到key的first集合
set<string> slr::get_first(string key) {
    if (this->ntSet.find(key) == this->ntSet.end()) {
        return set<string>{key};
    }
    return this->m_first[key];
}

//得到key的follow集合
set<string> slr::get_follow(string key) {
    return m_follow[key];
}

//批量按序
set<string> slr::first(vector<string> value) {
    set<string> first_set;
    int k;
    for (k = 0; k < value.size(); ++k) {
        set<string> first_set_k = this->get_first(value[k]);
        for (auto &s : first_set_k) {
            first_set.insert(s);
        }
        if (first_set_k.find("E") == first_set_k.end()) {
            break;
        }
        first_set.erase("E");
    }
    if (k == value.size()) {
        first_set.insert("E");
    }
    return first_set;
}

//求first和follow
void slr::first_follow_all() {
    //求所有非终结符的first集合
     //初始化
    for (auto &nt : this->ntSet) {
        this->m_follow[nt] = set<string>();
    }
    bool isChange = true;
    while (isChange) {
        isChange = false;
        for (auto &p : this->m) {
            string key = p.first;
            vector<vector<string>> values = p.second;
            for (auto &value : values) {
                int k;
                for (k = 0; k < value.size(); ++k) {
                    auto && first_set_k = this->get_first(value[k]);
                    for (auto &s : first_set_k) {
                        if ((s != "E") && (this->m_first[key].find(s) == this->m_first[key].end())) {
                            this->m_first[key].insert(s);
                            isChange = true;
                        }
                    }
                    if (first_set_k.find("E") == first_set_k.end()) {
                        break;
                    }
                }
                if (k == value.size() && (this->m_first[key].find("E") == this->m_first[key].end())) {
                    this->m_first[key].insert("E");
                    isChange = true;
                }
            }
        }
    }
    //求所有非终结符的follow集合
     //初始化
    for (auto &nt : this->ntSet) {
        this->m_follow[nt] = set<string>();
    }
    this->m_follow[this->start].insert("$");
    isChange = true;
    while (isChange) {
        isChange = false;
        for (auto &p : this->m) { //遍历每一个产生式p
            string key = p.first;
            vector<vector<string>> values = p.second;
            for (auto &value : values) {
                //遍历value中每一个非终结符
                for (auto it = value.begin(); it != value.end(); ++it) {
                    if (this->ntSet.find(*it) != this->ntSet.end()) {
                        //特殊情况
                        if (it + 1 == value.end()) {
                            for (auto &x : this->get_follow(key)) {
                                if (this->m_follow[*it].find(x) == this->m_follow[*it].end()) {
                                    this->m_follow[*it].insert(x);
                                    isChange = true;
                                }
                            }
                        }
                        else {
                            set<string> first_set = this->first(vector<string>(it + 1, value.end()));
                            for (auto &x : first_set) {
                                if (this->m_follow[*it].find(x) == this->m_follow[*it].end() && x != "E") {
                                    this->m_follow[*it].insert(x);
                                    isChange = true;
                                }
                            }
                            if (first_set.find("E") != first_set.end()) { //如果有ε符号
                                this->m_follow[*it].erase("ε");
                                for (auto &x : this->get_follow(key)) {
                                    if (this->m_follow[*it].find(x) == this->m_follow[*it].end()) {
                                        this->m_follow[*it].insert(x);
                                        isChange = true;
                                    }
                                }
                            }
                        }

                    }
                }
            }
        }
    }
}

//求LR(0)和SLR(1)
void slr::node_relationship() {
    reason = "";
    //初始化
    vector<Item> node{ Item{this->start, 0, 0, 1} };
    this->DFA_nodes.push_back(node);
    this->isSLR1 = true;
    //循环处理每一个结点i
    for (int i = 0; i < this->DFA_nodes.size(); ++i) {
        this->forwards[i] = map<string, int>();
        this->backs[i] = map<string, int>();
        //扩展该结点
        extend(i);
        //遍历该结点的每一个项目
        for (int j = 0; j < this->DFA_nodes[i].size(); ++j) {
            //处理归约项
            Item &p = this->DFA_nodes[i][j];
            if (p.type == 2) {
                set<string> follow_set = this->get_follow(p.key);
                for (auto &s : follow_set) {
                    if (this->backs[i].find(s) != this->backs[i].end()) {
                        this->isSLR1 = false;
                        stringstream ss;
                        ss << "第" << i << "个结点中归约项目的follow集合有交集\n";
                        reason += ss.str();
                    }
                    this->backs[i][s] = j;
                }
            }
            //处理移进项
            else {
                string t = this->m[p.key][p.value_num][p.index];
                Item newP(p.key, p.value_num, p.index + 1, 1);
                if (newP.index >= this->m[p.key][p.value_num].size()) {
                    newP.type = 2;
                }
                if (this->forwards[i].find(t) == this->forwards[i].end()) {//转换t未存在
                    int k = 0;
                    for (k = 0; k < this->DFA_nodes.size(); ++k) {
                        vector<Item> & n = this->DFA_nodes[k];
                        if (find(n.begin(), n.end(), newP) != n.end()) {
                            break;
                        }
                    }
                    if (k < this->DFA_nodes.size()) { //项目已经存在
                        this->forwards[i][t] = k;
                    }
                    else { //项目未存在
                        //新建节点
                        this->DFA_nodes.push_back(vector<Item>{newP});
                        this->forwards[i][t] = this->DFA_nodes.size() - 1;
                    }
                }
                else { //转换t存在
                    int k = this->forwards[i][t];
                    vector<Item> & n = this->DFA_nodes[k];
                    if (find(n.begin(), n.end(), newP) == n.end()) { //项目不存在
                        this->DFA_nodes[k].push_back(newP);
                    }
                }
            }
        }
    }
    if (this->isSLR1) {
        for (int i = 0; i < this->DFA_nodes.size(); ++i) {
            set<string> set1, set2, result;
            for (auto &x : this->forwards[i]) {
                set1.insert(x.first);
            }
            for (auto &x : this->backs[i]) {
                set2.insert(x.first);
            }
            set_intersection(begin(set1), end(set1), begin(set2), end(set2),
                inserter(result, begin(result)));
            if (result.size() != 0) {
                this->isSLR1 = false;
                stringstream ss;
                ss << "第" << i << "个结点的移进项的first集合和归约项的follow集合有交集\n";
                reason += ss.str();
            }
        }
    }
}

//扩展
void slr::extend(int k) {
    vector<Item> &node = this->DFA_nodes[k];
    for (int i = 0; i < node.size(); ++i) {
        Item &p = node[i];
        if (p.type == 1) {
            string extend_s = this->m[p.key][p.value_num][p.index];
            if (this->ntSet.find(extend_s) != this->ntSet.end()) {
                //可扩展的符号
                vector<vector<string>> &values = this->m[extend_s];
                //遍历extend_s对应的每一个value
                for (int j = 0; j < values.size(); ++j) {
                    Item addP(extend_s, j, 0, 1);
                    if (values[j][0] == "E") {//extend_s -> E特殊情况
                        addP.index = 1;
                        addP.type = 2;
                    }
                    //判断有无重复
                    if (find(node.begin() + i, node.end(), addP) == node.end()) {
                        node.push_back(addP);
                    }
                }
            }
        }
    }
}
