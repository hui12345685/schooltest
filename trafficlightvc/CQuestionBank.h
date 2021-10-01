#pragma once

#include <afxstr.h>
#include <vector>

struct QuestionAndAnswer
{
    CString Question; //����
    CString Answer1; //��1
    CString Answer2; //��2
    CString CorrectAnswer; //��2
};

class QuestionMgr {
public:
    static QuestionMgr& GetInst() {
        static QuestionMgr questMgr;
        return questMgr;
    }
    //���ѡ�񼸸���Ŀ,Ĭ��ѡ3��
    std::vector<QuestionAndAnswer*> RandQuests(int num = 3);

private:
    QuestionMgr();
    ~QuestionMgr() {}
    QuestionMgr(const QuestionMgr&);
    void operator=(const QuestionMgr&);

    std::vector<QuestionAndAnswer> allQuestions; // ������Ŀ
    std::vector<int> allIndex;
};

