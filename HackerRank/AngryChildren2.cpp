//
//  AngryChildren2.cpp
//  HackerRank
//
//  Created by trongbangvp@gmail.com on 4/1/17.
//  Copyright © 2017 trongbangvp. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

bool comparator(int a, int b)
{
    return a < b;
}

unsigned long long calculateUnfairness(int* arr, int n)
{
    unsigned long long sum = arr[0];
    unsigned long long result = 0;
    unsigned long long temp;
    for(int i = 1; i<n; ++i)
    {
        temp = arr[i];
        result = result + i*temp - sum;
        sum += temp;
    }
    return result;
}

void solve(vector<int>& arr, int K) {
    if(arr.size() == 1 || K == 1)
    {
        cout<<0 <<endl;
        return;
    }
    size_t N = arr.size();
    sort(arr.begin(), arr.end(), comparator);
    
    unsigned long long minUnfairness = LONG_MAX;
    int* data = arr.data();
    
    unsigned long long sum[N-K+1]; //sum[i] = sum (i -> i+K-2)
    sum[0] = 0;
    for(int i = 0; i<K-1; ++i)
    {
        sum[0] += data[i];
    }
    for(int i = 1; i<= N-K; ++i)
    {
        sum[i] = sum[i-1] - data[i-1] + data[i+K-2];
    }
    minUnfairness = calculateUnfairness(data, K);
    
    for(int i = 1; i <= N - K; ++i)
    {
        unsigned long long tmp1 = ((unsigned long long)(K-1)) * data[i-1];
        unsigned long long tmp2 = ((unsigned long long)(K-1)) * data[i+K-1];
        minUnfairness = min(minUnfairness, minUnfairness - (sum[i] - tmp1) + (tmp2 - sum[i]));
    }
    cout << minUnfairness <<endl;
}

int main2() {
    int N, K;
    cin >> N >> K;
    vector<int> arr;
    for(int i = 0; i < N; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    solve(arr, K);
    return 0;
}

