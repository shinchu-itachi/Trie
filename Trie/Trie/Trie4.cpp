// problem link : https://www.codingninjas.com/codestudio/problems/count-distinct-substrings_985292?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos

struct Node {
    Node* links[26];

    bool contains( char c ) { return links[c - 'a'];}
    void put ( char c , Node* node) {
        links[c - 'a'] = node;
    }

    Node* get ( char c) {
        return links[c - 'a'];
    }
};

class Trie {
  private :
    Node* root ;

  public :
    int cnt = 0 ;
    Trie () {
        root = new Node();
    }

    void insert (string s) {
        Node* node = root ;
        for ( int i = 0 ; i < s.size() ; i++) {
            if (!node->contains(s.at(i))) node -> put ( s.at(i) , new Node ()) , cnt ++ ;
            node = node -> get ( s.at(i));
        }
    }
};
int countDistinctSubstrings(string &s) {
    Trie t;

    for ( int i = 0 ; i < s.size() ; i++) {
        t.insert(s.substr(i));
    }

    return t.cnt + 1;
}