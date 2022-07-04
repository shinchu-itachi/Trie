//problem link : https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/

struct Node {
    Node* links[2];

    Node() {
        links[1] = NULL ;
        links[0] = NULL ;
    }

    bool contains( int bit ) {
        return links[bit] != NULL;
    }

    void put ( int bit , Node* node) {
        links[bit] = node;
    }

    Node* get ( int bit ) {
        return links[bit];
    }
};

class Trie {
  private:
    Node* root ;

  public:
    Trie() {
        root = new Node();
    }

    void insert (int num ) {
        Node* node = root ;

        for ( int i = 31 ; i >= 0 ; i -- ) {
            int bit = ( num >> i) & 1;

            if ( !node -> contains( bit )) node -> put( bit , new Node());
            node = node -> get(bit);
        }
    }

    int getMax( int num ) {
        Node* node = root ;
        int mx = 0 ;
        for ( int i = 31 ; i >= 0 ; i -- ) {
            int bit = ( num >> i) & 1;

            if ( node -> contains ( 1 - bit )) {
                mx =  ( mx  | ( 1 << i ));
                node = node -> get(1 - bit);
            }

            else node = node -> get ( bit );
        }

        return mx;
    }
};

class Solution {
  public:
    int findMaximumXOR(vector<int>& nums) {
        // so to solve this question we will use trie
        Trie trie;

        for ( auto &i : nums ) trie.insert(i);

        int mx = 0 ;
        for ( auto &i : nums ) {
            mx = max ( mx , trie.getMax ( i ));
        }

        return mx;
    }
};