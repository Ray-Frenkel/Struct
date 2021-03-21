#ifndef __APPSTORE_H
#define __APPSTORE_H
#pragma warning(disable:4996)
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "Application.h"
#include<malloc.h>;

typedef struct AppStore
{
	Application** apps;		//a pointer to an array of pointers to products
	int num_of_apps;		//the number of different Application types
	char* name;				//the name of the AppStore (apple, google, etc.)
}AppStore;

AppStore* AddApp(AppStore* as, Application* app);
AppStore* DuplicateStore(AppStore* source);
void SortByCost(AppStore* as);
void SortByName(AppStore* as);
int TotalDownloads(AppStore* as);
int UpdateDownloads(AppStore* as, char* name, int toAdd);
int UpdateCost(AppStore* as, char* name, float newCost);
int GetAppDownloads(AppStore* as, char* name);
void FreeAppStore(AppStore* as);

#endif
