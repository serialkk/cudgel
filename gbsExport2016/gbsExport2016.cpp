//**************************************************************************/
// Copyright (c) 1998-2007 Autodesk, Inc.
// All rights reserved.
// 
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information written by Autodesk, Inc., and are
// protected by Federal copyright law. They may not be disclosed to third
// parties or copied or duplicated in any form, in whole or in part, without
// the prior written consent of Autodesk, Inc.
//**************************************************************************/
// DESCRIPTION: Appwizard generated plugin
// AUTHOR: 
//***************************************************************************/

//#include "gbsExport2016.h"
#include "GbsWriter.h"

#define gbsExport2016_CLASS_ID	Class_ID(0x59c8c928, 0xcdb64b98)

class gbsExport2016 : public SceneExport {
public:
	GbsWriter m_Writer;

	//Constructor/Destructor
	gbsExport2016();
	~gbsExport2016();

	int				ExtCount();					// Number of extensions supported
	const TCHAR *	Ext(int n);					// Extension #n (i.e. "3DS")
	const TCHAR *	LongDesc();					// Long ASCII description (i.e. "Autodesk 3D Studio File")
	const TCHAR *	ShortDesc();				// Short ASCII description (i.e. "3D Studio")
	const TCHAR *	AuthorName();				// ASCII Author name
	const TCHAR *	CopyrightMessage();			// ASCII Copyright message
	const TCHAR *	OtherMessage1();			// Other message #1
	const TCHAR *	OtherMessage2();			// Other message #2
	unsigned int	Version();					// Version number * 100 (i.e. v3.01 = 301)
	void			ShowAbout(HWND hWnd);		// Show DLL's "About..." box

	BOOL SupportsOptions(int ext, DWORD options);
	int  DoExport(const TCHAR *name,ExpInterface *ei,Interface *i, BOOL suppressPrompts=FALSE, DWORD options=0);
};



class gbsExport2016ClassDesc : public ClassDesc2 
{
public:
	virtual int IsPublic() 							{ return TRUE; }
	virtual void* Create(BOOL /*loading = FALSE*/) 		{ return new gbsExport2016(); }
	virtual const TCHAR *	ClassName() 			{ return GetString(IDS_CLASS_NAME); }
	virtual SClass_ID SuperClassID() 				{ return SCENE_EXPORT_CLASS_ID; }
	virtual Class_ID ClassID() 						{ return gbsExport2016_CLASS_ID; }
	virtual const TCHAR* Category() 				{ return GetString(IDS_CATEGORY); }

	virtual const TCHAR* InternalName() 			{ return _T("gbsExport2016"); }	// returns fixed parsable name (scripter-visible name)
	virtual HINSTANCE HInstance() 					{ return hInstance; }					// returns owning module handle
	

};


ClassDesc2* GetgbsExport2016Desc() { 
	static gbsExport2016ClassDesc gbsExport2016Desc;
	return &gbsExport2016Desc; 
}





INT_PTR CALLBACK gbsExport2016OptionsDlgProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam) {
	static gbsExport2016* imp = nullptr;

	switch(message) {
		case WM_INITDIALOG:
			imp = (gbsExport2016 *)lParam;
			CenterWindow(hWnd,GetParent(hWnd));
			return TRUE;
		case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{
			case IDC_EXPORT:
			{
				imp->m_Writer.Exporter();
				EndDialog(hWnd, 1);
			}
			}
		}
		case WM_CLOSE:
			EndDialog(hWnd, 0);
			return 1;
	}
	return 0;
}


//--- gbsExport2016 -------------------------------------------------------
gbsExport2016::gbsExport2016()
{

}

gbsExport2016::~gbsExport2016() 
{

}

int gbsExport2016::ExtCount()
{
	#pragma message(TODO("Returns the number of file name extensions supported by the plug-in."))
	return 1;
}

const TCHAR *gbsExport2016::Ext(int /*i*/)
{		
	#pragma message(TODO("Return the 'i-th' file name extension (i.e. \"3DS\")."))
	return _T("gbs");
}

const TCHAR *gbsExport2016::LongDesc()
{
	#pragma message(TODO("Return long ASCII description (i.e. \"Targa 2.0 Image File\")"))
	return _T("Gbs Exporter 0.1");
}
	
const TCHAR *gbsExport2016::ShortDesc() 
{			
	#pragma message(TODO("Return short ASCII description (i.e. \"Targa\")"))
	return _T("Gbs Exporter (GBS)");
}

const TCHAR *gbsExport2016::AuthorName()
{			
	#pragma message(TODO("Return ASCII Author name"))
	return _T("Tom Lee");
}

const TCHAR *gbsExport2016::CopyrightMessage() 
{	
	#pragma message(TODO("Return ASCII Copyright message"))
	return _T("Copyright(c) 2016 Tom Lee All rights reserved. ");
}

const TCHAR *gbsExport2016::OtherMessage1() 
{		
	//TODO: Return Other message #1 if any
	return _T("");
}

const TCHAR *gbsExport2016::OtherMessage2() 
{		
	//TODO: Return other message #2 in any
	return _T("");
}

unsigned int gbsExport2016::Version()
{				
	#pragma message(TODO("Return Version number * 100 (i.e. v3.01 = 301)"))
	return 100;
}

void gbsExport2016::ShowAbout(HWND /*hWnd*/)
{			
	// Optional
}

BOOL gbsExport2016::SupportsOptions(int /*ext*/, DWORD /*options*/)
{
	#pragma message(TODO("Decide which options to support.  Simply return true for each option supported by each Extension the exporter supports."))
	return TRUE;
}


int	gbsExport2016::DoExport(const TCHAR* /*name*/, ExpInterface* /*ei*/, Interface* /*ip*/, BOOL suppressPrompts, DWORD /*options*/)
{
	#pragma message(TODO("Implement the actual file Export here and"))

	if(!suppressPrompts)
		DialogBoxParam(hInstance, 
				MAKEINTRESOURCE(IDD_PANEL), 
				GetActiveWindow(), 
				gbsExport2016OptionsDlgProc, (LPARAM)this);

	#pragma message(TODO("return TRUE If the file is exported properly"))
	return FALSE;
}

