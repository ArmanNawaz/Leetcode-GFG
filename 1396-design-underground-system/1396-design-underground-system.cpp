class UndergroundSystem {
public:

    unordered_map<int, pair<string, int>> in;  // id: <station, time>
    unordered_map<string, vector<int>> totalTime; // <fromStation, toStation> : Times
    
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto fromStation = in[id].first;
        auto startTime = in[id].second;
        string route = fromStation + '-' + stationName;
        totalTime[route].push_back(t - startTime);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + '-' + endStation;
        vector<int> times = totalTime[route];
        
        double sum = accumulate(times.begin(), times.end(), 0);
        return sum / times.size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */