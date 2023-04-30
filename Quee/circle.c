#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	return;
}

void init_queue(QueueType* q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
	return(q->front == q->rear);
}

int is_full(QueueType* q)
{
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다\n");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다\n");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element front(QueueType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다\n");
	return q->data[q->front];
}


void rear(QueueType* q, element item)
{
	if (is_full(q))
		error("큐가 포화상태입니다\n");
	q->data[q->rear] = item;
}

void queue_print(QueueType* q)
{
	printf("Queue(front=%d raer=%d) = ", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);

	}
	printf("\n");
}

int main(void)
{
	QueueType queue;
	int element;
	int num = 0;
	init_queue(&queue);

	while (1)
	{
		printf("==== MENU ====\n");
		printf("1. Input data and Enqueue\n");
		printf("2. Dequeue and print data\n");
		printf("3. print Queue\n");
		printf("4. Exit\n");
		printf("Select number : ");
		scanf_s("%d", &num);

		if (num == 1)
		{
			printf("Input the data : ");
			scanf_s("%d", &element);
			enqueue(&queue, element);
			printf("Enqueue : ");
			printf("%d\n", element);
		}
		if (num == 2)
		{
			if (is_empty(&queue))
			{
				error("Queue is Empty");
			}
			else
			{
				printf("Dequeue : %d\n", dequeue(&queue));
			}

		}
		if (num == 3)
		{
			if (is_empty(&queue))
			{
				error("Queue is Empty");
			}
			else
			{
				queue_print(&queue);
			}

		}
		if (num == 4)
		{
			printf("Exit the program");
			break;
		}
	}
}