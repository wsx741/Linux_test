#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<double> sources{75, 95.4, 55.2, 45.6, 87, 66};
    double s = 0;
    [&]{
        for(double t : sources)
            s += t;
    }();
    cout << s << endl;
    return 0;
}
