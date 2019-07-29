/**
 *
 * @Name : RamseyNumber/graph.old.c
 * @Version : 1.0
 * @Programmer : Max
 * @Date : 2019-07-15
 * @Released under : https://github.com/BaseMax/RamseyNumber/blob/master/LICENSE
 * @Repository : https://github.com/BaseMax/RamseyNumber
 *
 **/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int key;
	int value;
	int color;
} pair;

typedef struct  {
	pair item;
} val;

int factorial(int v) {
	int result=v;
	for(int i=1;i<v;i++) {
		result*=i;
	}
	return result;
}

int main(int argc, char const *argv[]) {
	const int k=5;
	const int c=2;
	//////////////////////
	int v[k];
	for(int i=0;i<k;i++) {
		v[i]=i+1;
	}
	//////////////////////
	// int e[k][k-1];
	// for(int i=0;i<k;i++) {
	// 	for(int j=i+1;j<k;j++) {
	// 		e[i][j]=-1;
	// 		// printf("%d, %d\n", i+1, j+1);
	// 	}
	// }
	//////////////////////
	int ecsize=factorial(k) / (factorial(k-2) * factorial(2));
	// e.g: (5×4×3×2)÷(3×2×2)
	//	printf("-->%d\n", factorial(k));
	//	printf("-->%d\n", factorial(k-2));
	//	printf("-->%d\n", factorial(2));
	pair *ec=malloc(sizeof(pair) * ecsize);
	int l=0;
	for(int i=0;i<k;i++) {
		for(int j=i+1;j<k;j++) {
			ec[l].key=i+1;
			ec[l].value=j+1;
			ec[l].color=-1;
			l++;
		}
	}
	// printf(":::::::::::%d\n", l);
	//////////////////////
	pair **items=malloc(sizeof(pair*)*l);
	for(int i=0;i<l;i++) {
		items[i]=malloc(sizeof(pair)*3);
	}
	//////////////////////
	int q=0;
	for(int i=0;i<k;i++) {
		for(int j=i+1;j<k;j++) {
			// printf("%d, %d\n", i+1, j+1);
			for(int l=j+1;l<k;l++) {
				// printf("----> %d, %d, %d\n", i+1, j+1, l+1);
				items[q][0].key=i+1;
				items[q][0].value=j+1;

				items[q][1].key=i+1;
				items[q][1].value=l+1;

				items[q][2].key=j+1;
				items[q][2].value=l+1;
				// for(int j=0;j<3;j++) {
				// 	...
				// }
				q++;
				// for(int p=0;p<l;p++) {
				//	...
				// }
			}
		}
	}
	for(int i=0;i<q;i++) {
		printf("============> %d, %d, %d\n", items[i][0].key, items[i][0].value, items[i][2].value);
		for(int j=0;j<3;j++) {
			printf(":::::>%d, %d\n", items[i][j].key, items[i][j].value);
		}
	}
	//////////////////////
	while(1) {
		//////////////////////
		srand(time(0));
		for(int i=0;i<ecsize;i++) {
			ec[i].color=rand() % c; // 0 or 1, -1: none
		}
		//////////////////////
		for(int i=0;i<ecsize;i++) {
			printf("===> %d [%d => %d] / Color %d\n", i, ec[i].key, ec[i].value, ec[i].color);
		}
		//////////////////////
		//////////////////////
		break;
	}
	//////////////////////
	return 0;
}
