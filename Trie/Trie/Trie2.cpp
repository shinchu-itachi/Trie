// Question Link :  https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

#include<bits/stdc++.h>
struct Node {
    Node* link[26];
    int cntPrefix = 0 , cntEndWord = 0 ;

    bool contains( char c ) {
        return link[c - 'a'] !=  NULL;
    }

    void put ( char c , Node* node) {
        link[c - 'a'] = node;
    }

    Node* get ( char c ) {
        return link[c - 'a'];
    }

    void increasePrefix () {
        cntPrefix ++ ;
    }

    void increaseEndword() {
        cntEndWord ++ ;
    }

    void decreasePrefix() {
        cntPrefix -- ;
    }

    void decreaseEndword() {
        cntEndWord -- ;
    }

    int getEnd() {
        return cntEndWord;
    }

    int getpre() {
        return cntPrefix;
    }

};
class Trie {
  private:
    Node* root ;
  public:

    Trie() {
        root = new Node();
    }

    void insert(string &word) {
        Node* node = root ;
        for ( int i = 0 ; i < word.size() ; i ++) {
            if ( !node-> contains(word.at(i)))
                node-> put ( word.at(i) , new Node());
            node = node -> get(word.at(i));
            node -> increasePrefix ();
        }

        node -> increaseEndword();
    }

    int countWordsEqualTo(string &word) {
        Node* node = root ;
        for ( int i = 0 ; i < word.size() ; i ++) {
            if (!node -> contains(word.at(i))) return 0 ;
            else
                node = node -> get(word.at(i));
        }

        return node -> getEnd();
    }

    int countWordsStartingWith(string &word) {
        Node* node = root ;
        for ( int i = 0 ; i < word.size() ; i ++) {
            if (!node -> contains(word.at(i))) return 0 ;
            else
                node = node -> get(word.at(i));
        }

        return node -> getpre();
    }

    void erase(string &word) {
        Node* node = root ;
        for ( int i = 0 ; i < word.size() ; i ++) {
            if (!node -> contains(word.at(i))) return  ;
            else {
                node = node -> get( word.at(i));
                node -> decreasePrefix();
            }
        }

        node -> decreaseEndword();
    }
};
