class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        if (tokens.size()==0 || power<tokens[0]){ // 51 < 26
            return 0;
        }
        int c=0;
        int s=power;
        int i=0;
        int j=tokens.size()-1;
        while(i<tokens.size() && s>=tokens[i] && i<=j){
            s=s-tokens[i];
            i++;
            c++;
        }
        while(i<j){
            s=s+tokens[j];
            j--;
            s=s-tokens[i];
            i++;
            while(s>=tokens[i] && i<=j){
                s=s-tokens[i];
                i++;
                c++;
            }
        }
    return c;}
};