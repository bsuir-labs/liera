#include "Datetime.h"



Datetime::Datetime()
{
    m_time = time(0) - rand() % 10 * 24 * 60 * 60;
}

Datetime::Datetime(int code)
{
    m_time = time(0);
}

Datetime::~Datetime()
{
}


void Datetime::set_current()
{
    m_time = time(0);
}

std::wstring Datetime::localstr() const
{
    tm localtm;
    localtime_s(&localtm, &m_time);

    char str[50];
    asctime_s(str, sizeof str, &localtm);
    std::string narrowStr(str);
    std::wstring result(narrowStr.begin(), narrowStr.end());
    if (result.back() == L'\n') result.pop_back();
    return result;
}


bool operator< (const Datetime& lhs, const Datetime& rhs) { return lhs.m_time < rhs.m_time; }
bool operator> (const Datetime& lhs, const Datetime& rhs) { return rhs < lhs; }
bool operator<=(const Datetime& lhs, const Datetime& rhs) { return !(lhs > rhs); }
bool operator>=(const Datetime& lhs, const Datetime& rhs) { return !(lhs < rhs); }