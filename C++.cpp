#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 312;
const int INF = 1000000000;
//x是村庄在坐标轴上的位置 
int x[MAXN];
//f用于存储中间状态 
int f[MAXN][MAXN];
//dist[i][j]第i个村庄到第j个村庄之间建立一个邮局时,i, j之间其他村庄到这个村庄的距离之和
int dist[MAXN][MAXN];
int main()
{
    int i, j, k, n, m;
    scanf("%d %d", &n, &m);//n是村庄数，m是邮局数 
    for(i = 1; i <= n; i++) scanf("%d", &x[i]);//x[i]代表第几个村庄，它的值是村庄在坐标轴上的位置 
    for(i = 1; i < n; i++)  //初始化dist数组 
        for(j = i + 1; j <= n; j++) {
            int p = x[(i + j) / 2];//将邮局建在两个村庄之间
            int sum = 0;//到邮局的距离总和为零
            for(k = i; k <= j; k++)
                sum += abs(x[k] - p);//到邮局的距离  他们差的绝对值 
            dist[i][j] = sum;//当建在i,j之间时，i,j之间所有村庄到邮局的距离总和
        }
    for(i = 0; i <= n; i++) //初始化f数组 
        for(j = 0; j <= m; j++)
            f[i][j] = INF;  //由于现在我们不知道它们的距离和所以默认是无穷大
    f[0][0] = 0;    //f[0][0]永远是零,所以现在把它赋值为零
    for(i = 1; i <= n; i++) //动态规划  n是村庄数
        for(j = 1; j <= n; j++)
            for(k = i - 1; k >= 0; k--)
                f[i][j] = min(f[i][j], f[k][j - 1] + dist[k + 1][i]);   //What does it mean
    printf("%d\n", f[n][m]);    //输出结果
    system("pause");
    return 0;
}
