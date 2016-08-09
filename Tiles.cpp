#include "Tiles.h"

Tiles::Tiles(){ // デフォルトコンストラクタ
    type = "";
    tileData = 0;
    next = nullptr;
    prev = nullptr;
}

Tiles::Tiles(int indx, string tileType, int data){ // 引数付きコンストラクタ
    index = indx;
    type = "tileType";
    tileData = data;
    next = nullptr;
    prev = nullptr;
}