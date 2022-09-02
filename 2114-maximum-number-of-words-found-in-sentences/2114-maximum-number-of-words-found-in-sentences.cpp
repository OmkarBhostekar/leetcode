class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int m = 0;
        int count = 0;
        for (int i = 0; i < sentences.size(); i++) {
            count = 0;
            for (int j = 0; j < sentences[i].size(); j++) 
                if (sentences[i][j] == ' ')
                    ++count;
            if (count > m)
                m = count;
        }
        return m + 1;
    }
};