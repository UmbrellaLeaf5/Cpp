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
{CWV,CWH,CWH,CWH,CWH,CWH,CWH,CWH,CWH,CWV},
{CWV,CF, CF, CF, CF, CF, CF, CF, CF, CWV},
{CWV,CF, CF, CF, CF, CF, CF, CF, CF, CWV},
{CWV,CF, CF, CF, CF, CF, CF, CF, CF, CWV},
{CWV,CWH,CWH,CWH,CWH,CWH,CWH,CWH,CWH,CWV}
};

#endif // DEFINES_H
