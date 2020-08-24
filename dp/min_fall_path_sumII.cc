#include <iostream>
#include <vector>

using namespace std;

class TwoInt {  
public:
    int value;
    int idx;
    TwoInt(int v, int idx) {
        this->value = v;
        this->idx = idx;
    }
};
class Solution {
public:
    int minFallingPathSum(vector<vector<int> >& arr) {
       int m = arr.size(), n = arr[0].size();
       TwoInt lastMin(0, -1);
       TwoInt curMin(10000000, -1);     
       int omin = 10000000;
       for(int i = 0;i < n; ++i) {
          if (arr[0][i] < omin) {
              omin = arr[0][i];
              lastMin.value = omin;
              lastMin.idx = i;
          }
       }  
       for(int i = 1;i < m;++i) {
           for (int j = 0;j < n; ++j) {
               int idx = lastMin.idx;
               if(idx == j) {
                   int min = 10000000;
                   for(int k = 0; k < n;++k) {
                       if( k == j)
                           continue;
                        if(arr[i -1][k] < min) {
                            min = arr[i -1][k];
                        }                        
                   }
                   arr[i][j] += min;
               } else {
                  arr[i][j] += lastMin.value;   
               }               
               if(curMin.value > arr[i][j]) {
                   curMin.value = arr[i][j];
                   curMin.idx = j;
               }
           }
           lastMin.value = curMin.value;
           lastMin.idx = curMin.idx;
           curMin.value = 10000000;
       }
       return lastMin.value;
    }
};

int main() {
    vector<vector<int> > vect{ 
        {-73,61,43,-48,-36},
        {3,30,27,57,10},
        {96,-76,84,59,-15},
        {5,-49,76,31,-7},
        {97,91,61,-46,67}
        };
    Solution s;
    std::cout << s.minFallingPathSum(vect) << std::endl;
    for(int i = 0;i < vect.size(); ++i) {
        for (int j = 0;j < vect[0].size(); ++j) {
            std::cout << vect[i][j] << " " ;
        }
        std::cout << std::endl;
    }

    return 0;
}
