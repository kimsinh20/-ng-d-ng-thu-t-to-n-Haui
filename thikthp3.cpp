#include <bits/stdc++.h>
#define max 10
#define min 5
using namespace std;


float *a;
int n;
void khoitaodanhsach() {
	srand(time(0));
	 n = min+rand()%(max-min+1);
	a = new float[n];
	for(int i = 0;i<n;i++) {
		a[i] = rand()%10+1;
		cout<<a[i]<<"\t";
	}
	cout<<endl;
}

void xuat() {
	for(int i = 0;i<n;i++) {
		cout<<a[i]<<"\t";
	}
	cout<<endl;
}
void sapxeptangdan() {
	for(int i=0;i<n;i++) {
		for(int j=n-1;j>i;j--) {
			if(a[j]>a[j-1]) {
				float tmp = a[j];
				a[j]= a[j-1];
				a[j-1] = tmp;
			}
		}
	}
}
int c = 20;
float m = 0;
float* sophantulayra(int &count) {
	int i = 0;
	float* ds = new float[n];
	while(m<c&&i<n) {
		ds[count++] = a[i];
		m+=a[i];
		i++;
	}
	return ds;	
}

int char_in_string(char c,string s) {
	for(int i=0;i<s.size();i++) {
		if(s[i]==c) {
			return i;
		}
	}
	return -1;
}
int boyer_mooore_hospool(string t,string p) {
	int count = 0,i = p.size(),v = p.size();
	while(i<t.size()) {
		int j = i-1,x = v-1;
		while(t[j]==p[x] && x>-1) {
			j--;
			x--;
		}
		if(x<0) {
//			cout<<"vt : "<<j+1<<endl;
			count++;
			i+=v;
			return j+2;
		} else {
			int k = char_in_string(t[j],p);
			if(k<0) {
				i+=v;
			}else {
				i+=v-k-1;
			}
		}
	}
	return -1;
}

int main()
{
    khoitaodanhsach();
    sapxeptangdan();
    xuat();
    int count = 0;
    float* dstm = sophantulayra(count);
    if(count>0 && c<m) {
    	  	cout<<"gia tri m : "<<m<<endl;
    	    cout<<"so phan tu tm : "<<count<<endl;
    		for(int i = 0;i<count;i++) {
				cout<<dstm[i]<<"\t";
			}
			cout<<endl;
	} else {
		cout<<"khong co gia tri nao tm "<<endl;
	}
	
	 string p = "32 1ss da2 asdas dss2";
    string q = "asd";
    cout<<"p :"<<p<<endl;
    cout<<"q :"<<q<<endl;
    int vtxh = boyer_mooore_hospool(p,q);
    if(vtxh>0) {
    	cout<<"q la chuoi con cua q : "<<vtxh<<endl;
	} else {
			cout<<"q ko phai la chuoi con cua q";
	}
    return 0;
}

