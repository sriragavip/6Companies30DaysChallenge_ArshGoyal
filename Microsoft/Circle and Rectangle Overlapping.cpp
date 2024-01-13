class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        for(int i=x1;i<=x2;i++){
            for(int j=y1;j<=y2;j++){
                double p=(i-xCenter)*(i-xCenter) + (j-yCenter)*(j-yCenter);
                double r=radius*radius;
                if(p<=r) return true;
            }
        }
        return false;
    }
};