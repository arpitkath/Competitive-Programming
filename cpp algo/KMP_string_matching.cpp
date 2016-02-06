#include<iostream>
#include<cstdlib>
using namespace std;


//It computes the lenght of longest suffix which matches the prefix for various prefixes.
void prefixTable(char P[], int n, int pre[]){
	int i = 1, j = 0; pre[0] = 0;
	while(i < n){
		if(P[i] == P[j]){
			pre[i] = j+1;
			i++;
			j++;
		}
		else if(j > 0) j = pre[j-1];
		else{
			pre[i] = 0;
			i++;
		}
	}
}

int strMatchKMP(char T[], int n, char P[], int m){
	int pre[m];
	prefixTable(P,m,pre);
	int i = 0, j = 0;
	int count = 0;
	while(i < n){
		if(P[j] == T[i] ){
			if(j == m-1) count++;
			j++;
			i++;
		}
		else if(j > 0) j = pre[j-1];
		else i++;
	}
	if(count>0) return count;
	return -1;
}
int main(){
	char T[] = "helloworld";
	char P[] = "low";
	cout<<strMatchKMP(T,sizeof(T)/sizeof(T[0])-1,P,sizeof(P)/sizeof(P[0])-1);
}
