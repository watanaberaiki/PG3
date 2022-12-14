#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include<functional>
#include<list>

int main() {

	//カウント用
	int count = 0;

	//駅のリスト
	std::list <const char*> station{"Tokyo","Kanda","Akihabara","Okachimachi","Ueno",
							"Uguisudani","Nippori","Tabata","Komagome","Sugamo",
							"Ootsuka","Ikebukuro","Mejiro","Takadanobata","Shinookubo",
							"Shinjuku","Yoyogi","Harajuku","Shibuya","Ebisu",
							"Meguro","Gotanda","Oosaki","Shinagawa","Tamachi",
							"Hamamatsutyou","Shinbashi","Yuurakutyou"};


	printf("1970年\n-------------\n");
	//駅名を表示
	for (std::list<const char*>::iterator itr = station.begin(); itr != station.end(); ++itr) {
		++count;
		printf("駅名:%s-----%d\n", *itr, count);
	}
	count = 0;


	printf("-------------\n2019年-------------\n");
	//西日暮里駅を追加
	for (std::list<const char*>::iterator itr = station.begin(); itr != station.end(); ++itr) {
		if (*itr == "Nippori") {
			itr = station.insert(itr, "Nisinippori");
			++itr;
		}
	}
	//駅名を表示
	for (std::list<const char*>::iterator itr = station.begin(); itr != station.end(); ++itr) {
		++count;
		printf("駅名:%s-----%d\n", *itr,count);
	}
	count = 0;



	printf("-------------\n2022年\n");
	//高輪ゲートウェイ駅を追加
	for (std::list<const char*>::iterator itr = station.begin(); itr != station.end(); ++itr) {
		if (*itr == "Shinagawa") {
			itr = station.insert(itr, "Takanawa Gateway");
			++itr;
		}
	}
	//駅名を表示
	for (std::list<const char*>::iterator itr = station.begin(); itr != station.end(); ++itr) {
		++count;
		printf("駅名:%s-----%d\n", *itr,count);
	}
	count = 0;
	printf("-------------\n");


	return 0;
}