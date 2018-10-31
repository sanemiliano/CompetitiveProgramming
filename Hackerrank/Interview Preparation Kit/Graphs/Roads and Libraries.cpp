#include <bits/stdc++.h>


using namespace std;

vector<string> split_string(string);
int fathers[100005];
int bucket[100005];
int find(int a){
    if(fathers[a] == a)
        return a;
    else
        return find(fathers[a]);
}
void unionN(int a, int b){
    int aux1 = find(a);
    int aux2 = find(b);
    fathers[aux2] = aux1;
}

void insertToBucket(int n){
    for(int i = 1; i <= n; i++){
        bucket[fathers[i]]++;
    }
}

// Complete the roadsAndLibraries function below.
long long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
   if(c_lib <= c_road)
        return n * c_lib;
    else{
        for (int i =0; i < 100005; i++){
            fathers[i] = i;
            bucket[i] = 0;
        }
        long long minimunCost = 0;
        for(int i= 0; i < cities.size(); i++){
            unionN(cities[i][0],cities[i][1]);
        }

        int groups = 0;
        for(int i =1; i <=n; i++){
            if(find(i) == i)
                groups++;
            fathers[i] = find(i);
        }
        minimunCost += groups * c_lib;
        
        insertToBucket(n);
        for(int i = 1; i <= 100000; i++){
            if(bucket[i] > 1)
                minimunCost += (bucket[i]-1) * c_road;
        }
        return minimunCost;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nmC_libC_road_temp;
        getline(cin, nmC_libC_road_temp);

        vector<string> nmC_libC_road = split_string(nmC_libC_road_temp);

        int n = stoi(nmC_libC_road[0]);

        int m = stoi(nmC_libC_road[1]);

        int c_lib = stoi(nmC_libC_road[2]);

        int c_road = stoi(nmC_libC_road[3]);

        vector<vector<int>> cities(m);
        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> cities[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}