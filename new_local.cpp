#include<iostream>
#include<fstream>
using namespace std;
int **matrix;
int c;
void findMin(int &x,int &y,int lowx,int lowy,int highx,int highy)
{
    int a=x;
    int b=y;
    int mina=a,minb=b;
    int min=matrix[a][b];
    if(not(a-1<lowx) && min>matrix[a-1][b])
    {
        min=matrix[a-1][b];
        mina=a-1;
        minb=b;
    }
    if(not(a+1>=highx)&& min>matrix[a+1][b])
    {
        min=matrix[a+1][b];
        mina=a+1;
        minb=b;
    }
    if(not(b-1<lowy) && min>matrix[a][b-1])
    {
        min=matrix[a][b-1];
        mina=a;
        minb=b-1;
    }
    if(not(b+1>=highy) && min>matrix[a][b+1])
    {
        min=matrix[a][b+1];
        mina=a;
        minb=b+1;
    }
    x=mina;
    y=minb;
}
int findMinimum(int lowx,int lowy,int highx,int highy)
{
    if(lowx==highx)
      return matrix[lowx][highx];
    else if(lowy==highy)
      return matrix[lowy][highy];

    int mida=(lowx+highx)/2;
    int midb=(lowy+highy)/2;
    int lowrow=matrix[mida][midb],lowcolumn=matrix[mida][midb];
    int lowrowa=mida,lowrowb=midb,lowcolumna=mida,lowcolumnb=midb;

    for(int i=lowy;i<highy;i++)
    {
        if(lowrow>matrix[mida][i])
        {
            lowrow=matrix[mida][i];
            lowrowa=mida;
            lowrowb=i;
        }
    }
    for(int i=lowx;i<highx;i++)
    {
        if(lowcolumn>matrix[i][midb])
        {
            lowcolumn=matrix[i][midb];
            lowcolumna=i;
            lowcolumnb=midb;
        }
    }
    cout<<endl<<lowrow<<"    "<<lowcolumn<<"   "<<matrix[mida][midb];
    if(lowrow<lowcolumn)
    {
        int x=lowrowa,y=lowrowb;
        findMin(x,y,lowx,lowy,highx,highy);
        cout<<endl<<"x: "<<x<<"  y:"<<y<<"  data: "<<matrix[x][y];

        if(x<mida && y<midb)            //first Quadrant
          return findMinimum(lowx,lowy,mida,midb);
        else if(x>mida && y>midb)       //Third Quadrant
          return findMinimum(mida,midb,highx,highy);
        else if(x>mida && y<midb)       //Forth Quadrant
          return findMinimum(mida,lowy,highx,midb);
        else if(x<mida && y>midb)       //Second Quadrant
          return findMinimum(lowx,midb,mida,highy);
        return lowrow;
    }
    else
    {
      int x=lowcolumna,y=lowcolumnb;
      findMin(x,y,lowx,lowy,highx,highy);
      cout<<endl<<"x: "<<x<<"  y:"<<y<<"  data: "<<matrix[x][y];

      if(x<mida && y<midb)            //first Quadrant
        return findMinimum(lowx,lowy,mida,midb);
      else if(x>mida && y>midb)       //Third Quadrant
        return findMinimum(mida,midb,highx,highy);
      else if(x>mida && y<midb)
      {       //Forth Quadrant
        cout<<"\nHEre\n";
        return findMinimum(mida,lowy,highx,midb);
      }
      else if(x<mida && y>midb)       //Second Quadrant
        return findMinimum(lowx,midb,mida,highy);
      else
        return lowcolumn;
    }
}
int main()
{
    ifstream infile("input.txt");
    infile>>c;
    matrix=new int*[c];
    for(int i=0;i<c;i++)
      matrix[i]=new int[c];
    int a;
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<c;j++)
        {
            infile>>a;
            matrix[i][j]=a;
        }
    }
    cout<<"\nMatrix is: ---\n";
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<"  "<<matrix[i][j];
        }
        cout<<endl;
    }

    int findmin=findMinimum(0,0,c,c);
    cout<<endl<<"\nMinimum element is : "<<findmin<<endl;
    return 0;
}
