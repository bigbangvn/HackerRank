//
//  MaxSubArray.cpp
//  HackerRank
//
//  Created by trongbangvp@gmail.com on 4/1/17.
//  Copyright © 2017 trongbangvp. All rights reserved.
//

//06:10 PM 01/04/2017
// -> 06:42 PM

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <assert.h>
using namespace std;

int maxContigousSubArr(int* arr, int n)
{
    if(n == 1)
    {
        return arr[0];
    } else if(n == 2)
    {
        return max(arr[0], arr[1]);
    }
    int prevMax = arr[n-1];
    int maxVal = prevMax;
    for (int i = n-2; i>=0; --i) {
        int Ai = arr[i];
        int maxi = max(Ai, Ai + prevMax);
        prevMax = maxi;
        if(maxi > maxVal)
        {
            maxVal = maxi;
        }
    }
    return maxVal;
}

int maxNonContigousSubArr(vector<int>& arr)
{
    size_t n = arr.size();
    if(n == 1)
    {
        return arr[0];
    } else if(n == 2)
    {
        return max(arr[0], arr[1]);
    }
    
    int sum = 0;
    int max = arr[0];
    bool foundPositiveElement = false;
    for(size_t i = 0; i<n; ++i)
    {
        int ai = arr[i];
        if(ai > 0)
        {
            sum += ai;
            foundPositiveElement = true;
        }
        if(ai > max)
        {
            max = ai;
        }
    }
    if(foundPositiveElement)
    {
        return sum;
    }
    return max;
}

int mainx(int argc, const char * argv[]) {
    int numTest;
    cin >> numTest;
    //cout << "Num test: " << numTest <<endl;
    for(int i = 0; i<numTest; ++i)
    {
        int len;
        cin >> len;
        vector<int> arr;
        for(int j = 0; j<len; ++j)
        {
            int element;
            cin >> element;
            arr.push_back(element);
            //cout << element <<" ";
        }
        //cout << endl;
        cout <<maxContigousSubArr(arr.data(), len) <<" " <<maxNonContigousSubArr(arr) <<endl;
    }
    return 0;
}
