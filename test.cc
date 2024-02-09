#include <callbacks.h>
#include "TCanvas.h"
#include "TApplication.h"
#include "TClass.h"
#include "TClassMenuItem.h"
#include "TH1.h"
#include "TRootCanvas.h"

void customContextMenu()
{
   TH1F *h;
   TH1F *h2;
   TClassMenuItem *n;
   TList *l;

   // Create test histograms
   h = new TH1F("h","Schtroumpf",100,-4,4);
   h->FillRandom("gaus");
   h->Draw();

   h2 = new TH1F("h2","h2",1000,-4,4);
   h2->FillRandom("gaus",30000);

   // Retrieve menu list from TClass
   TClass *cl = h->IsA();
   l = cl->GetMenuList();

   // Add some items to the popup menus
   n = new TClassMenuItem(TClassMenuItem::kPopupUserFunction,cl,
                          "Test object, draw a second h","Draw",h2,"Option_t*");
   l->AddFirst(n);
   n = new TClassMenuItem(TClassMenuItem::kPopupSeparator,cl);
   l->AddFirst(n);

   n = new TClassMenuItem(TClassMenuItem::kPopupUserFunction,cl,
                          "test no 4","poptest4",0,"const char*");
   l->AddFirst(n);
   n = new TClassMenuItem(TClassMenuItem::kPopupUserFunction,cl,
                          "test no 3","poptest3",0,"");
   l->AddFirst(n);
   n = new TClassMenuItem(TClassMenuItem::kPopupUserFunction,cl,
                          "test no 2 bis","poptest2bis",0,"TObject*",2);
   l->AddFirst(n);
   n = new TClassMenuItem(TClassMenuItem::kPopupUserFunction,cl,
                          "test no 2","poptest2",0,"int,int,TObject*",2);
   l->AddFirst(n);
   n = new TClassMenuItem(TClassMenuItem::kPopupUserFunction,cl,
                          "test no 1","poptest1",0,"int,int");
   l->AddFirst(n);
   n = new TClassMenuItem(TClassMenuItem::kPopupUserFunction,cl,
			  "Zoom ALL X as last","URZoomAllXAsLastProxy",0,"TObject*",2);
   l->AddFirst(n);
}

int
main (int argc, char **argv)
{
	TApplication app("app", &argc, argv);
	TCanvas* c = new TCanvas("c", "Something", 0, 0, 800, 600);

	gInterpreter->Declare("void URZoomAllXAsLast(TObject *objaxis);\nvoid URZoomAllXAsLastProxy(TObject *objaxis) {URZoomAllXAsLast(objaxis);}");

	customContextMenu();

	TRootCanvas *rc = (TRootCanvas *)c->GetCanvasImp();
	rc->Connect("CloseWindow()", "TApplication", gApplication, "Terminate()");
	app.Run();
}
