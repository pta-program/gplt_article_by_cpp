#include <bits/stdc++.h>
using namespace std;

struct Node{
    bool isLeaf=false;
    string num;
    char op=0;
    Node *l=nullptr,*r=nullptr;
};

string s;
int pos;

Node* parseExpr(){
    if(pos >= (int)s.size()) return nullptr;
    if(isdigit(s[pos])){
        int st=pos;
        while(pos < (int)s.size() && isdigit(s[pos])) pos++;
        Node* nd=new Node();
        nd->isLeaf=true;
        nd->num=s.substr(st,pos-st);
        return nd;
    }else if(s[pos]=='('){
        pos++; // '('
        Node* left=parseExpr();
        char op = s[pos++];
        Node* right=parseExpr();
        pos++; // ')'
        Node* nd=new Node();
        nd->isLeaf=false;
        nd->op=op;
        nd->l=left;
        nd->r=right;
        return nd;
    }
    return nullptr;
}

vector<string> out;
void collect(Node* nd){
    if(!nd || nd->isLeaf) return;
    collect(nd->l);
    collect(nd->r);
    string line;
    if(nd->l->isLeaf) line+=nd->l->num;
    line+=nd->op;
    if(nd->r->isLeaf) line+=nd->r->num;
    out.push_back(line);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(!getline(cin,s)) return 0;
    // remove spaces if any (spec says no spaces)
    string t;
    for(char c: s) if(c!=' ' && c!='\r' && c!='\n' && c!='\t') t.push_back(c);
    s=t;
    if(s.empty()) return 0;
    pos=0;
    Node* root=parseExpr();
    collect(root);
    for(auto &e: out) cout<<e<<"\n";
    return 0;
}
