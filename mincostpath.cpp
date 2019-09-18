//here we have to find out the minimum cost path. here we can go right,down,and along diagonal but not left 
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void printmat(int mat[3][3])
{
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void calculate(int mat[3][3])
{
    int temp[3][3]={{0},{0},{0}};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==0&j==0)temp[i][j]=mat[i][j];
            else if(i==0&&j!=0)temp[i][j]=temp[i][j-1]+mat[i][j];
            else if(j==0&&i!=0)temp[i][j]=temp[i-1][j]+mat[i][j];
            else temp[i][j]=min(min(temp[i-1][j],temp[i][j-1]),temp[i-1][j-1])+mat[i][j];
        }
    }
    cout<<"The temporary matrix is : "<<endl;
    printmat(temp);
    cout<<"Minimum cost is "<<temp[2][2]<<endl;

}
int main()
{
    int mat[3][3]={ {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} };
    printmat(mat);
    calculate(mat);
    return 0;
}