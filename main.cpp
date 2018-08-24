#include "AmericanMahjong.h"
using namespace std;

int main(){
    const int NUMTILE = 152; //　全体の牌の数
#
    
//    char num_player;
//    cout << "プレイの人数を選択してください(A: 3人　B:4人): ";
//    cin >> num_player;
//    
//    while(num_player != 'A' && num_player != 'B'){
//        cin.ignore(256, '\n');
//        cout << "入力エラー：3人で遊ぶ場合はA、4人で遊ぶ場合はBを入力してください: ";
//        cin >> num_player;
//    }

    AmericanMahjong myMahjong; //デフォルトコンストラクタを呼ぶ
    myMahjong.set_all_tile(); // 牌を152個山にセットする
        
    
    
    cout << "\n\n今回あなたは" << myMahjong.get_wind() << "です。\n";
    cout << "持ち牌: ";
    myMahjong.print_my_tile();
    
    
    return 0;
}
