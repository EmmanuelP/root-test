#include <callbacks.h>

void poptest1(int a, int b)
{
   printf("poptest1 %d %d\n",a,b);
}

void poptest2(int a, int b, TObject *c)
{
   // Remark: the object c will not be asked for since it is the selected object
   printf("poptest2 %d %d\n",a,b);
   printf("histo : %lx\n",(Long_t)c);
   printf("title of the histogram : %s\n",((TH1F*)c)->GetTitle());
}

void poptest2bis(TObject *c)
{
   // Remark: the object c will not be asked for since it is the selected object
   printf("poptest2bis\n");
   printf("histo : %lx\n",(Long_t)c);
   printf("title of the histogram : %s\n",((TH1F*)c)->GetTitle());
}

int poptest3()
{
   printf("poptest3\n");
   return 12;
}

void poptest4(const char *ch)
{
   printf("poptest4 %s\n",ch);
}

void URZoomAllXAsLast(TObject* objaxis)
{
	printf("URZoomAllXAsLast %tx\n",(intptr_t)objaxis);
}
