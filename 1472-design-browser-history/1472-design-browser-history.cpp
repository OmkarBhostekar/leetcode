class BrowserHistory {
public:
    int curr=0,n=0;
    string v[110];
    BrowserHistory(string homepage) {
        v[curr]=homepage;
    }
    
    void visit(string url) {
        v[++curr]=url;
        n=curr;
    }
    
    string back(int steps) {
        curr = max(curr-steps, 0);
        return v[curr];
    }
    
    string forward(int steps) {
        curr = min(n, curr+steps);
        return v[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */