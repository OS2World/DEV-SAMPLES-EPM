/*อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
บ What's it called: ERES.H                                                               บ
บ                                                                                        บ
บ What does it do : bindings to ERES.DLL: Protypes and structures                        บ
บ                                                                                        บ
บ Who and When    : Gennaro A. Cuomo                              10 -88                 บ
บ                                                                                        บ
ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*/

#if OS2VERSION == 20
   #define MSG ULONG
#else
   #define MSG USHORT
#endif

/*อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
บ The following are Structures used to Communicated with ERES.DLL    GC 9-89 บ
ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*/
#define RETRIEVENUM  25               // number of items in a retrieve list
#define MAXFILENAME  260
#define MAXRETRIEVESTR 256
/*ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ
ณ List structure used to store various types of retrieve box entries         ณ
ภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ*/
typedef struct LISTDLG_TYPE {
   SHORT       top,bot;               /* index of top and bot of list    */
   SHORT       last;                  /* last legal index                */
                                      /* pointers to retrievable list    */
   UCHAR       retrieve[RETRIEVENUM][MAXRETRIEVESTR];
} LISTDLG;
typedef LISTDLG  *PLISTDLG;

/*ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ
ณ Shared Data Between EPM and ERES.                                          ณ
ภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ*/
typedef struct EPMRES_TYPE {
   HWND    hwndAppFrame;            // application window frame  handle
   HWND    hwndAppClient;           // application window client handle
   HWND    hwndActiveEdit;          // current edit window handle
   HWND    hwndSearchReplaceBox;    // search replace dialog handle, modeless
   CHAR    exfilename[MAXFILENAME]; // pointer to main ex file (configure option)
   LISTDLG cmd;                     // command line structure
   LISTDLG msgbox;                  // message box dialog structure
   LISTDLG open1;                   // message box dialog structure
   BOOL    skipopen1;               // if set file list dialog will be displayed first.
   CHAR    IniApplicationName[20];  // used to save and retrieve 'ini' data
   CHAR    searchpath[MAXFILENAME]; // path used to search for profile data
   HINI    hini;                    // handle to an opened INI profile
} EPMRES;
typedef EPMRES  *PEPMRES;        // pointer to the EPM resource shared structure


//E Window Linked List Node
typedef struct _EWINDOWLLNODE {
   HWND                    hwnd;  //handle of the edit window
   struct _EWINDOWLLNODE   *next;
} EWINDOWLLNODE;
typedef EWINDOWLLNODE *PEWINDOWLLNODE;
/*ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ
ณ Main Info structure                                                        ณ
ภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ*/
typedef struct {
    HAB         hAB;                 // application anchor block
    EPMRES      eres;                // pointer to shared buffer w ERES.DL
    HMODULE     eresModule;          // module handle of ERES.DLL
    PFNWP       DefFrameProc;        // address of the default frame proc
    PSZ         ShrMsgBuff;          // pointer to EPM's shared msg buffer
    SWP         swp;                 // edit window rectangle
    USHORT      stagcount;           // stagger window count
    CHAR        LastCmdLine[256];    // last command line used2 open ewnd
    CHAR        EPMClass[32];        // EPM window class name
    CHAR        AllowMultProcesses;
    HWND        hwndHelpInstance;    // hooks for info pres facil
    HELPINIT    hmiHelpData;
    BOOL        CountOnlyVisibleWindows; // flag for ERESCountEWindows
    USHORT      ApplicationID;
    CHAR        ApplicationName[20];     // Name of application */
    ULONG       EditWindowListStyle;
    CHAR        ExePath[MAXFILENAME+1];
    PSZ         ERES_NAME;           //
    PSZ         EDLL_NAME;
    ULONG       ProfileFlags;
    ULONG       ShellInterface;
    ULONG       SaveFileType;
    // The following are functions that can be found in the E???.DLL
    // These functions are used to create, minipulate, and destroy edit windows.
    VOID       (ETKENTRY *EpmEditVersion)(PSZ);
    USHORT     (ETKENTRY *EpmCreateEditWindow)(PEDITORINFO, PHWND);
    USHORT     (ETKENTRY *EpmDestroyEditWindow)( HAB, HWND, HWND);
    PSZ        (ETKENTRY *EpmRegisterEditWindow)(HAB, ULONG);
    USHORT     CodePage;
    BOOL       onDBCS;
    PHELPTABLE HelpTable;
    BOOL       HelpHookReleased;
    LONG       (*pfnNear32)(LONG pfntarget, SHORT parmcount, ...);
    BOOL       ThunkDllLoaded;
    ULONG      pfnDos32LoadModule;
    ULONG      pfnDos32GetProcAddr;
    ULONG      pfnDos32FreeModule;
    HMODULE    ThunkModule;
    HMODULE    PmctlsModule;
    BOOL       ThunkModuleLoaded;
    HWND       (EXPENTRY *WinFileDlg)(HWND, HWND, PVOID);
    BOOL       (EXPENTRY *WinFreeFileDlgList)(PVOID);
    BOOL       (EXPENTRY *InputHook)(HAB, PQMSG, USHORT);
    PEWINDOWLLNODE EWindowLL;
    HWND       hwndmem;
} GLOBDATA;
typedef GLOBDATA *PGLOBDATA;

