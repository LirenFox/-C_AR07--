#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int table[80];
    char c;
    int flag=0;
    vector<vector<int>> vec;
    set<int> s;
    for(int i=0; i<81; i++){
        cin >> c;
        table[i] = c-48;
    }
    int x = table[80];
    for(int row=0; row<9; row++){//檢查row，沒看過就丟到set，看到重複就cout
        for(int i=0; i<9; i++){
            if( table[row*9 + i] != 0 && s.count(table[row*9 + i]) != 0){
                cout << "row" << row+1 << " #" << table[row*9 + i] << endl;
                flag = 1;
                s.clear();
                break;
            }
            else{
                s.insert(table[row*9 + i]);
            }
        }
        s.clear();
    }
    for(int col=0; col<9; col++){//檢查column，沒看過就丟到set，看到重複就cout
        for(int i=0; i<81; i+=9){
            if( table[col + i] != 0 && s.count(table[col + i]) != 0){
                cout << "column" << col+1 << " #" << table[col + i] << endl;
                flag = 1;
                s.clear();
                break;
            }
            else
                s.insert(table[col + i]);
        }
        s.clear();
    }
    table[80] = x;
    vec.resize(9);
    vec[0].push_back(0);
    vec[1].push_back(3);
    vec[2].push_back(6);
    vec[3].push_back(27);
    vec[4].push_back(30);
    vec[5].push_back(33);
    vec[6].push_back(54);
    vec[7].push_back(57);
    vec[8].push_back(60);
    for(int blk=0; blk<9; blk++){//分到9個block
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(i!=0 || j!=0){
                    vec[blk].push_back(vec[blk][0] + i*9 + j);
                    //cout << vec[blk][0] + i*9 + j << " ";
                }
            }
        }
    }
    for(int blk=0; blk<9; blk++){//檢查block，沒看過就丟到set，看到重複就cout
        for(int i=0; i<9; i++){
            if( table[ vec[blk][i] ] != 0 && s.count(table[ vec[blk][i] ]) != 0){
                cout << "block" << blk+1 << " #" << table[ vec[blk][i] ] << endl;
                flag = 1;
                s.clear();
                break;
            }
            else
                s.insert(table[ vec[blk][i] ]);
        }
        s.clear();
    }
    if(flag == 0)
        cout << "true"<< endl;
    return 0;
}
