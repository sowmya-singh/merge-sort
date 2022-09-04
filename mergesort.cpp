#include<iostream>
#include<vector>
using namespace std;
void merge(vector <int> &a,int s,int e)
{
    int mid=(s+e)/2;
    int i=s,j=mid+1;
    vector <int> temp;
    while(i<=mid && j<=e)
    {
        if(a[i]<a[j])
        {
           temp.push_back(a[i]);
           i++;
        }
        else
        {
           temp.push_back(a[j]);
           j++;
        }
    }

    while(i<=mid)
    {
         temp.push_back(a[i]);
           i++;
    }
    
    while(j<=e)
      {
           temp.push_back(a[j]);
           j++;
      }
      //copy back from temp to array
     int k=0;
      for(int inx=s;inx<=e;inx++)
    //  for(int k=s;k<=e;k++)
      {
          a[k]=temp[k];
      }

}
void mergesort(vector <int> &a,int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int mid=(s+e)/2;
    mergesort(a,s,mid);//sorting left part 
    mergesort(a,mid+1,e);//sorting right part 
    return merge(a,s,e);

}
int main(){
vector <int> a={1,2,7,5,3,9,33,25};
int s=0;//start
int e=a.size()-1;
mergesort(a,s,e);

for(int x:a)
cout<<x<<" ";

return 0;
}