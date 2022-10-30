#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include<functional>
#include<list>

int main() {

	//�J�E���g�p
	int count = 0;

	//�w�̃��X�g
	std::list <const char*> station{"Tokyo","Kanda","Akihabara","Okachimachi","Ueno",
							"Uguisudani","Nippori","Tabata","Komagome","Sugamo",
							"Ootsuka","Ikebukuro","Mejiro","Takadanobata","Shinookubo",
							"Shinjuku","Yoyogi","Harajuku","Shibuya","Ebisu",
							"Meguro","Gotanda","Oosaki","Shinagawa","Tamachi",
							"Hamamatsutyou","Shinbashi","Yuurakutyou"};


	printf("1970�N\n-------------\n");
	//�w����\��
	for (std::list<const char*>::iterator itr = station.begin(); itr != station.end(); ++itr) {
		++count;
		printf("�w��:%s-----%d\n", *itr, count);
	}
	count = 0;


	printf("-------------\n2019�N-------------\n");
	//�����闢�w��ǉ�
	for (std::list<const char*>::iterator itr = station.begin(); itr != station.end(); ++itr) {
		if (*itr == "Nippori") {
			itr = station.insert(itr, "Nisinippori");
			++itr;
		}
	}
	//�w����\��
	for (std::list<const char*>::iterator itr = station.begin(); itr != station.end(); ++itr) {
		++count;
		printf("�w��:%s-----%d\n", *itr,count);
	}
	count = 0;



	printf("-------------\n2022�N\n");
	//���փQ�[�g�E�F�C�w��ǉ�
	for (std::list<const char*>::iterator itr = station.begin(); itr != station.end(); ++itr) {
		if (*itr == "Shinagawa") {
			itr = station.insert(itr, "Takanawa Gateway");
			++itr;
		}
	}
	//�w����\��
	for (std::list<const char*>::iterator itr = station.begin(); itr != station.end(); ++itr) {
		++count;
		printf("�w��:%s-----%d\n", *itr,count);
	}
	count = 0;
	printf("-------------\n");


	return 0;
}