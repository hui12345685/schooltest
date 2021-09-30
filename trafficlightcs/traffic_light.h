#pragma once
#include <windows.h>
#include <string>

//�źŵƽӿ�
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
  const std::string str_enter_ = "\n"; //Ĭ�ϻس�һ��
  const std::string str_space_ = "   "; //Ĭ�Ͽո�3��
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
