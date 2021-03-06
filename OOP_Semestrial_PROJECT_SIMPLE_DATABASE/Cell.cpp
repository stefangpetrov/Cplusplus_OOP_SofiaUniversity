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
        if (value == "")
        {
            int intVal = 0;
            value = "NULL";
            this->setNewVal(type, value, intVal);
        }
        else
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
    }
    else if (type == "double")
    {
        if (value == "")
        {
            int dobVal = 0;
            value = "NULL";
            this->setNewVal(type, value, dobVal);
        }
        else
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

void Cell::operate(String operation, Cell other)
{
    if (operation == "minimum")
    {
        
        if (f_type == "double")
        {
            double otherValue = strtod(other.f_value.getStr(), NULL);
            if (f_doubleValue > otherValue)
            {
                
                f_doubleValue = otherValue;


                ofstream dobVal;
                dobVal.open("ConvertNumberToString.txt");
                dobVal << f_doubleValue;

                dobVal.close();

                char c;
                ifstream dobString;
                dobString.open("ConvertNumberToString.txt");
                
                f_value = "";
                while (dobString.get(c))
                {

                    f_value += c;
                }
                dobString.close();
                

            }
            
        }
        else if (f_type == "int")
        {
            double otherValue = strtod(other.f_value.getStr(), NULL);
            if (f_intValue > otherValue)
            {

                f_intValue = otherValue;


                ofstream dobVal;
                dobVal.open("ConvertNumberToString.txt");
                dobVal << f_intValue;

                dobVal.close();

                char c;
                ifstream dobString;
                dobString.open("ConvertNumberToString.txt");

                f_value = "";
                while (dobString.get(c))
                {

                    f_value += c;
                }
                dobString.close();


            }
        }
    }
    else if (operation == "maximum")
    {

        if (f_type == "double")
        {
            double otherValue = strtod(other.f_value.getStr(), NULL);
            if (f_doubleValue < otherValue)
            {

                f_doubleValue = otherValue;


                ofstream dobVal;
                dobVal.open("ConvertNumberToString.txt");
                dobVal << f_doubleValue;

                dobVal.close();

                char c;
                ifstream dobString;
                dobString.open("ConvertNumberToString.txt");

                f_value = "";
                while (dobString.get(c))
                {

                    f_value += c;
                }
                dobString.close();


            }

        }
        else if (f_type == "int")
        {
            double otherValue = strtod(other.f_value.getStr(), NULL);
            if (f_intValue < otherValue)
            {

                f_intValue = otherValue;


                ofstream dobVal;
                dobVal.open("ConvertNumberToString.txt");
                dobVal << f_intValue;

                dobVal.close();

                char c;
                ifstream dobString;
                dobString.open("ConvertNumberToString.txt");

                f_value = "";
                while (dobString.get(c))
                {

                    f_value += c;
                }
                dobString.close();


            }
        }
    }
    else if (operation == "sum")
    {

        if (f_type == "double")
        {
            double otherValue = strtod(other.f_value.getStr(), NULL);
            f_doubleValue = f_doubleValue + otherValue;


            ofstream dobVal;
            dobVal.open("ConvertNumberToString.txt");
            dobVal << f_doubleValue;

            dobVal.close();

            char c;
            ifstream dobString;
            dobString.open("ConvertNumberToString.txt");

            f_value = "";
            while (dobString.get(c))
            {

                f_value += c;
            }
            dobString.close();

        }
        else if (f_type == "int")
        {
            double otherValue = strtod(other.f_value.getStr(), NULL);
            f_intValue = f_intValue + otherValue;


            ofstream dobVal;
            dobVal.open("ConvertNumberToString.txt");
            dobVal << f_intValue;

            dobVal.close();

            char c;
            ifstream dobString;
            dobString.open("ConvertNumberToString.txt");

            f_value = "";
            while (dobString.get(c))
            {

                f_value += c;
            }
            dobString.close();
        }
    }
    else if (operation == "product")
    {

        if (f_type == "double")
        {
            double otherValue = strtod(other.f_value.getStr(), NULL);
            f_doubleValue = f_doubleValue * otherValue;


            ofstream dobVal;
            dobVal.open("ConvertNumberToString.txt");
            dobVal << f_doubleValue;

            dobVal.close();

            char c;
            ifstream dobString;
            dobString.open("ConvertNumberToString.txt");

            f_value = "";
            while (dobString.get(c))
            {

                f_value += c;
            }
            dobString.close();

        }
        else if (f_type == "int")
        {
            double otherValue = strtod(other.f_value.getStr(), NULL);
            f_intValue = f_intValue * otherValue;


            ofstream dobVal;
            dobVal.open("ConvertNumberToString.txt");
            dobVal << f_intValue;

            dobVal.close();

            char c;
            ifstream dobString;
            dobString.open("ConvertNumberToString.txt");

            f_value = "";
            while (dobString.get(c))
            {

                f_value += c;
            }
            dobString.close();
        }
    }
    

}



ostream& operator<<(ostream& out, const Cell& cell)
{
    out << cell.f_value;
    return out;
}

