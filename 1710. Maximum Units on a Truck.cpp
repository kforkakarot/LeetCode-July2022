 bool compare(vector<int> a,vector<int> b)
    {
        return a[1]>b[1];
    }
class Solution {
public:
    
       int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
       sort(boxTypes.begin(),boxTypes.end(),compare);
       int count =0;
        int i=0;
        while(truckSize>0 && i<boxTypes.size())
        {
            if(boxTypes[i][0]<=truckSize)
            {
                count+=boxTypes[i][0]*boxTypes[i][1];
                truckSize=truckSize-boxTypes[i][0];
            }
            else
            {
                
                count+=truckSize*boxTypes[i][1];
                truckSize=0;
            }
            ++i;
        }
           return count;
        
    }
};
