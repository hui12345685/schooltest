
#include "stdio.h"
#include "traffic_light.h"

/*******************************************************************************
 * ȫ������̨����
 * ȡ�����������߿�
 ******************************************************************************/
void FullScreen()
{
  HWND hwnd = GetForegroundWindow();
  int cx = GetSystemMetrics(SM_CXSCREEN);            /* ��Ļ��� ���� */
  int cy = GetSystemMetrics(SM_CYSCREEN);            /* ��Ļ�߶� ���� */

  LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);   /* ��ȡ������Ϣ */
  /* ���ô�����Ϣ ��� ȡ�����������߿� */
  SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);

  SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
  //ShowWindow(GetConsoleWindow(), SW_MINIMIZE);
}

int main() {
  //�Ƚ���Ļ���
  FullScreen();
  
  RedLight red_light;
  GreenLight green_light;
  
  while (1){
    green_light.ShowTextFrom(15);
    red_light.ShowTextFrom(15);
  }
  return 0;
}