/* Constants used to set the EditWindowStyle bits */
#define EWindow_List_Window_Middle      1
#define EWindow_List_Window_Corner      2
#define EWindow_List_System_Menu_Item   4
#define EWindow_List_No_Scrollbars      8
#define EWindow_List_No_Sysmenu         16
#define EWindow_List_No_Minmax          32
#define EWindow_List_PWB                64


  /*ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ
  ณQuitbox information structure used for the quit box dialog ณ
  ภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ*/

typedef struct _QUITBOXINFO {
   PSZ     filename;
   PSZ     dlgtitle;
   PSZ     dlgmessage;
   HWND    hwndApp;
   HWND    hwndHelpInstance;
   } QUITBOXINFO;

typedef QUITBOXINFO  *PQUITBOXINFO;

  /*ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ
  ณListbox information structure used for the listbox dialog ณ
  ภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ*/

typedef struct _LISTBOXINFO {
   PSZ    title;                 /* pointer to list box title     */
   SHORT  flags;
   SHORT  listlen;               /* total length of items in list */
   PSZ    list;                  /* pointer to list of items      */
   SHORT  nb;                    /* number of buttons             */
   PSZ    b1,b2,b3,b4,b5,b6,b7;  /* button text                   */
   ULONG  x,y;                   /* x,y coordinate of list box    */
   ULONG  row,col;
   PSZ    inputdata;
} LISTBOXINFO;
typedef LISTBOXINFO *PLISTBOXINFO;
#define LIST_FLAG_DISPLAYBELOWPOINT 1
#define LIST_FLAG_POINTSTODESKTOP   2
#define LIST_FLAG_DETAILSBUTTON     4
#define LIST_FLAG_MODELESS          8

  /*ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ
  ณEntrybox information structure used for the entrybox dialog box ณ
  ภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ*/

typedef struct _ENTRYBOXINFO {
   PSZ    title;                 /* pointer to list of items      */
   ULONG  x,y;                   /* x,y coordinate of list box    */
   ULONG  cols;
   ULONG  max;
   PSZ    entrytext;
   PSZ    b1,b2,b3,b4;
   USHORT nb;
   PSZ    entry;
} ENTRYBOXINFO;
typedef ENTRYBOXINFO  *PENTRYBOXINFO;

typedef struct _GETPROFILEBOXINFO {
   PSZ  IniName;
   PSZ  ApplicationName;
   HWND hwndHelpInstance;
} GETPROFILEBOXINFO;
typedef GETPROFILEBOXINFO *PGETPROFILEBOXINFO;

typedef struct _OPENBOXINFO {
   SHORT   mode;
   HINI    hini;
   HWND    hwndHelp;
   HWND    hwndHelpInstance;
   #define BUGFIX00130
   #ifdef BUGFIX00130
      UCHAR   files[MAXFILENAME*2];
   #else
      UCHAR   files[MAXFILENAME];
   #endif
   UCHAR   reserved[50];
} OPENBOXINFO;
typedef OPENBOXINFO *POPENBOXINFO;

typedef struct _OPEN1BOXINFO {
   SHORT    mode;
   PLISTDLG list;
   BOOL     addtomsglist;
   HINI     hini;
   HWND     hwndHelp;
   HWND     hwndHelpInstance;
   #ifdef BUGFIX00130
      UCHAR    files[MAXFILENAME*2];
   #else
      UCHAR    files[MAXFILENAME];
   #endif
   UCHAR    reserved[50];
   HWND     hwndEdit;
   HWND     hwndShell;
} OPEN1BOXINFO;
typedef OPEN1BOXINFO *POPEN1BOXINFO;

