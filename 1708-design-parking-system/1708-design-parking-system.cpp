class ParkingSystem {
public:
    unordered_map<int, int> mp;
    ParkingSystem(int big, int medium, int small) {
        mp[1] = big;
        mp[2] = medium;
        mp[3] = small;
    }
    
    bool addCar(int carType) {
        if(mp.find(carType) != mp.end() && mp[carType] > 0)
        {
            mp[carType]--;
            return true;
        }
        return false;
    }
};
