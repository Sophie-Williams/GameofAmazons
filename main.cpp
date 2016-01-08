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
    bool operator==( const pos & d ) const {
       return ((x==d.x)&&(y==d.y));
    }
};

int DP[10][10];
pos queen[2][4];


int bfs(pos f, int startplay){
	int visited[10][10];
	memset(visited,0,100*sizeof(int));
	list< pair<pos, int> > q;
	q.push_back(make_pair(queen[startplay][0] , 0));
	q.push_back(make_pair(queen[startplay][1] , 0));
	q.push_back(make_pair(queen[startplay][2] , 0));
	q.push_back(make_pair(queen[startplay][3] , 0));
	while(!q.empty()){
		pair< pos,int > a = q.front();
		q.pop_front();
		if(a.first==f){
			return a.second;
			// break;
		}
		FOR(j,10){
			if(j==a.first.x || j==a.first.y){
				continue;
			}

			if(DP[a.first.x][j]==0 && (visited[a.first.x][j]==0)){
				q.push_back(make_pair(pos(a.first.x,j) , a.second+1));
				visited[a.first.x][j]==0;
			}
			if(DP[j][a.first.y]==0 && (visited[j][a.first.y]==0)){
				q.push_back(make_pair(pos(j,a.first.y) , a.second+1));
				visited[j][a.first.y]==0;
			}

			if((a.first.x+j)<10 && (a.first.y+j)<10 && DP[a.first.x+j][a.first.y+j]==0 && (visited[a.first.x+j][a.first.y+j]==0)){
				q.push_back(make_pair(pos(a.first.x+j,a.first.y+j) , a.second+1));
				visited[a.first.x+j][a.first.y+j]==0;
			}
			if((a.first.x-j)>=0 && (a.first.y-j)>=0 && DP[a.first.x-j][a.first.y-j]==0 && (visited[a.first.x-j][a.first.y-j]==0)){
				q.push_back(make_pair(pos(a.first.x-j,a.first.y-j) , a.second+1));
				visited[a.first.x-j][a.first.y-j]==0;
			}
		}
	}
	return INT_MAX;

	// visited[f.x][f.y]=1;
}

int territory(){

	FOR(i,10){
		FOR(j,10){
			if(DP[i][j] !=0){
				continue;
			}

		}
	}
}


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