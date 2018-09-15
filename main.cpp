#include <QCoreApplication>
#include <QDebug>
#include <QList>

#include <vector>

#define s 0x12345678
#define MAX(x,y) ( ((x) > (y)) ? (x) : (y) )//最大值
#define MIN(x,y) ( ((x) < (y)) ? (x) : (y) )//最小值
typedef quint32 word;
typedef quint8  byte;
#define LLO(xxx) ((byte) ((word)(xxx) & 255)) //最低位
#define HLO(xxx) ((byte) ((word)(xxx) >> 8))  //次低位
#define LHI(xxx) ((byte) ((word)(xxx) >> 16)) //次高位
#define HHI(xxx) ((byte) ((word)(xxx) >> 24)) //最高位


int main()
{
    QList<byte> value;
    value<<HHI(s)<<LHI(s)<<HLO(s)<<LLO(s);

    word z;
    z=HLO(s)<<24|HHI(s)<<16|LLO(s)<<8|LHI(s);

    qDebug()<<"原始值：0x12345678=="<<s;

    qDebug()<<"0x12=="<<value.at(0)<<"0x34=="<<value.at(1)<<"0x56=="<<value.at(2)<<"0x78=="<<value.at(3);

    qDebug("最高8位和次高8位最大值：0x%x(%d)",MAX(HHI(s),LHI(s)),MAX(HHI(s),LHI(s)));
    qDebug("次低8位和最低8位最小值：0x%x(%d)",MIN(HLO(s),LLO(s)),MIN(HLO(s),LLO(s)));

    qDebug("重新组合后数值：0x%x(%d)",z,z);
    std::sort(value.begin(),value.end(),std::less<byte>());//升序
    qDebug()<<value;
    std::sort(value.begin(),value.end(),std::greater<byte>());//降序
    qDebug()<<value;
}
