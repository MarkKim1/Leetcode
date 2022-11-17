class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int areaA = (ax2-ax1) * (ay2-ay1);
        int areaB = (bx2-bx1) * (by2-by1);
        int overlap = 0;
        int left = max(ax1,bx1);
        int right = min(ax2,bx2);
        int xoverlap = right-left;
        
        int top = min(ay2,by2);
        int bot = max(ay1,by1);
        int yoverlap = top-bot;
        if(xoverlap > 0 and yoverlap > 0){
            overlap = xoverlap * yoverlap;
        }
        
        return areaA+areaB-overlap;
    }
};