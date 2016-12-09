// ******* E.DLL  Stuff
#include <edll.h>         // user defined window messages used by E.DLL and prototypes

// ****** ERES.DLL  Stuff
#include <eres.h>         // bindings to ERES.DLL: Protypes and structures
#include <eresdlg.h>      // definitions of dialogbox constants in ERES.DLL


#ifndef  INCL_DONT_EXT_GLOB
extern GLOBDATA GlobData; // GlobData contains all the global data of the
                          // application. The address of this structure is
                          // passed into functions in ERES.DLL
#endif
