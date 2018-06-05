#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 312;
const int INF = 1000000000;
//x�Ǵ�ׯ���������ϵ�λ�� 
int x[MAXN];
//f���ڴ洢�м�״̬ 
int f[MAXN][MAXN];
//dist[i][j]��i����ׯ����j����ׯ֮�佨��һ���ʾ�ʱ,i, j֮��������ׯ�������ׯ�ľ���֮��
int dist[MAXN][MAXN];
int main()
{
    int i, j, k, n, m;
    scanf("%d %d", &n, &m);//n�Ǵ�ׯ����m���ʾ��� 
    for(i = 1; i <= n; i++) scanf("%d", &x[i]);//x[i]����ڼ�����ׯ������ֵ�Ǵ�ׯ���������ϵ�λ�� 
    for(i = 1; i < n; i++)  //��ʼ��dist���� 
        for(j = i + 1; j <= n; j++) {
            int p = x[(i + j) / 2];//���ʾֽ���������ׯ֮��
            int sum = 0;//���ʾֵľ����ܺ�Ϊ��
            for(k = i; k <= j; k++)
                sum += abs(x[k] - p);//���ʾֵľ���  ���ǲ�ľ���ֵ 
            dist[i][j] = sum;//������i,j֮��ʱ��i,j֮�����д�ׯ���ʾֵľ����ܺ�
        }
    for(i = 0; i <= n; i++) //��ʼ��f���� 
        for(j = 0; j <= m; j++)
            f[i][j] = INF;  //�����������ǲ�֪�����ǵľ��������Ĭ���������
    f[0][0] = 0;    //f[0][0]��Զ����,�������ڰ�����ֵΪ��
    for(i = 1; i <= n; i++) //��̬�滮  n�Ǵ�ׯ��
        for(j = 1; j <= n; j++)
            for(k = i - 1; k >= 0; k--)
                f[i][j] = min(f[i][j], f[k][j - 1] + dist[k + 1][i]);   //What does it mean
    printf("%d\n", f[n][m]);    //������
    system("pause");
    return 0;
}
