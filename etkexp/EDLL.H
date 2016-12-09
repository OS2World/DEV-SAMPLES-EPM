/*อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
บ What's it called : EDLL.H                                                  บ
บ                                                                            บ
บ What does it do  : Defines function prototypes of entry functions to E.DLL บ
บ                    Defines E window information and structures.            บ
บ                                                                            บ
บ Who and when     : Gennaro (Jerry) Cuomo                          9-88     บ
บ                                                                            บ
ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*/

/*อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
บ EPM version Length String.                                         GC 7-88 บ
ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*/

//#define EVERSION "5.50"         // version number asciiz string.
                                  // name of E dynalink library.

#define EDLLINCLUDE_INCLUDED

#define MAXFILENAME 260

/*อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
บ EPM related Window Messages                                        GC 7-88 บ
ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*/
/* Sent to pass a command to the interpreter (defcmd). */
#define EPM_EDIT_MSGID          WM_USER        +  0x500   // This evaluates to EPM_EDIT_MSGID = 5376
#define EPM_EDIT_COMMAND        EPM_EDIT_MSGID +  1
#define EPM_EDIT_RETCODE        EPM_EDIT_MSGID +  2
#define EPM_EDIT_SAYERROR       EPM_EDIT_MSGID +  3
#define EPM_EDIT_CURSORMOVE     EPM_EDIT_MSGID +  4
#define EPM_EDIT_CHANGEFONT     EPM_EDIT_MSGID +  5
#define EPM_EDIT_ACTIVEHWND     EPM_EDIT_MSGID +  6
#define EPM_EDIT_OPTION         EPM_EDIT_MSGID +  7
#define EPM_EDIT_ID             EPM_EDIT_MSGID +  8
#define EPM_EDIT_SHOW           EPM_EDIT_MSGID +  9
#define EPM_EDIT_NEWFILE        EPM_EDIT_MSGID +  10
#define EPM_EDIT_DESTROYNOTIFY  EPM_EDIT_MSGID +  11
#define EPM_EDIT_CONTROLTOGGLE  EPM_EDIT_MSGID +  12
#define EPM_EDIT_MOUSEMGR       EPM_EDIT_MSGID +  13
#define EPM_EDIT_RECORDKEY      EPM_EDIT_MSGID +  14
#define EPM_EDIT_PLAYKEY        EPM_EDIT_MSGID +  15
#define EPM_EDIT_ENDRECORDKEY   EPM_EDIT_MSGID +  16
#define EPM_EDIT_QUERYRECORDKEY EPM_EDIT_MSGID +  17
#define EPM_EDIT_CHAR           EPM_EDIT_MSGID +  18
#define EPM_EDIT_DESTROY        EPM_EDIT_MSGID +  19
#define EPM_EDIT_DESTROYRC      EPM_EDIT_MSGID +  20
#define EPM_EDIT_HELPNOTIFY     EPM_EDIT_MSGID +  21
#define EPM_EDIT_ASKTOQUIT      EPM_EDIT_MSGID +  22
#define EPM_EDIT_ASKTOCLOSE     EPM_EDIT_MSGID +  23
#define EPM_EDIT_ASKTODONE      EPM_EDIT_MSGID +  24
#define EPM_EDIT_ASKTOFAILED    EPM_EDIT_MSGID +  25

