#include "String.h"
#include "String.h"

String::String()
{
    str = new char[1];
    strcpy(str, "\0");
    length = 0;
};

String::String(const char* _str)
{
    setLength(strlen(_str));
    setStr(_str);
}

String::String(const String& other)
{
    setLength(other.length);
    setStr(other.str);
}

String::~String()
{
    delete[] str;
}

void String::setStr(const char* _str)
{
    if (_str != nullptr)
    {
        this->str = new char[strlen(_str) + 1];
        strcpy(this->str, _str);
    }     
    else
    {
        this->str = new char[1];
        strcpy(this->str, "");
    }
}

void String::setLength(int _length)
{
    this->length = _length;
}

String& String::operator=(const String& other)
{
    if (this != &other)
    {
        delete[] this->str;

        this->str = new char[other.length];

        setLength(other.length);
        setStr(other.str);
    }

    return *this;
}

String String::operator+=(const String& other)
{
    int newLength = this->length + other.length, index = this->length;
    char* biggerBuffer = new char[newLength + 1];

    for (int i = 0; i < this->length; i++)
    {
        biggerBuffer[i] = this->str[i];
    }

    for (int i = 0; i < other.length; i++)
    {
        biggerBuffer[index] = other.str[i];
        index++;
    }
    biggerBuffer[index] = '\0';

    delete[] this->str;

    this->str = biggerBuffer;
    this->length = newLength;

    return *this;
}

String String::operator+=(const char* _str)
{
    int newLength = this->length + strlen(_str), index = this->getLength();
    char* biggerBuffer = new char[newLength + 1];

    for (int i = 0; i < this->length; i++)
    {
        biggerBuffer[i] = this->str[i];
    }

    for (int i =0; i < strlen(_str); i++)
    {
        biggerBuffer[index] = _str[i];
        index++;
    }

    biggerBuffer[index] = '\0';
    delete[] this->str;

    this->str = biggerBuffer;
    this->length = newLength;

    return *this;
}

String String::operator+=(char _str)
{
    int newLength = this->length + 1, index = this->getLength();
    char* biggerBuffer = new char[newLength + 1];

    for (int i = 0; i < this->length; i++)
    {
        biggerBuffer[i] = this->str[i];
    }

    biggerBuffer[index] = _str;
    index++;

    biggerBuffer[index] = '\0';
    delete[] this->str;

    this->str = biggerBuffer;
    this->length = newLength;

    return *this;
}

String String::operator+(const String& other)
{
    String res;

    int resLength = this->length + other.length, index = 0;
    char* resStr = new char[resLength];

    for (int i = 0; i < this->length; i++)
    {
        index++;
    }

    for (int i = 0; i < other.length;  i++)
    {
        resStr[index] = other.str[i];
        index++;
    }
    resStr[index] = '\0';

    res.length = resLength;
    res.str = resStr;

    return res;
}

String String::operator+(const char* other)
{
    int resLength = this->length + strlen(other), index = 0;
    char* resStr = new char[resLength + 1];

    for (int i = 0; i < this->length; i++)
    {
        resStr[index] = this->str[i];
        index++;
    }

    for (int i = 0; i < strlen(other); i++)
    {
        resStr[index] = other[i];
        index++;
    }
    resStr[index] = '\0';

    String res(resStr);

    return res;
}

char String::operator[](const int index) const
{
    assert(index >= 0 && index <= this->length);
    return this->str[index];
}

bool String::operator!=(const String& other)
{ 
    return strcmp(this->str, other.str) != 0;    
}

bool String::operator==(const String& other)
{
    return strcmp(this->str, other.str) == 0;

    return false;
}

bool String::operator==(const char* other)
{
    return strcmp(this->str, other) == 0;

    return false;
}

bool String::operator<(const String& other)
{
    return strcmp(this->str, other.str) < 0;
}

bool String::operator>(const String& other)
{
    return strcmp(this->str, other.str) > 0;
}

bool String::operator<=(const String& other)
{
    return strcmp(this->str, other.str) <= 0;
}

bool String::operator>=(const String& other)
{
    return strcmp(this->str, other.str) >= 0;
}

bool String::isIntString()
{
    if (this->str[0] == '+' || this->str[0] == '-')
    {
        for (size_t i = 1; i < this->length; i++)
        {
            if (this->str[i] < '0' || this->str[i] > '9')
            {
                return false;
            }
        }
    }
    else
    {
        for (size_t i = 0; i < this->length; i++)
        {
            if (this->str[i] < '0' || this->str[i] > '9')
            {
                return false;
            }
        }
    }
    

    return true;
}

