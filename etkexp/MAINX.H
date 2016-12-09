#ifndef MAINX_INCLUDED
   #define MAINX_INCLUDED

   typedef long LINE_INDEX_FR;  // file relative
   typedef long LINE_INDEX_G;   // global
   typedef long LINE_INDEX;     // arbitrary, or not yet categorized
   #define  FIDXType       SHORT
   #define  FIDType        LONG

   /* 4.103 for new buffer() opcode.  See BUFFER.C, PORTSVLD.C and SAVELINE.ASM.*/
   #define NOFORMAT        0     /* buffer is used for some unplanned purpose */
   #define APPENDCR        1     /* append ASCII 13 */
   #define APPENDLF        2     /* append ASCII 10 after the CR if any */
   #define APPENDNULL      4     /* append ASCII  0 after the CR-LF if any */
   #define TABCOMPRESS     8     /* tab-compress the line */
   #define STRIPSPACES    16     /* remove trailing spaces as usual in a save */
   #define FINALNULL      32     /* 4.112:  append final null at end of buffer*/

   #define LF_IS_NEWLINE  64     /* jbl 1/6/89:  when loading a disk file (not */
                                 /* a buffer), do we take a LF not after a CR  */
                                 /* as a newline, a la UNIX?                   */
   #define NO_EOF        128     /* LAM 91/12/16: option to omit EOF when      */
                                 /* saving a disk file.                        */

   /* MARK TYPE CONSTANTS  */
   #define LINEMARK    0
   #define CHARMARK    1
   #define BLOCKMARK   2
   #define CHARMARKG   3
   #define BLOCKMARKG  4
   #define NOMARK     -1

#endif
