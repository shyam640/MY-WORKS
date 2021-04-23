// Problem 29  : https://leetcode.com/problems/flipping-an-image/

/* 
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        vector<vector<int>> temp(image.size(),vector<int>(image.size()));
        for(int i=0;i<image.size();i++){
            for(int j=0;j<image.size();j++){
                temp[i][j] = image[i][image.size()-1-j];      // flip horizontally
                temp[i][j]=((temp[i][j]==0)?1:0);        // invert
            }
        }
        image = temp;
        return image;
        
    }
};

// Time complexity O(n)   

 */