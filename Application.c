#include "Application.h"

//Function Number 1:
/*This Function  get name, cost and download and creat new application*/

Application* CreateNewApp(char* _name, float _cost, int _downloads)
{
	char* copyName;
	Application * NewApp = (Application*)malloc(1 * sizeof(Application));
	if (!NewApp)
	{
		free(NewApp);
		return NULL;
	}
	else
	{
		int size = strlen(_name);
		copyName= (char*)malloc(sizeof(char) * (strlen(_name) + 1));
		if (!copyName)
		{
			free(copyName);
			return NULL;
		}
	else
		{
			strcpy(copyName, _name);
			NewApp->name = copyName;
			NewApp->cost = _cost;
			NewApp->downloads = _downloads;
			
		}
	}
	return NewApp;

}

//Function Number 2
/*This Function Get point to app, and duplicate the app*/
Application* DuplicateApp(Application* source)
{
	Application* temp;
	temp = (Application*)malloc(1 * sizeof(Application));
	if (!temp)
		return NULL;
	temp = CreateNewApp(source->name, source->cost, source->downloads);//use the first function to copy the app to the new one.
	return temp;
}
//===========ex11============
/*this function get pointer to app and free the memory*/
void FreeApp(Application* app)
{
	int i;
	for (i = 0; i < sizeof(app->name)/sizeof(char*); i++)
	{
		free(app->name);
	}
	free(app);
}


	


