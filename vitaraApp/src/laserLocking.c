#include <string.h>
#include <subRecord.h>
#include <epicsTypes.h>
#include <registryFunction.h>
#include <epicsExport.h>

static long LL16bitInit(subRecord *psub)
{
    return 0;  /* nothing todo */
}


static long LL16bitAmpl(subRecord *psub)
{
    short a = psub->a;

    psub->val = (double)a / 32767.;


    return 0;
    
}

static long LL16bitPhase(subRecord *psub)
{
    short a = psub->a;

    psub->val = (double)a / 32767. * 180.;

    return 0;
}

static long LL16bitVolt(subRecord *psub)      /* +-5 Volts */
{
    short a = psub->a;

    psub->val = (double)a / 32767. * 5.;

    return 0;
}

static long LL16bitBoolean(subRecord *psub)
{
    short a = psub->a;

    psub->val = a?1.:0.;

    return 0;
}



static long LL16bitInverseBoolean(subRecord *psub)
{
    short a = psub->a;

    psub->val = a?0.:1.;

    return 0;
}


static long LL16bitAmplVolt(subRecord *psub) /* 0...+5Volt */
{
    short a = psub->a;

    psub->val = (double)a / 32767. * 2.5 + 2.5;

    return 0;
}

static long LL16bit4Volt(subRecord *psub) /* 0 ... +4Volts */
{
    short a = psub->a;

    psub->val = (double)a / 32767. * 2. + 2.;

    return 0;
}



static long LL16bitFemto(subRecord *psub)
{
    short a = psub->a;
 
    psub->val = (double)a / 32767. / (2. * 2856.) * 1.E+9;

    return 0;
}

static long LLFemto32bit(subRecord *psub)
{
    static int init =1;
    double t;
    
    if(init) {
        init =0;
        psub->b = psub->a;
        return 0;
    }
    
    t = psub->a - psub->b;
    
    psub->b = psub->a;

    psub->val = t * 2. * 2856. * 8191. * 1.E-6;

    return 0;
}



epicsRegisterFunction(LL16bitInit);
epicsRegisterFunction(LL16bitAmpl);
epicsRegisterFunction(LL16bitPhase);
epicsRegisterFunction(LL16bitVolt);
epicsRegisterFunction(LL16bitBoolean);
epicsRegisterFunction(LL16bitInverseBoolean);
epicsRegisterFunction(LL16bitAmplVolt);
epicsRegisterFunction(LL16bit4Volt);
epicsRegisterFunction(LL16bitFemto);
epicsRegisterFunction(LLFemto32bit);

