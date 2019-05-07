#ifndef UI_H
#define UI_H
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "ChessBoard.h"
#include "Record.h"
using std::cout;

class UI
{
public:
    UI();

    // 印出遊戲畫面
    static void printUI();

    // 讀取鍵盤
    void readKeyBoard();

    // 跳出確認視窗
    bool showAlert(string);

    // 跳出確認視窗
    bool showWin(string);

    // 跳出選單
    int showMenu();

    ChessBoard chessBoard;

private:
    Chess* lastChosed;
    bool cueMode;
};

#endif // !UI_H

