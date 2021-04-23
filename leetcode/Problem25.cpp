// Problem 25 : https://leetcode.com/problems/minimum-time-visiting-all-points/

/* 
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int totalTime=0;
        for(int i=1;i<points.size();i++){
            int timex=points[i][0]-points[i-1][0];       // x cordinate
            int timey=points[i][1]-points[i-1][1];      // y cordinate
            if(timex<0)
                timex=-timex;
            if(timey<0)
                timey=-timey;
            totalTime+=((timex>timey)?timex:timey);
        }
        return totalTime;
    }
};


// time complexity is O(n)  n=points array size

 */
