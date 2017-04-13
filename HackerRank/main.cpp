//
//  main.cpp
//  HackerRank
//
//  Created by trongbangvp@gmail.com on 4/1/17.
//  Copyright © 2017 trongbangvp. All rights reserved.
//

#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

int main1(int argc, const char * argv[]) {
    string timeStr;
    cin >> timeStr;
    
    bool isAfternoon = false;
    size_t pPos = timeStr.find("p");
    if(pPos == string::npos)
    {
        pPos = timeStr.find("P");
    }
    if(pPos != string::npos)
    {
        isAfternoon = true;
    }
    
    size_t fistColonPos = timeStr.find(":");
    const string hhStr = timeStr.substr(0, fistColonPos);
    int hh = stoi(hhStr, NULL);
    if(isAfternoon)
    {
        if(hh != 12)
        {
            hh += 12;
        }
    } else
    {
        if(hh == 12)
        {
            hh = 0;
        }
    }
    
    string mmssStr = timeStr.substr(fistColonPos, 6);
    char result[9];
    sprintf(result, "%0.2d%s", hh, mmssStr.c_str());
    cout << result <<endl;
    
    return 0;
}