#define  OPEN_MODE 0
#define  EDIT_MODE 1
#define  GET_MODE  2
#define  EPMSHELL_OPEN_MODE 3

typedef struct _COMMANDBOXINFO {
  HINI     hini;
  PSZ      cmdtext;
  PLISTDLG list;
  PSZ      command;
  HWND     hwndApp;
  HWND     hwndHelpInstance;
  HWND     hwndEdit;
  BOOL     onDBCS;
} COMMANDBOXINFO;
typedef COMMANDBOXINFO *PCOMMANDBOXINFO;

typedef struct _ABOUTBOXINFO {
  ULONG Size;
  PSZ   EditorVersion;
  PSZ   MacroVersion;
} ABOUTBOXINFO;
typedef ABOUTBOXINFO *PABOUTBOXINFO;


typedef struct _MSGBOXINFO {
   HWND     hwndApp;
   PSZ      msgtext;
   PLISTDLG list;
   HINI     hini;
   HWND     hwndEdit;
   BOOL     onDBCS;
} MSGBOXINFO;
typedef MSGBOXINFO *PMSGBOXINFO;

typedef struct _FINDBOXINFO {
   HINI    hini;
   PSZ     findtext;
   HWND    hwndApp;
   HWND    hwndHelpInstance;
   BOOL    onDBCS;
} FINDBOXINFO;
typedef FINDBOXINFO *PFINDBOXINFO;

typedef struct _CONFIGBOXINFO {
   HINI    hini;
   HWND    hwndApp;
   HWND    hwndEdit;
   ULONG   type;
   HWND    hwndHelpInstance;
   USHORT  *options;
   HWND    owner;
} CONFIGBOXINFO;
typedef CONFIGBOXINFO *PCONFIGBOXINFO;
#define CONFIGDLG_SAVE    WM_USER + 1
#define POPHELPPANEL      WM_USER + 2
#define SHOWDEFAULTS      WM_USER + 3
#define GIVE_NB_FOCUS     WM_USER + 4
#define GIVE_PB_FOCUS     WM_USER + 5
#define SHOW_DLG          WM_USER + 6
#define GETTING_FOCUS     WM_USER + 7
#define LOSING_FOCUS      WM_USER + 8
#define TURN_NB_PAGE      WM_USER + 9

typedef struct _UNDOBOXINFO {
   HINI   hini;
   HWND   hwndApp;
   HWND   hwndEdit;
   HWND   hwndHelpInstance;
} UNDOBOXINFO;
typedef UNDOBOXINFO *PUNDOBOXINFO;

typedef struct _PRINTBOXINFO {
   HINI   hini;
   HWND   hwndApp;
   HWND   hwndEdit;
   HWND   hwndHelpInstance;
   ULONG  Flags;
} PRINTBOXINFO;
typedef PRINTBOXINFO *PPRINTBOXINFO;

typedef struct _AVIOFONTBOXINFO {
   USHORT cur_height;
   USHORT cur_width;
   HINI   hini;
   HWND   hwndApp;
   HWND   hwndEdit;
   USHORT type;
   HWND   hwndHelpInstance;
} AVIOFONTBOXINFO;
typedef AVIOFONTBOXINFO *PAVIOFONTBOXINFO;
#define AFONT_DIALOG  1
#define AFONT_PAGE    2
#define AFONT_SAVE    WM_USER +1

typedef struct _ENTERKEYSBOXINFO {
   HWND hwndEdit;
   HWND hwndApp;
   HWND hwndHelpInstance;
   HWND owner;
} ENTERKEYSBOXINFO;
typedef ENTERKEYSBOXINFO *PENTERKEYSBOXINFO;

#define ENTERKEYS_SAVE WM_USER +1


typedef struct _RINGBOXINFO {
   HINI   hini;
   HWND   hwndApp;
   HWND   hwndEdit;
   HWND   hwndHelpInstance;
} RINGBOXINFO;
typedef RINGBOXINFO *PRINGBOXINFO;

typedef struct _FONTBOXINFO {
   HINI   hini;
   PSZ    EDLL_NAME;
   HWND   hwndApp;
   HWND   hwndEdit;
   HWND   hwndHelpInstance;
   ULONG  type;
   USHORT HelpPanel;
   UCHAR  Defaults[MAXFILENAME];
   HWND   owner;
} FONTBOXINFO;
typedef FONTBOXINFO *PFONTBOXINFO;
#define FONTDLG_DIALOG 1
#define FONTDLG_PAGE   2
#define FONTDLG_SAVE WM_USER +1

