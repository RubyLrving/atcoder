#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9
#define DegreesToRads( degrees ) ((degrees) * (M_PI/ 180.0f))

using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }
const long long INF = 1LL << 60;

typedef struct {
    ll index[3];
} Matrix3X1;

typedef struct {
    ll index[3][3];
} Matrix3X3;

Matrix3X3 CreateFixed3X3Matrix(ll v){
    Matrix3X3 temp;
    rep(i, 3){
        rep(j, 3){
            temp.index[i][j] = v;
        }
    }
    return temp;
}

Matrix3X1 multiplyMatrixNxM(Matrix3X3 a, Matrix3X1 b){
    Matrix3X1 temp;
    temp.index[0] = 0; temp.index[1] = 0; temp.index[2] = 0;

    rep(i, 3){
        rep(j, 3){
            temp.index[i] += (a.index[i][j] * b.index[j]);
        }
    }
    return temp;
}

Matrix3X3 multiply3X3Matrices(Matrix3X3 a, Matrix3X3 b)
{
    Matrix3X3 temp = CreateFixed3X3Matrix(0);

    for(int i = 0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                temp.index[i][j] += (a.index[i][k] * b.index[k][j]);
            }
        }
    }
    return temp;
}

Matrix3X3 translate2DByMultiplication(ll dx, ll dy){
    Matrix3X3 temp;

    temp = CreateFixed3X3Matrix(0);
    if(dy==0) temp.index[0][0] = -1;
    else temp.index[0][0] = 1;
    if(dx==0) temp.index[1][1] = -1;
    else temp.index[1][1] = 1;
    temp.index[2][2] = 1;

    temp.index[0][2] = dx;
    temp.index[1][2] = dy;

    return temp;
}

Matrix3X3 Rotate2D(ll theta){
    Matrix3X3 temp;

    temp = CreateFixed3X3Matrix(0);
    temp.index[0][0] = cos(DegreesToRads(theta));
    temp.index[1][1] = cos(DegreesToRads(theta));
    temp.index[2][2] = 1;
    temp.index[0][1] = -1 * sin(DegreesToRads(theta));
    temp.index[1][0] = sin(DegreesToRads(theta));

    return temp;
}

int main() {
    int n;
    cin >> n;

    vector<Matrix3X1> piece(n);
    rep(i, n){
        cin >> piece[i].index[0] >> piece[i].index[1];
        piece[i].index[2] = 1;
    }

    int m;
    cin >> m;
    
    vector<Matrix3X3> mat(1);
    mat[0].index[0][0] = 1;
    mat[0].index[1][1] = 1;
    mat[0].index[2][2] = 1;
    mat[0].index[0][2] = 0;
    mat[0].index[1][2] = 0;

    rep(i, m){
        int op;
        cin >> op;

        if(op == 1){
            Matrix3X3 m = Rotate2D(270);
            m = multiply3X3Matrices(m, mat.back());
            mat.push_back(m);
        }else if(op == 2){
            Matrix3X3 m = Rotate2D(90);
            m = multiply3X3Matrices(m, mat.back());
            mat.push_back(m);
        }else if(op == 3){
            int p;
            cin >> p;
            Matrix3X3 m = translate2DByMultiplication(2 * p, 0);
            m = multiply3X3Matrices(m, mat.back());
            mat.push_back(m);
        }else{
            int p;
            cin >> p;
            Matrix3X3 m = translate2DByMultiplication(0, 2 * p);
            m = multiply3X3Matrices(m, mat.back());
            mat.push_back(m);
        }
    }
   
    int q;
    cin >> q;

    rep(i, q){
        int a, b;
        cin >> a >> b;
        b--;

        Matrix3X1 m = multiplyMatrixNxM(mat[a], piece[b]);
        cout << m.index[0] << " " <<  m.index[1] << endl;
    }

    return 0;
}