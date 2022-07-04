// problem link :  https://www.codingninjas.com/codestudio/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

#include<bits/stdc++.h>

struct Node {
    Node* links[26];
    bool flag = false;

    bool contains(char ch) {
        return links[ch - 'a'];
    }

    void put( char ch , Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get( char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
    Node* root ;
  public:
    Trie () {
        root = new Node();
    }

    void insert (string s) {
        Node * node = root ;
        for ( int i = 0 ; i < s.size() ; i ++) {
            if ( !node -> contains(s.at(i)))
                node-> put( s.at(i) , new Node());

            node = node -> get(s.at(i));
        }

        node -> setEnd();
    }

    bool checkPrefix(string& s ) {
        Node * node = root;
        for (int i = 0; i < s.length(); ++i) {
            if (!node->contains(s[i])) return false;
            node = node->get(s[i]);
            if (!node->isEnd()) return false;
        }
        return true;
    }
};
string completeString(int n, vector<string> &a) {
    Trie trie;
    for ( int i = 0 ; i < n ; i ++) {
        trie.insert(a.at(i));
    }

    string longest = "" , s;
    for ( int i = 0 ; i < n ; i ++) {
        s = a.at(i);
        if ( trie.checkPrefix(s)) {
            if ( s.size() > longest.size()) longest = s;
            else if ( s.size() == longest.size() and s < longest)
                longest = s;
        }

    }

    if ( longest == "") return "None";
    return longest ;
}