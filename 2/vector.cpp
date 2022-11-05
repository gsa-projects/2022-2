#include <iostream>

using namespace std;

template <int dimension>
class vector {
public:
    double *elements = new double[dimension];
    double& operator[](int i) { return elements[i]; }
};

template <int D>
vector<D> operator+(vector<D> v1, vector<D> v2) {
    vector<D> ret;
    for (int i = 0; i < D; ++i) {
        ret[i] = v1[i] + v2[i];
    }

    return ret;
}

int main() {
    vector<19> v1, v2;
    
    cout << "v1: ";
    for (int i = 0; i < 19; i++) cin >> v1[i];
    cout << "v2: ";
    for (int i = 0; i < 19; i++) cin >> v2[i];

    vector<19> r = v1 + v2;
    for (int i = 0; i < 19; i++) cout << r[i] << " ";
}