// Exercise13_AutoLISPFunction.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "arxHeaders.h"
#include "acedCmdNF.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define PI 3.14159
#define ELEMENTS(array) (sizeof(array)/sizeof((array)[0]))

struct func_entry
{
	ACHAR* func_name; int (*func) (struct resbuf*); 
};

// Advanced Messaging
int Ex_Alert(struct resbuf* rb);

// Math functions
int Dtr(struct resbuf* rb);
int Rtd(struct resbuf* rb);
int tangent(struct resbuf* rb);

// Add the AutoLISP functions to the function table
static struct func_entry func_table[] = 
{
	{_T("Ex_Alert"), Ex_Alert},
	{_T("Dtr"), Dtr},
	{_T("Rtd"), Rtd},
	{_T("Tan"), tangent}
};

static int funcload()
{
	int i;
	for (i = 0; i < ELEMENTS(func_table); i++) {
		if (!acedDefun(func_table[i].func_name, (short)i))
			return RTERROR;
	}
	return RTNORM;
}

static int dofun()
{
	struct resbuf* rb;
	int val;
	
	if ((val = acedGetFunCode()) < 0 || val >= ELEMENTS(func_table)) 
	{
		acdbFail(_T("Received nonexistent function code."));
		return RTERROR;
	}
	
	/* Get the arguments passed into the function */
	rb = acedGetArgs();
	
	/* Execute the callback function and return its status. */
	val = (*func_table[val].func)(rb);
	acutRelRb(rb);
	return val;
}


// Tangent - Tan function doesn't exist in AutoLISP by default
static int tangent(struct resbuf* rb)
{
	double dDistance;
	if (rb == NULL)
	{
		acutPrintf(_T("Improper use of function:(Tan <angle in radians>)"));
			return RTERROR;
	}
	
	if (rb->restype == RTREAL) { /* Can accept an interger */
		dDistance = rb->resval.rreal;
	}
	else if (rb->restype == RTLONG) {
		dDistance = rb->resval.rlong;
	}
	else if (rb->restype == RTSHORT) {
		dDistance = rb->resval.rint;
	}
	else {
		acdbFail(_T("Argument one should be a number"));
		return RTERROR;
	}
	acedRetReal(tan(dDistance));
	return RTNORM;
}

static ads_real rdtr(ads_real deg) /* Degrees to Radians */
{
	ads_real retVal;
	retVal = (deg * (PI / 180)); // PI is defined above
	return retVal;
}

static int Dtr(struct resbuf* rb)
{
	double x;
	if (rb == NULL)
	{
		acutPrintf(_T("Improper use of function: (dtr <degrees>)\n"));
		return RTERROR;
	}
	
	if (rb->restype == RTSHORT) { /* Can accept an interger */
		x = (ads_real)rb->resval.rint;
	}
	else if (rb->restype == RTREAL) 
	{
		x = rb->resval.rreal; /* or a real number */
	}
	else 
	{
		acdbFail(_T("Argument should be an real or integer number."));
		return RTERROR;
	}
	acedRetReal(rdtr(x)); /* Call the function itself, and return the value to AutoLISP */
	return RTNORM;
}

static ads_real rrtd(ads_real rad) /* Radians to Degrees */
{
	ads_real retVal;
	retVal = (180 * (rad / PI)); // PI is defined above
	return retVal;
}

/* RTD -- First set up the argument, then call the RRTD function */
static int Rtd(struct resbuf* rb)
{
	double x;
	if (rb == NULL)
	{
		acutPrintf(_T("Improper use of function: (rtd <radians>)\n"));
		return RTERROR;
	}
	
	if (rb->restype == RTSHORT) 
	{ /* Can accept an interger */
		x = (ads_real)rb->resval.rint;
	}
	else if (rb->restype == RTREAL) 
	{
		x = rb->resval.rreal; /* or a real number */
	}
	else 
	{
		acdbFail(_T("Argument should be an real or integer number."));
		return RTERROR;
	}
	acedRetReal(rrtd(x)); /* Call the function itself, and return the value to AutoLISP */
	return RTNORM;
}

