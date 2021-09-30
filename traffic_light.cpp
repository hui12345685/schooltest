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

      //���ع��
      CONSOLE_CURSOR_INFO CursorInfo;
      GetConsoleCursorInfo(std_handle_, &CursorInfo);//��ȡ����̨�����Ϣ
      CursorInfo.bVisible = false; //���ؿ���̨���
      SetConsoleCursorInfo(std_handle_, &CursorInfo);//���ÿ���̨���״̬

      //���ÿ���̨��������С
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

      //��ȡ������ԭ���ı���ɫ
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
    std::cout << str_enter_; //��һ������
    std::cout << str_space_; //���Ͽո�
    ShowTextColor(times, idx);
    Sleep(1000);//1��
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
    std::cout << str_enter_; //ÿ����һ��
  }
  std::cout << str_space_ << str_space_; //���һ�οո�
  ShowPerson();
}

void Semaphore::ShowPerson() {
  //���ñ���Ϊ��ɫ��
  SetConsoleTextAttribute(std_handle_, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
  std::cout << "*"; //*�Ŵ�������
  //�ָ�����ɫ
  SetConsoleTextAttribute(std_handle_, old_color_attr_);
}

void Semaphore::OutPutBlack() {
  //����������֮��Ŀո�
  std::cout << str_space_ << str_space_ << str_space_ << str_space_;
}

void Semaphore::OutPutBlackAndPerson() {
  std::cout << " ";
  ShowPerson();
  //������OutPutBlackһ��
  std::cout << str_space_ << str_space_ << str_space_ << "  "; 
}

void RedLight::ShowRedTextOnce(int num) {
  //���ñ�����ɫ
  SetConsoleTextAttribute(std_handle_, FOREGROUND_INTENSITY | bakg_red_);
  OutPutNum(num);
  //�ָ�����ɫ
  SetConsoleTextAttribute(std_handle_, old_color_attr_);
}

void RedLight::ShowTextColor(int cnt, int idx) {
  ShowRedTextOnce(idx);//��ߵ�
  OutPutBlack();
  ShowRedTextOnce(idx);//�ұߵ�
}

void GreenLight::ShowGreenTextOnce(int num) {
  //���ñ���Ϊ��ɫ
  SetConsoleTextAttribute(std_handle_, FOREGROUND_INTENSITY | bakg_green_);
  OutPutNum(num);
  //�ָ�����ɫ
  SetConsoleTextAttribute(std_handle_, old_color_attr_);
}

void GreenLight::ShowTextColor(int cnt, int idx) {
  ShowGreenTextOnce(idx);//��ߵ�
  if (cnt == idx){
    OutPutBlackAndPerson();
  }
  else {
    OutPutBlack();
  }
  
  ShowGreenTextOnce(idx);//�ұߵ�
  OutPutPerson(cnt, idx);//���ߵ���
}
