#pragma once

#include <afxstr.h>
#include <vector>

struct QuestionAndAnswer
{
    CString Question; //问题
    CString Answer1; //答案1
    CString Answer2; //答案2
    CString CorrectAnswer; //答案2
};

class QuestionMgr {
public:
    static QuestionMgr& GetInst() {
        static QuestionMgr questMgr;
        return questMgr;
    }
    //随机选择几个题目,默认选3题
    std::vector<QuestionAndAnswer*> RandQuests(int num = 3);

private:
    QuestionMgr();
    ~QuestionMgr() {}
    QuestionMgr(const QuestionMgr&);
    void operator=(const QuestionMgr&);

    std::vector<QuestionAndAnswer> allQuestions; // 所有题目
    std::vector<int> allIndex;
};

