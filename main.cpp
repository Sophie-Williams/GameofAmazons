#include <bits/stdc++.h>
using namespace std;


#define FOR(i,n) for(int i=0;i<n;i++)
#define MOD 1000000009 
#define MAX(a,b) ( (a) > (b) ? (a) : (b))
#define MIN(a,b) ( (a) < (b) ? (a) : (b))



struct pos {
    int x;int y;
    pos(){};
    pos( int i, int r ) : x(i), y(r) {}
    bool operator=( const myclass & d ) const {
       return ((x==d.x)&&(y==d.y));
    }
};

int DP[10][10];
pos queen[2][4];


// int bfs()

// int territory(){

// 	FOR(i,10){
// 		FOR(j,10){
// 			if(DP[i][j] !=0){
// 				continue;
// 			}

// 		}
// 	}
// }


int mobility(){
	int count=0;
	int sign=1;
	FOR(i,10){
		FOR(j,10){
			if(DP[i][j] == 1 ||  DP[i][j]==2){
				if(DP[i][j] == 2){
					sign = -1;
				}
				else{
					sign=1;
				}
				std::vector<int> a;
				a.push_back(i);
				if(i<9){
					a.push_back(i+1);
				}
				if(i>0){
					a.push_back(i-1);
				}
				std::vector<int> b;
				b.push_back(j);
				if(j<9){
					b.push_back(j+1);
				}
				if(j>0){
					b.push_back(j-1);
				}
				FOR(k,a.size()){
					FOR(l,b.size()){
						if(DP[a[k]][b[l]] == 0){
							count = count+sign;
						}
					}
				}
			}
		}
	}
}

int evaluator(){
	int ans = 0;
	ans = ans+mobility();

}

int main(){
	int player;
	int qcount1=0;
	int qcount2=0;
	FOR(i,10){
		FOR(j,10){
			scanf("%d",&DP[i][j]);
			if(DP[i][j]==1){
				queen[0][qcount1].x=i;
				queen[0][qcount1].y=j;
				qcount1++;
			}
			if(DP[i][j]==2){
				queen[1][qcount2].x=i;
				queen[1][qcount2].y=j;
				qcount2++;
			}
		}
	}
	scanf("%d",&player);

	return 0;
}