#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> a = { 2,4,6,7,1,0,8,9,6,3,2 };
    auto maxPosition = max_element(a.begin(), a.end());
    cout << *maxPosition << " at the postion of " << maxPosition - a.begin() <<endl;
    //cout << a[maxPosition - a.begin()] << " at the postion of " << distance(a.begin(), maxPosition) << endl;
    // system("pause");
    return 0;
}
