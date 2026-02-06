#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
// array<int,N> a,sp,bu;
int a[N], sp[N], bu[N];
int n, m;

void dis()
{
    for (int i = 0; i < n; i++)
    {
        cout << bu[i] << " ";
    }
    cout << endl;
    for (int j = 0; j < n; j++)
    {
        cout << sp[j] << " ";
    }
    cout << endl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    cin >> a[0];
    if (a[0] < 0)
        bu[0] = -1 * a[0];
    else
        sp[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < 0)
        {
            sp[i] = sp[i - 1];
            bu[i] = abs(a[i]) + bu[i - 1];
        }
        else
        {
            sp[i] = a[i] + sp[i - 1];
            bu[i] = bu[i - 1];
        }
    }
    // dis();
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x != 0)
            y += bu[x - 1];
        int idx = lower_bound(bu, bu + n, y) - bu;
        idx--;
        // cout << "idx ->  " << idx << endl;
        if (idx == -1)
        {
            cout << 0 << '\n';
        }
        else
        {
            if (x == 0)
                cout << sp[idx] << '\n';
            else
                cout << sp[idx] - sp[x - 1] << '\n';
        }
    }
    // dis();
}