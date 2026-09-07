class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(auto &row:image){
            int first=0;
            int last=row.size()-1;

            while(first<=last){
                int temp=row[first];

                row[first]=1-row[last];
                row[last]=1-temp;

                first++;
                last--;
            }
        }

        return image;
    }
};