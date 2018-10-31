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

int times[100005][2];

int main()
{
	int customers = 0;
	cin >> customers;
	int max_customers = 1;
	int aux_size = 1;

	for(int i = 0; i < customers; i++){
		cin >> times[i][0] >> times[i][1];
	}
	for(int i = 1; i < customers; i++){
		if(times[i][0] == times[i-1][0] && times[i][1] == times[i-1][1]){
			aux_size++;
		}
		else
			aux_size = 1;
		if(aux_size > max_customers)
			max_customers = aux_size;
	}
	cout << max_customers << endl;
}