#define EPM_EDIT_UPDATE_EDITLIST_ITEM EPM_EDIT_MSGID + 26
#define EPM_EDIT_DOC2WIN              EPM_EDIT_MSGID + 27
#define EPM_EDIT_WIN2DOC              EPM_EDIT_MSGID + 28
#define EPM_EDIT_MINMAXFRAME          EPM_EDIT_MSGID + 29
#define EPM_EDIT_EXEC_PROC            EPM_EDIT_MSGID + 30
#define EPM_EDIT_EXEC_DYNALINK        EPM_EDIT_MSGID + 31
#define EPM_EDIT_TURN_OFF_HIGHLIGHT   EPM_EDIT_MSGID + 32
#define EPM_EDIT_SETTIMER             EPM_EDIT_MSGID + 33
#define EPM_EDIT_POSTEDMSG1           EPM_EDIT_MSGID + 34
#define EPM_EDIT_POSTEDMSG2           EPM_EDIT_MSGID + 35
#define EPM_EDIT_POSTEDMSG3           EPM_EDIT_MSGID + 36  // future use
#define EPM_EDIT_POSTDONE             EPM_EDIT_MSGID + 37
#define EPM_EDIT_COMMAND2             EPM_EDIT_MSGID + 38
#define EPM_EDIT_GETMEM               EPM_EDIT_MSGID + 39
#define EPM_EDIT_VERSION              EPM_EDIT_MSGID + 40
#define EPM_EDIT_MEMNOTIFY            EPM_EDIT_MSGID + 41
#define EPM_EDIT_EXEC_DYNALINK2       EPM_EDIT_MSGID + 42

#define EPM_EXTRAWINDOW_REFRESH       EPM_EDIT_MSGID + 50
#define EPM_EDIT_GETPROFILE           EPM_EDIT_MSGID + 51
#define EPM_EDIT_ACTIVATEFILEID       EPM_EDIT_MSGID + 52
#define EPM_EDIT_QUERY_HELP_INSTANCE  EPM_EDIT_MSGID + 53
#define EPM_FRAME_STATUSLINE          EPM_EDIT_MSGID + 55
#define EPM_FRAME_MESSAGELINE         EPM_EDIT_MSGID + 56
#define EPM_FRAME_ROTATEICONS         EPM_EDIT_MSGID + 57
#define EPM_DRAGDROP_DIRECTTEXTMINIP  EPM_EDIT_MSGID + 58
#define EPM_EDIT_WINDOWCREATED        EPM_EDIT_MSGID + 59
#define EPM_CREATE_DDE_LINK           EPM_EDIT_MSGID + 60
#define EPM_DRAGDROP_DRAGTARGET       EPM_EDIT_MSGID + 61
#define EPM_PRINT_RENDERPAGE          EPM_EDIT_MSGID + 62
#define EPM_PRINT_RENDERPAGERC        EPM_EDIT_MSGID + 63
#define EPM_QHELP_TABLE               EPM_EDIT_MSGID + 64
#define EPM_EDIT_CLIPBOARDCOPY        EPM_EDIT_MSGID + 65
#define EPM_EDIT_CLIPBOARDPASTE       EPM_EDIT_MSGID + 66
#define EPM_BROADCASTHELP             EPM_EDIT_MSGID + 67
#define EPM_GET_ERROR_MESSAGE         EPM_EDIT_MSGID + 68
#define EPM_SEND_MACROS_ERRORS        EPM_EDIT_MSGID + 69
#define EPM_QUERY_GLOBDATA            EPM_EDIT_MSGID + 70
#define EPM_IS_HELP_LOADED            EPM_EDIT_MSGID + 71
#define EPM_EDIT_TASKLIST             EPM_EDIT_MSGID + 72
#define EPM_EDIT_DELETEFILE           EPM_EDIT_MSGID + 73
#define EPM_DRAGDROP_RENDERCOMPLETE   EPM_EDIT_MSGID + 74
#define BUGFIX00143
#ifdef BUGFIX00143
   #define EPM_EDIT_SAYERROR2            EPM_EDIT_MSGID + 75
#endif
#define EPM_EDIT_LOGERROR             EPM_EDIT_MSGID + 76
#define EPM_EDIT_LOGAPPEND            EPM_EDIT_MSGID + 77

// Return codes sent by the EPM_EDIT_DESTROYRC message
#define EPM_RC_DESTROYOK       0
#define EPM_RC_DESTROYTIMEOUT  1
#define EPM_RC_DESTROYCANCEL   2
#define EPM_RC_DESTROYNOFREE   3

// Return codes sent by the EPM_EDIT_ASKTOQUITDONE message
#define ERES_CANCEL             0
#define ERES_DISCARD            1
#define ERES_SAVE               2

