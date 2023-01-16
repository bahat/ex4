//
// Created by Omer Bahat on 14/01/2023.
//

#ifndef EX4_EXCEPTION_H
#define EX4_EXCEPTION_H

class Exception : public std::exception
{
protected:
    std::string m_errorMessage;
public:
    Exception()
    {
        m_errorMessage = "shit fuck something went wrong";
    }
    const char * what() const noexcept override
    {
        return m_errorMessage.c_str();
    }
};

class DeckFileNotFound : public Exception
{
public:
    DeckFileNotFound()
    {
        m_errorMessage = "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public Exception
{
public:
    DeckFileFormatError(int lineNumber)
    {
        m_errorMessage = "Deck File Error: File format error in line "+ std::to_string(lineNumber);
    }

};

class DeckFileInvalidSize : public Exception
{
    DeckFileInvalidSize()
    {
        m_errorMessage = "Deck File Error: Deck size is invalid";
    }
};


#endif //EX4_EXCEPTION_H
