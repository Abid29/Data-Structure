#include<iostream>
using namespace std;

#define sz 26

class trie{
    public:
    int isleaf;
    trie *character[sz];

    //constructor 
    trie(){
        this->isleaf = 0;
        for(int i=0;i<sz;i++){
            this->character[i] = NULL;
        }
    }

    void insert(string);
	bool deletion(trie*&,string);
	bool search(string);
	bool havechildren(trie const*);
    
};

void trie :: insert(string key){
    trie *cur = this;
    for(int i=0;i<key.length();i++){
        if(cur->character[key[i]-'a']==NULL) cur->character[key[i]-'a'] = new trie();
        cur = cur->character[key[i]-'a'];
    }
    cur->isleaf++;
}

bool trie :: search(string key){
    trie *cur = this;
    for(int i=0;i<key.length();i++){
        cur = cur->character[key[i]-'a'];
        if(cur == NULL) return false;
    }
    return cur->isleaf>0;
}

bool trie :: havechildren(trie const *curr){
    for(int i=0;i<sz;i++) if(curr->character[i]) return true;
    return false;
}

bool trie :: deletion(trie *&cur, string key){
    if(cur == NULL) return false;  

    if(key.length()){
        bool ind = deletion(cur->character[key[0]-'a'],key.substr(1));
        if(ind && cur->isleaf>0 && !havechildren(cur)){
            delete cur;
            cur = NULL;
            return true;
        }
    }
    else if(cur->isleaf>0){
        if(!havechildren(cur) && cur->isleaf == 1){
            delete cur; cur = NULL;
            return true;
        }
        cur->isleaf--;
    }
    return false;
}

int main(){
    trie *head = new trie();
    head->insert("abid");
    head->insert("abida");
    cout<<head->search("abid")<<endl;
    head->insert("abida");
    cout<<head->search("abida")<<endl;
    head->deletion(head,"abida");
    cout<<head->search("abida")<<endl;
    head->deletion(head,"abida");
    cout<<head->search("abida");
}