/*อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
บ Editor Styles                                                      GC 7-88 บ
ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*/
#define EDIT_STYLE_BROWSE               0x00000001L
#define EDIT_STYLE_ACTIVATEFOCUS        0x00000004L
#define EDIT_STYLE_STATUSLINE           0x00000008L
#define EDIT_STYLE_MESSAGELINE          0x00000010L
#define EDIT_STYLE_FILEICON             0x00000040L
#define EDIT_STYLE_MOVECURSORACTIVATE   0x00000080L
#define EDIT_STYLE_DISABLEOWNERAFFECTS  0x00000100L
#define EDIT_STYLE_ROTATEBUTTONS        0x00000400L
#define EDIT_STYLE_DMTITLEBAR           0x00000800L
#define EDIT_STYLE_CURSORON             0x00001000L
#define EDIT_STYLE_VSCROLL              0x00010000L
#define EDIT_STYLE_HSCROLL              0x00040000L
#define EDIT_STYLE_STATUSONTOP          0x00080000L
#define EDIT_STYLE_STREAMEDIT           0x00100000L
#define EDIT_STYLE_CUAMARKING           0x00200000L
#define EDIT_STYLE_TASKLISTENTRY        0x00400000L
#define EDIT_STYLE_USEDEFAULTARROWKEYS  0x00800000L
#define EDIT_STYLE_COMMANDMSGTOMACROS   0x01000000L
#define EDIT_STYLE_DISPLAYERRORRETRY    0x02000000L

/*อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
บ Editor Command Message Parameter Styles (mp2 of EPM_EDIT_COMMAND)  GC 7-88 บ
ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*/
#define COMMAND_FREESEL    0x00000001L
#define COMMAND_SYNC       0x00000004L
#define COMMAND_GETABLE    0x00000008L

/*อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
บ Editor Options (Used with EPM_EDIT_OPTION message)                 GC 7-88 บ
ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*/
#define OPTIONS_MARGINS          1
#define OPTIONS_LINE             2
#define OPTIONS_COLUMN           3
#define OPTIONS_INSERT           4
#define OPTIONS_AUTOSAVE         5
#define OPTIONS_NTABS            6
#define OPTIONS_NROWS            7
#define OPTIONS_NCOLS            8
#define OPTIONS_MODIFY           9
#define OPTIONS_TAB              10
#define OPTIONS_SEARCH           11
#define OPTIONS_GETTEXT          12
#define OPTIONS_NAME             13
#define OPTIONS_HWNDEXTRA        14
#define OPTIONS_HWNDEIOBJECT     15
#define OPTIONS_TEXTCOLOR        16
#define OPTIONS_RING             17
#define OPTIONS_FILEID           18
#define OPTIONS_QSELECTION       19


//     In EPM the field variables are:
//
  #define  AUTOSAVE_FIELD                      0L
  #define  COL_FIELD                           1L
  #define  CURSORX_FIELD                       2L
  #define  CURSORY_FIELD                       3L
  #define  KEYSET_FIELD                        4L
  #define  LAST_FIELD                          5L
  #define  LINE_FIELD                          6L
  #define  MARGINS_FIELD                       7L
  #define  MARKCOLOR_FIELD                     8L
  #define  MODIFY_FIELD                        9L
//#define  STATUSCOLOR_FIELD                  10L
  #define  TABS_FIELD                         11L
  #define  WINDOWHEIGHT_FIELD                 12L
  #define  WINDOWWIDTH_FIELD                  13L
  #define  WINDOWX_FIELD                      14L
  #define  WINDOWY_FIELD                      15L
  #define  FILENAME_FIELD                     16L
  #define  USERSTRING_FIELD                   17L
  #define  MOUSEX_FIELD                       18L
  #define  MOUSEY_FIELD                       19L
  #define  TEXTCOLOR_FIELD                    20L
  #define  VISIBLE_FIELD                      21L
//#define  MESSAGECOLOR_FIELD                 22L
  #define  DRAGCOLOR_FIELD                    23L
  #define  DRAGSTYLE_FIELD                    24L
  #define  FONTWIDTH_FIELD                    25L
  #define  FONTHEIGHT_FIELD                   26L
