#ifndef DEFINES_H
#define DEFINES_H

enum CellsTypes{
    CF=0,
    CWH,
    CWV,
    CDH,
    CDV
};

CellsTypes Plane[5][10]={
{CWV,CWH,CWH,CWH,CWH,CWH,CWH,CWH,CDH,CWV},
{CWV,CF, CF, CF, CF, CF, CWV, CF, CF, CWV},
{CWV,CF, CF, CF, CF, CF, CDV , CF,  CF, CWV},
{CWV,CF, CF, CF, CF, CF, CWV, CF, CF, CWV},
{CWV,CWH,CWH,CWH,CWH,CWH,CWH,CWH,CWH,CWV}
};

#endif // DEFINES_H
