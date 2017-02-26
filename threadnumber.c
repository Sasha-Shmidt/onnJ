#define N 100
#define M 10

#include<stdio.h>

void comment_out(FILE *fp, int x, int y);

int main(void)
{
	FILE *fp;
	fp = fopen("thread.txt","w");//�t�@�C�����J��
	
	if(fp == NULL)//�G���[����
	{
		printf("This file can't be opened.");
		return 1;
	}
	
	int thread;//�X���b�h�ԍ�
	int thread_end;//�I�_�̃X���b�h�ԍ�
	int co;//�R�����g�A�E�g�J�E���g
	
	printf("Start?\n");//�쐬�J�n�X���b�h�ԍ�
	scanf("%d", &thread);//�ԍ���ǂݍ���
	
	printf("End?\n");//�쐬�I���X���b�h�ԍ�
	scanf("%d", &thread_end);
	
	printf("Comment out Start?\n");//��������R�����g�A�E�g������X���b�h�̔ԍ�
	scanf("%d", &co);
	
	for(; thread <= thread_end; thread++)//for�Ń��[�v������
	{
		
		if(thread % N == 1)//100�Ŋ����ė]�肪1�̏ꍇ
		{
			comment_out(fp,thread, co);
			fprintf(fp, "**&color(Green){%d�X���ځ`%d�X����}; [#thread%d_%d]\n", thread, thread + N - 1, thread, thread + N - 1);//���̍s��ǉ�
		}
		
		if(thread % M == 1)//10�Ŋ����ė]�肪1�̏ꍇ
		{
			comment_out(fp,thread, co);
			fprintf(fp, "#accordion_start(%d�ǖځ`%d�ǖ�,***,close)\n", thread, thread + M - 1);
			comment_out(fp,thread, co);
			fprintf(fp, "|CENTER:20|LEFT:520|RIGHT:85|c\n");
			comment_out(fp,thread, co);
			fprintf(fp, "|~No.|CENTER:~�X���b�h|CENTER:~�ŏI���e��|\n");
		}
		
		comment_out(fp,thread, co);	
		fprintf(fp,"|%d||XX/XX|\n", thread);
		
		if(thread % M == 0)//10�Ŋ���؂��Ƃ�
		{
			comment_out(fp,thread, co);
			fprintf(fp, "#accordion_end\n");
			comment_out(fp,thread, co);
			fprintf(fp, "\n");
		}
	}
		
	
	fclose(fp);//�t�@�C�������
	
	printf("Done.\n");
	
	return 0;
}
		
void comment_out(FILE *fp, int x, int y)
{
	if(x >= y)//������X��������̏ꍇ
	{
		fprintf(fp, "//");//�s�̐擪�ɃR�����g�A�E�g��}������
	}
}