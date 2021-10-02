
#include "pch.h"
#include "CQuestionBank.h"
//#include <algorithm>

QuestionMgr::QuestionMgr() {
    allQuestions.push_back(
        QuestionAndAnswer{"行人准备过马路时，要等红绿黄哪个灯亮的时候最安全？", "红灯", "绿灯", "绿灯" });
    allQuestions.push_back(
        QuestionAndAnswer{ "绿灯时可以沿着人行横道通过马路。", "对", "不对", "对" });
    allQuestions.push_back(
        QuestionAndAnswer{ "红灯时可以沿着人行横道通过马路。", "对", "不对", "不对" });
    allQuestions.push_back(
        QuestionAndAnswer{ "行人可以进入高速公路吗？", "可以", "不可以", "不可以" });
    allQuestions.push_back(
        QuestionAndAnswer{ "行人在没有人行道的道路上行走，应该走哪边？", "左边", "右边", "右边" });
    allQuestions.push_back(
        QuestionAndAnswer{ "交通信号灯有两种，分别时红灯和绿灯。", "对", "不对", "不对" });
    allQuestions.push_back(
        QuestionAndAnswer{ "驾驶自行车、三轮车必须年满多少岁？", "10岁", "12岁", "12岁" });
    allQuestions.push_back(
        QuestionAndAnswer{ "行人在道路上行走时，要走哪里？", "人行道", "非机动车道", "人行道" });
    allQuestions.push_back(
        QuestionAndAnswer{ "《道路交通安全法》总共有多少条？", "124条", "134条", "124条" });
    allQuestions.push_back(
        QuestionAndAnswer{ "方向指示信号灯的箭头方向向左、向上、向右分别表示左转、直行、右转。", "对", "不对", "对" });

    for (int idx = 0; idx < allQuestions.size(); idx++) {
        allIndex.push_back(idx);
    }
}

std::vector<QuestionAndAnswer*> QuestionMgr::RandQuests(int num) {
    std::vector<QuestionAndAnswer*> ret;
    //随机打乱顺序
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
