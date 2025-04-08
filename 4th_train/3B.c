#include "stdio.h"
#include "stdlib.h"

struct queue 
{
  int arr[100*100];
  int p;
  int left;
  int right;  
};

void push(struct queue *s, int a)
{
  s->arr[s->right] = a;
  s->right++;
  s->right = s->right % s->p;
}

int pop(struct queue *s)
{
  int a = s->arr[s->left];
  s->left++;
  s->left = s->left % s->p;
  return a;
}

int empty(struct queue * s)
{
  return (s->left == s->right);
}

int main()
{
  int N, S, F;
  struct queue sq;
  sq.left = 0;
  sq.right = 0;
  sq.p = 10000;
  scanf("%d %d %d", &N, &S, &F);
  
  int *matrix = calloc(N*N, sizeof(int));
  int *visited = calloc(N, sizeof(int));
  int *path = calloc(N, sizeof(int));
  int *path_rev = calloc(N, sizeof(int));
  
  for (int i = 0; i < N; i++)
  {
    visited[i] = -1;
    path[i] = -1;
  }
    
  visited[S-1] = 0;
  push(&sq, S-1);
  
  for (int i = 0 ; i < N; i++)
    for (int j = 0; j < N; j++)
      scanf("%d", matrix + i*N + j);
  int cur; 
  while (!empty(&sq))
  {
    cur = pop(&sq);
    for (int i = 0; i < N; i++)
    {
      if(matrix[(cur)*N + i] >= 0 && i != cur)
        if ((visited[i] == -1) || (visited[cur] + matrix[cur*N + i] < visited[i]))
        {
          visited[i] = visited[cur] + matrix[cur*N + i];
          path[i] = cur;
          push(&sq, i);
        }
    }
  }
  cur = F - 1;
  int length = 0;
  if (visited[F - 1] == -1)
    printf("-1");
  else 
  {
    while (cur != -1)
    {
      path_rev[length] = cur + 1;
      cur = path[cur];
      length++;
    }

   for (int i = length - 1; i >= 0; i--)
    printf("%d ", path_rev[i]);
  }
}
