//
//  Zalora.cpp
//  HackerRank
//
//  Created by trongbangvp@gmail.com on 4/1/17.
//  Copyright © 2017 trongbangvp. All rights reserved.
//

//11h32PM 01/04/2017

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int maxDifference(vector < int > a) {
    size_t n = a.size();
    int diff = -1;
    for(size_t i = 0; i<n-1; ++i)
    {
        for(size_t j = i+1; j<n; ++j)
        {
            if(a[j] > a[i]) {
                diff = max(diff, a[j] - a[i]);
            }
        }
    }
    return diff;
}

int maxDifference2(vector < int > a) {
    size_t n = a.size();
    if(n <= 1)
    {
        return -1;
    }
    int maxDiff = a[1] - a[0];
    int minVal = min(a[1], a[0]);
    for(size_t i = 2; i<n; ++i)
    {
        maxDiff = max(maxDiff, a[i] - minVal);
        minVal = min(minVal, a[i]);
    }
    if(maxDiff < 0) {
        return -1;
    }
    return maxDiff;
}

int main() {
    
    
    return 0;
}
