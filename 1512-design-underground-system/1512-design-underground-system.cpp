class UndergroundSystem {
public:

    map<pair<string,string>,vector<int>>mp; //container output
    map<int,pair<string,int>>ip; //container input
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        ip[id]= {stationName,t};
         // ip.insert({id,{stationName,t}});
    }
    
    void checkOut(int id, string stationName, int t) {
        auto q = ip[id]; //gives pair of string and int (time)
        int time = t-q.second; // differnce from start and end
        mp[{q.first,stationName}].push_back(time); //entry string from set exit string from input parameter
        auto it = ip.find(id);
        ip.erase(it);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double ans=0;
         auto it = mp[{startStation,endStation}];
         for(auto &i: it ){
             ans+=i;
         }
         ans/=it.size();
         return ans;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */