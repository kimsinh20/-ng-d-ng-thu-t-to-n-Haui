#include<bits/stdc++.h>
using namespace std;
float a[] = {1,2.5,3,4,4,7,9,10};
int n = 8;
float c = 15;
float m = 0;
float* ds(int &count) {
	int i = 0;
	float *kq = new float[n];
	while(c>a[i]&&i<n) {
		kq[count++] = a[i];
		c-=a[i];
		m+=a[i];
		i++;
	}
	return kq;
}
void xuat() {
	for(int i=0;i<n;i++) {
		cout<<a[i]<<"\t";
	}
	cout<<endl;
}
int char_in_string(char c,string s) {
	for(int i=0;i<s.size();i++) {
		if(s[i]==c) {
			return i;
		}
	}
	return -1;
}
int boyer_more_hospool(string t,string p) {
	int count = 0,i = p.size(),v = p.size();
	while(i<t.size()) {
		int j = i-1;
		int x = v-1;
		while(t[j]==p[x] && x>-1) {
			j--;
			x--;
		}
		if(x<0) {
			count++;
			i+=v;
		} else {
			int k = char_in_string(t[j],p);
			if(k<0) {
				i+=v;
			} else {
				i+=v-k-1;
			}
		}
	}
	return count;
} 
int main() {
	xuat();
	int count  = 0;
	cout<<"gia tri c : "<<c<<endl;
	float* dstm = ds(count); 
	if(count>0) {
		cout<<"gia tri m : "<<m<<endl;
		cout<<"so phan tu tm : "<<count<<endl;
		for(int i=0;i<count;i++) {
			cout<<dstm[i]<<"\t";
		}
	} else {
		cout<<"\nkhong co gia tri nao tm ";
	}
	string P = "mot hai ba bon nam sau bay tam chin";
	string Q = "bon";
	cout<<"\nP : "<<P<<endl;
	cout<<"Q : "<<Q<<endl;
	if(boyer_more_hospool(P,Q)>0) {
		cout<<"Q la chuoi con con P" ;
	} else {
		cout<<"Q khong phai la chuoi con con P" ;
	}
	return 0;
}
