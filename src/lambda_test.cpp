#include <iostream>
using namespace std;

int main(){
    auto f = [](int a, int b){return a-b;};
    cout << f(5, 3) << endl;
    int r = [](int a, int b){return a*b;}(3, 5);
    cout << r << endl;
    int s = [r]{return r*r;}();
    cout << s << endl;
    [&]{r = r * r;}();
    cout << r << endl;
    return 0;
}
