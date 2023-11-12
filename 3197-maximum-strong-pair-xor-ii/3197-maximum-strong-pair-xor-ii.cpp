struct XorTrie {
    static constexpr int max_b = 1 << 30; // max value can be inserted
	XorTrie *p[2] = {};
	void insert(int n) {
        XorTrie *r = this;
        for (int b = max_b; b > 0; b >>= 1) {
            int bit = (n & b) > 0;
            if (r->p[bit] == nullptr)
                r->p[bit] = new XorTrie();
            r = r->p[bit];
        }
    }
	bool remove(int n, int b = max_b) {
        if (b == 0)
            return true;
        int bit = (n & b) > 0;
        if (p[bit] != nullptr && p[bit]->remove(n, b >> 1)) {
            delete p[bit];
            p[bit] = nullptr;
        }
        return p[0] == p[1]; // both are nullptr
    }    
    int maxXor(int n) {
        int res = 0;
        XorTrie *r = this;
        for (int b = max_b; b > 0; b >>= 1)
            if (int bit = (n & b) > 0; r->p[!bit] != nullptr) {
                res += b;
                r = r->p[!bit];
            }
            else
                r = r->p[bit];
        return res;
    }
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& v) {
        XorTrie t;
        sort(v.begin(),v.end());
        int j=0, ans = 0;
        for(int i=0;i<v.size();i++){
            t.insert(v[i]);
            while(v[j]*2<v[i]) t.remove(v[j++]);
            ans = max(ans,t.maxXor(v[i]));
        }
        return ans;
    }
};