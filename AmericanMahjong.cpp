#include "AmericanMahjong.h"
using namespace std;

/*------------------コンストラクタ----------------*/
AmericanMahjong::AmericanMahjong(){
    num_tile_left = 152;
    set_wind();
    set_all_tile();
}
    
    
/*------------------メンバ関数------------------*/
void AmericanMahjong::set_all_tile(){// 牌を山にセットする

    // クラック,ドット,バンブーの1~9牌を山に入れる
    for(int i=1; i<10; i++){
        for(int j=1; j<5; j++){
            Tiles *ptr = new Tiles('a',i);
            yama.push_back(*ptr);
            Tiles *ptr = new Tiles('b',i);
            yama.push_back(*ptr);
            Tiles *ptr = new Tiles('c',i);
            yama.push_back(*ptr);
        }
    }
    
    // 各種ドラゴン, WINDSを山に入れる
    for(int i=1; i<5; i++){
        Tiles *ptr = new Tiles('d',1);
        yama.push_back(*ptr);
        Tiles *ptr = new Tiles('e',1);
        yama.push_back(*ptr);
        Tiles *ptr = new Tiles('f',1);
        yama.push_back(*ptr);
        Tiles *ptr = new Tiles('g',1);
        yama.push_back(*ptr);
        Tiles *ptr = new Tiles('h',1);
        yama.push_back(*ptr);
        Tiles *ptr = new Tiles('i',1);
        yama.push_back(*ptr);
        Tiles *ptr = new Tiles('j',1);
        yama.push_back(*ptr);
    }
    
    // フラワー, JOKERを山に入れる
    for(int i=1; i<9; i++){
        Tiles *ptr = new Tiles('k',1);
        yama.push_back(*ptr);
        Tiles *ptr = new Tiles('l',1);
        yama.push_back(*ptr);
    }
}

void AmericanMahjong::shuffle_all_tile(){
    for(int i=0; i<NUMTILE; i++){ // 配列を横断しtiles[i]を値をランダムで別の値にスワップしシャッフルする
        int rand_pos = rand()%152;
        swap_tiles(i,rand_pos); // 牌の値をスワップする
    }
}

void AmericanMahjong::swap_tiles(int index1, int index2){ // 牌の値をスワップする
    char temp_ch = yama[index2].type;
    int temp_int = yama[index2].data;
    
    yama[index2].type = yama[index1].type;
    yama[index2].data = yama[index1].data;
    
    yama[index1].type = temp_ch;
    yama[index1].data = temp_ch;
}

//void AmericanMahjong::set_tile(string wind){ // ゲーム開始時の手牌をセットする 親=14個/子=13個
//    if(myWind=="E"){ // 親の場合
//        for(int i=0; i<EAST_TILE; i++){
//            tehuda.push_back(tiles[num_tile_left - 1]);
//            tiles.pop_back();
//            num_tile_left--;
//        }
//    } else { // 子の場合
//        for(int i=0; i<NON_EAST_TILE; i++){
//            tehuda.push_back(tiles[num_tile_left - 1]);
//            tiles.pop_back();
//            num_tile_left--;
//        }
//    }
//}

//void AmericanMahjong::begin_sort(){
//    int limit, pos, j;
//    if(myWind == "E"){
//        limit = EAST_TILE;
//    } else {
//        limit = NON_EAST_TILE;
//    }
//    
//    // クラック属-ドット属-バンブー属-ドラゴン属-ウィンド属-フラワー-JOKERの順に並びかえる
//    for(int i=0; i<limit; i++){
//        pos = 0, j = 0;
//        while(j<NUMTILE){
//            if(tehuda[i] == tiles_sorted[j]){
//                tehuda_num.push_back(pos);
//                break;
//            }
//            pos++;
//            j++;
//        }
//    }
//    
//    
//    sort(tehuda_num.begin(), tehuda_num.end());
//    //for(i=0; i<limit; i++) cout << tehuda_num[i] << ' ';
//    
//    
//}


//void AmericanMahjong::print_my_tile(){ for(int i=0; i<get_tehuda_size(); i++) cout << tehuda[i] << ' '; cout << endl;}
void AmericanMahjong::print_my_tile(){ cout << yama[0].type << ' ' << yama[0].data << endl;}

string AmericanMahjong::get_myWind(){ return myWind;}
int AmericanMahjong::get_tehuda_size(){ if(myWind == "E") return 14; else return 13;}
int AmericanMahjong::get_tile_count(){ return num_tile_left;}
