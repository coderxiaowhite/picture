#include<stdio.h>
#include<Windows.h>
/*处理bmp图片*/
typedef struct 
{
	BYTE a;
	BYTE b;
	BYTE c;
}RGB;
void loadFile(RGB**buffer) {
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;
	RGB* info = fopen("星空.bmp", 'r');
	RGB* oufo = fopen("星空_grey", 'w');
	fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, info);//调用位图文件头
	fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, info);//调用位图信息头
	/*建立二维结构数组储存位图信息*/
	LONG count = infoHeader.biWidth * infoHeader.biHeight;
	buffer = (RGB*) malloc(sizeof(RGB) * count);
	/*储存*/
	if(infoHeader.biBitCount==24)
		fread(buffer, count, sizeof(RGB), info);
	
}
void main() {
	char input_1;
	int input_2;
	RGB** input;
	RGB** output;
	printf("if you want to choose a way to deal with the (*bmp)pictiure	(y/s)\n");
	scanf("%c", &input_1);
	if (input_1 == 'y') {
		int choose = 1;
		while (choose) {
			printf("灰度处理_1;\n结束_0;\n不能重复选择;\n");
			scanf("%d", &input_2);
			switch (input_2) {
			case 0:
				choose = 0;
			case 1:
				loadFile(input, output);

			}
		}



	}




}