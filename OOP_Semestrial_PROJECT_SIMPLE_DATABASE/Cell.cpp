#include "Cell.h"


Cell::Cell() :
    f_intValue(0), f_doubleValue(0.00)
{
    setNewVal(String("string"), String(""));
}

Cell::Cell(String type, String value)
{
    this->setNewVal(String("string"), String("NULL"));

    if (type == "int")
    {
        if (value.isIntString())
        {
            int intVal = atoi(value.getStr());

            this->setNewVal(type, value, intVal);
        }
        else
        {
            value = "NULL";
            this->setNewVal(type, value, 0);
        }
    }
    else if (type == "double")
    {
        if (value.isDoubleString())
        {
            double dobVal = strtod(value.getStr(), NULL);

            this->setNewVal(type, value, dobVal);
        }
        else
        {
            value = "NULL";
            this->setNewVal(type, value, 0.00);
        }
        
    }
    else if(type == "string")
    {
        this->setNewVal(type, value);
    }



}



const String Cell::getType() const
{
    return this->f_type;
}

void Cell::setNewVal(String type, String value)
{
    f_type = type;
    f_value = value;
}

void Cell::setNewVal(String type, String value, int intVal)
{
    f_type = type;
    f_value = value;
    f_intValue = intVal;
}

const int Cell::getLength() const
{
    return f_value.getLength();
}

void Cell::setNewVal(String type, String value, double doubleVal)
{
    f_type = type;
    f_value = value;
    f_doubleValue = doubleVal;
}

const String Cell::getValue() const
{
    return f_value;
}



ostream& operator<<(ostream& out, const Cell& cell)
{
    out << cell.f_value;
    return out;
}

