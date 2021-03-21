#include"AppStore.h"
#include<stdlib.h>
#define _NO_DEBUG_HEAP
/*Name: Raymond Frenkel
Id: 206594038
Date:10/1/21
*/
//=================EX3=======================
/*This Function get get AppStore and Application and check if the app exist in the appstore if not he add, if the app exist he change the number of download the app have*/
AppStore* AddApp(AppStore* as, Application* app)
{
	int i;
	AppStore* store;
	store = (AppStore*)malloc(1 * sizeof(AppStore));
	if (!store)
		return NULL;
	if (as == NULL ) //We insert the first name to the names
	{
		store->name = "Colman Store";
		store->num_of_apps = 1;
		store->apps = (Application*)malloc(1 * sizeof(Application));
		store->apps[0] = (Application*)malloc(1 * sizeof(Application));
		store->apps[0]->name = (char*)malloc((strlen(app->name) + 1)*sizeof(char));
		strcpy(store->apps[0]->name, app->name);
		store->apps[0]->name[strlen(app->name)] = '\0';

		store->apps[0]->downloads = app->downloads;
		store->apps[0]->cost = app->cost;
		return store;
	}
	

	for (i = 0; i < as->num_of_apps; i++)
	{
		if (strcmp(app->name, as->apps[i]->name) == 0) //if there is equal Application names
		{
			as->apps[i]->downloads = app->downloads;//only update amount of downloads
			return as;
		}
	}
	as->apps[as->num_of_apps]= (Application*)malloc(1 * sizeof(Application));//allocate new memory
		if (!as->apps)
		{
			return NULL;
		}
	    as->apps[as->num_of_apps] = DuplicateApp(app);
		as->num_of_apps++;
	

		return as;
	
}
// ======================ex4================
/*This funciton get AppStore pointer and copy this to new appstore*/
AppStore* DuplicateStore(AppStore* source)
{
	int i;
	AppStore* newA;
	newA = (AppStore*)malloc(1 * sizeof(AppStore));
	if (!newA)
		return NULL;
	//we cinsert values to the first place.
	newA->apps= (Application*)malloc(source->num_of_apps * sizeof(Application));
	newA->name = (char*)malloc((strlen(source->name) + 1) * sizeof(char));
	strcpy(newA->name, source->name);//name of the store;
	newA->name[strlen(source->name)] = '\0';

	newA->num_of_apps = 1;

	newA->apps = (Application*)malloc(1 * sizeof(Application));
	newA->apps[0] = (Application*)malloc(1 * sizeof(Application));
	newA->apps[0]->name = (char*)malloc((strlen(source->apps[0]->name) + 1) * sizeof(char));
	strcpy(newA->apps[0]->name, source->apps[0]->name);
	newA->apps[0]->name[strlen(source->apps[0]->name)] = '\0';

	newA->apps[0]->downloads = source->apps[0]->downloads;
	newA->apps[0]->cost = source->apps[0]->cost;


	for (i = 1; i < source->num_of_apps; i++)//insert valuse to the new->apps here.
	{
		newA= AddApp(newA, source->apps[i]);

	}



	return newA;

}
//================ex5=================
/*This Function ger pointer to app store and sort the application from the cheapest the the expensive*/
void SortByCost(AppStore* as)
{
	int i, j;
	Application* copyApp;
	copyApp = (Application*)malloc(1 * sizeof(Application));
	for (i = 0; i < as->num_of_apps - 1; i++)
	{
		for (j = 0; j < as->num_of_apps - 1 - i; j++)
		{
			if ((as->apps[j]->cost) > (as->apps[j + 1]->cost))
			{
				copyApp = DuplicateApp(as->apps[j]);
				as->apps[j] = DuplicateApp(as->apps[j + 1]);
				as->apps[j + 1] = DuplicateApp(copyApp);

			}
		}
	}
}
//==================ex6===================
/*this function sory the apps from the small to the big names.*/
void SortByName(AppStore* as)
{
	int i, j;
	Application* copyApp;
	copyApp = (Application*)malloc(1 * sizeof(Application));
	for (i = 0; i < as->num_of_apps - 1; i++)
	{
		for (j = 0; j < as->num_of_apps- 1 - i; j++)
		{
			if (strcmp(as->apps[j]->name,as->apps[j + 1]->name)>0)
			{
				copyApp = DuplicateApp(as->apps[j]);
				as->apps[j] = DuplicateApp(as->apps[j + 1]);
				as->apps[j + 1] = DuplicateApp(copyApp);
			}
		}
	}
}
//==================ex7==============
/*this function ger pointer to appstore and return the sum of the download of all the apps*/
int TotalDownloads(AppStore* as)
{
	int sum = 0;
	for (int i = 0; i < as->num_of_apps; i++)
	{
		sum = sum + as->apps[i]->downloads;
	}
	return sum;
}
//===========ex8=============
/*this funciton ger pointer to app store, name of app, and number, search by name if the app exist if yes we update the number of download with "toadd"*/
int UpdateDownloads(AppStore* as, char* name, int toAdd)
{
	for (int i = 0; i < as->num_of_apps; i++)
	{
		if (strcmp(as->apps[i]->name, name) == 0)//compare the names in the appsotre and the name we got
		{
			as->apps[i]->downloads += toAdd;
			return 1;
		}
	}
	return 0;

}
//================ex9==========
/*this funciton ger pointer to app store, name of app, and number, search by name if the app exist if yes we update the cost with "newCost"*/
int UpdateCost(AppStore* as, char* name, float newCost)
{
	for (int i = 0; i < as->num_of_apps; i++)
	{
		if (strcmp(as->apps[i]->name, name) == 0)//compare the names in the appsotre and the name we got
		{
			as->apps[i]->cost = newCost;
			return 1;
		}
	}
	return 0;
}
//==============ex10==========
/*this function get pointer to app sotre and app name, and return the number of download the app have*/
int GetAppDownloads(AppStore* as, char* name)
{
	for (int i = 0; i < as->num_of_apps; i++)
	{
		if (strcmp(as->apps[i]->name, name) == 0)//compare the names in the appsotre and the name we got
		{
			return as->apps[i]->downloads;
		}
	}
	return -1;
}
//================ex12========
/*this function free the memnory of the appstores*/
void FreeAppStore(AppStore* as)
{
	int i;
	for (i = 0; i < as->num_of_apps; i++)
		FreeApp(as->apps[i]);
	free(as);
}


