// ===========================================================================
//	CBasicApp.cp 		©1994-2002 Metrowerks Corporation. All rights reserved.
// ===========================================================================
//	This file contains the starter code for a basic PowerPlant project

#include "CBasicApp.h"

#include <LGrowZone.h>
#include <PP_Messages.h>
#include <PP_Resources.h>
#include <UDrawingState.h>
#include <UMemoryMgr.h>
#include <URegistrar.h>

#include <LWindow.h>
#include <LCaption.h>

#include "LicensePlate.h"

// ---------------------------------------------------------------------------
//	Constant declarations

const ResIDT	PPob_SampleWindow			= 128;


// ===========================================================================
//	€ main
// ===========================================================================

int main()
{							
		// Set Debugging options
	SetDebugThrow_(debugAction_Alert);
	SetDebugSignal_(debugAction_Alert);

		// Initialize Memory Manager. Parameter is the number of
		// master pointer blocks to allocate
	InitializeHeap(3);
	
		// Initialize standard Toolbox managers
	UQDGlobals::InitializeToolbox();
	
		// Install a GrowZone to catch low-memory situations	
	new LGrowZone(20000);

		// Create the application object and run
	CBasicApp	theApp;
	theApp.Run();
	
	return 0;
}


// ---------------------------------------------------------------------------
//	€ CBasicApp										[public]
// ---------------------------------------------------------------------------
//	Application object constructor

CBasicApp::CBasicApp()
{
	RegisterClasses();
}


// ---------------------------------------------------------------------------
//	€ ~CBasicApp									[public, virtual]
// ---------------------------------------------------------------------------
//	Application object destructor

CBasicApp::~CBasicApp()
{
	// Nothing
}


// ---------------------------------------------------------------------------
//	€ StartUp										[protected, virtual]
// ---------------------------------------------------------------------------
//	Perform an action in response to the Open Application AppleEvent.
//	Here, issue the New command to open a window.

void
CBasicApp::StartUp()
{
	ObeyCommand(cmd_New, nil);
}


// ---------------------------------------------------------------------------
//	€ ObeyCommand									[public, virtual]
// ---------------------------------------------------------------------------
//	Respond to Commands. Returns true if the Command was handled, false if not.

Boolean
CBasicApp::ObeyCommand(
	CommandT	inCommand,
	void*		ioParam)
{
	Boolean		cmdHandled = true;	// Assume we'll handle the command

	switch (inCommand) {

		case cmd_New: {
			LWindow* theWindow = LWindow::CreateWindow(PPob_SampleWindow, this);
			ThrowIfNil_(theWindow);

			theWindow->Show();
			break;
		}

		default: {
			cmdHandled = LApplication::ObeyCommand(inCommand, ioParam);
			break;
		}
	}
	
	return cmdHandled;
}


// ---------------------------------------------------------------------------
//	€ FindCommandStatus								[public, virtual]
// ---------------------------------------------------------------------------
//	Determine the status of a Command for the purposes of menu updating.

void
CBasicApp::FindCommandStatus(
	CommandT	inCommand,
	Boolean&	outEnabled,
	Boolean&	outUsesMark,
	UInt16&		outMark,
	Str255		outName)
{
	switch (inCommand) {

		case cmd_New: {
			outEnabled = true;
			break;
		}

		default: {
			LApplication::FindCommandStatus(inCommand, outEnabled,
											outUsesMark, outMark, outName);
			break;
		}
	}
}


// ---------------------------------------------------------------------------
//	€ RegisterClasses								[protected]
// ---------------------------------------------------------------------------
//	To reduce clutter within the Application object's constructor, class
//	registrations appear here in this seperate function for ease of use.

void
CBasicApp::RegisterClasses()
{
	RegisterClass_(LWindow);
	RegisterClass_(LCaption);
}