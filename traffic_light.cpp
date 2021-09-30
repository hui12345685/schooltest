#include <iostream>
#include "traffic_light.h"

#pragma warning(disable:4996)

class ConsonleInit {
public:
  static ConsonleInit& GetInst() {
    static ConsonleInit con_init;
    return con_init;
  }
  void Init(HANDLE& std_handle, WORD old_color_attr) {
    if (!init_){
      std_handle_ = GetStdHandle(STD_OUTPUT_HANDLE);

      //隐藏光标
      CONSOLE_CURSOR_INFO CursorInfo;
      GetConsoleCursorInfo(std_handle_, &CursorInfo);//获取控制台光标信息
      CursorInfo.bVisible = false; //隐藏控制台光标
      SetConsoleCursorInfo(std_handle_, &CursorInfo);//设置控制台光标状态

      //设置控制台输出字体大小
      CONSOLE_FONT_INFOEX cfi;
      cfi.cbSize = sizeof(cfi);
      cfi.nFont = 0;
      cfi.dwFontSize.X = 0;                   // Width of each character in the font
      cfi.dwFontSize.Y = 130;                  // Height
      cfi.FontFamily = FF_DONTCARE;
      cfi.FontWeight = FW_NORMAL;
      std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font

      SetCurrentConsoleFontEx(std_handle_, FALSE, &cfi);

      std::cout << "program start." << std::endl;
      system("cls");

      //获取并保存原来的背景色
      CONSOLE_SCREEN_BUFFER_INFO csb_info;
      GetConsoleScreenBufferInfo(std_handle_, &csb_info);
      old_color_attr_ = csb_info.wAttributes;

      init_ = true;
    }
    std_handle = std_handle_;
    old_color_attr = old_color_attr_;
  }
private:
  ConsonleInit() {}
  ~ConsonleInit() {}
  ConsonleInit(const ConsonleInit&);
  void operator=(const ConsonleInit&);
  bool init_ = false;
  HANDLE std_handle_;
  WORD old_color_attr_;
};

Semaphore::Semaphore() {
  ConsonleInit::GetInst().Init(std_handle_, old_color_attr_);
}

void Semaphore::ShowTextFrom(int times) {
  for (int idx = times; idx > 0; idx--){
    std::cout << str_enter_; //加一个空行
    std::cout << str_space_; //加上空格
    ShowTextColor(times, idx);
    Sleep(1000);//1秒
    system("cls");
  }
}

void Semaphore::OutPutNum(int num) {
  if (num < 10) {
    std::cout << " " << num ;
  }
  else {
    std::cout << num ;
  }
}

void Semaphore::OutPutPerson(int cnt, int idx) {
  if (cnt == idx){
    return;
  }
  for (int i = cnt; i > idx; i--){
    std::cout << str_enter_; //每秒走一行
  }
  std::cout << str_space_ << str_space_; //多加一次空格
  ShowPerson();
}

void Semaphore::ShowPerson() {
  //设置背景为蓝色吧
  SetConsoleTextAttribute(std_handle_, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
  std::cout << "*"; //*号代表人物
  //恢复背景色
  SetConsoleTextAttribute(std_handle_, old_color_attr_);
}

void Semaphore::OutPutBlack() {
  //输入两个灯之间的空格
  std::cout << str_space_ << str_space_ << str_space_ << str_space_;
}

void Semaphore::OutPutBlackAndPerson() {
  std::cout << " ";
  ShowPerson();
  //填空填到和OutPutBlack一样
  std::cout << str_space_ << str_space_ << str_space_ << "  "; 
}

void RedLight::ShowRedTextOnce(int num) {
  //设置背景红色
  SetConsoleTextAttribute(std_handle_, FOREGROUND_INTENSITY | bakg_red_);
  OutPutNum(num);
  //恢复背景色
  SetConsoleTextAttribute(std_handle_, old_color_attr_);
}

void RedLight::ShowTextColor(int cnt, int idx) {
  ShowRedTextOnce(idx);//左边的
  OutPutBlack();
  ShowRedTextOnce(idx);//右边的
}

void GreenLight::ShowGreenTextOnce(int num) {
  //设置背景为绿色
  SetConsoleTextAttribute(std_handle_, FOREGROUND_INTENSITY | bakg_green_);
  OutPutNum(num);
  //恢复背景色
  SetConsoleTextAttribute(std_handle_, old_color_attr_);
}

void GreenLight::ShowTextColor(int cnt, int idx) {
  ShowGreenTextOnce(idx);//左边的
  if (cnt == idx){
    OutPutBlackAndPerson();
  }
  else {
    OutPutBlack();
  }
  
  ShowGreenTextOnce(idx);//右边的
  OutPutPerson(cnt, idx);//行走的人
}
