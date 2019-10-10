#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<map>
#include<utility>
using namespace std;
typedef long long int LLI;
//void initialize( vector<int> &Arr, int N)
//{
//    for(int i=0; i<N; i++)
//    	Arr[ i ] = i ;
//}
// Naive implementation 
/*
bool find(vector<int> &Arr, int A, int B)
{
	if(Arr[A] == Arr[B])
		return true;
	else
		return false;
}
void union(vector<int> &Arr, int N, int A, int B)
{
	int temp = Arr[A];
	for(int i=0;i<N;i++)
	{
		if(Arr[i] == temp)
			Arr[i] = Arr[B];
	}
} */

// Un- Weighted union find
/* 
int root(vector<int> &Arr, int i)
{
	while(Arr[i] != i)
		i = Arr[i];
	return i;
}
void union(vector<int> &Arr, int A, int B)
{
	int root_a = root(Arr, A);
	int root_b = root(Arr, B);
	Arr[root_b] = root_a; 
}
bool find(vector<int> &Arr, int A, int B)
{
	int root_a = root(Arr, A);
	int root_b = root(Arr, B);
	if(root_a == root_b)
		return true;
	else
		return false;
}*/

// Weighted Union find

void initialize(vector<int> &Arr, vector<int> &size, int N)
{
	for(int i=0; i<N; i++)
	{
		Arr[i] = i;
		size[i] = 1;
	}
}
// modified root funtion using path compression to prevent memory error
int root(vector<int> &Arr, int i)
{
	while(Arr[i] != i)
	{
		Arr[i] = Arr[Arr[i]]; // comment for using without path compression
		i = Arr[i];
	}
	return i;
}

bool find(vector<int> &Arr, int A, int B)
{
	int root_a = root(Arr, A);
	int root_b = root(Arr, B);
	if(root_a == root_b)
		return true;
	else
		return false;
}
void wieghted_union(vector<int> &Arr, vector<int> &size, int A, int B)
{
	int root_a = root(Arr, A);
	int root_b = root(Arr, B);
	if(size[root_a] >= size[root_b])
	{
		Arr[root_b] = root_a;
		size[root_b] = size[root_b] + size[root_a];
	}
	else
	{
		Arr[root_a] = root_b;
		size[root_a] = size[root_b] + size[root_a];
	}
}
vector<int> par;
vector<int> sz;
int find_p(int u)
{
	if(par[u]==u) return u;
	return par[u]=find_p(par[u]);
}
void uni(int a, int b)
{
	int x=find_p(a), y=find_p(b);
	if(x==y) return;
	if(sz[x]<sz[y]) swap(x, y);
	par[y]=x;
	sz[x]+=sz[y];
}
int main()
{
	int n;
	cin >> n;
	par.resize(n);
	sz.assign(n, 1);
	for(int i=0; i<n; i++) par[i]=i;
}
