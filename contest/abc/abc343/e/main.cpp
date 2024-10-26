#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0; i<(n); ++i)
#define repx(i,x,n) for(int i=x; i<(n); ++i)
#define fixed_setprecision(n) fixed << setprecision((n))
#define execution_time(ti) printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
#define pai 3.1415926535897932384
#define NUM_MAX 2e18
#define NUM_MIN -1e9
 
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmax(T& a, T b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b){ if(a>b){ a=b; return 1; } return 0; }

class Cube {
public:
    double x, y, z; // 立方体の中心座標
    double side;   // 立方体の一辺の長さ

    // コンストラクタ
    Cube(double x, double y, double z, double side)
        : x(x), y(y), z(z), side(side) {}

    // 立方体の体積を計算するメソッド
    double volume() const {
        return side * side * side;
    }
};

// 2つの立方体の重なっている部分の体積を計算する関数
double overlappingVolume(const Cube& cube1, const Cube& cube2) {
    double dx = abs(cube1.x - cube2.x);
    double dy = abs(cube1.y - cube2.y);
    double dz = abs(cube1.z - cube2.z);

    double overlapX = cube1.side / 2 + cube2.side / 2 - dx;
    double overlapY = cube1.side / 2 + cube2.side / 2 - dy;
    double overlapZ = cube1.side / 2 + cube2.side / 2 - dz;

    // 重なっている部分の体積を計算
    if (overlapX < 0 || overlapY < 0 || overlapZ < 0) {
        // 重なっていない場合
        return 0.0;
    } else {
        return overlapX * overlapY * overlapZ;
    }
}

// 3つの立方体の重なっている部分の体積を計算する関数
double overlappingVolume(const Cube& cube1, const Cube& cube2, const Cube& cube3) {
    // それぞれの立方体の各座標軸での最小値と最大値を計算
    double minX = max({cube1.x - cube1.side / 2, cube2.x - cube2.side / 2, cube3.x - cube3.side / 2});
    double maxX = min({cube1.x + cube1.side / 2, cube2.x + cube2.side / 2, cube3.x + cube3.side / 2});
    
    double minY = max({cube1.y - cube1.side / 2, cube2.y - cube2.side / 2, cube3.y - cube3.side / 2});
    double maxY = min({cube1.y + cube1.side / 2, cube2.y + cube2.side / 2, cube3.y + cube3.side / 2});
    
    double minZ = max({cube1.z - cube1.side / 2, cube2.z - cube2.side / 2, cube3.z - cube3.side / 2});
    double maxZ = min({cube1.z + cube1.side / 2, cube2.z + cube2.side / 2, cube3.z + cube3.side / 2});

    // 3つの立方体が重なっていない場合は体積は0
    if (minX >= maxX || minY >= maxY || minZ >= maxZ) {
        return 0.0;
    }

    // 重なっている部分の体積を計算
    double overlapVolume = (maxX - minX) * (maxY - minY) * (maxZ - minZ);
    return overlapVolume;
}

int main() {
    ll V1, V2, V3;
    cin >> V1 >> V2 >> V3;

    for(ll a=-7; a<=7; a++){
        for(ll b=-7; b<=7; b++){
            for(ll c=-7; c<=7; c++){
                for(ll d=-7; d<=7; d++){
                    for(ll e=-7; e<=7; e++){
                        for(ll f=-7; f<=7; f++){
                            Cube c1 = Cube(0, 0, 0, 7);
                            Cube c2 = Cube(a, b, c, 7);
                            Cube c3 = Cube(d, e, f, 7);

                            double c1c2 = overlappingVolume(c1, c2);
                            double c2c3 = overlappingVolume(c2, c3);
                            double c3c1 = overlappingVolume(c3, c1);
                            double c1c2c3 = overlappingVolume(c1, c2, c3);

                            if(1029-(c1c2*2+c2c3*2+c3c1*2)+c1c2c3*3 == V1 && c1c2+c2c3+c3c1-c1c2c3*3 == V2 && c1c2c3==V3){
                                cout << "Yes" << endl;
                                cout << 0 << ' ' << 0 << ' ' << 0 << ' ' << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "No" << endl;
    return 0;
} 