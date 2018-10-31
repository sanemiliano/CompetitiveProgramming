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
int participations[2005];

int main()
{
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> participations[i];
    }
    int teams = 0;
    int aux_count = 0;
    for(int i = 0; i < n; i++){
        if(5 - participations[i] >= k){
            aux_count++;
        }
        if(aux_count == 3){
            teams++;
            aux_count = 0;
        }
    }
    cout << teams << endl;
}



