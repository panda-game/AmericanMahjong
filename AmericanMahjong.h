#ifndef AMERICAN_MAHJONG_H
#define AMERICAN_MAHJONG_H

#include "Tiles.h"
#include "Dice.h"
#include "Wind.h"
#include <iostream> // cout
#include <ctime> // time
#include <vector> // vector

#include <string>

using namespace std;

class AmericanMahjong: public Wind
{
    const int NUMTILE = 152; //　全体の牌の数
    const int EAST_TILE = 14; // 親の牌
    const int NON_EAST_TILE = 13; // 子の牌
    int num_tile_left; // 場に出た牌の数
    // 牌を格納
    // ソートされた状態の牌を格納
    // 手札の牌を格納
    Tiles *head;
    Tiles *tail;
    
public:
    // コンストラクタ
    AmericanMahjong();
    
    // メンバ関数の宣言
    int get_discarded(); // 場に捨てられた牌の数を返す
    int get_my_size();
    bool isEmpty(); // リストが空かどうか確認しブール値を返す
    void print_my_tile(); // 手札を出力
    void add_tile(); // 牌の配列を生成
    void shuffle_all_tile(Tiles *ptr); // 牌をシャッフルする
    void set_all_tile(); // 152個の牌をセットする
    void set_my_tile(); // ゲーム開始時の手牌をセットする 親=14個/子=13個
    void sort_tile(); // 牌をソートする
    void discard_tile(int num); // 牌を捨てる
    string get_tile(); // 牌を一つ引く
    
};


#endif
