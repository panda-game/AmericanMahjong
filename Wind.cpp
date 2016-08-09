#include "Wind.h"
#include <stdlib.h> // rand

void Wind::set_wind(){
    int i = rand()%4; // 0-3の整数をランダムに生成
    myWind = winds[i];
}

string Wind::get_wind(){
    return myWind;
}