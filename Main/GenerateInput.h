#include <bits/stdc++.h>
#include "../libraries/FunctionRadom.h"

#define int long long
using namespace std;

vector<Subtask> subtasks = {
    {percent: 20, lenN: 2, lenAi: 3}, //20% test có n <= 10^2, mỗi ai <= 10^3
    {percent: 30, lenN: 4, lenAi: 6}, //30% test có n <= 10^4, mỗi ai <= 10^6
    {percent: 50, lenN: 6, lenAi: 18}, //50% test có n <= 10^6, mỗi ai <= 10^18
};


void generateInput(int currentTest, int totalTests , string target_file = "input.txt")
{
    ofstream cout(target_file);
    srand(time(0) + currentTest); // Sinh số ngẫu nhiên theo thời gian thực
    // Cout ra những đầu vào cần thiết ở phía dưới
    int n = random(1, 100);
    cout << n << endl;
}

    