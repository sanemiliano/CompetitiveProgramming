#include <stdio.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <math.h>
#include <queue>
#include <bitset>
#include <utility>
#include<cmath>
#include<cstdio>
#include<vector>

typedef long long ll;
typedef std::vector<ll> vi;

const double EPS = 1e-12;
const ll MAX = 1e6 + 10;
const ll MOD = 1e9 + 7;

using namespace std;
#include <bits/stdc++.h>

int starsPedalArr[60];
int starsWheelArr[60];

using namespace std;

int main()
{
    //cin.tie(0);
    //ios_base::sync_with_stdio(0);

    int starsPedal,starsWheel;
    cin >> starsPedal;

    for(int i = 0; i < starsPedal; i++){
        cin >> starsPedalArr[i];
    }
    cin >> starsWheel;
    for(int i = 0; i < starsWheel; i++){
        cin >> starsWheelArr[i];
    }
    int counter = 0;
    int maxQuotient = 0;
    int auxQuotient = 0;
    for(int i = 0; i < starsPedal; i++){
        for(int e = 0; e < starsWheel; e++){
            if(starsWheelArr[e] % starsPedalArr[i] == 0){
                auxQuotient = starsWheelArr[e] / starsPedalArr[i];
                if(auxQuotient > maxQuotient)
                    maxQuotient = auxQuotient;
            }
        }
    }
    for(int i = 0; i < starsPedal; i++){
        for(int e = 0; e < starsWheel; e++){
            if(starsWheelArr[e] % starsPedalArr[i] == 0){
                if(starsWheelArr[e] / starsPedalArr[i] == maxQuotient)
                    counter++;
            }
        }
    }
    cout << counter << endl;
}