//#define  MESSAGELINE_FIELD                  27L
//#define  STATUSLINE_FIELD                   28L
  #define  LOCKHANDLE_FIELD                   29L
//#define  DRAGTHRESHHOLDX_FIELD              30L
//#define  DRAGTHRESHHOLDY_FIELD              31L
  #define  EA_AREA_FIELD                      32L
  #define  ATTRIBUTE_SUPPORT_LEVEL            33L
  #define  CURSOR_OFFSET                      34L
//#define  TABMODE_FIELD                      35L
  #define  AUTOSHELL_FIELD                    35L
  #define  TITLETEXT_FIELD                    36L
  #define  CURSOR_COLUMN                      37L
  #define  FONT_FIELD                         38L
  #define  SCROLLX_FIELD                      39L
  #define  SCROLLY_FIELD                      40L
  #define  CURSORYG_FIELD                     41L
  #define  LINEG_FIELD                        42L
  #define  WINDOWWIDTHG_FIELD                 43L
  #define  WINDOWHEIGHTG_FIELD                44L
  #define  READONLY_FIELD                     45L
  #define  CODEPAGE_FIELD                     46L

// Constants to be used with EtkProcessEditKey().
  #define ADJUST_BLOCK     2
  #define BACKTAB         10
  #define BACKTAB_WORD    11
  #define BEGIN_LINE      12
  #define BOTTOM          13
  #define COPY_MARK       21
  #define DELETE_CHAR     23
  #define DELETE_LINE     24
  #define DELETE_MARK     25
  #define DOWN            29
  #define END_LINE        36
  #define ERASE_END_LINE  40
  #define INSERT_LINE     62
  #define INSERT_TOGGLE   64
  #define JOIN            69
  #define LEFT            77
  #define MOVE_MARK       93
  #define NEXT_FILE       98
  #define OVERLAY_BLOCK  105
  #define PAGE_DOWN      107
  #define PAGE_UP        108
  #define PREVFILE_OP    118
  #define REFLOW         126
  #define REPEAT_FIND    129
  #define RIGHT          139
  #define RUBOUT         140
  #define SHIFT_LEFT     150
  #define SHIFT_RIGHT    151
  #define SPLIT          153
  #define TAB            162
  #define TAB_WORD       161
  #define TOP            162
  #define UNDO_LINE      163
  #define UNMARK         165
  #define UP             167

/*อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
บ Application structure passed to editor                             GC 7-88 บ
ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*/
typedef struct _EDITORINFO {
   HAB    hab;          // application anchor block
   HWND   hwndparent;   // handle to parent of edit window
   HWND   hwndowner;    // handle to owner of edit window
   PSWP   pswp;         // positioning of edit window
   PSZ    filename;     // file to be edited (with wildcard)
   PVOID  hEditPtr;     // handle to editor pointer icon.
   PVOID  hMarkPtr;     // handle to mark pointer icon.
   PVOID  hEditorIcon;  // editor ICON.
   ULONG  editorstyle;  // internal editor options
   ULONG  pmstyle;      // PM standard window styles (FCF_xxxx)
   USHORT font;         // TRUE = LARGE FONT,  FALSE = SMALL FONT
   PSZ    exfile;       // pre-compiled macro code file (EPM.EX)
   PSZ    topmkr;       // top and bottom of file marker
   PSZ    botmkr;       //
   USHORT editid;       // unique window id specified for edit wind
   PSZ    exsearchpath; // a set of paths to search for ex's files
   PSZ    exe_path;     // path where the application started
   HINI   hini;         // handle to an opened ini profile
} EDITORINFO;
typedef EDITORINFO far *PEDITORINFO;

/*อออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป
บ Function Prototypes                                                        บ
ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ*/
#define BUGFIX00174
#ifdef BUGFIX00174
   #define ETKENTRY _loadds _cdecl
#else
   #define ETKENTRY _loadds
#endif

#include <mainx.h>
#include <attr.h>

