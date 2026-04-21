#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    if(!(cin >> m >> n)) return 0;
    vector<vector<int>> a(m, vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++) cin >> a[i][j];
    }

    int H = 3*m, W = 3*n;
    vector<vector<int>> out(H, vector<int>(W, 0));

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(i%3==1 && j%3==1){
                int R = i/3, C = j/3;
                out[i][j] = a[R][C];
                continue;
            }
            int Rb = i/3, Cb = j/3;
            double sumA = 0.0, sumB = 0.0;
            int cntA = 0, cntB = 0;
            for(int dR=-1; dR<=1; dR++){
                int R = Rb + dR;
                if(R < 0 || R >= m) continue;
                int ci = 3*R + 1;
                for(int dC=-1; dC<=1; dC++){
                    int C = Cb + dC;
                    if(C < 0 || C >= n) continue;
                    int cj = 3*C + 1;
                    int d = abs(ci - i) + abs(cj - j);
                    if(d == 1){ sumA += a[R][C]; cntA++; }
                    else if(d == 2){ sumB += a[R][C]; cntB++; }
                }
            }
            int val = 0;
            if(cntA == 0 && cntB > 0){
                val = (int)floor(sumB / cntB);
            }else if(cntB == 0 && cntA > 0){
                val = (int)floor(sumA / cntA);
            }else if(cntA > 0 && cntB > 0){
                double avgA = sumA / cntA;
                double avgB = sumB / cntB;
                val = (int)floor(avgA * 0.8 + avgB * 0.2);
            }else{
                // Fallback: shouldn't happen, but keep safe
                val = 0;
            }
            if(val < 0) val = 0;
            if(val > 100) val = 100;
            out[i][j] = val;
        }
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cout << out[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
