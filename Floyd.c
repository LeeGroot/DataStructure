#include<stdio.h>
#define INF 65536
int main(int argc, char const *argv[])
{
    int Vnum,Edgenum;
    int v1,v2,weight;
    printf("请输入顶点数：");
    scanf("%d",&Vnum);
    printf("请输入边数：");
    scanf("%d",&Edgenum);
    int Graph[Vnum][Vnum];
    for(int i = 0;i<Vnum;i++)
    {
        for (int j = 0; j < Vnum; j++)
        {
            if(i!=j){
                Graph[i][j] = INF;
            }else{
                Graph[i][j] = 0;
            }
        }
        
    }
    printf("请输入边的信息（结点1 结点2 权重）：\n");
    for(int i = 0;i<Edgenum;i++)
    {
        scanf("%d%d%d",&v1,&v2,&weight);
        v1--;
        v2--;
        if(v1 == v2)
        {
            printf("输入有误！请重新输入");
        }else{
            Graph[v1][v2] = weight;
            Graph[v2][v1] = weight;
        }
    }
    for (int k = 0; k < Vnum; k++)
    {
        for(int i = 0 ;i<Vnum;i++)
        {
            for (int j = 0; j < Vnum; j++)
            {
                if (Graph[i][j]>Graph[i][k] + Graph[k][j])
                {
                    Graph[i][j] = Graph[i][k]+Graph[k][j];                
                }
                
            }
            
        }
    }
    
    printf("任意两点间的最短路径：\n");
    for(int i = 0;i<Vnum;i++){
        for (int j = 0; j < Vnum; j++)
        {
            if (Graph[i][j]==INF)
            {
                printf("INF   ");
            }else
            {
                printf("%3d   ",Graph[i][j]);
            }  
        }
        printf("\n");
    }

    return 0;
}
