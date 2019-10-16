//https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

vector<int> positions;


/**
    Solution: We precalculate the position of every score,
              then for each result Alice has we see where it would rank up.
    This solution uses binary search, which will be talked about on Friday (18.10.19)
    I have intentionally left the slow (linear) solution commented there. 
    You can test its speed for yourself and see why we need biary search. 
*/
int getAlicePosition(int aliceScore, vector<int>& scores){

    int scoresSize= scores.size();

    int left = 0, right = scoresSize - 1;
    while(left < right){
        if(scores[(left + right) / 2] <= aliceScore){
            right = (left + right) / 2;
        } else {
            left = (left + right) / 2 + 1;
        }
    }
    if(scores[right] <= aliceScore){
        return positions[right];
    } else {
        return positions[right] + 1;
    }
}

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    int scoresSize = scores.size(),
        aliceSize = alice.size();
    
    positions.push_back(1);
    int currentPosition = 1;
    for(int i = 1; i < scoresSize; i++){
        if(scores[i] < scores[i - 1]){
            currentPosition++;
        }
        positions.push_back(currentPosition);
    }

    
    vector<int> result;

    for(int i = 0; i < aliceSize; i++){
        /*for(int j = 0; j < scoresSize; j++){
            if(alice[i] >= scores[j]){
                result.push_back(positions[j]);
                break;
            } else if (j == scoresSize - 1){
                result.push_back(positions[j] + 1);
            }
        }*/
        result.push_back(getAlicePosition(alice[i], scores));
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int scores_count;
    cin >> scores_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string scores_temp_temp;
    getline(cin, scores_temp_temp);

    vector<string> scores_temp = split_string(scores_temp_temp);

    vector<int> scores(scores_count);

    for (int i = 0; i < scores_count; i++) {
        int scores_item = stoi(scores_temp[i]);

        scores[i] = scores_item;
    }

    int alice_count;
    cin >> alice_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string alice_temp_temp;
    getline(cin, alice_temp_temp);

    vector<string> alice_temp = split_string(alice_temp_temp);

    vector<int> alice(alice_count);

    for (int i = 0; i < alice_count; i++) {
        int alice_item = stoi(alice_temp[i]);

        alice[i] = alice_item;
    }

    vector<int> result = climbingLeaderboard(scores, alice);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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
