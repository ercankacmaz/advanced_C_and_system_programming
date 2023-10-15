#define _CRT_SECURE_NO_WARNINGS



#include <stdio.h>
#include <stdlib.h>


typedef struct tagMATRIX
{
	size_t row;
	size_t col;
	int* matrix;
}MATRIX, *HMATRIX;


HMATRIX CreatMatrix(size_t row, size_t col);
void CloseMatrix(HMATRIX hMatrix);
void SetMatrix(HMATRIX hMatrix, size_t row, size_t col, int val);
int GetElement(HMATRIX hMatrix, size_t row, size_t col);



int main()
{
	HMATRIX hMatrix;

	if ((hMatrix = CreatMatrix(3, 3)) == NULL)
	{
		fprintf(stderr, "matrix cannot created..!\n");
		exit(EXIT_FAILURE);
	}

	int i = 0;
	for (size_t row = 0; row < 3; ++row)
	{
		for (size_t col = 0; col < 3; ++col)
		{
			SetMatrix(hMatrix, row, col, i++);
		}
	}

	for (size_t row = 0; row < 3; ++row)
	{
		for (size_t col = 0; col < 3; ++col)
		{
			printf("%d ", GetElement(hMatrix, row, col));
		}

		printf("\n");
	}

	printf("succes\n");

	CloseMatrix(hMatrix);
}




HMATRIX CreatMatrix(size_t row, size_t col)
{
	HMATRIX hMatrix;

	if ((hMatrix = (HMATRIX)malloc(sizeof(MATRIX))) == NULL)
		return NULL;

	hMatrix->row = row;
	hMatrix->col = col;
	if ((hMatrix->matrix = (int*)malloc(sizeof(int) * row * col)) == NULL)
	{
		free(hMatrix);
		return NULL;
	}

	


	return hMatrix;
}


void CloseMatrix(HMATRIX hMatrix)
{
	free(hMatrix->matrix);
	free(hMatrix);
}

void SetMatrix(HMATRIX hMatrix, size_t row, size_t col, int val)
{
	size_t index;

	index = row * hMatrix->col + col;
	hMatrix->matrix[index] = val;
}

int GetElement(HMATRIX hMatrix, size_t row, size_t col)
{
	size_t index;

	index = row * hMatrix->col + col;
	return hMatrix->matrix[index];
}