// Problem 9 :  https://leetcode.com/problems/design-parking-system/

/* 

class ParkingSystem {
public:
    int big_spc,mdm_spc,sml_spc;            // Space available (Class Objects)
    ParkingSystem(int big, int medium, int small) {
        big_spc = big;
        mdm_spc = medium;
        sml_spc = small;
    }
    
    bool addCar(int carType) {
        if(carType==1 and big_spc>0){
            big_spc--;
            return true;
        }else if(carType==2 and mdm_spc>0){
            mdm_spc--;
            return true;
        }else if(carType==3 and sml_spc>0){
            sml_spc--;
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

// Simple constraints so using simple method

 */