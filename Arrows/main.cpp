#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;


class Arrows{
public:
    int longestArrow(string s){
        int max = -1;
        int left = 0;
        // int right = 0;
        int length = -1;
        char tail = '\0';
        int tail_size = 0;
        for(char c: s){
            switch (c){
                case '<':
                    left = 1;
                    length = 1;
                    tail_size = 0;
                    tail = '\0';
                    break;
                case '>' :
                    left = 0;
                    length = tail_size + 1;
                    tail_size = 0;
                    tail = '\0';
                    break;
                case '-':
                    if(tail == '-'){
                        tail_size++;
                        if(left) length = tail_size +1;
                    }else if(tail == '='){
                        tail_size = 1;
                        left = 0; 
                    }else{
                        tail_size = 1;
                    }
                    tail = '-';
                    break;
                case '=':
                     if(tail == '='){
                        tail_size++;
                        if(left) length = tail_size + 1;
                    }else if (tail == '-'){
                        tail_size = 1;
                        left = 0;
                    }else{
                        tail_size = 1;
                    }
                    tail = '=';
                    break;
                default:
                    break;
            }
            if(length > max) max = length;
        }
        return max;

    }

};

int main(int argc, char * argv[]){
    Arrows a;
    cout << a.longestArrow("<--->--==>") << "\n";
    cout << a.longestArrow("<<<<<<<<<") << "\n";
    cout << a.longestArrow("----==-") << "\n";
    cout << a.longestArrow("<----======>") << "\n";
    return 0;
}
