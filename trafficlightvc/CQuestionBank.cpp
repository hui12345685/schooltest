
#include "pch.h"
#include "CQuestionBank.h"
#include <algorithm>

QuestionMgr::QuestionMgr() {
    allQuestions.push_back(
        QuestionAndAnswer{"1", "1", "1", "1" });
    allQuestions.push_back(
        QuestionAndAnswer{ "2", "2", "2", "2" });
    allQuestions.push_back(
        QuestionAndAnswer{ "3", "3", "3", "3" });
    allQuestions.push_back(
        QuestionAndAnswer{ "4", "4", "4", "4" });
    allQuestions.push_back(
        QuestionAndAnswer{ "5", "5", "5", "5" });
    allQuestions.push_back(
        QuestionAndAnswer{ "6", "6", "6", "6" });
    allQuestions.push_back(
        QuestionAndAnswer{ "7", "7", "7", "7" });
    allQuestions.push_back(
        QuestionAndAnswer{ "8", "8", "8", "8" });
    allQuestions.push_back(
        QuestionAndAnswer{ "9", "9", "9", "9" });
    allQuestions.push_back(
        QuestionAndAnswer{ "10", "10", "10", "10" });

    for (int idx = 0; idx < allQuestions.size(); idx++) {
        allIndex.push_back(idx);
    }
}

std::vector<QuestionAndAnswer*> QuestionMgr::RandQuests(int num) {
    std::vector<QuestionAndAnswer*> ret;
    //Ëæ»ú´òÂÒË³Ðò
    random_shuffle(allIndex.begin(), allIndex.end());
    for (int idx = 0; idx < num; idx++) {
        ret.push_back(&allQuestions[idx]);
    }
    return ret;
}
