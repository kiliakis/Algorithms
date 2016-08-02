#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// first reqs, classes, s, t
int g[146][146];


// bool satisfied[num of classes];
//
class Graduation{
    public:

    string moreClasses(string taken, vector<string> req){
        // need to implement an adjancy list here
        string res = "";
        for(int i =0; i < 146; ++i)
            for (int j = 0; j<146; ++j)
                g[i][j] = 0;
        
        for(int i = 0; i< req.size(); ++i){
            int s = req[i].find_first_of("123456789");
            int e = req[i].find_last_of("0123456789");
            //cout << req[i].substr(s, e-s+1) << "\n";
            int num = atoi(req[i].substr(s, e-s+1).c_str());
            g[144][i] = num;
            for(int j = e+1; j < req[i].size(); ++j){
                g[i][50 + req[i][j] - 33] = 1;
                g[50 + req[i][j] - 33][145] = 1;
            }

        }
        
        // now add the already taken classes
        
        for(const auto &c: taken){
            for(int i = 0; i< req.size(); ++i){
                if(g[i][c + 17] > 0 && g[144][i] > 0){
                    g[144][i]--;
                    g[i][144]++;
                    g[i][c+17]--;
                    g[c+17][i]++;
                    g[c+17][145]--;
                    g[145][c+17]++;
                }
            }
        }
        /*
        for(int i =0; i < 146; ++i){
            for (int j = 0; j<146; ++j)
                cout << g[i][j];
            cout << "\n";
        }
        */
        bool flag = true;
        while(true){
            flag = false;
            for(int i = 0; i < req.size(); ++i){
                if(g[144][i] > 0){
                    for(int j = 0; )
                }
            
            } 
        }
        return res;
    }


};


int main(int argc, char * argv[]){
   Graduation gr;
   gr.moreClasses("A", {"2ABC", "2CDE"});
    
    return 0;
}
