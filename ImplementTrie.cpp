/*
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings.
There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
*/

class Trie {
public:
    vector<Trie*> v;
    bool end = false;
    Trie() {
        v = vector<Trie*>(26, NULL);
    }
    
    void insert(string word) {
        Trie* temp = this;
        for(auto &x : word){
            if(temp->v[x-'a'] == NULL)
                temp->v[x-'a'] = new Trie;
            temp = temp->v[x - 'a'];

        }
        temp->end = true;
    }
    
    bool search(string word) {
        Trie* temp = this;
        for(auto &x : word){
            if(temp->v[x-'a'] == NULL)
                return false;
            temp = temp->v[x-'a'];
        }
        return temp->end;
    }
    
    bool startsWith(string prefix) {
        Trie *temp = this;
        for(auto &x : prefix){
            if(temp->v[x-'a'] == NULL)
                return false;
            temp = temp->v[x-'a'];
        }
        return true;
    }
};

\
