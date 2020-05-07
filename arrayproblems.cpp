#include<iostream>
using namespace std;
int main(){
  int a[15] = {1,2,3,4,5,6,8,9,10,11,12};
  int b[15] = {6,7,8,9,10,11,13,15,16};
  //-----------------sorted----------------
  //single missing element
  int sum = 0;
  int s = (12*(12+1))/2;
  for(int i=0;i<11;i++) sum=sum+a[i];
  cout<<"Missing number:"<<s-sum<<"\n";
  // for 2nd Array
  int l = b[0];
  int h = b[10];
  int diff = l-0;
  for(int i=0;i<10;i++){
      if(b[i]-i!=diff){
        cout<<"Missing Element:"<<i+diff<<"\n";
        break;
      }
  }
  //multiple missing Elements
  int c[11] = {6,7,8,9,11,12,15,16,17,18,19};
  int l1 = c[0];
  int h1 = c[10];
  int diff1 = l1-0;
  cout<<"Missing Elements are:\n";
  for(int i = 0;i<11;i++){
    if(c[i]-i!=diff1){
      while(diff1<c[i]-i){
        cout<<i+diff1<<" ";
        diff1++;
      }
    }
  }
      cout<<"\n";
    //-----------------unsorted using hash table----------------
  int d[11] = {3,7,4,9,12,6,1,11,2,10};
  int hash[12] = {0};
  for(int i=0;i<11;i++){
    hash[d[i]]++;
  }
  cout<<"Missing Elements are:";
  for(int i = 0;i<12;i++)
    if(hash[i]==0)
      cout<<i<<" ";
  cout<<"\n";
  //---------------Duplicates in sorted Array-----------------
  int e[10] = {3,6,8,8,10,12,15,15,15,20};
  int ld = 0;
  cout<<"Duplicates are:";
  for(int i=0;i<9;i++){
    if(e[i] == e[i+1] && e[i] != ld)
      cout<<e[i]<<" ";
      ld=e[i];
  }
  cout<<"\n";
  //-------------counting the no. of Duplicates in sorted Array-------------
  int f[10] = {3,6,8,8,10,12,15,15,15,20};
  for(int i=0;i<9;i++){
    int j=i+1;
    while(f[j]==f[i]){
      j++;
    }
    cout<<f[i]<<" is appearing "<<j-i<<" times";
    cout<<"\n";
    i=j-1;
  }
  //-------------------finding Duplicates in sorted array--------------
  int g[10] = {3,6,8,8,10,12,15,15,15,20};
  int hash2[20] = {0};
  for(int i=0;i<10;i++)
    hash2[g[i]]++;
  cout<<"Duplicates are:";
  for(int i=0;i<20;i++)
    if(hash2[i]>1)
      cout<<i<<" ";

  cout<<"\n";
  //---------------finding duplicates in unsorted array----------------
  int ia[10] = {8,3,6,4,6,5,6,8,2,7};
  cout<<"Duplicates & no. of counts:"<<"\n";
  for(int i=0;i<9;i++){
    int count = 1;
    if(ia[i]!=-1){
      for(int j=i+1;j<10;j++){
        if(ia[i]==ia[j]){
          count++;
          ia[j]=-1;
        }
      }
      if(count>1)
        cout<<ia[i]<<" "<<count<<"\n";
    }
  }
  cout<<"\n";
//-----------------finding duplictes in unsorted array using hsah table------------
int k[10] = {8,3,6,4,6,5,6,8,2,7};
int hash3[8] = {0};
for(int i=0;i<11;i++)
  hash3[k[i]]++;
cout<<"Duplicates & no of counts:\n";
for(int i=0;i<9;i++)
  if(hash3[i]>1)
    cout<<i<<" "<<hash3[i]<<"\n";
//--------------------finding the pair with sum k in unsorted array--------------
int arr1[10] = {6,3,8,10,16,7,5,2,9,14};
int no = 10;
cout<<"Pairs of sum 10 are:\n";
for(int i=0;i<9;i++){
  for(int j=i+1;j<10;j++){
    if(arr1[i]+arr1[j]==no)
      cout<<arr1[i]<<"+"<<arr1[j]<<"="<<no;
      cout<<"\n";
  }
}
//--------------------finding the pair with sum k in unsorted array using hash table--------------
int arr2[10] = {6,3,8,10,16,7,5,2,9,14};
int hash4[16] = {0};
for(int i=0;i<10;i++){
  if(hash4[10-arr2[i]]!=0)
    cout<<arr2[i]<<"+"<<10-arr2[i]<<"="<<10<<"\n";
  hash4[arr2[i]]++;
}
//----------------finding a pair with sum k in sorted array-------------
int arr[10] = {1,3,4,5,6,8,9,10,12,14};
int x = 0;
int y = 9;
while(x<y){
  if(arr[x]+arr[y]==10){
    cout<<arr[x]<<"+"<<arr[y]<<"="<<10<<"\n";
    x++; y--;
  }
  else if(arr[x]+arr[y]<10)
    x++;
  else
    y--;
}
// ----------------------finding min and max in a single search--------------
  int list[10] = {5,8,3,9,6,2,10,7,-1,4};
  int min = list[0];
  int max = list[0];
  for(int i=0;i<10;i++){
    if(list[i]<min)
      min = list[i];
    else if(list[i]>max)
      max = list[i];
  }
  cout<<"min:"<<min<<" "<<"max:"<<max<<"\n";
  return 0;
}
