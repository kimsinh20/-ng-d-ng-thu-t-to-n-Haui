#include <bits/stdc++.h>
#define max 10
#define min 5
using namespace std;
class goihang{
	public :
		int m;
		int v;
		void khoitao(int m,int v) {
			this->m = m;
			this->v = v;
		}
	    void xuat() {
	    	cout<<setw(20)<<m<<setw(20)<<v<<endl;
		}
};
goihang* dsgh;
int n;
void khoitaodanhsach() {
	srand(time(0));
	 n = min+rand()%(max-min+1);
	 dsgh = new goihang[n];
	 for(int i=1;i<=n;i++) {
	 	int rdm = rand()%20+1;
	 	int rdv = rand()%20+1;
	 	dsgh[i].khoitao(rdm,rdv);
	 	cout<<"goi hang thu : "<<i;
	 	dsgh[i].xuat();
	 }
}
int kq[100][50];
int m = 20 ;
int maxP(int n,int m) {
	int temp;
	for(int j=0;j<=m;j++) {
		kq[0][j] = 0;
	}
	for(int i = 1;i<=n;i++) {
		for(int j=0;j<=m;j++) {
			kq[i][j] = kq[i-1][j];
			temp = kq[i-1][j-dsgh[i].m]+dsgh[i].v;
			if(dsgh[i].m <=j && kq[i][j] < temp) {
				kq[i][j] = temp;
			}
		}
	}
	return kq[n][m];
}
void result() {
	int i = n, j = m;
	 cout<<"\ndanh sach cac goi hang thoa man : "<<endl;
	while (i != 0) {
		if (kq[i][j]!=kq[i-1][j]) {
			cout<<"goi hang thu : "<<i;
			dsgh[i].xuat();
			j -= dsgh[i].m;
		}
		i--;
	}
    cout<<"\nbang phuong an : "<<endl;
    for(int i=1;i<=n;i++) {
    	for(int j=1;j<=m;j++) {
    		cout<<"-"<<kq[i][j];
		}
		cout<<endl;
	}
}
int main()
{
    khoitaodanhsach();
    cout<<"gia tri max p : "<<maxP(n,m)<<endl;
    result();
    return 0;
}

