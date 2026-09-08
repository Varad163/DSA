class Solution {
public:
    double r,xc,yc;
    
    Solution(double radius, double x_center, double y_center) {
        r=radius;
        xc=x_center;
        yc=y_center;
        
    }
    
    vector<double> randPoint() {
        while(true){
            double x=((double)rand()/RAND_MAX)*2*r-r;
            double y=((double)rand()/RAND_MAX)*2*r-r;

            if(x*x+y*y<=r*r){
                return {xc+x,yc+y};
            }
        }

        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */