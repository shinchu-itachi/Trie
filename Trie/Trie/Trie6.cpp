// problem link : https://leetcode.com/problems/maximum-xor-with-an-element-from-array/

struct Node {
    Node* link[2];

    Node() {
        link[0] = link[1] = NULL;
    }

    bool contains( int bit ) { return link[bit]; }
    Node* get ( int bit ) { return link[bit]; }
    void put ( int bit , Node* node) { link[bit] = node; }
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
            int bit = ( num >> i ) & 1;
            if (!node -> contains( bit )) node -> put ( bit , new Node());
            node = node -> get(bit);
        }
    }

    int getMax( int num ) {
        Node* node = root ;
        int mx = 0 ;
        for ( int i = 31 ; i >= 0 ; i --) {
            int bit = ( num >> i ) & 1 ;
            if ( node -> contains( 1 - bit )) {
                mx = mx | ( 1 << i );
                node = node -> get ( 1 - bit );
            }

            else node = node -> get ( bit );
        }


        return mx ;
    }
};
class Solution {
  public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // we will solve this question using trie
        int n = nums.size();
        int q = queries.size();

        vector<pair<int, pair<int, int>>> offQuery;
        for ( int i = 0 ; i < q ; i ++) {
            int ai = queries[i][1];
            int xi = queries[i][0];
            offQuery.push_back({ai, {xi , i}});
        }

        // tc = QlogQ
        sort( offQuery.begin() , offQuery.end());
        sort( nums.begin() , nums.end());

        vector<int> ans( q , -1);

        Trie trie;
        int ind = 0 ;

        for ( int i = 0 ; i < q ; i ++) {
            int ai = offQuery[i].first;
            int xi = offQuery[i].second.first;
            int qind = offQuery[i].second.second;

            while ( ind < n and nums.at(ind) <= ai ) {
                trie.insert(nums.at(ind));
                ind++;
            }

            if ( ind == 0 ) ans[qind] = -1 ;
            else ans[qind] = trie.getMax(xi);
        }

        return ans;
    }
};

