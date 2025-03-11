#include <windows.h>
#include <bits/stdc++.h>
using namespace std;

// Chuyển số nguyên thành chuỗi có độ dài cố định (ít nhất 4 ký tự)
string str(long long a) {
    if (a == 0) return "0000";
    if (a < 0) return "-" + str(-a);
    string ans = "";
    for (int i = 1; i <= 4; i++) {
        ans = char((a % 10) + '0') + ans;
        a /= 10;
    }
    return ans;
}

// Tạo thư mục cho từng bộ test
void create_set(const string& prob_name, int iTest) {
    system(("mkdir " + prob_name + "\\Test" + str(iTest)).c_str());
}

// Tạo thư mục gốc cho bài toán
void create_root(const string& prob_name) {
    system(("mkdir " + prob_name).c_str());
}

// Biên dịch chương trình
void compile() {
    system("g++ solution.cpp -o solution.exe");
}

// Tạo thư mục bài toán, các bộ test và biên dịch
void create_all_and_compile(const string& prob_name, int start, int TestNum) {
    create_root(prob_name);
    for (int i = start; i <= TestNum; i++) {
        create_set(prob_name, i);
    }
    compile();
}

// Sao chép nội dung từ file nguồn sang file đích
void copy_file(const string& source_file, const string& target_file) {
    ifstream input(source_file);
    ofstream output(target_file);
    string line;
    while (getline(input, line)) {
        output << line << '\n';
    }
}