#include<bits/stdc++.h>
using namespace std;


int main(int argc,char **argv)
{
ifstream inf(argv[1]);
string c="";
while(inf)
{
    string b;
    inf>>b;
    c=c+b;
}
int n=c.size();
int V=c[0]-48;   //c[0] stores no of vertices from the input file
char start=c[3];   //names of the vertices i.e second line
int index=3+(2*V)-1;  //to reach the third line in the input file
int graph[V][V];
for(int i=0;i<V;i++)
{
for(int j=0;j<V;j++)
{
    graph[i][j]=0;
}
}
ofstream outf(argv[2]);
 for(int i=index;i<n;i=i+3)
 {
     int x=c[i]-97;
     int y=c[i+2]-97;
     graph[x][y]=1;
     graph[y][x]=1;
 }
for(int i=0;i<V;i++)
{int count=0;
    for(int j=0;j<V;j++)
    {
        if(graph[i][j]==1){
            count++;
        }
    }
    char x=start+i;
    outf<<x<<" "<<count<<endl;
}
}