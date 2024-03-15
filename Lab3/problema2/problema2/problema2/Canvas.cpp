#include "Canvas.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Canvas::Canvas(int width, int height) {
	this->h = height;
	this->w = width;
	this->matrix = (char**)malloc(this->h * sizeof(char*));
	for (int i = 0; i < this->h; i++)
	{
		matrix[i] = (char*)malloc(this->w * sizeof(char));
		memset(matrix[i], ' ', this->w * sizeof(char));
	}
}
void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	for (int i = 0; i < this->h; i++)
		for (int j = 0; j < this->w; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) >= ray * (ray - 1) && (i - x) * (i - x) + (j - y) * (j - y) <= ray * (ray + 1))
			{
				this->matrix[i][j] = ch;
			}
}
void Canvas::FillCircle(int x, int y, int ray, char ch) {
	for (int i = 0; i < this->h; i++)
		for (int j = 0; j < this->w; j++)
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
			{
				this->matrix[i][j] = ch;
			}
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	for (int i = top; i < bottom; i++)
		this->matrix[i][left] = this->matrix[i][right - 1] = ch;
	for (int i = left; i < right; i++)
		this->matrix[top][i] = this->matrix[bottom - 1][i] = ch;
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	for (int i = top; i < bottom; i++)
		for (int j = left; j < right; j++)
			this->matrix[i][j] = ch;
}
void Canvas::SetPoint(int x, int y, char ch) {
	this->matrix[x][y] = ch;
}
void Canvas::DrawLine(int x0, int y0, int x1, int y1, char ch) {
	int dx = x1 - x0;
	int dy = y1 - y0;
	int D = 2 * dy - dx;
	int y = y0;
	for (int x = x0; x <= x1; x++)
	{
		this->matrix[x][y] = ch;
		if (D > 0)
		{
			y++;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
	}
}
void Canvas::Print()// shows what was printed
{
	for (int i = 0; i < this->h; i++)
	{
		for (int j = 0; j < this->w; j++)
			printf("%c ", this->matrix[i][j]);
		printf("\n");
	}
}
void Canvas::Clear()// clears the canvas
{
	for (int i = 0; i < this->h; i++)
		for (int j = 0; j < this->w; j++)
			this->matrix[i][j] = ' ';
}