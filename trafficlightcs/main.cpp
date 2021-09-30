
#include "stdio.h"
#include "traffic_light.h"

/*******************************************************************************
 * 全屏控制台窗口
 * 取消标题栏及边框
 ******************************************************************************/
void FullScreen()
{
  HWND hwnd = GetForegroundWindow();
  int cx = GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 像素 */
  int cy = GetSystemMetrics(SM_CYSCREEN);            /* 屏幕高度 像素 */

  LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);   /* 获取窗口信息 */
  /* 设置窗口信息 最大化 取消标题栏及边框 */
  SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);

  SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
  //ShowWindow(GetConsoleWindow(), SW_MINIMIZE);
}

int main() {
  //先将屏幕最大化
  FullScreen();
  
  RedLight red_light;
  GreenLight green_light;
  
  while (1){
    green_light.ShowTextFrom(15);
    red_light.ShowTextFrom(15);
  }
  return 0;
}
