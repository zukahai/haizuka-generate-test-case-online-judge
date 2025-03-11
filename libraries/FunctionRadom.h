#include<bits/stdc++.h>
#include <ctime>
using namespace std;

template <typename T>
void print_vector (vector<T> a, ofstream &cout) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
}

struct Subtask
{
    int percent;
    int lenN;
    int lenAi;
};


template <typename T>
void printMatrix (vector<vector<T>> a, ofstream &cout) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}


long long random();
long long random(long long l, long long r);
vector<long long> randomVector(int n, long long l, long long r);
vector<long long> randomVector(int n, long long x);
string randomString(int n, string charset);
string randomString(int n);
string randomString(int n, int type);
long long randomLen(int len);
vector<long long> randomVector(vector<Subtask> subtasks, int iTest, int testnum);

/**
 * Tạo một số ngẫu nhiên kiểu long long.
 *
 * @return Số ngẫu nhiên được tạo ra.
 */
long long random()
{
    long long ans = 1;
    int length = rand() % 17 + 1;
    for (int i = 0; i < length; i++)
    {
        ans = ans * 10 + rand() % 10;
    }
    return ans;
}

/**
 * Tạo một số ngẫu nhiên kiểu long long trong khoảng [l, r].
 *
 * @param l Giới hạn dưới (bao gồm) của số ngẫu nhiên.
 * @param r Giới hạn trên (bao gồm) của số ngẫu nhiên.
 * @return Số ngẫu nhiên được tạo ra.
 */
long long random(long long l, long long r)
{
    return l + random() % (r - l + 1);
}

/**
 * Tạo một vector gồm các số ngẫu nhiên kiểu long long trong khoảng [l, r].
 *
 * @param n Kích thước của vector.
 * @param l Giới hạn dưới (bao gồm) của các số ngẫu nhiên.
 * @param r Giới hạn trên (bao gồm) của các số ngẫu nhiên.
 * @return Vector chứa các số ngẫu nhiên được tạo ra.
 */
vector<long long> randomVector(int n, long long l, long long r)
{
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = random(l, r);
    }
    return a;
}

/**
 * Tạo một chuỗi ngẫu nhiên có độ dài n sử dụng bộ ký tự cho trước.
 *
 * @param n Độ dài của chuỗi ngẫu nhiên.
 * @param charset Bộ ký tự được sử dụng để tạo chuỗi ngẫu nhiên.
 * @return Chuỗi ngẫu nhiên được tạo ra.
 */
string randomString(int n, string charset)
{
    string s = "";
    for (int i = 0; i < n; i++)
    {
        s += charset[rand() % charset.size()];
    }
    return s;
}

/**
 * Tạo một chuỗi ngẫu nhiên có độ dài n sử dụng bộ ký tự mặc định.
 *
 * @param n Độ dài của chuỗi ngẫu nhiên.
 * @return Chuỗi ngẫu nhiên được tạo ra.
 */
string randomString(int n)
{
    return randomString(n, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
}

/**
 * Tạo một chuỗi ngẫu nhiên có độ dài n dựa trên kiểu ký tự cho trước.
 *
 * @param n Độ dài của chuỗi ngẫu nhiên.
 * @param type Loại ký tự sử dụng để tạo chuỗi ngẫu nhiên.
 * @return Chuỗi ngẫu nhiên được tạo ra.
 */
string randomString(int n, int type)
{
    string charset = "";
    switch (type) {
        case 0:
            charset = "abcdefghijklmnopqrstuvwxyz";
            break;
        case 1:
            charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
            break;
        case 2:
            charset = "0123456789";
            break;
        case 3:
            charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            break;
        case 4:
            charset = "abcdefghijklmnopqrstuvwxyz0123456789";
            break;
        case 5:
            charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
            break;
        case 6:
            charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
            break;
        default:
            charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
            break;
    }
    return randomString(n, charset);
}

/**
 * Tạo một số ngẫu nhiên có độ dài cố định.
 *
 * @param len Độ dài của số ngẫu nhiên.
 * @return Số ngẫu nhiên được tạo ra.
 */
long long randomLen(int len) {
    long long ans = 0;
    for (int i = 0; i < len; i++) {
        ans = ans * 10 + rand() % 10;
    }
    return ans;
}

/**
 * Tạo một vector các số ngẫu nhiên dựa trên các yêu cầu của từng subtask.
 *
 * @param subtasks Danh sách các subtask.
 * @param iTest Chỉ số bài kiểm tra hiện tại.
 * @param testnum Tổng số bài kiểm tra.
 * @return Vector các số ngẫu nhiên được tạo ra.
 */
vector<long long> randomVector(vector<Subtask> subtasks, int iTest, int testnum) {
    int sumPercent = 0;
    for (int i = 0; i < subtasks.size(); i++) {
        sumPercent += subtasks[i].percent;
    }

    for (int i = 0; i < subtasks.size(); i++) {
        subtasks[i].percent = subtasks[i].percent * 100 / sumPercent;
    }

    for (int i = 1; i < subtasks.size(); i++) {
        subtasks[i].percent += subtasks[i - 1].percent;
    }

    Subtask st = subtasks[0];
    for (int i = 0; i < subtasks.size(); i++) {
        if (iTest <= testnum * subtasks[i].percent / 100.0) {
            st = subtasks[i];
            break;
        }
    }
    vector<long long> a;
    int n = randomLen(st.lenN);
    for (int i = 0; i < n; i++) {
        a.push_back(randomLen(st.lenAi));
    }
    return a;
}
