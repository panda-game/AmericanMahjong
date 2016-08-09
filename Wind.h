//
//  Wind.h
//  Amerian Majong
//
//  Created by Yujiro on 2016/08/07.
//  Copyright (c) 2016年 Yujiro Nakanishi. All rights reserved.
//

#ifndef WIND_H
#define WIND_H

#include <string>
using namespace std;

class Wind{
    const string winds[4] = {"E","S","W","N"};
    string myWind;
public:
    void set_wind();
    string get_wind();
};

#endif /* defined(__Amerian_Majong__Wind__) */
