#include "string.h"
#include <stdio.h>
#include <stdlib.h>
struct accounts {
	char IBAN[100];
	int sum;
	char type[100];
	bool isEmpty = true;
};

class persons {
	char fname[100];
	char lname[100];
	int braccounts;
	struct accounts acc[50];
	int sumAllAcc;
	int currentAccs;
public:
	persons(char *fname, char *lname, int br) {
		strcpy(this->fname, fname);
		strcpy(this->lname, lname);
		this->sumAllAcc = 0;
		currentAccs = 0;
		braccounts = br;
	}
	int Getbraccounts() {
		return this->braccounts;
	}
	char *GetName() {
		return this->fname;
	}
	int GetsumAllAcc() {
		return this->sumAllAcc;
	}
	void AddAccount(char *iban, int sum, char *type) {
		if (acc[currentAccs].isEmpty == true) {
			strcpy(acc[currentAccs].IBAN, iban);
			acc[currentAccs].sum = sum;
			strcpy(acc[currentAccs].type, type);
			acc[currentAccs].isEmpty = false;
			currentAccs++;
		}
	}
	void deleteAcc(char *iban) {
		for (int i = 0; i < braccounts; i++) {
			if (strcmp(acc[i].IBAN, iban)) {
				strcpy(acc[i].IBAN, "");
				acc[i].sum = 0;
				strcpy(acc[i].type, "");
				acc[i].isEmpty = true;
			}
		}
	}
	accounts *FindByIBan(char *iban) {
		for (int i = 0; i < braccounts; i++) {
			if (strcmp(acc[i].IBAN, iban))
				return &acc[i];
		}
		return NULL;
	}
	accounts *FindByIBan(int sum) {
		for (int i = 0; i < braccounts; i++) {
			if (acc[i].sum == sum)
				return &acc[i];
		}
		return NULL;
	}
	int AllSum() {
		for (int i = 0; i < braccounts; i++) {
			if (acc[i].isEmpty == false)
				sumAllAcc += acc[i].sum;
		}
		return sumAllAcc;
	}

};
int main()
{
	persons *people[5];
	int oprsum = 5;
	people[0] = new persons("krastyo", "dulgerov", 2);
	people[1] = new persons("alek", "kosev", 1);
	people[2] = new persons("stanislav", "peshov", 2);
	people[3] = new persons("roli ", "pehlivanov", 2);
	people[4] = new persons("dimityr", "georgiev", 2);
	people[4]->AddAccount("5825125da5d54da155", 6, "type e tup!");
	people[4]->AddAccount("1111111111111155", 1, "nqkavtype");
	people[3]->AddAccount("155", 8, "tup!");
	people[3]->AddAccount("55", 1, "!");
	people[2]->AddAccount("58255", 4, "umentype");
	people[2]->AddAccount("sameshitjustanotherday", 2, "fuckthatshit");
	people[1]->AddAccount("justshit", 10, "shishatime!!!");
	people[0]->AddAccount("asl?", 6, "type");
	people[0]->AddAccount("a12l?", 6, "pe");
	for (int i = 0; i < 5; i++) {
		int temp = people[i]->AllSum();
	}
	for (int i = 0; i < 5; i++) {
		if (people[i]->GetsumAllAcc() > oprsum)
			printf("%d %s\n", people[i]->GetsumAllAcc(), people[i]->GetName());
	}
	system("PAUSE");
	return 0;
}
