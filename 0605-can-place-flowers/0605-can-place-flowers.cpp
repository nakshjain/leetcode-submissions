class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(flowerbed.size()==1 && flowerbed[0]==0) return n<=1;
        for(int i=0;i<flowerbed.size();i++){
            if(n==0) return true;
            if(flowerbed[i]==0 && i==0 && i+1<flowerbed.size() && flowerbed[i+1]==0){
                n--;
                flowerbed[i]=1;
            } else if (flowerbed[i]==0 && i==flowerbed.size()-1 && i-1>=0 && flowerbed[i-1]==0){
                n--;
                flowerbed[i]=1;
            } else if(flowerbed[i]==0 && i+1<flowerbed.size() && i-1>=0 && flowerbed[i+1]==0 && flowerbed[i-1]==0){
                n--;
                flowerbed[i]=1;
            }
        }
        return n==0;
    }
};