// Register/Create/Destroy Functions.
PSZ    ETKENTRY EtkRegister( HAB hab, ULONG class_style );
USHORT ETKENTRY EtkCreate( PEDITORINFO epm_p, PHWND hEwnd_p);
USHORT ETKENTRY EtkDestroy( HAB hab, HWND hwnd, HWND hwndef);
VOID   ETKENTRY EtkVersion( PSZ strbuffer );
VOID   ETKENTRY EtkGetProcAddrs(PFN * fptr);

// Window Procedure
PVOID  EXPENTRY EtkWndProc(HWND hwnd, USHORT message, MPARAM lParam1, MPARAM lParam2 );

// Special Access Functions.
USHORT ETKENTRY EtkRegisterFont( HWND  hwndClient, PSZ fontname, USHORT  fontsize, USHORT  fontsel);
USHORT ETKENTRY EtkRegisterFont2(HWND  hwndClient, PSZ fontname, USHORT  fontsize, USHORT  fontheight, USHORT  fontwidth, USHORT  fontsel);
SHORT  ETKENTRY EtkProcessEditKey( HWND  hwndClient, SHORT  key);
SHORT  ETKENTRY EtkQueryFileID( HWND hwndClient, PULONG  fileid);
SHORT  ETKENTRY EtkDeleteText( HWND  hwndClient, ULONG  thefileid, ULONG  y, ULONG  number_oflines);
SHORT  ETKENTRY EtkReplaceText( HWND  hwndClient, FIDType  repFileid, LINE_INDEX_FR  repLocLinenum, attrstring_ftpp  repLineString);
SHORT  ETKENTRY EtkInsertText( HWND  hwndClient, FIDType  insFileid, LINE_INDEX  insLocLinenum, attrstring_ftpp  insLineString);
SHORT  ETKENTRY EtkQueryText(HWND hwndClient, ULONG getFileid, ULONG getLocLinenum, PSZ  *getText, AttribRecType far * far * getAttrs, AttribRecType far * far * getALAttr);
SHORT  ETKENTRY EtkFindAttribute( HWND hwndClient, FIDType fileid, LINE_INDEX_FR TheLineNm, SHORT TheColm, SHORT TheOfst, AttribRecType ** TheAttribute, PBOOL Found);
SHORT  ETKENTRY EtkSetSelection( HWND  hwndClient, LINE_INDEX_G  firstline,  LINE_INDEX_G  lastline, USHORT firstcol, USHORT lastcol, SHORT  firstoff, SHORT  lastoff, USHORT marktype, FIDType fileid);
SHORT  ETKENTRY EtkQuerySelection(HWND hwndClient, PULONG firstline, PULONG lastline, PUSHORT firstcol, PUSHORT lastcol, PULONG markfileid, USHORT respectattributes, USHORT relative2file);
SHORT  ETKENTRY EtkQuerySelectionType(HWND hwndClient, PUSHORT marktype);
SHORT  ETKENTRY EtkSetFileField(HWND hwndClient, ULONG field, FIDType fileid,  PVOID indata);
SHORT  ETKENTRY EtkExecuteCommand(HWND hwndClient, PSZ command);
SHORT  ETKENTRY EtkQueryFileField( HWND hwndClient, ULONG field, ULONG fileid, PLONG retdata);
SHORT  ETKENTRY EtkQueryFileFieldString(HWND hwndClient, ULONG field, ULONG getFileid, PSZ getText);
SHORT  ETKENTRY EtkInvalidateText( HWND  hwndClient, LINE_INDEX_FR firstline, LINE_INDEX_FR lastline);
ULONG  ETKENTRY EtkInsertTextBuffer( HWND  hwndClient, LINE_INDEX_FR line, ULONG LenText, PSZ buffer);
ULONG  ETKENTRY EtkQueryTextBuffer( HWND  hwndClient, LINE_INDEX_FR startline, LINE_INDEX_FR lastline, ULONG TotalLen, PSZ buffer);
SHORT  ETKENTRY EtkAccessLowLevelData( HWND  hwndClient, FIDType  getFileid, PVOID far *  getSubLineArray);
