#ifndef GUID_8f9f34c0_9d5f_4874_bf16_e50baf617204
#define GUID_8f9f34c0_9d5f_4874_bf16_e50baf617204

#include <unit.hpp>
#include <string>
class PrintOperatorUnit : public Unit
{
  public:
    explicit PrintOperatorUnit(const std::string &text) : m_text(text)
    {
    }
    std::string compile(unsigned int level = 0) const
    {
        return generateShift(level) + "printf( \"" + m_text + "\" );\n";
    }

  private:
    std::string m_text;
};

#endif