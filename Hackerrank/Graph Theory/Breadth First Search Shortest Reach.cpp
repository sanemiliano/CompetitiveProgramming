#include <bits/stdc++.h>

using namespace std;
class Node{
    public:
    int index = 0;
    int sum = -1;
    vector<Node*> connected;
    bool visited = false;
    Node(int index){
       this->index = index;
    }
};
vector<string> split_string(string);
vector<Node*> nodes;

// Complete the bfs function below.
vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    nodes.clear();
    vector<int> answer;
    //Creating our graph.
    for(int i = 0 ; i < n; i++){
        Node* aux = new Node(i+1);
        nodes.push_back(aux);
    }
    for(int i = 0; i < m; i++){
        nodes[edges[i][0]-1]->connected.push_back(nodes[edges[i][1]-1]);
        nodes[edges[i][1]-1]->connected.push_back(nodes[edges[i][0]-1]);
    }
    int size_aux;
    for(int i = 0; i < n; i++){
        cout << nodes[i]->index << ":\n";
        size_aux = nodes[i]->connected.size();
        for(int e = 0; e < size_aux; e++){
            cout << "     "<< nodes[i]->connected[e]->index<< endl;
        }
    }
    //BFS from starting vertex
    //Passing values to the answer vector
    queue<Node*> myqueue;
    myqueue.push(nodes[s-1]);
    while(!myqueue.empty()){
        Node* aux = myqueue.front();
        myqueue.pop();
        size_aux = aux->connected.size();
        for(int i = 0; i < size_aux; i++){
            if(!aux->connected[i]->visited){
                aux->connected[i]->visited = true;
                int sumaux = aux->connected[i]->sum;
                aux->connected[i]->sum = aux->sum == -1 ? 6: aux->sum + 6;
                myqueue.push(aux->connected[i]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(i+1 != s)
            answer.push_back(nodes[i]->sum);
    }
    return answer;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<vector<int>> edges(m);
        for (int i = 0; i < m; i++) {
            edges[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> edges[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int s;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<int> result = bfs(n, m, edges, s);

        for (int i = 0; i < result.size(); i++) {
            fout << result[i];

            if (i != result.size() - 1) {
                fout << " ";
            }
        }

        fout << "\n";
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
