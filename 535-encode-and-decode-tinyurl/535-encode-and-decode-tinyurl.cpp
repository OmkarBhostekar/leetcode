class Solution {
public:
    unordered_map<string, string> mpp;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string x = "";
        x += to_string(rand()%1000);
        while(mpp[x] != ""){
            x += to_string(rand()%1000);
        }
        mpp[x] = longUrl;
        return x;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mpp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));