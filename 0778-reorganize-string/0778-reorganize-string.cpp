class Solution {
public:
    string reorganizeString(std::string s) {
    std::unordered_map<char, int> freq_map;
    for (char c : s) {
        freq_map[c]++;
    }

    std::vector<char> sorted_chars;
    for (auto& pair : freq_map) {
        sorted_chars.push_back(pair.first);
    }

    std::sort(sorted_chars.begin(), sorted_chars.end(), [&](char a, char b) {
        return freq_map[a] > freq_map[b];
    });

    if (freq_map[sorted_chars[0]] > (s.length() + 1) / 2) {
        return "";
    }

    std::string res(s.length(), ' ');
    int i = 0;
    for (char c : sorted_chars) {
        for (int j = 0; j < freq_map[c]; ++j) {
            if (i >= s.length()) {
                i = 1;
            }
            res[i] = c;
            i += 2;
        }
    }

    return res;
}
};