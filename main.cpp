#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include<functional>
#include<list>

int main() {

	//ƒJƒEƒ“ƒg—p
	int count = 0;

	//‰w‚ÌƒŠƒXƒg
	std::list <const char*> station{"Tokyo","Kanda","Akihabara","Okachimachi","Ueno",
							"Uguisudani","Nippori","Tabata","Komagome","Sugamo",
							"Ootsuka","Ikebukuro","Mejiro","Takadanobata","Shinookubo",
							"Shinjuku","Yoyogi","Harajuku","Shibuya","Ebisu",
							"Meguro","Gotanda","Oosaki","Shinagawa","Tamachi",
							"Hamamatsutyou","Shinbashi","Yuurakutyou"};


	printf("1970”N\n-------------\n");
	//‰w–¼‚ğ•\¦
	for (std::list<const char*>::iterator itr = station.begin(); itr != station.end(); ++itr) {
		++count;
		printf("‰w–¼:%s-----%d\n", *itr, count);
	}
	count = 0;


	printf("-------------\n2019”N-------------\n");
	//¼“ú•é—¢‰w‚ğ’Ç‰Á
	for (std::list<const char*>::iterator itr = station.begin(); itr != station.end(); ++itr) {
		if (*itr == "Nippori") {
			itr = station.insert(itr, "Nisinippori");
			++itr;
		}
	}
	//‰w–¼‚ğ•\¦
	for (std::list<const char*>::iterator itr = station.begin(); itr != station.end(); ++itr) {
		++count;
		printf("‰w–¼:%s-----%d\n", *itr,count);
	}
	count = 0;



	printf("-------------\n2022”N\n");
	//‚—ÖƒQ[ƒgƒEƒFƒC‰w‚ğ’Ç‰Á
	for (std::list<const char*>::iterator itr = station.begin(); itr != station.end(); ++itr) {
		if (*itr == "Shinagawa") {
			itr = station.insert(itr, "Takanawa Gateway");
			++itr;
		}
	}
	//‰w–¼‚ğ•\¦
	for (std::list<const char*>::iterator itr = station.begin(); itr != station.end(); ++itr) {
		++count;
		printf("‰w–¼:%s-----%d\n", *itr,count);
	}
	count = 0;
	printf("-------------\n");


	return 0;
}