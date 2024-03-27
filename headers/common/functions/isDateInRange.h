#ifndef ISDATEINRANGE
#define ISDATEINRANGE
// (старт периода, дата которую сравниваем, конец периода)
bool isDateInRange(Date start, Date current, Date end)
{
    if ((start.year < current.year && current.year < end.year) ||
        (start.year == current.year && ((start.month < current.month) || (start.month == current.month && start.day < current.day))) ||
        (end.year == current.year && ((end.month > current.month) || (end.month == current.month && end.day > current.day))))
    {
        return true;
    }

    return false;
}
#endif
