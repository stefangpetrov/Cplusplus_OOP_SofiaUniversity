#pragma once
class Date
{
private:
	size_t f_year;
	size_t f_month;
	size_t f_day;

public:
	Date(size_t year = 2020, size_t month = 1, size_t day = 1) :
		f_year(year), f_month(month), f_day(day)
	{
		setYear(year);
		setMonth(month);
		setDay(day);	
	}

	size_t getYear() const { return f_year; } 
	size_t getMonth() const { return f_month; } 
	size_t getDay() const { return f_day; } 

	void setYear(size_t year)
	{
		if (f_year > 2020)
		{
			f_year = 2020;
		}
	}

	void setMonth(size_t month)
	{
		if (f_month > 12)
		{
			f_month = 1;
		}
	}

	void setDay(size_t day)
	{
		if (f_year % 4 == 0)
		{
			if (f_year % 100 == 0)
			{
				if (f_year % 400 == 0)
				{
					if (f_month == 2)
					{
						if (day > 29)
						{
							f_day = 1;
						}
					}
					else
					{
						if (day > 31)
						{
							f_day = 1;
						}
					}
				}

			}
			else
			{
				if (f_month == 2)
				{
					if (day > 29)
					{
						f_day = 1;
					}
				}
				else
				{
					if (day > 31)
					{
						f_day = 1;
					}
				}
			}

		}
		else
		{
			if (f_month == 2)
			{
				if (day > 28)
				{
					f_day = 1;
				}
			}
			else
			{
				if (day > 31)
				{
					f_day = 1;
				}
			}
		}
	}


};