typedef struct _EPMCONFIGBOXINFO {
  HINI  hini;
  HWND  hwndApp;
  ULONG ProfileFlags;
  HWND  hwndHelpInstance;
} EPMCONFIGBOXINFO;
typedef EPMCONFIGBOXINFO *PEPMCONFIGBOXINFO;

typedef struct _INTERFACEBOXINFO {
  HINI  hini;
  PSZ  *InterfaceNames;
  ULONG Num_of_interfaces;
  ULONG Current_Interface;
  ULONG Interface_Selected;
  HWND  hwndApp;
  HWND  hwndHelpInstance;
} INTERFACEBOXINFO;
typedef INTERFACEBOXINFO *PINTERFACEBOXINFO;

typedef struct _FILETYPEBOXINFO {
  HINI   hini;
  HWND   hwndApp;
  USHORT TypeSelected;
} FILETYPEBOXINFO;
typedef FILETYPEBOXINFO *PFILETYPEBOXINFO;

typedef struct _NBBOXINFO {
  HWND  hwndApp;
  HWND  hwndEdit;
  HINI  hini;
  HWND  hwndHelpInstance;
  ULONG pages;
  USHORT *options;
} NBBOXINFO;
typedef NBBOXINFO *PNBBOXINFO;


#define CONFIGDLG_FULL       1
#define CONFIGDLG_TABS       2
#define CONFIGDLG_COLORS     4
#define CONFIGDLG_MARGINS    8
#define CONFIGDLG_PATHS      16
#define CONFIGDLG_AUTOSAVE   32

/*ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ
ณ Other Misso structures                                                     ณ
ณ                                                                            ณ
ภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ*/
typedef struct _WINDOWSIZE {
                 // x and y must be signed values
   SHORT  x;     // horizontal origin can be to the right of position 0
   SHORT  y;     // vertical origin can be below position 0
   USHORT  cx;
   USHORT  cy;
} WINDOWSIZE;

typedef WINDOWSIZE *PWINDOWSIZE;

/*ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ
ณ Structure used to save window's to an INI profile.                         ณ
ภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ*/
typedef struct _PROFILEPOS {
   ULONG        chksum;
   WINDOWSIZE   ws;
} PROFILEPOS;
typedef PROFILEPOS *PPROFILEPOS;

/*อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
บ EPM custom Winodw Messages:                                       GC. 1-89 บ
บ                                                                            บ
บ Note:  When these values are changed REMEMBER to change the editor macros  บ
บ        especially STDCTRLS.E.    STDCTRLS.E has hard coded message numbers บ
บ        that correspond to the constants below.                             บ
ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*/
#define   EPM_MSGID            WM_USER        +  0x400
#define   EPM_BOOK_ID          EPM_MSGID      +  1
#define   EPM_OPEN_EDITWINDOW  EPM_MSGID      +  2
#define   EPM_DLGBOXACTIVATE   EPM_MSGID      +  3
#define   EPM_POPCMDLINE       EPM_MSGID      +  4
#define   EPM_POPMSGBOX        EPM_MSGID      +  5
#define   EPM_POPOPENDLG       EPM_MSGID      +  6
#define   EPM_POPFINDDLG       EPM_MSGID      +  7
#define   EPM_POPCHANGEDLG     EPM_MSGID      +  8
#define   EPM_POPCONFIGDLG     EPM_MSGID      +  9
#define   EPM_POPFONTDLG       EPM_MSGID      +  10
#define   EPM_POPUNDODLG       EPM_MSGID      +  11
#define   EPM_POPHELPBROWSER   EPM_MSGID      +  12
#define   EPM_POPHELPMGRPANEL  EPM_MSGID      +  13
#define   EPM_SAVE_LISTS       EPM_MSGID      +  15
#define   EPM_RETRIEVE_LISTS   EPM_MSGID      +  16
#define   EPM_QUIT             EPM_MSGID      +  17
#define   EPM_POPAVIOFONTDLG   EPM_MSGID      +  18
#define   EPM_QHELPINSTANCE    EPM_MSGID      +  19
#define   EPM_MODELESS_DIALOG_DESTROY EPM_MSGID      +  20
#define   EPM_POPRINGDLG       EPM_MSGID      +  21
#define   EPM_POP_BOOK_ICON    EPM_MSGID      +  22
#define   EPM_POPSAVEASDLG     EPM_MSGID      +  23
#define   EPM_POPPRINTDLG      EPM_MSGID      +  24
#define   EPM_REGPAGEPROC      EPM_MSGID      +  25
#define   EPM_POPABOUTBOX      EPM_MSGID      +  26

