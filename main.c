#include<stdio.h>
#include<Windows.h>
/*����bmpͼƬ*/
typedef struct 
{
	BYTE a;
	BYTE b;
	BYTE c;
}RGB;
void loadFile(RGB**buffer) {
	BITMAPFILEHEADER fileHeader;
	BITMAPINFOHEADER infoHeader;
	RGB* info = fopen("�ǿ�.bmp", 'r');
	RGB* oufo = fopen("�ǿ�_grey", 'w');
	fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, info);//����λͼ�ļ�ͷ
	fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, info);//����λͼ��Ϣͷ
	/*������ά�ṹ���鴢��λͼ��Ϣ*/
	LONG count = infoHeader.biWidth * infoHeader.biHeight;
	buffer = (RGB*) malloc(sizeof(RGB) * count);
	/*����*/
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
			printf("�Ҷȴ���_1;\n����_0;\n�����ظ�ѡ��;\n");
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