#include<stdio.h>
#include<stdlib.h>
int main(){

	int i, j, vert, ed, count = 0, tmp;
	int mincost = 0;

	scanf("%d", &vert);
	scanf("%d", &ed);

	//동적할당
	int *check = (int*)malloc(vert*sizeof(int));
	int *edge = (int*)malloc(ed*3*sizeof(int));

	//check[i]를 초기값 0으로  
	for (i = 0; i < vert; i++)
		check[i] = 0;

	for (i = 0; i < ed; i++)
	{
		scanf("%d", &edge[i * 3]);
		scanf("%d", &edge[i * 3 + 1]);
		scanf("%d", &edge[i * 3 + 2]);

		edge[i * 3]--;
		edge[i * 3 + 1]--;
	}

	for (i = 0; i < ed; i++){
		for (j = i + 1; j < ed; j++){
			if (edge[i * 3 + 2] > edge[j * 3 + 2]){
				
				//간선[j*3]과 간선[i*3]을 교환
				tmp = edge[j*3];
				edge[j*3] = edge[i*3];
				edge[i*3] = tmp;

				//간선[j*3+1]과 간선[j*3+1]을 교환
				tmp = edge[j * 3 + 1];
				edge[j * 3 + 1] = edge[i * 3 + 1];
				edge[i * 3 + 1] = tmp;

				//간선[j*3+2]와 간선[i*3+2]를 교환
				tmp = edge[j * 3 + 2];
				edge[j * 3 + 2] = edge[i * 3 + 2];
				edge[i * 3 + 2] = tmp;

			}
		}
	}

	for (i = 0; i < ed; i++){
		//간선의 check정보에 따라 
		if (check[edge[i * 3]] == 0 && check[edge[i * 3 + 1]] == 0){
			count++;
			
			check[edge[i * 3]] = count;
			check[edge[i * 3 + 1]] = count;

			printf(" %d", edge[i * 3 + 2]);//간선 무게
			mincost += edge[i * 3 + 2];//총무게 변수에 간선 무게 더한다
		}

		else if (check[edge[i * 3]] == 0 && check[edge[i * 3 + 1]] != 0){
			check[edge[i * 3]] = check[edge[i * 3 + 1]];
			printf(" %d", edge[i * 3 + 2]);//간선 무게
			mincost += edge[i * 3 + 2];//총무게 변수에 간선 무게 더한다
		}
		else if (check[edge[i * 3]] != 0 && check[edge[i * 3 + 1]] == 0){
			check[edge[i * 3 + 1]] = check[edge[i * 3]];
			printf(" %d", edge[i * 3 + 2]);//간선 무게
			mincost += edge[i * 3 + 2];//총무게 변수에 간선 무게 더한다
		}

		else if (check[edge[i * 3]] != 0 && check[edge[i * 3 + 1]] != 0 && check[edge[i * 3]] != check[edge[i * 3 + 1]]){
			tmp = check[edge[i * 3 + 1]];

			for (j = 0; j < vert; j++)
			{
				if (check[j] == tmp)//같으면
				{
					check[j] = check[edge[i * 3]];//j번째 check값 갱신
				}
			}
			printf(" %d", edge[i * 3 + 2]);//간선 무게
			mincost += edge[i * 3 + 2];//총무게 변수에 간선 무게 더한다
		}
	}
	printf("\n%d\n", mincost);//MST 총 무게

	return 0;
}