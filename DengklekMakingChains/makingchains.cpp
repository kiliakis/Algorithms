#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;



class DengklekMakingChains{
    int string_to_int(const string &str){
        int res = 0;
        for(const auto &c: str)
            if(c != '.')
                res += c - '0';
        return res;
    }

    bool contains_dot(const string &str){
        return str.find(".")!=string::npos;
    }
    
    int left_val(const string &str){
        int j = 0;
        int res = 0;
        while(j<3 && str[j]!='.'){
            res += str[j] - '0';
            j++;
        }
        
        return j==3 ? 0 : res;
    }

    int right_val(const string &str){
        int j = 2;
        int res = 0;
        while(j>=0 && str[j]!='.'){
            res += str[j] - '0';
            j--;
        }
        
        return j==-1 ? 0 : res;
    }

public:
    int maxBeauty(vector<string> chains){
        int res = 0;
        
        // first we add all not rusty parts
        for(const auto &str: chains)
            if(!contains_dot(str))
                res += string_to_int(str);
        
        //int i1 = -1;
        //int i2 = -1;
        //int maxR = 0;
        //int maxL = 0;
        //int maxC = 0;
        // then we search for the best right little rusty part
        /*
        for(const auto &str: chains){
            if(contains_dot(str)){
                if(str[2]!='.' && str[1]!='.'){
                    int val = string_to_int(str);
                    if(val > maxR)
                        maxR= val;
                }else if(str[0]!='.' && str[1]!='.'){
                    int val = string_to_int(str);
                    if(val > maxL)
                        maxL = val;
                }else if(str[2]!='.' && str[0]!='.'){
                    int valL = str[0] - '0';
                    int valR = str[2] - '0';
                    if(valL > valR && valL > maxL)
                        maxL = valL;
                    else if(valR > maxR)
                        maxR = valR;
                }else if(str[2]!='.' && str[1]=='.'){
                    int val = str[2] - '0';
                    if(val > maxR) maxR = val; 
                }else if(str[0]!='.' && str[1] == '.'){
                    int val = str[0] - '0';
                    if(val > maxL) maxL = val;
                }else if(str[0] == '.' && str[2] == '.' && str[1]!='.'){
                    if (str[1] - '0' > maxC)
                        maxC = str[1] - '0';
                }
            }

        }
        */

        int i1 = 0;
        int i2 = 0;
        
        for(int i =0; i < chains.size(); ++i){
            int val = left_val(chains[i]);
            if(val > left_val(chains[i2]))
                i2 = i;
            if(val > left_val(chains[i1]))
                swap(i1, i2);
        }
        
        int i3 = 0;
        int i4 = 0;
        for(int i =0; i < chains.size(); ++i){
            int val = right_val(chains[i]);
            if(val > right_val(chains[i4]))
                i4 = i;
            if(val > right_val(chains[i3]))
                swap(i3, i4);
        }
        
        int maxC = 0;
        for(const auto &str: chains){
            if(str[0] == '.' && str[1]!='.' && str[2] == '.')
                if(str[1] - '0' > maxC)
                    maxC = str[1] - '0';
        }
        int maxL = 0;
        int maxR = 0;
        if(i1 != i3){
            maxL = left_val(chains[i1]);
            maxR = right_val(chains[i3]);
        }else{
            int max1L = left_val(chains[i1]);
            int max2L = i2 == i1 ? 0 : left_val(chains[i2]);
            int max1R = right_val(chains[i3]);
            int max2R = i4 == i3 ? 0 : right_val(chains[i4]);
            if(max1L + max2R > max2L + max1R){
                maxL = max1L;
                maxR = max2R;
            }else{
                maxL = max2L;
                maxR = max1R;
            }
        }
        res = res + maxR + maxL;
        
        if(maxC > res) res = maxC;
        return res;
       
    }
};  
  
int main(int argc, char * argv[]){
    DengklekMakingChains mc;
    cout << mc.maxBeauty({".15", "7..", "402", "..3"}) << "\n";
    cout << mc.maxBeauty({"..1", "7..", "567", "24.", "8..", "234"}) << "\n";
    cout << mc.maxBeauty({"...", "..."}) << "\n";
    cout << mc.maxBeauty({"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"}) << "\n";
    cout << mc.maxBeauty({"..1", "3..", "2..", ".7."}) << "\n";
    cout << mc.maxBeauty({"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"}) << "\n";
    
    return 0;
}
