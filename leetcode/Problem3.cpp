// Problem 3 : https://leetcode.com/problems/container-with-most-water/


/* 

class Solution {
public:
    int maxArea(vector<int>& height) {
        // // First approach -> Brute force approach 
        // int area=0;
        // for(int i=0;i<height.size()-1;i++){
        //     for(int j=i+1;j<height.size();j++){is 
        //         // Area of rectangle = lxb
        //         int temp = (j-i)*min(height[j],height[i]);
        //         area = max(area,temp);     // finding max area 
        //     }
        // }
        // return area;
        
        // Second approach => optimised technique
        int area=0;
        int st=0,en=height.size()-1;
        int temp=0;
        while(st<en){
            // actually compiler was giving problem here
            // no problem if we done what we do before here
            temp = ((en-st)*min(height[st],height[en]));
            area = max(area,temp);
            if(height[st]<height[en])
                st++;
            else if(height[en]<height[st])
                en--;
            else                                // if both are equal then 
                en--;                // incease st or decrease en  ur wish
        }
        return area;
    }
};

// Here is one problem as it is running for O(n^2) times so it will give TLE 

// SO now applying optimising technique 

// What if i could do this in O(N) ......

// so lets start with it

 */