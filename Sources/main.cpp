﻿#include <Tasks/Task02.h>
#include "GraphicsEngine/Application.h"

#include "Tasks/Task01.h"
#include "Tasks/Task04.h"
#include "Tasks/Task05_01.h"


// The application's entry point
int main(int argc, char ** argv)
{
	// Remember argc, argv
	{
		Application & app = Application::Instance();
		app.argc = argc;
		app.argv = argv;
	}

    //Task * pTask = new Task01();
    //Task * pTask = new Task04();
    Task * pTask = new Task04();
	{
		GraphicsEngine & engine = GraphicsEngine::Instance();

		engine.Init();
        pTask->Init();

		while (engine.IsRunning())
		{
            pTask->Update();
			engine.Render();
		}

        delete pTask;
		engine.Deinit();
    }
	
    return 0;
}