#define NUM_OF_EA_TYPES   9

/*อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
บ Application Window Definitions                                    GC.10-88 บ
ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*/
#define   ID_EPMWND            10
#define   ID_EPMMARKPTR        11
#define   ID_EPMICON           12

/*อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
บ Misc Constants shared with EXE                                    GC.10-88 บ
ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*/
#define   MAXCMDLINE              512
#define   CLASSLEN                32
#define   MAXLEN                  260

#define   MAX_E_WINDOWS           32

#define   MAXLEN                  260
#define   STAGGER                 4

/*อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
บ System Menu Definitions      200-299                              GC.10-88 บ
ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*/
#define   MAXITEMSIZE          80

#define   IDM_COMMANDS        200
#define   IDM_EDITFILE        201
#define   IDM_MSGBOX          202
#define   IDM_EDITWNDS        203
#define   IDM_HELP            206
#define   IDM_SAVEAS          207
#define   IDM_ABOUTBOX        208

//******* USED FOR ERESReparentEwindows ***************** */
#define   E_ICONS               1
#define   E_WINDOWS             2


/*อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
บ Function Prototypes.                                               GC 4-88 บ
ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*/

/*ฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฟ
ณ Dynalink function Prototypes.                                              ณ
ภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤ*/

//******************* Dialog Box Related Functions ***************************
USHORT  EXPENTRY  ERESaddtomsglist( PLISTDLG plst, PSZ text, BOOL AllowDuplicate);
VOID    EXPENTRY  ERESCenterWindow( HINI hini, USHORT dlgid, HWND hwnd, BOOL move );
VOID    EXPENTRY  ERESSaveDlgPosition(HINI hini, USHORT dlgid, HWND hwnd );
MRESULT EXPENTRY  ERESOpen1DlgProc( HWND hDlg, USHORT msg, MPARAM mp1, MPARAM mp2 ) ;
MRESULT EXPENTRY  ERESOpenDlgProc ( HWND hDlg, USHORT msg, MPARAM mp1, MPARAM mp2 ) ;
MRESULT EXPENTRY  ERESCommandDlgProc( HWND hDlg, USHORT msg, MPARAM mp1, MPARAM mp2 );
MRESULT EXPENTRY  ERESMsgBoxDlgProc( HWND hDlg, USHORT msg, MPARAM mp1, MPARAM mp2 );
MRESULT EXPENTRY  ERESFindChangeDlgProc( HWND hDlg, USHORT msg, MPARAM mp1, MPARAM mp2 );
MRESULT EXPENTRY  ERESConfigDlgProc( HWND hDlg, USHORT msg, MPARAM mp1, MPARAM mp2 );
MRESULT EXPENTRY  ERESFontDlgProc( HWND hDlg, USHORT msg, MPARAM mp1, MPARAM mp2 );
MRESULT EXPENTRY  ERESAvioFontDlgProc( HWND hDlg, USHORT msg, MPARAM mp1, MPARAM mp2 );
MRESULT EXPENTRY  ERESRingDlgProc( HWND hDlg, USHORT msg, MPARAM mp1, MPARAM mp2 );
MRESULT EXPENTRY  ERESUndoDlgProc( HWND hDlg, USHORT msg, MPARAM mp1, MPARAM mp2 );
MRESULT EXPENTRY  ERESQuitDlgProc( HWND, USHORT, MPARAM, MPARAM);
BOOL    EXPENTRY  ERESDlgBoxValid(GLOBDATA *);
VOID    EXPENTRY  LISTBOX(HWND,USHORT, USHORT, USHORT, USHORT, USHORT, SHORT, PSZ, PSZ, PSZ, PSZ, PSZ, PSZ, PSZ, PSZ, SHORT, PSZ, PSZ);
VOID    EXPENTRY  ENTRYBOX(HWND hwnd,PSZ title,USHORT  x, USHORT y,USHORT cols,USHORT max, PSZ entrytext,USHORT nb, PSZ  b1, PSZ b2, PSZ b3, PSZ b4,PSZ entry);
MRESULT EXPENTRY  ERESGetProfilePathDlgProc( HWND hwndDlg, USHORT msg, MPARAM mp1, MPARAM mp2);
MRESULT EXPENTRY  ERESEPMConfigDlgProc(HWND, USHORT, MPARAM, MPARAM);
MRESULT EXPENTRY  ERESFileTypeDlgProc(HWND, USHORT, MPARAM, MPARAM);
MRESULT EXPENTRY  ERESInterfaceDlgProc(HWND, USHORT, MPARAM, MPARAM);
MRESULT EXPENTRY  ERESFontSubClassWndProc(HWND, USHORT, MPARAM, MPARAM);


