#pragma once
#include <windows.h>
#include <string>

//信号灯接口
class Semaphore {
public:
  Semaphore();
  void ShowTextFrom(int times);
  void OutPutNum(int num);
  void OutPutPerson(int cnt, int idx);
  void ShowPerson();
  void OutPutBlack();
  void OutPutBlankAndPerson();
  virtual void ShowTextColor(int cnt, int idx) = 0;
protected:
  WORD old_color_attr_;
  HANDLE std_handle_;
  const std::string str_enter_ = "\n"; //默认回车一个
  const std::string str_space_ = "   "; //默认空格3个
};

class RedLight :public Semaphore {
public:
  virtual void ShowTextColor(int cnt, int idx);
  void ShowRedTextOnce(int num);
protected:
  WORD bakg_red_ = BACKGROUND_RED;
};

class GreenLight :public Semaphore {
public:
  virtual void ShowTextColor(int cnt, int idx);
  void ShowGreenTextOnce(int num);
protected:
  WORD bakg_green_ = BACKGROUND_GREEN;
};
