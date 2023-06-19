#include<bits/stdc++.h>
using namespace std;

 float a[] = {1, 4, 6, 3, -2, 8, 9, 5};
 int n = sizeof(a) / sizeof(int);
 
float tinhtong(float a[],int l,int r) {
	if(l==r) {
		return a[l];
	}
	int mid = (l+r)/2;
	float tongleft = tinhtong(a,l,mid);
	float tongright = tinhtong(a,mid+1,r);
	return tongleft+tongright;
} 
float tongle(int k) {
	float tl =  a[k];
	if(k == n-1) {
		 	return tl;
	} 
	if((int)tl%2==0) {
	  return tongle(k+1);
	}
	return tl+tongle(k+1);
}
float tinhtongsoduong(float a[],int l,int r) {
	if(l==r) {
		if(a[l]>0) {
			return	a[l];
		} else {
		  return 0;
		}
	}
	int mid = (l+r)/2;
	return tinhtongsoduong(a,l,mid)+tinhtongsoduong(a,mid+1,r);
	
}

int main() {


	cout<<"tong cac phan tu "<<tinhtong(a,0,n-1);
	cout<<"\ntong cac phan tu le "<<tongle(0);
	cout<<"\ntong cac phan tu duong "<<tinhtongsoduong(a,0,n-1);
	return 0;
}
