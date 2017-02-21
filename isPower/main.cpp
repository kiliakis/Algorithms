#include <vector>
#include <iostream>
using namespace std;

bool isPower(int A) {
	if(A==1) return true;
	for(int i = 2; i*i <= A; i++){
		int num = A;
		while(num > 1 && num%i == 0) { cout << num << "\n"; num /= i;}
		if(num == 1) return true;
	}
	return false;
}

int main(){
	cout << isPower(4) << "\n"; 

}
