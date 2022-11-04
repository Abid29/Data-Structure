#include<iostream>
using namespace std;

#define sz 26

class trie{
    public:
    bool isleaf;
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
    cur->isleaf = true;
}

bool trie :: search(string key){
    trie *cur = this;
    for(int i=0;i<key.length();i++){
        cur = cur->character[key[i]-'a'];
        if(cur == NULL) return false;
    }
    return cur->isleaf;
}





int main(){
    trie *head = new trie();
    head->insert("abid");
    head->insert("abida");
    cout<<head->search("abid");
}