#ifndef ATTR_INCLUDED
   #define ATTR_INCLUDED
   typedef unsigned char   AttribClassType;
   typedef signed long     AttribValueType;
   #define INVALIDCLASS    ((AttribClassType)0)
   #define COLORCLASS      ((AttribClassType)1)
   #define MAXCOLOR        ((AttribValueType)255)
   #define FLOWCLASS       ((AttribClassType)2)
   #define JUSTIFYCLASS    ((AttribClassType)3)
   #define FONTCLASS       ((AttribClassType)16)
   #define BREAKCLASS      ((AttribClassType)17)
   #define LINEBREAKLEVEL  0x10
   #define COLMBREAKLEVEL  0x40
   #define STACKBREAKLEVEL 0x60
   #define DIVNBREAKLEVEL  0x80
   #define HSPACECLASS     ((AttribClassType)18)
   #define DIVISIONCLASS   ((AttribClassType)19)

   // pack the following structures on byte boundaries.
   #pragma pack(1)

   typedef struct AttribRecType {
     USHORT          Col;
     AttribClassType Class;
     UCHAR           IsPush;
     AttribValueType Value;
   } AttribRecType;

   #define MAXATTRBPL       255
   #define MAXATTRBSPACE    (MAXATTRBPL*sizeof(AttribRecType))

   // the following type is allocated by AllocNullAttrString() and freed
   // via FreeAttrString(); The Text will grow from s[0] toward the
   // end of the record and the attributes will positioned so that
   // the last one is flush with the end of the allocated space for
   // this structure.
   typedef struct _attrstring_t {
      AttribRecType *ALAttr;
      AttribRecType *Attrs;
      PCHAR SelfPtr;      // this is a redundant field that points to itself.
                          //   This field is automatically initialized when
                          //   when the attrstring is created.
                          // procedures that receive attrstring's that
                          //   may have been created before the previous
                          //   heap compact should check this field to
                          //   insure that it still points to the Text
                          //   field.  They can do this by using the
                          //   ATTRSTRING_REVALIDATE() macro.  This is
                          //   necessary since the Attrs and ALAttr fields
                          //   become invalid when the heap compacter moves
                          //   the attrstring.
      SHORT  TextLen;
      CHAR   Text[1];
   } attrstring_t;
   typedef attrstring_t   *attrstring_ftp;
   typedef attrstring_ftp *attrstring_ftpp;
   #define access_as(a)   (*((attrstring_ftpp)(a)))
   #define ATTRSTRING_REVALIDATE(ina) \
          { \
             attrstring_ftp as = *(ina); \
             if (((PVOID)&(as->SelfPtr))!=(PVOID)as->SelfPtr) { \
                as->Attrs  = (AttribRecType*)((PCHAR)&(as->SelfPtr) + ((PCHAR)as->Attrs  - as->SelfPtr)); \
                as->ALAttr = (AttribRecType*)((PCHAR)&(as->SelfPtr) + ((PCHAR)as->ALAttr - as->SelfPtr)); \
                as->SelfPtr= (PCHAR)&(as->SelfPtr); \
             } /* endif */ \
          }

   // return to the type of packing specified on the command line.
   #pragma pack()
#endif

