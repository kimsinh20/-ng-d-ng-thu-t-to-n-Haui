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
			if(a[j]<a[j-1]) {
				float tmp = a[j];
				a[j]= a[j-1];
				a[j-1] = tmp;
			}
		}
	}
}
float c = 9;
float m = 0;
float* sophantulayra(int &count) {
	float d = c;
	int i = 0;
	float* ds = new float[n];
	while(c>=a[i]&&i<n) {
		ds[count++] = a[i];
		m+=a[i];
		c-=a[i];
		i++;
	}
	 if(d==m) {
	 	return ds; 
	 } else {
	 	count=0;
	 	float* ds = new float[n];
	 	return ds;
	 }	
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
	while(i<=t.size()) {
		int j = i-1,x = v-1;
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
			}else {
				i+=v-k-1;
			}
		}
	}
	return count;
}
void thuattoanz(string s,int *z) {
	int n =s.size(),l = 0 ,r= 0;
	for(int i=1;i<n;i++) {
		if(i>r) {
			l = r = i;
			while(r<n && s[r-l] == s[r]) {
				r++;
			}
			z[i] = r-l;
			r--;
		} else if(z[i-l] < r-i+1) {
			z[i] = z[i-l];
		} else {
				l  = i;
			while(r<n && s[r-l] == s[r]) {
				r++;
			}
			z[i] = r-l;
			r--;
		}
	}
}
void hienthikq(string s,string subs) {
	int n = s.size();
	int m = subs.size();
	string newstring = subs+"$"+s;
	int z[n+m];
	thuattoanz(newstring,z);
	  int count = 0;
	for(int i=0;i<=n+m;++i) {
		if(z[i]==m) {
			count++;
		}
	}
	cout<<"\nso phan tu q co trong p : "<<count<<endl;
}
int main()
{
    khoitaodanhsach();
    sapxeptangdan();
    xuat();
    int count = 0;
    float* dstm = sophantulayra(count);
    if(count>0) {
    	  	cout<<"gia tri m : "<<m<<endl;
    	    cout<<"so phan tu tm : "<<count<<endl;
    		for(int i = 0;i<count;i++) {
				cout<<dstm[i]<<"\t";
			}
			cout<<endl;
	} else {
		cout<<"khong co gia tri nao tm "<<endl;
	}
    string p = "32 1ss da asdas dss2";
    string q = "1ss";
    if(boyer_mooore_hospool(p,q)>0) {
    	cout<<"q la chuoi con cua q";
	} else {
			cout<<"q ko phai la chuoi con cua q";
	}
	hienthikq(p,q);
    return 0;
}

