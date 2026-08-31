class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA=0;
        int sumB=0;

        for(int x:aliceSizes){
            sumA+=x;
        }
        for(int x:bobSizes){
            sumB+=x;
        }
        int diff=(sumA-sumB)/2;

        set<int> s;

        for(int x:bobSizes){
            s.insert(x);
        }

        for(int x:aliceSizes){
            int y=x-diff;

            if(s.find(y)!=s.end()){
                return {x,y};
            }
        }

        return {};
    }
};