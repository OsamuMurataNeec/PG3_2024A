#include <stdio.h>
#include <windows.h>
#include <time.h>

typedef void (*PFunc)(int *, int *);

// コールバック関数
void DispResult(int *s, int *kazu){

	int kekka = rand() % 2;

	if (kekka == *kazu) {
		if(kekka == 0)
			printf("%dで丁（偶数）でした!大当たり!!\n", kekka);
		else
			printf("%dで半（奇数）でした!大当たり!!\n", kekka);
	}else{
		if (kekka == 0)
			printf("%dで丁（偶数）でした!残念!!\n", kekka);
		else
			printf("%dで半（奇数）でした!残念!!\n", kekka);
	}

}

// コールバック関数を呼び出す
void setTimeout( PFunc p, int second, int kazu){

	puts("さて結果は…\n");

	for (int i = 0; i < second; i++) {
		Sleep(1000);
		printf("%d...\n",second-i);
	}

	p(&second,&kazu);
}


int main(){

	int kazu;

	srand(static_cast<unsigned int>(time(NULL)));
	printf("丁（偶数）ならゼロ、半（奇数）なら1を入力してください\n");
	scanf_s("%d",&kazu);

	if (kazu == 0) {
		puts("あなたは丁（偶数）を選びましたね？");
	}
	else {
		puts("あなたは半（奇数）を選びましたね？");
	}

	PFunc p;
	p = DispResult;
	setTimeout( p, 3, kazu);

	return 0;
}


