/**
 *
 * @Name : RamseyNumber/graph.c
 * @Version : 1.0
 * @Programmer : Max
 * @Date : 2019-07-29
 * @Released under : https://github.com/BaseMax/RamseyNumber/blob/master/LICENSE
 * @Repository : https://github.com/BaseMax/RamseyNumber
 *
 **/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define FOR(index, start, end)\
	for(uint64_t index=start; index<end;index++)

#define SET_PAIR(item, first, end) \
	item.a=first;\
	item.b=end;

typedef enum {
	false,
	true,
} bool;

typedef struct {
	uint64_t a;
	uint64_t b;
} pair;

typedef struct {
	uint64_t a;
	uint64_t b;
	unsigned int c;
} color;

int art;
int count;
pair **items;
color *edges;
uint64_t edgesCount=0;

unsigned int randomColor() {
	return rand() % count;
}

unsigned int found(uint64_t i, uint64_t j) {
	FOR(i, 0, edgesCount) {
		// printf("==>%d\n", i);
		if(
			(edges[i].a == i && edges[i].b == j) ||
			(edges[i].a == j && edges[i].b == i)) {
			return edges[i].c;
		}
	}
	return -1;
}

int main(int argc, char const *argv[]) {
	art=43;
	count=2;	
	srand(time(0));
	items=malloc(sizeof(pair*)*962598);
	uint64_t first_limit=10000;
	uint64_t first_limit_index=0;
	edges=malloc(sizeof(color)*903);
	edgesCount=0;
	FOR(i, 0, art) {
		FOR(j, i+1, art) {
			SET_PAIR(edges[edgesCount], i+1, j+1);
			edgesCount++;
		}
	}
	uint64_t itemsCount=0;
	FOR(i, 0, art) {
		FOR(j, i+1, art) {
			FOR(l, j+1, art) {
				FOR(w, l+1, art) {
					FOR(e, w+1, art) {
						// printf("%d, %d, %d, %d, %d\n", i+1, j+1, l+1, w+1, e+1);
						items[itemsCount]=malloc(sizeof(pair)*10);

						SET_PAIR(items[itemsCount][0], i+1, j+1);
						SET_PAIR(items[itemsCount][1], i+1, l+1);
						SET_PAIR(items[itemsCount][2], i+1, w+1);
						SET_PAIR(items[itemsCount][3], i+1, e+1);

						SET_PAIR(items[itemsCount][4], j+1, l+1);
						SET_PAIR(items[itemsCount][5], j+1, w+1);
						SET_PAIR(items[itemsCount][6], j+1, e+1);

						SET_PAIR(items[itemsCount][7], l+1, w+1);
						SET_PAIR(items[itemsCount][8], l+1, e+1);

						SET_PAIR(items[itemsCount][9], w+1, e+1);
						itemsCount++;
					}
				}
			}
		}
	}
	while(1) {
		check:
		printf("%" PRIu64 "/%" PRIu64 "\n", first_limit_index+1, first_limit);
		first_limit_index+=1;
		if(first_limit_index == first_limit) {
				printf("END, Limit.....");
				exit(-1);
		}
		FOR(i, 0, edgesCount) {
			edges[i].c=randomColor();
		}
		bool sameColor=false;
		FOR(i, 0, itemsCount) {
			bool checkContinue=true;
			unsigned int color=-1;
			FOR(j, 0, 10) {
				if(color == -1) {
					color=found(items[i][j].a, items[i][j].b);
					continue;
				}
				else {
					unsigned int tcolor=found(items[i][j].a, items[i][j].b);
					// printf("==>%d\n", tcolor);
					if(tcolor != color) {
						checkContinue=false;
						break;
					}
				}
			}
			if(checkContinue == true) {
				sameColor=true;
				goto check;
				exit(1);
			}
		}
		if(sameColor == false) {
			printf("Done\n");
			// printf("Colorize edges of the graph: " + str(edges));
			exit(1);
		}
	}
	printf("%" PRIu64 "\n", itemsCount);
	return 0;
}
