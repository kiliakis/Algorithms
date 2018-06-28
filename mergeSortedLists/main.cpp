
#include <unordered_map>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void print(ListNode *head){
    for(; head!=NULL; head=head->next) cout << head->val << "->";
    cout << "\n";
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2){
        auto root = new ListNode(0);
        auto curr = root;
        while(l1 || l2){
            if(l1 && l2){
                if(l1->val <= l2->val) {
                    curr->next = l1;
                    // curr = curr->next;
                    l1 = l1->next;
                }else{
                    curr->next = l2;
                    // curr = curr->next;
                    l2 = l2->next;
                }
            }else if (l2){ // l2 only
                curr->next = l2;
                // curr = curr->next;
                l2 = l2->next;
            }else{
                curr->next = l1;
                l1 = l1->next;                
            }
            curr = curr->next;
        }
        return root->next;
    }

};


int main(){
    Solution s;
    auto l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(7);

    auto l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    l2->next->next->next = new ListNode(10);


    // auto res = s.mergeTwoLists(l1, l2);
    // print(res);

    // print(s.mergeTwoLists(l1, NULL));
    print(s.mergeTwoLists(NULL, NULL));

}
