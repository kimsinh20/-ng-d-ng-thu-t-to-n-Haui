#include<bits/stdc++.h>
using namespace std;
int char_in_string(char c,string s) {
	for(int i=0;i<s.size();i++) {
		if(s[i]==c) {
			return i;
		}
	}
	return -1;
}
int boyyer_moore_hospool(string t,string p) {
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
int *a = new int[10];
int boyyer_moore_hospool_v2(string t,string p) {
	int count = 0,i = p.size(),v = p.size();
	while(i<t.size()) {
		int j = i-1;
		int x = v-1;
		while(t[j]==p[x] && x>-1) {
			j--;
			x--;
		}
		if(x<0) {
			a[count++] = j+2;
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
	string P = "mot hai ba bon nam sau bay nam tam";
	string Q = "nam";
	int count = boyyer_moore_hospool_v2(P,Q);
	if(count>0) {
	  for(int i=0;i<count;i++) {
	  	cout<<"\nvi tri xuat hien : "<<a[i]<<"\t";
	  }
	  cout<<endl;
	} else {
		cout<<"\nno";
	}
	return 0;
}
