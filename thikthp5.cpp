#include<bits/stdc++.h>
using namespace std;
float a[] = {1,4,-2,5,8,5,6,4};
int n= 9 ;
float tinhtong(float a[],int l,int r) {
	if(l==r) {
		return a[l];
	}
	int mid  = (l+r)/2;
	return tinhtong(a,l,mid)+tinhtong(a,mid+1,r);
}
// tong le de quy
float tinhtongv2(int k) {
	int item = a[k];
	if(k==n-1) {
		return item;
	}
	if(item%2==0) {
		return tinhtongv2(k+1);
	} else {
		return item+tinhtongv2(k+1);
	}
}
float tinhtongv3(float a[],int l,int r) {
	if(l==r) {
		if(a[l]>0) {
			return a[l];
		} else {
			return 0;
		}
	}
	int mid  = (l+r)/2;
	return tinhtongv3(a,l,mid)+tinhtongv3(a,mid+1,r);
}
int main() {
	cout<<"tong cac phan tu trong mang a : "<<tinhtong(a,0,n-1);
	cout<<"\ntong cac phan tu le trong mang a : "<<tinhtongv2(0);
	cout<<"\ntong cac phan tu duong trong mang a : "<<tinhtongv3(a,0,n-1);
	return 0;
}
