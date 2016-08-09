#ifndef __Amerian_Majong__Tiles__
#define __Amerian_Majong__Tiles__

#include <string>
using namespace std;


class Tiles
{
    string type; // 牌の種類
    int index; // 牌の索引
    int tileData; // 牌の数字
    Tiles *next;
    Tiles *prev;
    
public:
    Tiles();
    Tiles(int index, string tileType, int tileData);
    friend class AmericanMahjong; // AmericanMahjongクラスからTilesクラスのプライベートデータメンバへのアクセス許可
};



#endif
