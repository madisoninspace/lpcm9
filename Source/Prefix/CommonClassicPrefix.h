// ===========================================================================
//	CommonClassicPrefix.h	�1999-2002 Metrowerks Corporation.  All rights reserved.
// ===========================================================================
//	Common options for a Classic Target


// ---------------------------------------------------------------------------
//	Classic Target

#define PP_Target_Carbon		0

#define PP_Target_Classic		(!PP_Target_Carbon)

#define TARGET_API_MAC_CARBON	PP_Target_Carbon
#define TARGET_API_MAC_OS8		PP_Target_Classic


// ---------------------------------------------------------------------------
//	Options
	
#define PP_Uses_PowerPlant_Namespace	0
#define PP_StdDialogs_Option			PP_StdDialogs_Conditional

#define PP_Warn_Obsolete_Classes		1

#define PP_Suppress_Notes_221			1
