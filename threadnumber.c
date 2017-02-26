#define N 100
#define M 10

#include<stdio.h>

void comment_out(FILE *fp, int x, int y);

int main(void)
{
	FILE *fp;
	fp = fopen("thread.txt","w");//ファイルを開く
	
	if(fp == NULL)//エラー処理
	{
		printf("This file can't be opened.");
		return 1;
	}
	
	int thread;//スレッド番号
	int thread_end;//終点のスレッド番号
	int co;//コメントアウトカウント
	
	printf("Start?\n");//作成開始スレッド番号
	scanf("%d", &thread);//番号を読み込む
	
	printf("End?\n");//作成終了スレッド番号
	scanf("%d", &thread_end);
	
	printf("Comment out Start?\n");//ここからコメントアウトさせるスレッドの番号
	scanf("%d", &co);
	
	for(; thread <= thread_end; thread++)//forでループさせる
	{
		
		if(thread % N == 1)//100で割って余りが1の場合
		{
			comment_out(fp,thread, co);
			fprintf(fp, "**&color(Green){%dスレ目～%dスレ目}; [#thread%d_%d]\n", thread, thread + N - 1, thread, thread + N - 1);//この行を追加
		}
		
		if(thread % M == 1)//10で割って余りが1の場合
		{
			comment_out(fp,thread, co);
			fprintf(fp, "#accordion_start(%d隻目～%d隻目,***,close)\n", thread, thread + M - 1);
			comment_out(fp,thread, co);
			fprintf(fp, "|CENTER:20|LEFT:520|RIGHT:85|c\n");
			comment_out(fp,thread, co);
			fprintf(fp, "|~No.|CENTER:~スレッド|CENTER:~最終投稿日|\n");
		}
		
		comment_out(fp,thread, co);	
		fprintf(fp,"|%d||XX/XX|\n", thread);
		
		if(thread % M == 0)//10で割り切れるとき
		{
			comment_out(fp,thread, co);
			fprintf(fp, "#accordion_end\n");
			comment_out(fp,thread, co);
			fprintf(fp, "\n");
		}
	}
		
	
	fclose(fp);//ファイルを閉じる
	
	printf("Done.\n");
	
	return 0;
}
		
void comment_out(FILE *fp, int x, int y)
{
	if(x >= y)//ある一定スレ数より先の場合
	{
		fprintf(fp, "//");//行の先頭にコメントアウトを挿入する
	}
}