/* EX_ALERT -- Extended Alert, Message, Button, ICON */
static int Ex_Alert(struct resbuf* rb)
{
	ACHAR* message = _T("");
	ACHAR* caption = _T("AutoCAD Message");
	int buttons = MB_OK;
	int icon = 0, defbutton = 0;
	int retVal;
	struct resbuf* rbList = NULL, * transList = NULL;
	if (rb == NULL)
	{
		acutPrintf(_T("Improper use of function: (ex_alert <message>([caption]([BUTTON][ICON]))"));
				return RTERROR;
	}

	if (rb->restype == RTSTR)
	{ /* Accept an string */
		message = rb->resval.rstring;
	}
	else
	{
		acdbFail(_T("Argument should be a string"));
		return RTERROR;
	}
	rb = rb->rbnext;

	if (rb != NULL)
	{
		if (rb->restype == RTSTR) { /* Accept an string */
			caption = rb->resval.rstring;
		}
		else
		{
			acdbFail(_T("Argument should be a string"));
			return RTERROR;
		}
		rb = rb->rbnext;

		if (rb != NULL)
		{
			if (rb->restype == RTSHORT)
			{ /* Accept an integer */
				buttons = rb->resval.rint;
			}
			else
			{
				acdbFail(_T("Argument should be an integer"));
				return RTERROR;
			}
			rb = rb->rbnext;

			if (rb != NULL)
			{
				if (rb->restype == RTSHORT)
				{ /* Accept an integer */
					icon = rb->resval.rint;
					switch (icon)
					{
					case 10:
						icon = MB_ICONSTOP;
						break;
					case 20:
						icon = MB_ICONQUESTION;
						break;
					case 30:
						icon = MB_ICONEXCLAMATION;
						break;
					case 40:
						icon = MB_ICONINFORMATION;
						break;
					default:
						icon = 0;
					}
				}
				else
				{
					acdbFail(_T("Argument should be an integer"));
					return RTERROR;
				}
			}
		}
	}
	retVal = MessageBox(adsw_acadMainWnd(), message, caption, buttons + icon);
	acedRetInt(retVal); /* Call the function itself, and return the value to AutoLISP */
	message = NULL;
	delete message;
	caption = NULL;
	delete caption;
	return RTNORM;
}

extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt)
{
	switch (Msg)
	{
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(pkt);
		acrxDynamicLinker->registerAppMDIAware(pkt);
		acutPrintf(L"\nLoading project...\n");

		int retVal;
		struct resbuf* symVal;
		
		symVal = acutNewRb(RTSHORT);
		symVal->resval.rint = 0;
		retVal = acedPutSym(_T("MB_OK"), symVal);
		
		symVal = acutNewRb(RTSHORT);
		symVal->resval.rint = 1;
		retVal = acedPutSym(_T("MB_OKCANCEL"), symVal);
		
		symVal = acutNewRb(RTSHORT);
		symVal->resval.rint = 2;
		retVal = acedPutSym(_T("MB_ABORTRETRYIGNORE"), symVal);
		
		symVal = acutNewRb(RTSHORT);
		symVal->resval.rint = 3;
		retVal = acedPutSym(_T("MB_YESNOCANCEL"), symVal);
		
		symVal = acutNewRb(RTSHORT);
		symVal->resval.rint = 4;
		retVal = acedPutSym(_T("MB_YESNO"), symVal);
		
		symVal = acutNewRb(RTSHORT);
		symVal->resval.rint = 5;
		retVal = acedPutSym(_T("MB_RETRYCANCEL"), symVal);
		
		symVal = acutNewRb(RTSHORT);
		symVal->resval.rint = 16384;
		retVal = acedPutSym(_T("MB_HELP"), symVal);
		
		symVal = acutNewRb(RTSHORT);
		symVal->resval.rint = 0;
		retVal = acedPutSym(_T("MB_DEFBUTTON1"), symVal);
		
		symVal = acutNewRb(RTSHORT);
		symVal->resval.rint = 256;
		retVal = acedPutSym(_T("MB_DEFBUTTON2"), symVal);
		
		symVal = acutNewRb(RTSHORT);
		symVal->resval.rint = 512;
		retVal = acedPutSym(_T("MB_DEFBUTTON3"), symVal);
		
		symVal = acutNewRb(RTSHORT);
		symVal->resval.rint = 768;
		retVal = acedPutSym(_T("MB_DEFBUTTON4"), symVal);
		
		symVal = acutNewRb(RTSHORT);
		symVal->resval.rint = 0;
		retVal = acedPutSym(_T("MB_ICONNONE"), symVal);
		
		symVal = acutNewRb(RTSHORT);
		symVal->resval.rint = 20;
		retVal = acedPutSym(_T("MB_ICONQUESTION"), symVal);
		
		symVal = acutNewRb(RTSHORT);
		symVal->resval.rint = 40;
		retVal = acedPutSym(_T("MB_ICONINFORMATION"), symVal);
		
		symVal = acutNewRb(RTSHORT);
		symVal->resval.rint = 10;
		retVal = acedPutSym(_T("MB_ICONSTOP"), symVal);
		
		symVal = acutNewRb(RTSHORT);
		symVal->resval.rint = 30;
		retVal = acedPutSym(_T("MB_ICONEXCLAMATION"), symVal);
		
		symVal = NULL;
		delete symVal;
		break;

	case AcRx::kUnloadAppMsg:
		acutPrintf(_T("\nUnloading createLine project...\n"));
		acedRegCmds->removeGroup(_T("AUCommnds"));
		break;

	default:
		break;
	}
	return AcRx::kRetOK;
}