#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <string>
using namespace std;

class Library{
private:
    void split(const string &r, string &name, 
               string &room, string &group)
    {
        int start = 0;
        int i = r.find_first_of(" ");
        name = r.substr(start, i-start);
        start = i+1;
        i = r.find_last_of(" ");
        room = r.substr(start, i-start);
        start = i+1;
        group = r.substr(start);
    }
public:
    int documentAccess(vector<string> &recs,
                       vector<string> &userGroups,
                       vector<string> &roomRights)
    {
        unordered_set<string> groups(userGroups.begin(), userGroups.end());
        unordered_set<string> rooms(roomRights.begin(), roomRights.end());
        unordered_set<string> docs;
        for(const auto &r: recs){
            string name, group, room;
            split(r, name, room, group);
            if(groups.find(group)!=groups.end() && 
                    rooms.find(room)!=rooms.end())
                docs.insert(name);
        }
        return docs.size();
    
    }

};


int main(){
    Library l;
    vector<string> recs = {"diary computers editor","fairytale gardening editor",
                            "comix cars author","comix cars librarian"};
    vector<string> groups = {"employee","editor","author"};
    vector<string> rooms = {"history","cars","computers"};
    cout << l.documentAccess(recs, groups, rooms) << "\n";
    
    vector<string> recs2 = {"a b c","a b d","b b c","b b d","e c d","e c b","e c c","t d e"};
    vector<string> groups2 ={"c","d","x"};
    vector<string> rooms2 = {"a","b","c"};

    cout << l.documentAccess(recs2, groups2, rooms2) << "\n";
    

}