bool String::isDoubleString()
{
    char* copy = nullptr;
    char* tok = nullptr;

    if (this->str[0] == '+' || this->str[0] == '-')
    {
        copy = new char[this->length];
        strcpy(copy, this->str + 1);


    }
    else
    {
        
        copy = new char[this->length + 1];
        strcpy(copy, this->str);

        
    }
    
    tok = strtok(copy, ".");
    

    if (tok != nullptr)
    {
        if (strcmp(tok, this->str) == 0)
        {
            return false;
        }

        for (size_t i = 0; i < strlen(tok); i++)
        {
            if (tok[i] < '0' || tok[i] > '9')
            {
                return false;
            }
        }

        tok = strtok(NULL, ".");
        if (tok == NULL)
            return false;
        for (size_t i = 0; i < strlen(tok); i++)
        {
            if (tok[i] < '0' || tok[i] > '9')
            {
                return false;
            }
        }

        tok = strtok(NULL, ".");

        if (tok == NULL)
        {
            return true;
        }
    }
    
    return false;

}

int String::getLength() const
{
    return this->length;
}

const char* String::getStr() const
{
    return this->str;
}

void String::output()
{
    for (int i = 0; i < this->length; i++)
    {
        std::cout << this->str[i];
    }

    std::cout << std::endl;
}

void String::add(const char* _str)
{
    int newLength = this->length + strlen(_str), index = 0;
    char* biggerBuffer = new (std::nothrow) char[newLength];

    if (!biggerBuffer)
    {
        std::cout << "Not enough memory!" << std::endl;
        delete[] biggerBuffer;
        return;
    }

    for (int i = 0; i < this->length; i++)
    {
        biggerBuffer[i] = this->str[i];
    }

    for (int i = this->length; i < newLength; i++)
    {
        biggerBuffer[i] = _str[index];
        index++;
    }

    delete[] this->str;

    this->str = biggerBuffer;
    this->length = newLength;
}

void String::removeLast()
{
    int index = 0;
    assert(this->length >= 0);

    char* smallerBuffer = new (std::nothrow) char[this->length];

    if (!smallerBuffer)
    {
        std::cout << "Not enough memory!" << std::endl;
        smallerBuffer = nullptr;
        return;
    }

    for (int i = 0; i < this->length - 1; i++)
    {
        smallerBuffer[index] = this->str[i];
        index++;
    }
    smallerBuffer[index] = '\0';

    delete[] this->str;

    this->str = smallerBuffer;
    this->length = this->length - 1;
}

String String::slice(int start, int end) const
{
    assert(start >= 0 && end < this->length && start <= end);

    String res;

    int _length = end - start + 1, index = start, resultIndex = 0;
    char* result = new char[_length + 1];

    while (index <= end)
    {
        result[resultIndex] = this->str[index];
        resultIndex++, index++;
    }

    result[_length] = '\0';

    res.length = _length;
    res.str = result;

    return res;
}

bool String::isMatching(char* strToSearch, const char* strToMatch)
{
    for (int i = 0; *(strToMatch + i); i++)
    {
        if (strToSearch[i] != strToMatch[i])
        {
            return false;
        }
    }
    return true;
}

void String::shiftLeft(char* strToShift, int shiftPosCount)
{
    int i = 0;

    for (; *(strToShift + i); i++)
    {
        strToShift[i - shiftPosCount] = strToShift[i];
    }

    strToShift[i - shiftPosCount] = strToShift[i];
}

void String::shiftRight(char* strToShift, int shiftPosCount)
{
    int textLen = strlen(strToShift);
    for (int i = textLen + 1; i >= 0; i--)
    {
        *(strToShift + i + shiftPosCount) = *(strToShift + i);
    }
}

void String::performStringReplacement(char* source, const char* newWord)
{
    for (int i = 0; *(newWord + i); i++)
    {
        *(source + i) = *(newWord + i);
    }
}

void String::replace(const char* oldWord, const char* newWord)
{
    int oldWordLen = strlen(oldWord);
    int newWordLen = strlen(newWord);

    for (int i = 0; *(this->str + i); i++)
    {
        
        if (isMatching(this->str + i, oldWord))
        {
            if (oldWordLen > newWordLen)
            {
                performStringReplacement(this->str + i, newWord);
                shiftLeft(this->str + i + oldWordLen, oldWordLen - newWordLen);
            }
            else if (oldWordLen < newWordLen)
            {
                shiftRight(this->str + i + oldWordLen, newWordLen - oldWordLen);
                performStringReplacement(this->str + i, newWord);
            }
            else
            {
                performStringReplacement(this->str + i, newWord);
            }
        }
    }
}



ostream& operator<<(ostream& out, const String str)
{
    out << str.getStr();
    return out;
}
