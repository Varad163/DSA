class RideSharingSystem {
public:

    queue<int> riders;
    queue<int> drivers;

    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riders.push(riderId);
    }
    
    void addDriver(int driverId) {
        drivers.push(driverId);
        
    }
    
    vector<int> matchDriverWithRider() {

        if(riders.empty()||drivers.empty())
        return {-1,-1};

        int rider=riders.front();
        int driver=drivers.front();

        riders.pop();
        drivers.pop();

        return {driver,rider};
        
    }
    
    void cancelRider(int riderId) {
        queue<int> temp;

        while(!riders.empty()){
            int x=riders.front();
            riders.pop();

            if(x!=riderId)
                temp.push(x);

        }

        riders=temp;
        
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */