#include "Cell.h"


Cell::Cell():
	f_intValue(0),f_doubleValue(0.00)
{
	setNewVal(String("string"), String(""));
}

Cell::Cell(String value)
{
    this->setNewVal(String("string"), String(""));

    if (value.isIntString())
    {
        int intVal = atoi(value.getStr());
        String integer("int");
        this->setNewVal(integer, value, intVal);
    }
    else if (value.isDoubleString())
    {
        double intVal = strtod(value.getStr(), NULL);
        String dob("double");
        this->setNewVal(dob, value, intVal);
    }
    else
    {

        if (value[0] == '\"' && value[value.getLength() - 1] == '\"')
        {
            if (value.isGood())
            {
                String cellValue;
                for (size_t j = 1; j < value.getLength() - 1; j++)
                {
                    cellValue += value[j];
                }
                String str = "string";
                this->setNewVal(str, cellValue);
            }
            else
            {
                value = "INVALID_STRING";
                String str = "string";
                this->setNewVal(str, value);
            }
        }
        
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

