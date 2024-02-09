#include <callbacks.h>
#include "TH1.h"

void Dummy::poptest1(int a, int b)
{
   printf("poptest1 %d %d\n",a,b);
}

void Dummy::poptest2(int a, int b, TObject *c)
{
   // Remark: the object c will not be asked for since it is the selected object
   printf("poptest2 %d %d\n",a,b);
   printf("histo : %lx\n",(Long_t)c);
   printf("title of the histogram : %s\n",((TH1F*)c)->GetTitle());
}

void Dummy::poptest2bis(TObject *c)
{
   // Remark: the object c will not be asked for since it is the selected object
   printf("poptest2bis\n");
   printf("histo : %lx\n",(Long_t)c);
   printf("title of the histogram : %s\n",((TH1F*)c)->GetTitle());
}

int Dummy::poptest3()
{
   printf("poptest3\n");
   return 12;
}

void Dummy::poptest4(const char *ch)
{
   printf("poptest4 %s\n",ch);
}

void Dummy::URZoomAllXAsLast(TObject* objaxis)
{
	printf("URZoomAllXAsLast %tx\n",(intptr_t)objaxis);
}
