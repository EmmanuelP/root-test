#include "TObject.h"

#ifdef __cplusplus
extern "C" {
#endif

class Dummy {
	static void URZoomAllXAsLast(TObject* objaxis);
	static void poptest1(int a=5, int b = 56);
	static void poptest2(int a, int b, TObject* c);
	static void poptest2bis(TObject* c);
	static int  poptest3();
	static void poptest4(const char* ch);
};

#ifdef __cplusplus
}
#endif
