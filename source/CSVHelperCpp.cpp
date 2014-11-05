#include "s3e.h"
#include "IwDebug.h"
#include "Iw2DSceneGraph.h"
#include "IwGx.h"
#include "CSVHelper.h"
#include <string>

using namespace Iw2DSceneGraphCore;
using namespace Iw2DSceneGraph;


#define FILENAME "sprites.txt"

// Scene root node
//CNode* g_SceneRoot = NULL;

// Main entry point for the application
int main()
{
	//Initialise graphics system(s)
	Iw2DInit();

	// Create root node
	// g_SceneRoot = new CNode();

	CSVReaderS3e* reader = new CSVReaderS3e(FILENAME);

	IwTrace(GAME, ("NUMERO: HELLOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"));

	CSVRow row;
	while (reader->ReadRow(row))
	{
		IwTrace(GAME, ("ROW CONTENT: %s", row.GetData().c_str()));
	}

    // Loop forever, until the user or the OS performs some action to quit the app
    while (!s3eDeviceCheckQuitRequest())
    {
        //Update the input systems
        //s3eKeyboardUpdate();
        //s3ePointerUpdate();
		Iw2DSurfaceClear(0xff8080);
        //Update the scene. The SDK's example framework has a fixed
        //framerate of 20fps, so we pass that duration to the update function.
        //g_SceneRoot->Update(1000/20);

       //Iw2DSurfaceClear(0xff00ff00);
        
        // Your rendering/app code goes here.

        //g_SceneRoot->Render();

        //Draws Surface to screen
        //Iw2DSurfaceShow();

        // Sleep for 0ms to allow the OS to process events etc.
        s3eDeviceYield(0);
    }

    //Terminate modules being used
    //delete g_SceneRoot;
    Iw2DTerminate();
    
	//delete reader;

    // Return
    return 0;
}
