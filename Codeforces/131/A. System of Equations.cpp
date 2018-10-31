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

using namespace std;

int main()
{
    //cin.tie(0);
    //ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int size_bigger = max(n,m);
    int cont = 0;
    for(int i = 0; i <= size_bigger; i++){
        for(int e = 0; e <= size_bigger; e++){
            if(i *i + e == n && i + e * e == m){
                cont++;
            }
        }
    }
    cout << cont << endl;
}



