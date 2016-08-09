//
//  File.cpp
//  Amerian Majong
//
//  Created by Yujiro on 2016/07/31.
//  Copyright (c) 2016年 Yujiro Nakanishi. All rights reserved.
//

#include "AmericanMahjong.h"
using namespace std;


// コンストラクタ
AmericanMahjong::AmericanMahjong(){
    num_tile_left = 152;
    set_wind();
    head = nullptr;
    tail = nullptr;
    
    set_all_tile();
}
    
    
// 配列に牌を追加
void AmericanMahjong::set_all_tile(){
    Tiles *ptr = new Tiles;
    for(int i=0; i<NUMTILE; i++){
        
    }
}

bool AmericanMahjong::isEmpty(){
    if(head == tail){
        return true;
    } else {
        return false;
    }
}

    // 牌の配列をシャッフルする
    shuffle_tile(ptr);
    
    // 牌をセットする
    set_tile(myWind);
    
    // 牌をソートする
    begin_sort();

}


// メンバ関数
void AmericanMahjong::add_tile(){
    int i,j;
    string s;
    
   // クラック、ドット、バンブーを格納
    for(i=1; i<10; i++){
        s = to_string(i);
        for(j=0; j<4; j++) tiles.push_back("kr" + s);
        for(j=0; j<4; j++) tiles.push_back("do" + s);
        for(j=0; j<4; j++) tiles.push_back("ba" + s);
    }
    
    // 東西南北、ドラゴンを格納
    for(i=0; i<4; i++) tiles.push_back("sop");
    for(i=0; i<4; i++) tiles.push_back("red");
    for(i=0; i<4; i++) tiles.push_back("grn");
    for(i=0; i<4; i++) tiles.push_back("wes");
    for(i=0; i<4; i++) tiles.push_back("sth");
    for(i=0; i<4; i++) tiles.push_back("est");
    for(i=0; i<4; i++) tiles.push_back("nor");
    
    // フラワー、ジョーカーを格納
    for(i=0; i<8; i++) tiles.push_back("flw");
    for(i=0; i<8; i++) tiles.push_back("jkr");
    
    // ソートされた牌のベクターに牌をコピーしておく
    for(i=0; i<NUMTILE; i++) tiles_sorted.push_back(tiles[i]);
    
}

void AmericanMahjong::shuffle_tile(vector<string> *ptr){
    for(int i=0; i<NUMTILE; i++){ // 配列を横断しtiles[i]を値をランダムで別の値にスワップしシャッフルする
        int rand_pos = rand()%152;
        string temp = (*ptr)[i];
        (*ptr)[i] = (*ptr)[rand_pos];
        (*ptr)[rand_pos] = temp;
    }
}


void AmericanMahjong::set_tile(string wind){ // ゲーム開始時の手牌をセットする 親=14個/子=13個
    if(myWind=="E"){ // 親の場合
        for(int i=0; i<EAST_TILE; i++){
            tehuda.push_back(tiles[num_tile_left - 1]);
            tiles.pop_back();
            num_tile_left--;
        }
    } else { // 子の場合
        for(int i=0; i<NON_EAST_TILE; i++){
            tehuda.push_back(tiles[num_tile_left - 1]);
            tiles.pop_back();
            num_tile_left--;
        }
    }
}

void AmericanMahjong::begin_sort(){
    int limit, pos, j;
    if(myWind == "E"){
        limit = EAST_TILE;
    } else {
        limit = NON_EAST_TILE;
    }
    
    // クラック属-ドット属-バンブー属-ドラゴン属-ウィンド属-フラワー-JOKERの順に並びかえる
    for(int i=0; i<limit; i++){
        pos = 0, j = 0;
        while(j<NUMTILE){
            if(tehuda[i] == tiles_sorted[j]){
                tehuda_num.push_back(pos);
                break;
            }
            pos++;
            j++;
        }
    }
    
    
    sort(tehuda_num.begin(), tehuda_num.end());
    //for(i=0; i<limit; i++) cout << tehuda_num[i] << ' ';
    
    
}


void AmericanMahjong::print_my_tile(){ for(int i=0; i<get_tehuda_size(); i++) cout << tehuda[i] << ' '; cout << endl;}
string AmericanMahjong::get_myWind(){ return myWind;}
int AmericanMahjong::get_tehuda_size(){ if(myWind == "E") return 14; else return 13;}
int AmericanMahjong::get_tile_count(){ return num_tile_left;}