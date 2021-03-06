/* C Abstract Syntax Implementation generated by the BNF Converter. */
#include <stdio.h>
#include <stdlib.h>
#include "Absyn.h"


/********************   Program    ********************/
Prog make_Program(PrsList p1, InstrList p2)
{
    Prog tmp = (Prog) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Program!\n");
        exit(1);
    }
    tmp->kind = is_Program;
    tmp->u.program_.prslist_ = p1;
    tmp->u.program_.instrlist_ = p2;
    return tmp;
}/********************   PLNone    ********************/
PrsList make_PLNone()
{
    PrsList tmp = (PrsList) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating PLNone!\n");
        exit(1);
    }
    tmp->kind = is_PLNone;
    return tmp;
}
/********************   PLElem    ********************/
PrsList make_PLElem(Pragma p1, PrsList p2)
{
    PrsList tmp = (PrsList) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating PLElem!\n");
        exit(1);
    }
    tmp->kind = is_PLElem;
    tmp->u.plelem_.pragma_ = p1;
    tmp->u.plelem_.prslist_ = p2;
    return tmp;
}/********************   Alloc    ********************/
Pragma make_Alloc(S p1)
{
    Pragma tmp = (Pragma) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Alloc!\n");
        exit(1);
    }
    tmp->kind = is_Alloc;
    tmp->u.alloc_.s_ = p1;
    return tmp;
}
/********************   Set    ********************/
Pragma make_Set(R p1, V p2)
{
    Pragma tmp = (Pragma) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Set!\n");
        exit(1);
    }
    tmp->kind = is_Set;
    tmp->u.set_.r_ = p1;
    tmp->u.set_.v_ = p2;
    return tmp;
}/********************   ILNone    ********************/
InstrList make_ILNone()
{
    InstrList tmp = (InstrList) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ILNone!\n");
        exit(1);
    }
    tmp->kind = is_ILNone;
    return tmp;
}
/********************   ILElem    ********************/
InstrList make_ILElem(Instr p1, InstrList p2)
{
    InstrList tmp = (InstrList) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ILElem!\n");
        exit(1);
    }
    tmp->kind = is_ILElem;
    tmp->u.ilelem_.instr_ = p1;
    tmp->u.ilelem_.instrlist_ = p2;
    return tmp;
}/********************   Inc    ********************/
Instr make_Inc(R p1)
{
    Instr tmp = (Instr) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Inc!\n");
        exit(1);
    }
    tmp->kind = is_Inc;
    tmp->u.inc_.r_ = p1;
    return tmp;
}
/********************   Dec    ********************/
Instr make_Dec(R p1, A p2)
{
    Instr tmp = (Instr) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Dec!\n");
        exit(1);
    }
    tmp->kind = is_Dec;
    tmp->u.dec_.r_ = p1;
    tmp->u.dec_.a_ = p2;
    return tmp;
}/********************   Reg    ********************/
R make_Reg(Integer p1)
{
    R tmp = (R) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Reg!\n");
        exit(1);
    }
    tmp->kind = is_Reg;
    tmp->u.reg_.integer_ = p1;
    return tmp;
}/********************   Addr    ********************/
A make_Addr(Integer p1)
{
    A tmp = (A) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Addr!\n");
        exit(1);
    }
    tmp->kind = is_Addr;
    tmp->u.addr_.integer_ = p1;
    return tmp;
}/********************   Size    ********************/
S make_Size(Integer p1)
{
    S tmp = (S) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Size!\n");
        exit(1);
    }
    tmp->kind = is_Size;
    tmp->u.size_.integer_ = p1;
    return tmp;
}/********************   Value    ********************/
V make_Value(Integer p1)
{
    V tmp = (V) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating Value!\n");
        exit(1);
    }
    tmp->kind = is_Value;
    tmp->u.value_.integer_ = p1;
    return tmp;
}
