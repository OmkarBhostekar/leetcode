class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> pass;
    unordered_map<string,vector<pair<string,double>>> data;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        pass[id] = {stationName,t};    
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string,int> ci = pass[id];
        data[stationName].push_back({ci.first,(double)(t-ci.second)});
    }
    
    double getAverageTime(string start, string end) {
        double sum = 0;
        int count = 0;
        for(auto x: data[end]){
            if(x.first == start){
                sum += x.second;
                count++;
            }
        }
        return sum / count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */