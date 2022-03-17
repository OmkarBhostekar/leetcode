class Solution {
public:
    int scoreOfParentheses(string str) {
        stack<int> s;
        int score = 0;
        for(char x: str){
            if(x == '('){
                s.push(score);
                score = 0;
            }else{
                score = s.top() + max(2*score, 1);
                s.pop();
            }
        }
        return score;
    }
};