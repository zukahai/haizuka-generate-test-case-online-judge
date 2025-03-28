#include<bits/stdc++.h>
using namespace std;

bool isSsdx(int n)
{
    int d = n % 10;
    while (n > 0)
    {
        if (n % 10 != d)
        {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    #endif
    
    int n;
    cin >> n;
    vector <int> ssdx = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int index = 0;
    while(ssdx[index] <= n)
    {
        ssdx.push_back(ssdx[index] * 10 + ssdx[index] % 10);
        index++;
    }
    vector <int> count(n + 1, 0);

    for (int i = 0; i < ssdx.size(); i++)
    {
        for (int j = ssdx[i]; j <= n; j += ssdx[i])
        {
            count[j]++;
        }
    }

    int max = 0, res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (count[i] >= max)
        {
            max = count[i];
            res = i;
        }
    }
    cout << res << endl;

    vector <int> a;
    for (int i = 1; i * i <= res; i++)
    {
        if (res % i == 0)
        {
            a.push_back(i);
            if (i != res / i)
            {
                a.push_back(res / i);
            }
        }
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < a.size(); i++)
    {
        if (isSsdx(a[i]))
        {
            cout << a[i] << " ";
        }
    }
}
