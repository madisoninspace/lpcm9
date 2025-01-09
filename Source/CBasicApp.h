// ===========================================================================
//	CBasicApp.h			©1994-2002 Metrowerks Corporation. All rights reserved.
// ===========================================================================

#ifndef _H_CBasicApp
#define _H_CBasicApp
#pragma once

#include <LApplication.h>

class CBasicApp : public LApplication {

public:
							CBasicApp();
	virtual					~CBasicApp();

	virtual Boolean			ObeyCommand(
								CommandT			inCommand,
								void*				ioParam = nil);	

	virtual void			FindCommandStatus(
								CommandT			inCommand,
								Boolean&			outEnabled,
								Boolean&			outUsesMark,
								UInt16&				outMark,
								Str255				outName);

protected:
	virtual void			StartUp();
	
			void			RegisterClasses();
};

#endif // _H_CBasicApp