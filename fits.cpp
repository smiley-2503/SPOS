#include <bits/stdc++.h>
using namespace std;

struct block
{
    int id;
    int size;
};

void first(vector<block>& v,int m,int process[],int n)
{
   vector<int> alloc(n,-1);
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<m;j++)
      {
        if(v[j].size>=process[i])
        {
           alloc[i]=j;
           v[j].size-=process[i];
           break;
        }
      }
   }
   cout<<"FIRST"<<endl;
   cout<<"Process\tBlock\n";
   for(int i=0;i<n;i++)
   {
     cout<<i+1<<"\t";
     if(alloc[i]!=-1)
     {
        cout<<alloc[i]+1<<endl;
     }
     else{
        cout<<"not allocated"<<endl;
     }
   }
}

void next(vector<block>& v,int m,int process[],int n)
{
    vector<int> alloc(n,-1);
    int last=0;
    for(int i=0;i<n;i++)
    {
       for(int j=last;j<n;j++)
       {
          if(process[i]<=v[j].size)
          {
               alloc[i]=j;
               v[j].size-=process[i];
                last=i;
                break;
          }
       }
        for(int j=0;j<last;j++)
           {
              if(process[i]<=v[j].size)
              {
                   alloc[i]=j;
                   v[j].size-=process[i];
                    last=i;
                    break;
              }
           }
    }
    cout<<"NEXT"<<endl;
       cout<<"Process\tBlock\n";
       for(int i=0;i<n;i++)
       {
         cout<<i+1<<"\t";
         if(alloc[i]!=-1)
         {
            cout<<alloc[i]+1<<endl;
         }
         else{
            cout<<"not allocated"<<endl;
         }
       }
}

void best(vector<block>& v,int m,int process[],int n)
{
   vector<int> alloc(n,-1);
   for(int i=0;i<n;i++)
   {
    int bi=-1;
    for(int j=0;j<m;j++)
    {
       if(v[j].size>=process[i] && (v[j].size<v[bi].size || bi==-1))
       {
         bi=j;
       }
    }
    if(bi!=-1)
    {
        alloc[i]=bi;
        v[bi].size-=process[i];
    }
   }
       cout<<"Process\tBlock\n";
       for(int i=0;i<n;i++)
       {
         cout<<i+1<<"\t";
         if(alloc[i]!=-1)
         {
            cout<<alloc[i]+1<<endl;
         }
         else{
            cout<<"not allocated"<<endl;
         }
       }
}

void worst(vector<block>& v,int m, int process[], int n) {
       vector<int> alloc(n,-1);
       for(int i=0;i<n;i++)
       {
        int bi=-1;
        for(int j=0;j<m;j++)
        {
           if(v[j].size>=process[i] && (v[j].size>v[bi].size || bi==-1))
           {
             bi=j;
           }
        }
        if(bi!=-1)
        {
            alloc[i]=bi;
            v[bi].size-=process[i];
        }
       }
           cout<<"Process\tBlock\n";
           for(int i=0;i<n;i++)
           {
             cout<<i+1<<"\t";
             if(alloc[i]!=-1)
             {
                cout<<alloc[i]+1<<endl;
             }
             else{
                cout<<"not allocated"<<endl;
             }
           }
}

int main()
{
    vector<block> v=
    {
        {1, 100},
        {2, 500},
        {3, 200},
        {4, 300},
        {5, 600}
    };
    int m=v.size();
    int process[]={212, 417, 112, 426};
    int n=sizeof(process)/sizeof(process[0]);
    worst(v,m,process,n);

}