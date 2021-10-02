
#include "pch.h"
#include "CQuestionBank.h"
//#include <algorithm>

QuestionMgr::QuestionMgr() {
    allQuestions.push_back(
        QuestionAndAnswer{"����׼������·ʱ��Ҫ�Ⱥ��̻��ĸ�������ʱ���ȫ��", "���", "�̵�", "�̵�" });
    allQuestions.push_back(
        QuestionAndAnswer{ "�̵�ʱ�����������к��ͨ����·��", "��", "����", "��" });
    allQuestions.push_back(
        QuestionAndAnswer{ "���ʱ�����������к��ͨ����·��", "��", "����", "����" });
    allQuestions.push_back(
        QuestionAndAnswer{ "���˿��Խ�����ٹ�·��", "����", "������", "������" });
    allQuestions.push_back(
        QuestionAndAnswer{ "������û�����е��ĵ�·�����ߣ�Ӧ�����ıߣ�", "���", "�ұ�", "�ұ�" });
    allQuestions.push_back(
        QuestionAndAnswer{ "��ͨ�źŵ������֣��ֱ�ʱ��ƺ��̵ơ�", "��", "����", "����" });
    allQuestions.push_back(
        QuestionAndAnswer{ "��ʻ���г������ֳ��������������ꣿ", "10��", "12��", "12��" });
    allQuestions.push_back(
        QuestionAndAnswer{ "�����ڵ�·������ʱ��Ҫ�����", "���е�", "�ǻ�������", "���е�" });
    allQuestions.push_back(
        QuestionAndAnswer{ "����·��ͨ��ȫ�����ܹ��ж�������", "124��", "134��", "124��" });
    allQuestions.push_back(
        QuestionAndAnswer{ "����ָʾ�źŵƵļ�ͷ�����������ϡ����ҷֱ��ʾ��ת��ֱ�С���ת��", "��", "����", "��" });

    for (int idx = 0; idx < allQuestions.size(); idx++) {
        allIndex.push_back(idx);
    }
}

std::vector<QuestionAndAnswer*> QuestionMgr::RandQuests(int num) {
    std::vector<QuestionAndAnswer*> ret;
    //�������˳��
    //random_shuffle(allIndex.begin(), allIndex.end());
    for (size_t id = 0; id < allIndex.size(); id++)
    {
        size_t pos = rand() % allIndex.size();
        if (pos != id){
            int tmp = allIndex[id];
            allIndex[id] = allIndex[pos];
            allIndex[pos] = tmp;
        }
    }

    for (int idx = 0; idx < num; idx++) {
        ret.push_back(&allQuestions[allIndex[idx]]);
    }
    return ret;
}
