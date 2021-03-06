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

#include "GbsExport2016.h"
#include "GbsWriter.h"

#define tbsExport2016_CLASS_ID	Class_ID(0x57b509b3, 0xc9b2eec)

class tbsExport2016 : public SceneExport {
public:
	//Constructor/Destructor
	tbsExport2016();
	~tbsExport2016();
	TbsWriter		m_tbsWriter;
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



class tbsExport2016ClassDesc : public ClassDesc2 
{
public:
	virtual int IsPublic() 							{ return TRUE; }
	virtual void* Create(BOOL /*loading = FALSE*/) 		{ return new tbsExport2016(); }
	virtual const TCHAR *	ClassName() 			{ return GetString(IDS_CLASS_NAME); }
	virtual SClass_ID SuperClassID() 				{ return SCENE_EXPORT_CLASS_ID; }
	virtual Class_ID ClassID() 						{ return tbsExport2016_CLASS_ID; }
	virtual const TCHAR* Category() 				{ return GetString(IDS_CATEGORY); }

	virtual const TCHAR* InternalName() 			{ return _T("tbsExport2016"); }	// returns fixed parsable name (scripter-visible name)
	virtual HINSTANCE HInstance() 					{ return hInstance; }					// returns owning module handle
	

};


ClassDesc2* GettbsExport2016Desc() { 
	static tbsExport2016ClassDesc tbsExport2016Desc;
	return &tbsExport2016Desc; 
}





INT_PTR CALLBACK tbsExport2016OptionsDlgProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam) {
	static tbsExport2016* imp = nullptr;

	switch(message) {
		case WM_INITDIALOG:
			imp = (tbsExport2016 *)lParam;
			CenterWindow(hWnd,GetParent(hWnd));
			return TRUE;
		case WM_COMMAND:
			switch (LOWORD(wParam))
			{
				case IDC_BUTTON1:
				{
					imp->m_tbsWriter.Export();
					EndDialog(hWnd, 1);
					return TRUE;
				}break;
			}
		case WM_CLOSE:
			EndDialog(hWnd, 0);
			return 1;
	}
	return 0;
}


//--- tbsExport2016 -------------------------------------------------------
tbsExport2016::tbsExport2016()
{

}

tbsExport2016::~tbsExport2016() 
{

}

int tbsExport2016::ExtCount()
{
	#pragma message(TODO("Returns the number of file name extensions supported by the plug-in."))
	return 1;
}

const TCHAR *tbsExport2016::Ext(int /*i*/)
{		
	#pragma message(TODO("Return the 'i-th' file name extension (i.e. \"3DS\")."))
	return _T("gbs");
}

const TCHAR *tbsExport2016::LongDesc()
{
	#pragma message(TODO("Return long ASCII description (i.e. \"Targa 2.0 Image File\")"))
	return _T("Game Basis Expoter");
}
	
const TCHAR *tbsExport2016::ShortDesc() 
{			
	#pragma message(TODO("Return short ASCII description (i.e. \"Targa\")"))
	return _T("GBS Expoter");
}

const TCHAR *tbsExport2016::AuthorName()
{			
	#pragma message(TODO("Return ASCII Author name"))
	return _T("KGCA Proj.");
}

const TCHAR *tbsExport2016::CopyrightMessage() 
{	
	#pragma message(TODO("Return ASCII Copyright message"))
	return _T("");
}

const TCHAR *tbsExport2016::OtherMessage1() 
{		
	//TODO: Return Other message #1 if any
	return _T("");
}

const TCHAR *tbsExport2016::OtherMessage2() 
{		
	//TODO: Return other message #2 in any
	return _T("");
}

unsigned int tbsExport2016::Version()
{				
	#pragma message(TODO("Return Version number * 100 (i.e. v3.01 = 301)"))
	return 100;
}

void tbsExport2016::ShowAbout(HWND /*hWnd*/)
{			
	// Optional
}

BOOL tbsExport2016::SupportsOptions(int /*ext*/, DWORD /*options*/)
{
	#pragma message(TODO("Decide which options to support.  Simply return true for each option supported by each Extension the exporter supports."))
	return TRUE;
}


int	tbsExport2016::DoExport(const TCHAR *name, ExpInterface *ei, Interface *i,
						BOOL suppressPrompts , DWORD options)
{
	#pragma message(TODO("Implement the actual file Export here and"))
	if (!m_tbsWriter.Init(name, i))
	{
		return FALSE;
	}
	if(!suppressPrompts)
		DialogBoxParam(hInstance, 
				MAKEINTRESOURCE(IDD_PANEL), 
				GetActiveWindow(), 
				tbsExport2016OptionsDlgProc, (LPARAM)this);

	m_tbsWriter.Release();
	#pragma message(TODO("return TRUE If the file is exported properly"))
	return TRUE;
}