//**************** Miscellaneous Functions ************************************
MRESULT EXPENTRY ERESCommonWndProc(HWND, USHORT, MPARAM, MPARAM);
VOID    EXPENTRY ERESSaveLists(GLOBDATA *);
VOID    EXPENTRY ERESRetrieveLists(GLOBDATA *);
void    EXPENTRY ERESHelp(ULONG, GLOBDATA *);
VOID    EXPENTRY ERESProcessCommands( MPARAM, MPARAM, MPARAM, GLOBDATA *);
HWND    EXPENTRY ERESOpenEditWindow( PSZ , GLOBDATA *, USHORT, ULONG);
USHORT  EXPENTRY ERESCountEWindows(GLOBDATA *);
BOOL    EXPENTRY ERESIsAnEditWin(HWND, GLOBDATA*);
BOOL    EXPENTRY ERESEwindowValid(GLOBDATA *);
VOID    EXPENTRY ERESEditWindowList(GLOBDATA *);
USHORT  EXPENTRY ERESShutDown(GLOBDATA *);
VOID    EXPENTRY ERESInitEResStruct(HWND, GLOBDATA *);
VOID    EXPENTRY ERESInitEresGlob(GLOBDATA *, PFN *);
USHORT  EXPENTRY ERESCheckVersion(GLOBDATA *, PSZ);
VOID    EXPENTRY ERESResolveIniPath(PSZ, PSZ, PSZ, HWND, HAB );
VOID    EXPENTRY ERESFlushError(HAB);
VOID    EXPENTRY ERESReparentWindows(HWND NewParent, USHORT Flags, PGLOBDATA GlobData);
VOID    ERESProportionWindow(HWND, HWND, PSWP, PGLOBDATA);
VOID    EXPENTRY ERESCascadeTileWindow( USHORT type, PGLOBDATA GlobData);
MRESULT EXPENTRY ERESNotebookDlgProc(HWND, USHORT, MPARAM, MPARAM);
MRESULT EXPENTRY ERESEnterKeysDlgProc(HWND, USHORT, MPARAM, MPARAM);
USHORT  EXPENTRY ERESSaveas(HWND hwndowner, HWND hwndshell, PSZ buffer, PSZ type );
MRESULT EXPENTRY ERESPrintDlgProc(HWND hwnd,USHORT usMsg,MPARAM mp1,MPARAM mp2);
MRESULT EXPENTRY DDEWndProc(HWND hwnd, USHORT msg, MPARAM mp1, MPARAM mp2);

VOID    ERESHelpBrowser(PSZ, GLOBDATA *);
VOID    ERESShowHelp(GLOBDATA *);
SHORT   ERESUpListEditWin(SHORT, GLOBDATA *);
VOID    ERESErrorHandler(MPARAM, MPARAM, GLOBDATA *);
VOID    ERESParseCmdline(INT , CHAR **, PSZ, GLOBDATA *);
VOID    ERESRegisterEtkFunctions(PFN, USHORT);
VOID    ERESSaveDefaultWindowSize(GLOBDATA *);
USHORT  ERESRetrieveDefaultWindowSize(GLOBDATA *, PWINDOWSIZE);
VOID    ERESFindDataFile(GLOBDATA *, PSZ , PSZ , PSZ );
MRESULT EXPENTRY SetProfilePathDlgProc(HWND, USHORT, MPARAM, MPARAM);
HINI    ERESGetProfileHandle(PEPMRES);
PVOID   EXPENTRY ERESMalloc(USHORT);
VOID    EXPENTRY ERESFree(PVOID);
HAB     EXPENTRY ERESTheHAB(VOID);
PSZ     ERESmsg( USHORT, PSZ);
CHAR    ERESGetBootDriveLetter();



