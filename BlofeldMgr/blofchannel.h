#ifndef BLOFCHANNEL_H
#define BLOFCHANNEL_H

#include "instrument.h"
#include "propriete.h"
#include "BlofeldMgr/parametre.h"
#include "Messaging/dumpmulti.h"

class BlofChannel
{
private:
    int _channelNum;
    Instrument _instrument;
    MixPropParams _mixPars;
    QVector<Parametre> _multiPars;

public:
    BlofChannel();
    BlofChannel(const BlofChannel * other);
    BlofChannel(const int ch);

    void Regenerate(){_instrument.regenerate();}
    const Instrument * getInstrument()const{return &_instrument;}
    Instrument * editInstrument();
    const Propriete * getProprieteChannel() const;

    const Parametre * getParametre(int pid) const{return _instrument.getParametre(pid);}
    Parametre * editParametre(int pid){return _instrument.editParametre(pid);}

    void setProprieteChannel(const Propriete * p);

    void setChannel(const BlofChannel *);
    void setInstrument(const Instrument);
    void setParamContrainte(int pid,const Contrainte * c);
    void setParamValue(int pid,int v);

    void MixParametre(const Parametre * par);

    MixPropParams *editMixPars(){return  &_mixPars;}
    const MixPropParams *getMixPars()const{return  &_mixPars;}
    const QVector<Parametre> *getMultiPars()const{return  &_multiPars;}

    void setMixPars(const MixPropParams *mpars){ _mixPars= *mpars;}
    void setMultiPars(const QVector<Parametre> *pars);
    void PrepareForProp();
    void setPropriete(int id, bool state);

private:

    void setParametreValue(int pid, int value)
    {
        _multiPars[pid].setValue(value);
    }
    int getParametreValue(int pid)
    {
        return _multiPars[pid].getValue();
    }

    friend QDataStream & operator << (QDataStream &, const BlofChannel &);
    friend QDataStream & operator >> (QDataStream &, BlofChannel &);

    friend class DumpMulti;

};
Q_DECLARE_METATYPE(BlofChannel)
QDataStream & operator << (QDataStream & out, const BlofChannel & Valeur);
QDataStream & operator >> (QDataStream & in, BlofChannel & Valeur);

#endif // BLOFCHANNEL_H
